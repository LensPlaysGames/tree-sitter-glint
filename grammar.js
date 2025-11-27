/**
 * @file The tree sitter parser declaration for the Glint programming language (part of the Lensor Compiler Collection)
 * @author Lens_r
 * @license 2025 All rights reserved
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
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
            "import",
            field("name", $.identifier),
            optional($._expression_separator)
        )),

        // ================
        // TYPES
        // ================
        _type: $ => prec(5, choice(
            $.type_array,
            $.type_enum,
            $.type_ffi,
            $.type_pointer,
            $.type_pointer_to_pointer,
            $.type_primitive,
            $.type_reference,
            $.type_struct,
            $.type_sum,
            $.type_union,
            $.type_function,
            $.identifier
        )),

        type_enum: $ => seq(
            "enum",
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
            "void"
        ),

        type_ffi: $ => choice(
            "cshort", "cushort",
            "cint", "cuint",
            "clong", "culong",
            "clonglong", "culonglong",
            "csize", "cusize"
        ),

        type_function: $ => prec(5, seq(
            $._type,
            "(",
            repeat($.param_decl),
            ")"
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

        // Possibly Terminated Expression List
        _PTEL: $ => repeat1(prec.right(seq($._expr, optional($._expression_separator)))),

        _expr_terminated: $ => seq($._expr, $._hard_expression_separator),

        _expr: $ => prec(5, choice($._unary_binary, $._expr_except_unary_binary)),

        _expr_except_unary_binary: $ => choice(
            $._binary,
            $._type,
            $._unary_notbinary,
            $.block,
            $.bool_literal,
            $.byte_literal,
            $.call,
            $.cfor,
            $.identifier,
            $.if,
            $.integer_literal,
            $.mapf,
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

        _expr_except_call: $ => prec(1, choice(
            $._binary,
            $._type,
            $._unary_binary,
            $._unary_notbinary,
            $.block,
            $.bool_literal,
            $.byte_literal,
            $.cfor,
            $.identifier,
            $.if,
            $.integer_literal,
            $.mapf,
            $.match,
            $.member_access,
            $.paren,
            $.rangedfor,
            $.return,
            $.string_literal,
            $.type_expr,
            $.while,
        )),

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

        subscript: $ => prec(10010, seq($._expr_except_call, "[", $._expr, "]")),

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

        // if types are expressions with no prefix, array types beginning with "[" token should go here.
        _unary_binary: $ => choice($.negate, $.addressof),
        _unary_notbinary: $ => choice($.dereference, $.increment, $.decrement, $.logical_negate),

        dereference: $ => seq("@", prec.right(10000, $._expr)),
        addressof: $ => seq("&", prec.right(10000, $._expr)),
        negate: $ => seq("-", prec.right(10000, $._expr)),
        increment: $ => seq("++", prec.right(10000, $._expr)),
        decrement: $ => seq("--", prec.right(10000, $._expr)),
        logical_negate: $ => seq(choice("!", "not"), prec.right(10000, $._expr)),

        // Use paren to "escape" back to a grammar that accepts a unary expression as an argument
        // call_repeat1 precedence to ensure that, if a call does apply, it is a
        // call, and not just two expressions back-to-back.
        call: $ => choice($._forced_call, $._multi_call),
        _forced_call: $ => prec(1, seq($._expr, "(", ")")),
        _multi_call: $ => prec.right(seq(
            $._expr,
            $._expr_except_unary_binary,
            repeat(seq($._soft_expression_separator, $._call_arg))
        )),

        // Can syntactically represent as a regular call, but, we include this for
        // extra information purposes.
        print: $ => prec.right(seq(
            "print",
            optional(seq(
                $._expr_except_unary_binary,
                repeat(seq($._soft_expression_separator, $._call_arg))
            ))
        )),

        _call_arg: $ => prec(90, $._expr_except_unary_binary),

        // A paren expression does not open up a new scope.
        paren: $ => seq("(", optional($._PTEL), ")"),
        // A block expression 's contained expressions are parsed within a new scope.
        block: $ => seq("{", optional($._PTEL), "}"),

        match: $ => prec(1, seq(
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
        add:       $ => prec.left(500, seq($._expr_except_call, "+", $._expr_except_call)),
        subtract:  $ => prec.left(500, seq($._expr_except_call, "-", $._expr_except_call)),
        multiply:  $ => prec.left(600, seq($._expr_except_call, "*", $._expr_except_call)),
        divide:    $ => prec.left(600, seq($._expr_except_call, "/", $._expr_except_call)),
        remainder: $ => prec.left(600, seq($._expr_except_call, "%", $._expr_except_call)),

        eq: $ => prec.left(200, seq($._expr_except_call, "=", $._expr_except_call)),
        ne: $ => prec.left(200, seq($._expr_except_call, "!=", $._expr_except_call)),
        gt: $ => prec.left(200, seq($._expr_except_call, ">", $._expr_except_call)),
        ge: $ => prec.left(200, seq($._expr_except_call, ">=", $._expr_except_call)),
        lt: $ => prec.left(200, seq($._expr_except_call, "<", $._expr_except_call)),
        le: $ => prec.left(200, seq($._expr_except_call, "<=", $._expr_except_call)),

        and: $ => prec.left(150, seq($._expr_except_call, "and", $._expr_except_call)),
        or: $ => prec.left(145, seq($._expr_except_call, "or", $._expr_except_call)),

        bitshl: $ => prec.left(400, seq($._expr_except_call, "<<", $._expr_except_call)),
        bitshr: $ => prec.left(400, seq($._expr_except_call, ">>", $._expr_except_call)),
        bitand: $ => prec.left(300, seq($._expr_except_call, "bitand", $._expr_except_call)),
        bitor: $ => prec.left(300, seq($._expr_except_call, "bitor", $._expr_except_call)),
        bitxor: $ => prec.left(300, seq($._expr_except_call, "bitxor", $._expr_except_call)),

        add_eq:       $ => prec.left(100, seq($._expr_except_call, "+=", $._expr_except_call)),
        subtract_eq:  $ => prec.left(100, seq($._expr_except_call, "-=", $._expr_except_call)),
        multiply_eq:  $ => prec.left(100, seq($._expr_except_call, "*=", $._expr_except_call)),
        divide_eq:    $ => prec.left(100, seq($._expr_except_call, "/=", $._expr_except_call)),
        remainder_eq: $ => prec.left(100, seq($._expr_except_call, "%=", $._expr_except_call)),
        tilde_eq:     $ => prec.left(100, seq($._expr_except_call, "~=", $._expr_except_call)),
        ampersand_eq: $ => prec.left(100, seq($._expr_except_call, "&=", $._expr_except_call)),
        pipe_eq:      $ => prec.left(100, seq($._expr_except_call, "|=", $._expr_except_call)),
        caret_eq:     $ => prec.left(100, seq($._expr_except_call, "^=", $._expr_except_call)),
        lbrack_eq:    $ => prec.left(100, seq($._expr_except_call, "[=", $._expr_except_call)),
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

        mapf: $ => prec.right(seq(
            "mapf",
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
            $._expr_except_call,
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
            $._number_hex,
            $._number_oct,
        ),

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

        identifier: $ => /[a-z\$_][a-z0-9_!\$@]*/i,
        _number_dec: $ => /\d+/,
        _number_hex: $ => /0x[0-9a-f]+/i,
        _number_oct: $ => /0o?[0-7]+/,
        comment: $ => /;;.*/
    }
});
