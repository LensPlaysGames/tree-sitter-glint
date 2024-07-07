module.exports = grammar({
    name: "glint",

    word: $ => $.identifier,

    extras: $ => [/(\s|\f)/, $.comment],

    rules: {
        source_file: $ => seq(
            optional($.module_declaration),
            repeat($._expr)
        ),

        module_declaration: $ => seq(
            "module",
            field("name", $.identifier),
            $._expression_separator
        ),

        _expr: $ => seq(
            $._expression,
            $._expression_separator
        ),

        _expr_soft: $ => prec.left(seq(
            $._expression,
            optional($._soft_expression_separator)
        )),

        _expression: $ => prec(0, choice(
            $._expression_declaration,
            $._expression_paren,
            $.expression_call,
            $._expression_type,
            $.identifier,
            $.number_literal
        )),

        _expression_paren: $ => seq(
            "(",
            $._expression,
            ")"
        ),

        expression_call: $ => choice(
            $._expression_call0,
            $._expression_call1
        ),

        _expression_call0: $ => prec(2, seq(
            $._expression,
            repeat1($._expr_soft)
        )),

        _expression_call1: $ => prec(2, seq(
            $._expression,
            "(",
            $._expr_soft,
            ")"
        )),

        _expression_declaration: $ => choice(
            $.declaration,
            $.declaration_type_inferred
        ),

        // Precedence to "beat" type expression
        declaration: $ => prec(2, seq(
            optional($.storage_specifier),
            field("name", $.identifier),
            ":",
            field("type", $._type)
        )),

        declaration_type_inferred: $ => seq(
            field("name", $.identifier),
            "::",
            field("init", $._expression)
        ),

        _expression_type: $ => choice(
            $._expression_type0,
            $._expression_type1
        ),

        _expression_type0: $ => seq(
            ":",
            $._type
        ),

        // Everything but type_function, basically, otherwise calls would be
        // ambiguous.
        _expression_type1: $ => choice(
            $._type_array,
            $.type_ffi,
            $.type_pointer,
            $.type_primitive,
            $.type_reference,
            $.type_struct
        ),

        _type: $ => prec(1, choice(
            $._type_array,
            $.type_ffi,
            $.type_function,
            $.type_pointer,
            $.type_primitive,
            $.type_reference,
            $.type_struct
        )),

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
            $._expression_type,
            optional($._expression),
            "]"
        ),

        type_fixed_array: $ => prec(1, seq(
            "[",
            $._expression_type,
            $.number_literal,
            "]"
        )),

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

        // Precedence to make T() not T followed by paren expression but a
        // function type.
        type_function: $ => prec(1, seq(
            $._type,
            "(",
            repeat(
                seq(
                    choice(
                        $.declaration,      // x : int
                        $._expression_type0 // :int
                    ),
                    optional($._soft_expression_separator)
                )
            ),
            ")"
        )),

        number_literal: $ => choice(
            $._number_dec,
            $._number_hex,
            $._number_oct,
        ),

        _expression_separator: $ => choice(
            $._hard_expression_separator,
            $._soft_expression_separator
        ),

        storage_specifier: $ => choice(
            "external",
            "export"
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
