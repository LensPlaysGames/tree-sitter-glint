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
        $._type
    ],

    // This is solely due to the fact that an `else` clause may come after a
    // HARD expression separator of the then body; this means the first "if"
    // is technically parseable as a valid if with no else, but, if there does
    // happen to be an `else` keyword directly beyond that hard separator, the
    // if also wants to eat that. This forces tree-sitter to explore that
    // possibility with lookahead instead of always assuming one or the other
    // based on left/right precedence.
    conflicts: $ => [[$.if], [$.print], [$._single, $.call], [$._single, $._group]],

    rules: {
        source_file: $ => seq(
            optional($.module_declaration),
            repeat($.module_import),
            repeat($._multi_expression),
            // It is not a syntax error if trailing semi-colon is missing from a
            // Glint program, so we don't require a separator for the last expression.
            optional($._multi_expression_nosep)
        ),

        module_declaration: $ => seq(
            "module",
            field("name", $.identifier),
            optional($._expression_separator)
        ),

        module_import: $ => seq(
            "import",
            field("name", $.identifier),
            optional($._expression_separator)
        ),

        // ================
        // TYPES
        // ================
        _type: $ => choice(
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
            $.type_function
        ),

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

        type_function: $ => prec(10, seq(
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
            optional($._soft_expression_separator)
        )),

        type_array: $ => prec(10, seq(
            "[",
            $._type,
            optional(choice(
                $._multi_expression_nosep,
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

        // e1-nosep
        _multi_expression_nosep: $ => choice(
            $._single,
            $.call,
            $._group,
            $.print // a print gets parsed as a call unless we put it here.
        ),

        // e1
        _multi_expression: $ => seq(
            $._multi_expression_nosep,
            $._hard_expression_separator
        ),

        // prec.left(0, ...) or prec(1, ...) both work.
        _single: $ => prec.dynamic(1, seq(
            $._expression_nosep
        )),
        call: $ => prec.dynamic(1, seq(
            $._expression_nosep,
            $._multi_expression_nosep
        )),
        _group: $ => seq(
            $._expression_nosep,
            $._soft_expression_separator,
            $._multi_expression_nosep
        ),

        _expression_nosep: $ => choice(
            $._binary_expression,
            $._unary_expression,
            $._paren_expression,
            $.assign,
            $.block,
            $.bool_literal,
            $.byte_literal,
            $.declaration,
            $.identifier,
            $.if,
            $.integer_literal,
            $.member_access,
            $.return,
            $.string_literal,
            $.subscript,
            $._type,
            $.while,
            $.match,
            $.cfor,
            $.rangedfor,
        ),

        _paren_expression: $ => seq(
            "(",
            $._multi_expression_nosep,
            ")"
        ),

        // precedence to win out over block parsing
        match: $ => prec(1, seq(
            "match",
            field("object", $._multi_expression_nosep),
            "{",
            repeat(seq(
                ".",
                $.identifier,
                optional(":"),
                $._multi_expression_nosep,
                optional($._expression_separator)
            )),
            "}"
        )),

        print: $ => seq(
            "print",
            optional($._multi_expression_nosep)
        ),

        subscript: $ => prec(1, seq(
            $._multi_expression_nosep,
            "[",
            $._multi_expression_nosep,
            "]"
        )),

        assign: $ => prec.right(1, seq(
            $._expression_nosep,
            ":=",
            $._multi_expression_nosep
        )),

        _unary_expression: $ => choice(
            $.addressof,
            $.negate,
            $.decrement,
            $.dereference,
            $.increment,
            $.logical_negate,
        ),

        dereference: $ => prec.right(seq("@", $._multi_expression_nosep)),
        addressof: $ => prec.right(seq("&", $._multi_expression_nosep)),
        negate: $ => prec.right(seq("-", $._multi_expression_nosep)),
        increment: $ => prec.right(seq("++", $._multi_expression_nosep)),
        decrement: $ => prec.right(seq("--", $._multi_expression_nosep)),
        logical_negate: $ => prec.right(seq(choice("!", "not"), $._multi_expression_nosep)),

        declaration: $ => seq(
            optional($.storage_specifier),
            choice(
                $._declaration_init,
                $._declaration_inferred,
                $._declaration_supplanted
            )
        ),

        _declaration_init: $ => prec.right(seq(
            field("name", $.identifier),
            ":", field("type", choice($._type, $.identifier)),
            optional(
                field("init", $._multi_expression_nosep)
            )
        )),

        _declaration_inferred: $ => seq(
            field("name", $.identifier),
            "::",
            field("init", $._multi_expression_nosep),
        ),

        _declaration_supplanted: $ => seq(
            "supplant",
            field("type", choice($._type, $.identifier))
        ),

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
        add:       $ => prec.left(500, seq($._multi_expression_nosep, "+", $._multi_expression_nosep)),
        subtract:  $ => prec.left(500, seq($._multi_expression_nosep, "-", $._multi_expression_nosep)),
        multiply:  $ => prec.left(600, seq($._multi_expression_nosep, "*", $._multi_expression_nosep)),
        divide:    $ => prec.left(600, seq($._multi_expression_nosep, "/", $._multi_expression_nosep)),
        remainder: $ => prec.left(600, seq($._multi_expression_nosep, "%", $._multi_expression_nosep)),

        eq: $ => prec.left(200, seq($._multi_expression_nosep, "=", $._multi_expression_nosep)),
        ne: $ => prec.left(200, seq($._multi_expression_nosep, "!=", $._multi_expression_nosep)),
        gt: $ => prec.left(200, seq($._multi_expression_nosep, ">", $._multi_expression_nosep)),
        ge: $ => prec.left(200, seq($._multi_expression_nosep, ">=", $._multi_expression_nosep)),
        lt: $ => prec.left(200, seq($._multi_expression_nosep, "<", $._multi_expression_nosep)),
        le: $ => prec.left(200, seq($._multi_expression_nosep, "<=", $._multi_expression_nosep)),

        and: $ => prec.left(150, seq($._multi_expression_nosep, "and", $._multi_expression_nosep)),
        or: $ => prec.left(145, seq($._multi_expression_nosep, "or", $._multi_expression_nosep)),

        bitshl: $ => prec.left(400, seq($._multi_expression_nosep, "<<", $._multi_expression_nosep)),
        bitshr: $ => prec.left(400, seq($._multi_expression_nosep, ">>", $._multi_expression_nosep)),
        bitand: $ => prec.left(300, seq($._multi_expression_nosep, "&", $._multi_expression_nosep)),
        bitor: $ => prec.left(300, seq($._multi_expression_nosep, "|", $._multi_expression_nosep)),
        bitxor: $ => prec.left(300, seq($._multi_expression_nosep, "^", $._multi_expression_nosep)),

        add_eq:       $ => prec.left(100, seq($._multi_expression_nosep, "+=", $._multi_expression_nosep)),
        subtract_eq:  $ => prec.left(100, seq($._multi_expression_nosep, "-=", $._multi_expression_nosep)),
        multiply_eq:  $ => prec.left(100, seq($._multi_expression_nosep, "*=", $._multi_expression_nosep)),
        divide_eq:    $ => prec.left(100, seq($._multi_expression_nosep, "/=", $._multi_expression_nosep)),
        remainder_eq: $ => prec.left(100, seq($._multi_expression_nosep, "%=", $._multi_expression_nosep)),
        tilde_eq:     $ => prec.left(100, seq($._multi_expression_nosep, "~=", $._multi_expression_nosep)),
        ampersand_eq: $ => prec.left(100, seq($._multi_expression_nosep, "&=", $._multi_expression_nosep)),
        pipe_eq:      $ => prec.left(100, seq($._multi_expression_nosep, "|=", $._multi_expression_nosep)),
        caret_eq:     $ => prec.left(100, seq($._multi_expression_nosep, "^=", $._multi_expression_nosep)),
        lbrack_eq:    $ => prec.left(100, seq($._multi_expression_nosep, "[=", $._multi_expression_nosep)),
        // ================
        // BINARY OPERATORS END
        // ================

        // ================
        // CONTROL FLOW
        // ================
        cfor: $ => prec.right(seq(
            "cfor",
            field("init", $._multi_expression),
            field("condition", $._multi_expression),
            field("increment", $._multi_expression),
            field("body", $._multi_expression_nosep),
        )),

        rangedfor: $ => prec.right(seq(
            "for",
            $.identifier,
            "in",
            field("container", $._multi_expression_nosep),
            optional($._soft_expression_separator),
            field("body", $._multi_expression_nosep)
        )),

        // TODO: doesn't handle separator between then expression and else
        // keyword, but it should. I don't know how to get it to handle that
        // without completely breaking everything, and I don't know why it doesn't
        // already work.
        if: $ => seq(
            "if",
            field("condition", $._multi_expression_nosep),
            optional($._soft_expression_separator),
            field("then", $._multi_expression_nosep),
            optional($._else)
        ),

        _else: $ => seq(
            optional($._expression_separator),
            "else",
            field("else", $._multi_expression_nosep)
        ),

        while: $ => prec.right(seq(
            "while",
            field("condition", $._multi_expression_nosep),
            optional($._soft_expression_separator),
            field("then", $._multi_expression_nosep)
        )),
        // ================
        // CONTROL FLOW END
        // ================


        block: $ => seq(
            "{",
            repeat($._multi_expression),
            optional($._multi_expression_nosep),
            optional($._soft_expression_separator),
            "}"
        ),

        return: $ => prec.right(seq(
            "return",
            optional($._multi_expression_nosep)
        )),

        member_access: $ => prec(10, seq(
            $.identifier,
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
            "external",
            "export"
        ),

        _expression_separator: $ => choice(
            $._hard_expression_separator,
            $._soft_expression_separator
        ),
        _hard_expression_separator: $ => token(";"),
        _soft_expression_separator: $ => token(","),

        identifier: $ => token(/[a-z\$_][a-z0-9_!\$@]*/i),
        _number_dec: $ => token(/\d+/),
        _number_hex: $ => token(/0x[0-9a-f]+/i),
        _number_oct: $ => token(/0o?[0-7]+/),
        comment: $ => token(/;;.*/)
    }
});
