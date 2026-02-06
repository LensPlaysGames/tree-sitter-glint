/**
 * @file The tree sitter parser declaration for the Glint programming language (part of the Lensor Compiler Collection)
 * @author Lens_r
 * @license 2025 All rights reserved
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

export default grammar({
    name: "glint",

    word: $ => $.identifier,

    extras: $ => [/(\s|\f)/, $.comment],

    supertypes: $ => [
        $._expr,
        $._type,
    ],

    rules: {
        source_file: $ => seq(
            optional($.module_declaration),
            repeat($.module_import),
            optional($._PTEL)
        ),

        module_declaration: $ => seq(
            "module",
            field("name", $.identifier),
            optional($._expression_separator)
        ),

        module_import: $ => prec(999999999, seq(
            choice(
                "import",
                seq("export", "import")
            ),
            field("name", $.identifier),
            optional(seq(
                "as",
                field("declared_name", $.identifier)
            )),
            optional($._expression_separator)
        )),

        // ================
        // TYPES
        // ================
        _type: $ => prec(5, choice(
            $.identifier,
            $.paren,
            $.type_array,
            $.type_enum,
            $.type_ffi,
            $.type_function,
            $.type_pointer,
            $.type_pointer_to_pointer,
            $.type_primitive,
            $.type_reference,
            $.type_struct,
            $.type_sum,
            $.type_union
        )),

        type_enum: $ => seq(
            "enum",
            optional(seq(
                "(",
                field("underlying", $._type),
                ")"
            )),
            $.block
        ),

        type_sum: $ => seq(
            "sum",
            $.block
        ),

        type_struct: $ => seq(
            "struct",
            $.block
        ),

        type_union: $ => seq(
            "union",
            $.block
        ),

        type_primitive: $ => choice(
            "bool",
            "byte",
            "int",
            "uint",
            "float",
            "void"
        ),

        type_ffi: $ => choice(
            "cshort", "cushort",
            "cint", "cuint",
            "clong", "culong",
            "clonglong", "culonglong",
            "csize", "cusize"
        ),

        // TODO: All the attributes
        function_attribute: $ => choice(
            "nomangle",
            "discardable",
            "pure",
            "used",
            "maps_arguments"
        ),

        type_function: $ => prec(5, seq(
            field("return_type", $._type),
            "(",
            repeat($.param_decl),
            ")",
            repeat($.function_attribute)
        )),

        // precedence to beat out regular declaration (so that type_function rule
        // applies rather than type expression + paren expression).
        param_decl: $ => prec(10, seq(
            optional(field("name", $.identifier)),
            ":", field("type", choice($._type, $.identifier)),
            optional(",")
        )),

        type_array: $ => prec(10, seq(
            "[",
            $._type,
            optional(choice(
                $._expr,
                "view"
            )),
            "]"
        )),
        type_pointer: $ => seq($._type, ".ptr"),
        type_pointer_to_pointer: $ => seq($._type, ".pptr"),
        type_reference: $ => seq($._type, ".ref"),

        // ================
        // TYPES END
        // ================


        // ================
        // EXPRESSIONS
        // ================

        _expr: $ => prec.right(1, $._B),
        _expr_terminated: $ => seq($._L, $._hard_expression_separator),
        // possibly terminated expression list
        _PTEL: $ => choice($._M, $._E),


        // multi expression
        _M: $ => seq(
            repeat1($._expr_terminated),
            $._E
        ),

        _E: $ => seq(
            $._L,
            optional($._hard_expression_separator)
        ),

        _L: $ => prec.right(seq(
            $._B,
            repeat(prec.right(seq(
                $._soft_expression_separator,
                $._B
            )))
        )),

        _B: $ => choice(
            $._binary,
            $._type,
            $._unary,
            $.block,
            $.bool_literal,
            $.byte_literal,
            $.call,
            $.cfor,
            $.identifier,
            $.if,
            $.integer_literal,
            $.fractional_literal,
            $.apply,
            $.match,
            $.member_access,
            $.paren,
            $.print,
            $.rangedfor,
            $.return,
            $.string_literal,
            $.type_expr,
            $.while,
        ),

        type_expr: $ => prec(99, seq(":", $._type)),

        _binary: $ => choice(
            $.add,
            $.subtract,
            $.multiply,
            $.divide,
            $.remainder,

            $.eq,
            $.ne,
            $.gt,
            $.ge,
            $.lt,
            $.le,

            $.and,
            $.or,

            $.bitshl,
            $.bitshr,
            $.bitand,
            $.bitor,
            $.bitxor,

            $.assign,
            $.declaration,
            $.subscript,

            $.add_eq,
            $.subtract_eq,
            $.multiply_eq,
            $.divide_eq,
            $.remainder_eq,
            $.tilde_eq,
            $.ampersand_eq,
            $.pipe_eq,
            $.caret_eq,
            $.lbrack_eq,

        ),

        subscript: $ => prec(10010, seq($._expr, "[", $._expr, "]")),

        assign: $ => prec.right(100, seq($._expr, ":=", prec.right($._expr))),
        declaration: $ => prec.right(6, choice(
            seq(
                optional($.storage_specifier),
                field("name", $.identifier),
                choice($._decl_var, $._decl_inferred)
            ),
            $._supplant
        )),
        _supplant: $ => seq(
            "supplant",
            field("supplanted_type", $._type)
        ),
        _decl_var: $ => prec.right(seq(
            ":", field("type", $._type),
            optional("="), optional(field("init", $._expr))
        )),
        _decl_inferred: $ => prec.right(seq("::", field("init", $._expr))),

        _unary: $ => choice(
            $.negate,
            $.addressof,
            $.dereference,
            $.increment,
            $.decrement,
            $.logical_negate,
            $.bitwise_negate
        ),

        dereference: $ => seq("@", prec.right(10000, $._expr)),
        addressof: $ => seq("&", prec.right(10000, $._expr)),
        negate: $ => seq("-", prec.right(10000, $._expr)),
        increment: $ => seq("++", prec.right(10000, $._expr)),
        decrement: $ => seq("--", prec.right(10000, $._expr)),
        logical_negate: $ => seq(choice("!", "not"), prec.right(10000, $._expr)),
        bitwise_negate: $ => seq("bit~", prec.right(10000, $._expr)),

        // Use paren to "escape" back to a grammar that accepts a unary expression as an argument
        // call_repeat1 precedence to ensure that, if a call does apply, it is a
        // call, and not just two expressions back-to-back.
        call: $ => choice($._forced_call, $._multi_call),
        _forced_call: $ => prec(10, seq($._expr, "(", ")")),
        _multi_call: $ => prec.right(seq(
            $._B,
            $._L
        )),

        // Can syntactically represent as a regular call, but, we include this for
        // extra information purposes.
        print: $ => prec.right(seq(
            "print",
            optional($._L)
        )),

        _call_arg: $ => prec(90, $._expr),

        // A paren expression does not open up a new scope.
        paren: $ => seq(
            "(",
            optional($._PTEL),
            ")"
        ),
        // A block expression 's contained expressions are parsed within a new scope.
        block: $ => seq(
            "{",
            optional($._PTEL),
            "}"
        ),

        match: $ => prec(10, seq(
            "match",
            field("object", $._expr),
            "{",
            repeat(prec.left(seq(
                ".",
                $.identifier,
                optional(":"),
                $._expr,
                optional($._expression_separator)
            ))),
            "}"
        )),

        // ================
        // BINARY OPERATORS
        // ================
        _binary_expression: $ => choice(
            $.add,
            $.subtract,
            $.multiply,
            $.divide,
            $.remainder,

            $.eq,
            $.ne,
            $.gt,
            $.ge,
            $.lt,
            $.le,

            $.and,
            $.or,

            $.bitshl,
            $.bitshr,
            $.bitand,
            $.bitor,
            $.bitxor,

            $.add_eq,
            $.subtract_eq,
            $.multiply_eq,
            $.divide_eq,
            $.remainder_eq,
            $.tilde_eq,
            $.ampersand_eq,
            $.pipe_eq,
            $.caret_eq,
            $.lbrack_eq
        ),

        // note that + left or right precedence doesn't matter for these
        // operators, but we pick one to be unambiguous in the grammar.
        add:       $ => prec.left(500, seq($._expr, "+", $._expr)),
        subtract:  $ => prec.left(500, seq($._expr, "-", $._expr)),
        multiply:  $ => prec.left(600, seq($._expr, "*", $._expr)),
        divide:    $ => prec.left(600, seq($._expr, "/", $._expr)),
        remainder: $ => prec.left(600, seq($._expr, "%", $._expr)),

        eq: $ => prec.left(200, seq($._expr, "=", $._expr)),
        ne: $ => prec.left(200, seq($._expr, "!=", $._expr)),
        gt: $ => prec.left(200, seq($._expr, ">", $._expr)),
        ge: $ => prec.left(200, seq($._expr, ">=", $._expr)),
        lt: $ => prec.left(200, seq($._expr, "<", $._expr)),
        le: $ => prec.left(200, seq($._expr, "<=", $._expr)),

        and: $ => prec.left(150, seq($._expr, "and", $._expr)),
        or: $ => prec.left(145, seq($._expr, "or", $._expr)),

        bitshl: $ => prec.left(400, seq($._expr, "<<", $._expr)),
        bitshr: $ => prec.left(400, seq($._expr, ">>", $._expr)),
        bitand: $ => prec.left(300, seq($._expr, "bit&", $._expr)),
        bitor: $ => prec.left(300, seq($._expr, "bit|", $._expr)),
        bitxor: $ => prec.left(300, seq($._expr, "bit^", $._expr)),

        add_eq:       $ => prec.left(100, seq($._expr, "+=", $._expr)),
        subtract_eq:  $ => prec.left(100, seq($._expr, "-=", $._expr)),
        multiply_eq:  $ => prec.left(100, seq($._expr, "*=", $._expr)),
        divide_eq:    $ => prec.left(100, seq($._expr, "/=", $._expr)),
        remainder_eq: $ => prec.left(100, seq($._expr, "%=", $._expr)),
        tilde_eq:     $ => prec.left(100, seq($._expr, "~=", $._expr)),
        ampersand_eq: $ => prec.left(100, seq($._expr, "&=", $._expr)),
        pipe_eq:      $ => prec.left(100, seq($._expr, "|=", $._expr)),
        caret_eq:     $ => prec.left(100, seq($._expr, "^=", $._expr)),
        lbrack_eq:    $ => prec.left(100, seq($._expr, "[=", $._expr)),
        // ================
        // BINARY OPERATORS END
        // ================

        // ================
        // CONTROL FLOW
        // ================
        cfor: $ => prec.right(seq(
            "cfor",
            field("init", $._expr_terminated),
            field("condition", $._expr_terminated),
            field("increment", $._expr_terminated),
            field("body", $._expr),
        )),

        rangedfor: $ => prec.right(seq(
            "for",
            $.identifier,
            "in",
            field("container", $._expr),
            $._soft_expression_separator,
            field("body", $._expr)
        )),

        if: $ => prec.right(seq(
            "if",
            field("condition", $._expr),
            $._soft_expression_separator,
            field("then", $._expr),
            optional(seq(
                "else",
                field("otherwise", $._expr),
            ))
        )),

        while: $ => prec.right(seq(
            "while",
            field("condition", $._expr),
            ",",
            field("then", $._expr)
        )),
        // ================
        // CONTROL FLOW END
        // ================

        apply: $ => prec.right(seq(
            "apply",
            field("function", $._expr),
            repeat(seq(
                $._soft_expression_separator,
                field("argument_list", $.paren)
            ))
        )),

        return: $ => prec.right(seq(
            "return",
            optional($._expr)
        )),

        member_access: $ => prec(1000000000, seq(
            $._expr,
            ".",
            $.identifier
        )),

        bool_literal: $ => choice(
            "true",
            "false",
        ),

        byte_literal: $ => seq(
            "`",
            choice(
                /\\./,
                /[^\\]/
            ),
            "`"
        ),

        integer_literal: $ => choice(
            $._number_dec,
            $._number_bin,
            $._number_hex,
            $._number_oct,
        ),

        fractional_literal: $ => $._fractional,

        string_literal: $ => choice(
            $._escapable_string,
            $._raw_string
        ),

        _escapable_string: $ => token(
            seq('"', repeat(choice(/[^"\\]/, seq("\\", /(.|\n)/))), '"')
        ),

        _raw_string: $ => token(
            seq("'", repeat(/[^']/), "'")
        ),

        storage_specifier: $ => choice(
            token("external"),
            token("export")
        ),

        _expression_separator: $ => choice(
            $._hard_expression_separator,
            $._soft_expression_separator
        ),
        _hard_expression_separator: $ => ";",
        _soft_expression_separator: $ => ",",

        identifier: $ => /[a-z\$_?][a-z0-9_!\$@\-\/&+?^|~]*/i,
        _fractional: $ => /[\d\']+\.[\d\']*/,
        _number_dec: $ => /[\d\']+/,
        _number_bin: $ => /0b[01\']+/,
        _number_hex: $ => /0x[0-9a-f\']+/i,
        _number_oct: $ => /0o?[0-7\']+/,
        comment: $ => /;;.*/
    }
});
