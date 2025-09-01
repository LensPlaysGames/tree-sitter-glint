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

    rules: {
        source_file: $ => seq(
            optional($.module_declaration),
            repeat($.module_import),
            repeat($._multi_expression),
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
            $.type_function,
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

        type_function: $ => prec.right(seq(
            $._type, // choice($._type, $.identifier),
            "(",
            repeat($.param_decl),
            ")"
        )),

        // Because _expression_nosep is right associative, we need to also use
        // precedence to beat it out here.
        param_decl: $ => prec(1, seq(
            optional(field("name", $.identifier)),
            ":", field("type", choice($._type, $.identifier)),
            optional($._soft_expression_separator)
        )),

        type_array: $ => prec.right(seq(
            "[",
            $._type,
            optional(choice(
                $._expression_nosep,
                "view"
            )),
            "]",
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
        _multi_expression: $ => prec.right(choice(
            $._expression,
            $.call,
        )),
        _expression: $ => prec.right(seq(
            choice(
                $._expression_nosep,
                $._type
            ),
            optional(repeat($._expression_separator))
        )),
        call: $ => prec.right(1,seq(
            $._expression_nosep,
            repeat1(prec.left($._expression_nosep)),
            $._expression_separator
        )),

        _expression_nosep: $ => prec.right(choice(
            $._binary_expression,
            $._paren_expression,
            $._unary_expression,
            $.assign,
            $.block,
            $.bool_literal,
            $.declaration,
            $.identifier,
            $.if,
            $.integer_literal,
            $.member_access,
            $.return,
            $.string_literal,
            $.subscript,
            $.while,
        )),

        _paren_expression: $ => seq(
            "(",
            $._multi_expression,
            ")"
        ),

        subscript: $ => seq(
            $._expression_nosep,
            "[",
            $._expression_nosep,
            "]"
        ),

        assign: $ => seq(
            $._expression_nosep,
            ":=",
            $._multi_expression
        ),

        _unary_expression: $ => prec.left(10000, choice(
            // $.addressof,
            // $.negate,
            $.decrement,
            $.dereference,
            $.increment,
            $.logical_negate,
        )),

        dereference: $ => seq("@", $._expression),
        addressof: $ => seq("&", $._expression),
        negate: $ => seq("-", $._expression),
        increment: $ => seq("++", $._expression),
        decrement: $ => seq("--", $._expression),
        logical_negate: $ => seq(choice("!", "not"), $._expression),

        declaration: $ => prec.right(seq(
            optional($.storage_specifier),
            choice(
                seq(
                    field("name", $.identifier),
                    ":", field("type", choice($._type, $.identifier)),
                    optional(
                        field("init", $._multi_expression)
                    )
                ),
                seq(
                    field("name", $.identifier),
                    "::",
                    field("init", $._multi_expression),
                ),
                seq(
                    "supplant",
                    field("type", choice($._type, $.identifier))
                )
            ))
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
            $.bitxor
        ),

        // note that + left or right precedence doesn't matter for these
        // operators, but we pick one to be unambiguous in the grammar.
        add:       $ => prec.left(500, seq($._expression_nosep, "+", $._expression_nosep)),
        subtract:  $ => prec.left(500, seq($._expression_nosep, "-", $._expression_nosep)),
        multiply:  $ => prec.left(600, seq($._expression_nosep, "*", $._expression_nosep)),
        divide:    $ => prec.left(600, seq($._expression_nosep, "/", $._expression_nosep)),
        remainder: $ => prec.left(600, seq($._expression_nosep, "%", $._expression_nosep)),

        eq: $ => prec.left(200, seq($._expression_nosep, "=", $._expression_nosep)),
        ne: $ => prec.left(200, seq($._expression_nosep, "!=", $._expression_nosep)),
        gt: $ => prec.left(200, seq($._expression_nosep, ">", $._expression_nosep)),
        ge: $ => prec.left(200, seq($._expression_nosep, ">=", $._expression_nosep)),
        lt: $ => prec.left(200, seq($._expression_nosep, "<", $._expression_nosep)),
        le: $ => prec.left(200, seq($._expression_nosep, "<=", $._expression_nosep)),

        and: $ => prec.left(150, seq($._expression_nosep, "and", $._expression_nosep)),
        or: $ => prec.left(145, seq($._expression_nosep, "or", $._expression_nosep)),

        bitshl: $ => prec.left(400, seq($._expression_nosep, "<<", $._expression_nosep)),
        bitshr: $ => prec.left(400, seq($._expression_nosep, ">>", $._expression_nosep)),
        bitand: $ => prec.left(300, seq($._expression_nosep, "&", $._expression_nosep)),
        bitor: $ => prec.left(300, seq($._expression_nosep, "|", $._expression_nosep)),
        bitxor: $ => prec.left(300, seq($._expression_nosep, "^", $._expression_nosep)),
        // ================
        // BINARY OPERATORS END
        // ================

        // ================
        // CONTROL FLOW
        // ================
        if: $ => prec.right(seq(
            "if",
            field("condition", $._expression),
            field("then", $._multi_expression),
            optional(seq(
                "else",
                field("else", $._multi_expression)
            ))
        )),

        while: $ => prec.right(seq(
            "while",
            field("condition", $._expression),
            field("then", $._multi_expression)
        )),
        // ================
        // CONTROL FLOW END
        // ================


        block: $ => seq(
            "{",
            repeat($._multi_expression),
            "}"
        ),

        return: $ => prec.right(seq(
            "return",
            choice($._multi_expression, $._expression_separator)
        )),

        member_access: $ => seq(
            $.identifier,
            ".",
            $.identifier
        ),

        bool_literal: $ => choice(
            "true",
            "false",
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

        identifier: $ => token(/[a-z][a-z0-9_]*/i),
        _number_dec: $ => token(/\d+/),
        _number_hex: $ => token(/0x[0-9a-f]+/i),
        _number_oct: $ => token(/0o?[0-7]+/),
        comment: $ => token(/;;.*/)
    }
});
