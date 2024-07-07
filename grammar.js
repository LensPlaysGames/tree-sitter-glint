module.exports = grammar({
    name: "glint",

    word: $ => $.identifier,

    extras: $ => [/(\s|\f)/, $.comment],

    rules: {
        source_file: $ => repeat($._expr),

        _expr: $ => seq(
            $._expression,
            $._expression_separator
        ),

        _expr_soft: $ => seq(
            $._expression,
            $._soft_expression_separator
        ),

        _expression: $ => choice(
            $._expression_declaration,
            $._expression_call,
            $.identifier,
            $._type
        ),

        _expression_call: $ => seq(
            $.identifier,
            repeat1($._expr_soft),
            $._hard_expression_separator
        ),

        _expression_declaration: $ => choice(
            $.declaration,
            $.declaration_type_inferred
        ),

        declaration: $ => seq(
            field("name", $.identifier),
            ":",
            field("type", $._type)
        ),

        declaration_type_inferred: $ => seq(
            field("name", $.identifier),
            "::",
            field("init", $._expression)
        ),

        _type: $ => choice(
            $._type_array,
            $.type_ffi,
            $.type_pointer,
            $.type_primitive,
            $.type_reference,
            $.type_struct
        ),

        type_primitive: $ => choice(
            choice("bool", "boolean", "Bool", "Boolean"),
            "int",
            "uint",
            "void"
        ),

        type_pointer: $ => seq(
            $._type,
            ".ptr"
        ),

        type_reference: $ => seq(
            $._type,
            ".ref"
        ),

        _type_array: $ => choice(
            $.type_dynamic_array,
            $.type_fixed_array
        ),

        type_dynamic_array: $ => seq(
            "[",
            $._type,
            optional($._expression),
            "]"
        ),

        type_fixed_array: $ => seq(
            "[",
            $._type,
            $.number_literal,
            "]"
        ),

        type_ffi: $ => choice(
            "cshort",
            "cushort",
            "cint",
            "cuint",
            "clong",
            "culong",
            "clonglong",
            "culonglong"
        ),

        type_struct: $ => seq(
            "struct",
            $.identifier,
            "{",
            repeat($._expr),
            "}"
        ),

        number_literal: $ => choice(
            $._number_dec,
            $._number_hex,
            $._number_oct,
        ),

        _expression_separator: $ => choice(
            $._hard_expression_separator,
            $._soft_expression_separator
        ),

        _hard_expression_separator: $ => token(";"),
        _soft_expression_separator: $ => token(","),
        identifier: $ => token(/[a-z][a-z0-9]*/i),
        _number_dec: $ => token(/\d+/),
        _number_hex: $ => token(/0x[0-9a-f]+/i),
        _number_oct: $ => token(/0[0-7]+/),
        comment: $ => token(/;;.*/)
    }
});
