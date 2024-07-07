#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 36
#define LARGE_STATE_COUNT 22
#define SYMBOL_COUNT 53
#define ALIAS_COUNT 0
#define TOKEN_COUNT 32
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 3

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_COLON = 2,
  anon_sym_COLON_COLON = 3,
  anon_sym_bool = 4,
  anon_sym_boolean = 5,
  anon_sym_Bool = 6,
  anon_sym_Boolean = 7,
  anon_sym_int = 8,
  anon_sym_uint = 9,
  anon_sym_void = 10,
  anon_sym_DOTptr = 11,
  anon_sym_DOTref = 12,
  anon_sym_LBRACK = 13,
  anon_sym_RBRACK = 14,
  anon_sym_cshort = 15,
  anon_sym_cushort = 16,
  anon_sym_cint = 17,
  anon_sym_cuint = 18,
  anon_sym_clong = 19,
  anon_sym_culong = 20,
  anon_sym_clonglong = 21,
  anon_sym_culonglong = 22,
  anon_sym_struct = 23,
  anon_sym_LBRACE = 24,
  anon_sym_RBRACE = 25,
  sym__hard_expression_separator = 26,
  sym__soft_expression_separator = 27,
  sym__number_dec = 28,
  sym__number_hex = 29,
  sym__number_oct = 30,
  sym_comment = 31,
  sym_source_file = 32,
  sym__expr = 33,
  sym__expr_soft = 34,
  sym__expression = 35,
  sym__expression_call = 36,
  sym__expression_declaration = 37,
  sym_declaration = 38,
  sym_declaration_type_inferred = 39,
  sym__type = 40,
  sym_type_primitive = 41,
  sym_type_pointer = 42,
  sym_type_reference = 43,
  sym__type_array = 44,
  sym_type_dynamic_array = 45,
  sym_type_fixed_array = 46,
  sym_type_ffi = 47,
  sym_type_struct = 48,
  sym_number_literal = 49,
  sym__expression_separator = 50,
  aux_sym_source_file_repeat1 = 51,
  aux_sym__expression_call_repeat1 = 52,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_COLON] = ":",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_bool] = "bool",
  [anon_sym_boolean] = "boolean",
  [anon_sym_Bool] = "Bool",
  [anon_sym_Boolean] = "Boolean",
  [anon_sym_int] = "int",
  [anon_sym_uint] = "uint",
  [anon_sym_void] = "void",
  [anon_sym_DOTptr] = ".ptr",
  [anon_sym_DOTref] = ".ref",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_cshort] = "cshort",
  [anon_sym_cushort] = "cushort",
  [anon_sym_cint] = "cint",
  [anon_sym_cuint] = "cuint",
  [anon_sym_clong] = "clong",
  [anon_sym_culong] = "culong",
  [anon_sym_clonglong] = "clonglong",
  [anon_sym_culonglong] = "culonglong",
  [anon_sym_struct] = "struct",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym__hard_expression_separator] = "_hard_expression_separator",
  [sym__soft_expression_separator] = "_soft_expression_separator",
  [sym__number_dec] = "_number_dec",
  [sym__number_hex] = "_number_hex",
  [sym__number_oct] = "_number_oct",
  [sym_comment] = "comment",
  [sym_source_file] = "source_file",
  [sym__expr] = "_expr",
  [sym__expr_soft] = "_expr_soft",
  [sym__expression] = "_expression",
  [sym__expression_call] = "_expression_call",
  [sym__expression_declaration] = "_expression_declaration",
  [sym_declaration] = "declaration",
  [sym_declaration_type_inferred] = "declaration_type_inferred",
  [sym__type] = "_type",
  [sym_type_primitive] = "type_primitive",
  [sym_type_pointer] = "type_pointer",
  [sym_type_reference] = "type_reference",
  [sym__type_array] = "_type_array",
  [sym_type_dynamic_array] = "type_dynamic_array",
  [sym_type_fixed_array] = "type_fixed_array",
  [sym_type_ffi] = "type_ffi",
  [sym_type_struct] = "type_struct",
  [sym_number_literal] = "number_literal",
  [sym__expression_separator] = "_expression_separator",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym__expression_call_repeat1] = "_expression_call_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_boolean] = anon_sym_boolean,
  [anon_sym_Bool] = anon_sym_Bool,
  [anon_sym_Boolean] = anon_sym_Boolean,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_uint] = anon_sym_uint,
  [anon_sym_void] = anon_sym_void,
  [anon_sym_DOTptr] = anon_sym_DOTptr,
  [anon_sym_DOTref] = anon_sym_DOTref,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_cshort] = anon_sym_cshort,
  [anon_sym_cushort] = anon_sym_cushort,
  [anon_sym_cint] = anon_sym_cint,
  [anon_sym_cuint] = anon_sym_cuint,
  [anon_sym_clong] = anon_sym_clong,
  [anon_sym_culong] = anon_sym_culong,
  [anon_sym_clonglong] = anon_sym_clonglong,
  [anon_sym_culonglong] = anon_sym_culonglong,
  [anon_sym_struct] = anon_sym_struct,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym__hard_expression_separator] = sym__hard_expression_separator,
  [sym__soft_expression_separator] = sym__soft_expression_separator,
  [sym__number_dec] = sym__number_dec,
  [sym__number_hex] = sym__number_hex,
  [sym__number_oct] = sym__number_oct,
  [sym_comment] = sym_comment,
  [sym_source_file] = sym_source_file,
  [sym__expr] = sym__expr,
  [sym__expr_soft] = sym__expr_soft,
  [sym__expression] = sym__expression,
  [sym__expression_call] = sym__expression_call,
  [sym__expression_declaration] = sym__expression_declaration,
  [sym_declaration] = sym_declaration,
  [sym_declaration_type_inferred] = sym_declaration_type_inferred,
  [sym__type] = sym__type,
  [sym_type_primitive] = sym_type_primitive,
  [sym_type_pointer] = sym_type_pointer,
  [sym_type_reference] = sym_type_reference,
  [sym__type_array] = sym__type_array,
  [sym_type_dynamic_array] = sym_type_dynamic_array,
  [sym_type_fixed_array] = sym_type_fixed_array,
  [sym_type_ffi] = sym_type_ffi,
  [sym_type_struct] = sym_type_struct,
  [sym_number_literal] = sym_number_literal,
  [sym__expression_separator] = sym__expression_separator,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym__expression_call_repeat1] = aux_sym__expression_call_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_boolean] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Boolean] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_void] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOTptr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOTref] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cshort] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cushort] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cint] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cuint] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_clong] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_culong] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_clonglong] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_culonglong] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_struct] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym__hard_expression_separator] = {
    .visible = false,
    .named = true,
  },
  [sym__soft_expression_separator] = {
    .visible = false,
    .named = true,
  },
  [sym__number_dec] = {
    .visible = false,
    .named = true,
  },
  [sym__number_hex] = {
    .visible = false,
    .named = true,
  },
  [sym__number_oct] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__expr] = {
    .visible = false,
    .named = true,
  },
  [sym__expr_soft] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym__expression_call] = {
    .visible = false,
    .named = true,
  },
  [sym__expression_declaration] = {
    .visible = false,
    .named = true,
  },
  [sym_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_declaration_type_inferred] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym_type_primitive] = {
    .visible = true,
    .named = true,
  },
  [sym_type_pointer] = {
    .visible = true,
    .named = true,
  },
  [sym_type_reference] = {
    .visible = true,
    .named = true,
  },
  [sym__type_array] = {
    .visible = false,
    .named = true,
  },
  [sym_type_dynamic_array] = {
    .visible = true,
    .named = true,
  },
  [sym_type_fixed_array] = {
    .visible = true,
    .named = true,
  },
  [sym_type_ffi] = {
    .visible = true,
    .named = true,
  },
  [sym_type_struct] = {
    .visible = true,
    .named = true,
  },
  [sym_number_literal] = {
    .visible = true,
    .named = true,
  },
  [sym__expression_separator] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__expression_call_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_init = 1,
  field_name = 2,
  field_type = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_init] = "init",
  [field_name] = "name",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 0},
    {field_type, 2},
  [2] =
    {field_init, 2},
    {field_name, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(7);
      ADVANCE_MAP(
        ',', 17,
        '.', 3,
        '0', 19,
        ':', 8,
        ';', 16,
        '[', 12,
        ']', 13,
        '{', 14,
        '}', 15,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(21);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 1:
      if (lookahead == 'e') ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == 'f') ADVANCE(11);
      END_STATE();
    case 3:
      if (lookahead == 'p') ADVANCE(5);
      if (lookahead == 'r') ADVANCE(1);
      END_STATE();
    case 4:
      if (lookahead == 'r') ADVANCE(10);
      END_STATE();
    case 5:
      if (lookahead == 't') ADVANCE(4);
      END_STATE();
    case 6:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(9);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_DOTptr);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_DOTref);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym__hard_expression_separator);
      if (lookahead == ';') ADVANCE(23);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym__soft_expression_separator);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym__number_dec);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(6);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(20);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym__number_dec);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym__number_dec);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym__number_hex);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(23);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'B') ADVANCE(1);
      if (lookahead == 'b') ADVANCE(2);
      if (lookahead == 'c') ADVANCE(3);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 's') ADVANCE(5);
      if (lookahead == 'u') ADVANCE(6);
      if (lookahead == 'v') ADVANCE(7);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(8);
      END_STATE();
    case 2:
      if (lookahead == 'o') ADVANCE(9);
      END_STATE();
    case 3:
      if (lookahead == 'i') ADVANCE(10);
      if (lookahead == 'l') ADVANCE(11);
      if (lookahead == 's') ADVANCE(12);
      if (lookahead == 'u') ADVANCE(13);
      END_STATE();
    case 4:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 5:
      if (lookahead == 't') ADVANCE(15);
      END_STATE();
    case 6:
      if (lookahead == 'i') ADVANCE(16);
      END_STATE();
    case 7:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 8:
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 9:
      if (lookahead == 'o') ADVANCE(19);
      END_STATE();
    case 10:
      if (lookahead == 'n') ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == 'o') ADVANCE(21);
      END_STATE();
    case 12:
      if (lookahead == 'h') ADVANCE(22);
      END_STATE();
    case 13:
      if (lookahead == 'i') ADVANCE(23);
      if (lookahead == 'l') ADVANCE(24);
      if (lookahead == 's') ADVANCE(25);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 15:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 16:
      if (lookahead == 'n') ADVANCE(28);
      END_STATE();
    case 17:
      if (lookahead == 'i') ADVANCE(29);
      END_STATE();
    case 18:
      if (lookahead == 'l') ADVANCE(30);
      END_STATE();
    case 19:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 20:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 21:
      if (lookahead == 'n') ADVANCE(33);
      END_STATE();
    case 22:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 23:
      if (lookahead == 'n') ADVANCE(35);
      END_STATE();
    case 24:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 25:
      if (lookahead == 'h') ADVANCE(37);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 27:
      if (lookahead == 'u') ADVANCE(38);
      END_STATE();
    case 28:
      if (lookahead == 't') ADVANCE(39);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(40);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_Bool);
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_bool);
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_cint);
      END_STATE();
    case 33:
      if (lookahead == 'g') ADVANCE(43);
      END_STATE();
    case 34:
      if (lookahead == 'r') ADVANCE(44);
      END_STATE();
    case 35:
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(46);
      END_STATE();
    case 37:
      if (lookahead == 'o') ADVANCE(47);
      END_STATE();
    case 38:
      if (lookahead == 'c') ADVANCE(48);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_uint);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_void);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(49);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(50);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_clong);
      if (lookahead == 'l') ADVANCE(51);
      END_STATE();
    case 44:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_cuint);
      END_STATE();
    case 46:
      if (lookahead == 'g') ADVANCE(53);
      END_STATE();
    case 47:
      if (lookahead == 'r') ADVANCE(54);
      END_STATE();
    case 48:
      if (lookahead == 't') ADVANCE(55);
      END_STATE();
    case 49:
      if (lookahead == 'n') ADVANCE(56);
      END_STATE();
    case 50:
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 51:
      if (lookahead == 'o') ADVANCE(58);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_cshort);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_culong);
      if (lookahead == 'l') ADVANCE(59);
      END_STATE();
    case 54:
      if (lookahead == 't') ADVANCE(60);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_Boolean);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 58:
      if (lookahead == 'n') ADVANCE(61);
      END_STATE();
    case 59:
      if (lookahead == 'o') ADVANCE(62);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_cushort);
      END_STATE();
    case 61:
      if (lookahead == 'g') ADVANCE(63);
      END_STATE();
    case 62:
      if (lookahead == 'n') ADVANCE(64);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_clonglong);
      END_STATE();
    case 64:
      if (lookahead == 'g') ADVANCE(65);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_culonglong);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_boolean] = ACTIONS(1),
    [anon_sym_Bool] = ACTIONS(1),
    [anon_sym_Boolean] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_uint] = ACTIONS(1),
    [anon_sym_void] = ACTIONS(1),
    [anon_sym_DOTptr] = ACTIONS(1),
    [anon_sym_DOTref] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_cshort] = ACTIONS(1),
    [anon_sym_cushort] = ACTIONS(1),
    [anon_sym_cint] = ACTIONS(1),
    [anon_sym_cuint] = ACTIONS(1),
    [anon_sym_clong] = ACTIONS(1),
    [anon_sym_culong] = ACTIONS(1),
    [anon_sym_clonglong] = ACTIONS(1),
    [anon_sym_culonglong] = ACTIONS(1),
    [anon_sym_struct] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym__hard_expression_separator] = ACTIONS(1),
    [sym__soft_expression_separator] = ACTIONS(1),
    [sym__number_dec] = ACTIONS(1),
    [sym__number_hex] = ACTIONS(1),
    [sym__number_oct] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(35),
    [sym__expr] = STATE(9),
    [sym__expression] = STATE(28),
    [sym__expression_call] = STATE(28),
    [sym__expression_declaration] = STATE(28),
    [sym_declaration] = STATE(28),
    [sym_declaration_type_inferred] = STATE(28),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [aux_sym_source_file_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(9),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(9),
    [anon_sym_int] = ACTIONS(9),
    [anon_sym_uint] = ACTIONS(9),
    [anon_sym_void] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_cshort] = ACTIONS(13),
    [anon_sym_cushort] = ACTIONS(13),
    [anon_sym_cint] = ACTIONS(13),
    [anon_sym_cuint] = ACTIONS(13),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(13),
    [anon_sym_culonglong] = ACTIONS(13),
    [anon_sym_struct] = ACTIONS(15),
    [sym_comment] = ACTIONS(3),
  },
  [2] = {
    [sym__expression] = STATE(30),
    [sym__expression_call] = STATE(30),
    [sym__expression_declaration] = STATE(30),
    [sym_declaration] = STATE(30),
    [sym_declaration_type_inferred] = STATE(30),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [sym_number_literal] = STATE(31),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(9),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(9),
    [anon_sym_int] = ACTIONS(9),
    [anon_sym_uint] = ACTIONS(9),
    [anon_sym_void] = ACTIONS(9),
    [anon_sym_DOTptr] = ACTIONS(17),
    [anon_sym_DOTref] = ACTIONS(19),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_RBRACK] = ACTIONS(21),
    [anon_sym_cshort] = ACTIONS(13),
    [anon_sym_cushort] = ACTIONS(13),
    [anon_sym_cint] = ACTIONS(13),
    [anon_sym_cuint] = ACTIONS(13),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(13),
    [anon_sym_culonglong] = ACTIONS(13),
    [anon_sym_struct] = ACTIONS(15),
    [sym__number_dec] = ACTIONS(23),
    [sym__number_hex] = ACTIONS(25),
    [sym__number_oct] = ACTIONS(23),
    [sym_comment] = ACTIONS(3),
  },
  [3] = {
    [sym__expr_soft] = STATE(6),
    [sym__expression] = STATE(33),
    [sym__expression_call] = STATE(33),
    [sym__expression_declaration] = STATE(33),
    [sym_declaration] = STATE(33),
    [sym_declaration_type_inferred] = STATE(33),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [aux_sym__expression_call_repeat1] = STATE(6),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_COLON] = ACTIONS(27),
    [anon_sym_COLON_COLON] = ACTIONS(29),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(9),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(9),
    [anon_sym_int] = ACTIONS(9),
    [anon_sym_uint] = ACTIONS(9),
    [anon_sym_void] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_RBRACK] = ACTIONS(31),
    [anon_sym_cshort] = ACTIONS(13),
    [anon_sym_cushort] = ACTIONS(13),
    [anon_sym_cint] = ACTIONS(13),
    [anon_sym_cuint] = ACTIONS(13),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(13),
    [anon_sym_culonglong] = ACTIONS(13),
    [anon_sym_struct] = ACTIONS(15),
    [sym__hard_expression_separator] = ACTIONS(33),
    [sym__soft_expression_separator] = ACTIONS(31),
    [sym_comment] = ACTIONS(3),
  },
  [4] = {
    [sym__expr] = STATE(4),
    [sym__expression] = STATE(28),
    [sym__expression_call] = STATE(28),
    [sym__expression_declaration] = STATE(28),
    [sym_declaration] = STATE(28),
    [sym_declaration_type_inferred] = STATE(28),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_identifier] = ACTIONS(37),
    [anon_sym_bool] = ACTIONS(40),
    [anon_sym_boolean] = ACTIONS(40),
    [anon_sym_Bool] = ACTIONS(40),
    [anon_sym_Boolean] = ACTIONS(40),
    [anon_sym_int] = ACTIONS(40),
    [anon_sym_uint] = ACTIONS(40),
    [anon_sym_void] = ACTIONS(40),
    [anon_sym_LBRACK] = ACTIONS(43),
    [anon_sym_cshort] = ACTIONS(46),
    [anon_sym_cushort] = ACTIONS(46),
    [anon_sym_cint] = ACTIONS(46),
    [anon_sym_cuint] = ACTIONS(46),
    [anon_sym_clong] = ACTIONS(46),
    [anon_sym_culong] = ACTIONS(46),
    [anon_sym_clonglong] = ACTIONS(46),
    [anon_sym_culonglong] = ACTIONS(46),
    [anon_sym_struct] = ACTIONS(49),
    [anon_sym_RBRACE] = ACTIONS(35),
    [sym_comment] = ACTIONS(3),
  },
  [5] = {
    [sym__expr] = STATE(7),
    [sym__expression] = STATE(28),
    [sym__expression_call] = STATE(28),
    [sym__expression_declaration] = STATE(28),
    [sym_declaration] = STATE(28),
    [sym_declaration_type_inferred] = STATE(28),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [aux_sym_source_file_repeat1] = STATE(7),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(9),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(9),
    [anon_sym_int] = ACTIONS(9),
    [anon_sym_uint] = ACTIONS(9),
    [anon_sym_void] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_cshort] = ACTIONS(13),
    [anon_sym_cushort] = ACTIONS(13),
    [anon_sym_cint] = ACTIONS(13),
    [anon_sym_cuint] = ACTIONS(13),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(13),
    [anon_sym_culonglong] = ACTIONS(13),
    [anon_sym_struct] = ACTIONS(15),
    [anon_sym_RBRACE] = ACTIONS(52),
    [sym_comment] = ACTIONS(3),
  },
  [6] = {
    [sym__expr_soft] = STATE(8),
    [sym__expression] = STATE(33),
    [sym__expression_call] = STATE(33),
    [sym__expression_declaration] = STATE(33),
    [sym_declaration] = STATE(33),
    [sym_declaration_type_inferred] = STATE(33),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [aux_sym__expression_call_repeat1] = STATE(8),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(9),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(9),
    [anon_sym_int] = ACTIONS(9),
    [anon_sym_uint] = ACTIONS(9),
    [anon_sym_void] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_cshort] = ACTIONS(13),
    [anon_sym_cushort] = ACTIONS(13),
    [anon_sym_cint] = ACTIONS(13),
    [anon_sym_cuint] = ACTIONS(13),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(13),
    [anon_sym_culonglong] = ACTIONS(13),
    [anon_sym_struct] = ACTIONS(15),
    [sym__hard_expression_separator] = ACTIONS(54),
    [sym_comment] = ACTIONS(3),
  },
  [7] = {
    [sym__expr] = STATE(4),
    [sym__expression] = STATE(28),
    [sym__expression_call] = STATE(28),
    [sym__expression_declaration] = STATE(28),
    [sym_declaration] = STATE(28),
    [sym_declaration_type_inferred] = STATE(28),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [aux_sym_source_file_repeat1] = STATE(4),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(9),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(9),
    [anon_sym_int] = ACTIONS(9),
    [anon_sym_uint] = ACTIONS(9),
    [anon_sym_void] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_cshort] = ACTIONS(13),
    [anon_sym_cushort] = ACTIONS(13),
    [anon_sym_cint] = ACTIONS(13),
    [anon_sym_cuint] = ACTIONS(13),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(13),
    [anon_sym_culonglong] = ACTIONS(13),
    [anon_sym_struct] = ACTIONS(15),
    [anon_sym_RBRACE] = ACTIONS(56),
    [sym_comment] = ACTIONS(3),
  },
  [8] = {
    [sym__expr_soft] = STATE(8),
    [sym__expression] = STATE(33),
    [sym__expression_call] = STATE(33),
    [sym__expression_declaration] = STATE(33),
    [sym_declaration] = STATE(33),
    [sym_declaration_type_inferred] = STATE(33),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [aux_sym__expression_call_repeat1] = STATE(8),
    [sym_identifier] = ACTIONS(58),
    [anon_sym_bool] = ACTIONS(61),
    [anon_sym_boolean] = ACTIONS(61),
    [anon_sym_Bool] = ACTIONS(61),
    [anon_sym_Boolean] = ACTIONS(61),
    [anon_sym_int] = ACTIONS(61),
    [anon_sym_uint] = ACTIONS(61),
    [anon_sym_void] = ACTIONS(61),
    [anon_sym_LBRACK] = ACTIONS(64),
    [anon_sym_cshort] = ACTIONS(67),
    [anon_sym_cushort] = ACTIONS(67),
    [anon_sym_cint] = ACTIONS(67),
    [anon_sym_cuint] = ACTIONS(67),
    [anon_sym_clong] = ACTIONS(67),
    [anon_sym_culong] = ACTIONS(67),
    [anon_sym_clonglong] = ACTIONS(67),
    [anon_sym_culonglong] = ACTIONS(67),
    [anon_sym_struct] = ACTIONS(70),
    [sym__hard_expression_separator] = ACTIONS(73),
    [sym_comment] = ACTIONS(3),
  },
  [9] = {
    [sym__expr] = STATE(4),
    [sym__expression] = STATE(28),
    [sym__expression_call] = STATE(28),
    [sym__expression_declaration] = STATE(28),
    [sym_declaration] = STATE(28),
    [sym_declaration_type_inferred] = STATE(28),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(75),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(9),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(9),
    [anon_sym_int] = ACTIONS(9),
    [anon_sym_uint] = ACTIONS(9),
    [anon_sym_void] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_cshort] = ACTIONS(13),
    [anon_sym_cushort] = ACTIONS(13),
    [anon_sym_cint] = ACTIONS(13),
    [anon_sym_cuint] = ACTIONS(13),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(13),
    [anon_sym_culonglong] = ACTIONS(13),
    [anon_sym_struct] = ACTIONS(15),
    [sym_comment] = ACTIONS(3),
  },
  [10] = {
    [sym__expression] = STATE(26),
    [sym__expression_call] = STATE(26),
    [sym__expression_declaration] = STATE(26),
    [sym_declaration] = STATE(26),
    [sym_declaration_type_inferred] = STATE(26),
    [sym__type] = STATE(24),
    [sym_type_primitive] = STATE(24),
    [sym_type_pointer] = STATE(24),
    [sym_type_reference] = STATE(24),
    [sym__type_array] = STATE(24),
    [sym_type_dynamic_array] = STATE(24),
    [sym_type_fixed_array] = STATE(24),
    [sym_type_ffi] = STATE(24),
    [sym_type_struct] = STATE(24),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(9),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(9),
    [anon_sym_int] = ACTIONS(9),
    [anon_sym_uint] = ACTIONS(9),
    [anon_sym_void] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_cshort] = ACTIONS(13),
    [anon_sym_cushort] = ACTIONS(13),
    [anon_sym_cint] = ACTIONS(13),
    [anon_sym_cuint] = ACTIONS(13),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(13),
    [anon_sym_culonglong] = ACTIONS(13),
    [anon_sym_struct] = ACTIONS(15),
    [sym_comment] = ACTIONS(3),
  },
  [11] = {
    [sym_identifier] = ACTIONS(77),
    [anon_sym_bool] = ACTIONS(77),
    [anon_sym_boolean] = ACTIONS(77),
    [anon_sym_Bool] = ACTIONS(77),
    [anon_sym_Boolean] = ACTIONS(77),
    [anon_sym_int] = ACTIONS(77),
    [anon_sym_uint] = ACTIONS(77),
    [anon_sym_void] = ACTIONS(77),
    [anon_sym_DOTptr] = ACTIONS(79),
    [anon_sym_DOTref] = ACTIONS(79),
    [anon_sym_LBRACK] = ACTIONS(79),
    [anon_sym_RBRACK] = ACTIONS(79),
    [anon_sym_cshort] = ACTIONS(77),
    [anon_sym_cushort] = ACTIONS(77),
    [anon_sym_cint] = ACTIONS(77),
    [anon_sym_cuint] = ACTIONS(77),
    [anon_sym_clong] = ACTIONS(77),
    [anon_sym_culong] = ACTIONS(77),
    [anon_sym_clonglong] = ACTIONS(77),
    [anon_sym_culonglong] = ACTIONS(77),
    [anon_sym_struct] = ACTIONS(77),
    [sym__hard_expression_separator] = ACTIONS(77),
    [sym__soft_expression_separator] = ACTIONS(79),
    [sym__number_dec] = ACTIONS(77),
    [sym__number_hex] = ACTIONS(79),
    [sym__number_oct] = ACTIONS(77),
    [sym_comment] = ACTIONS(3),
  },
  [12] = {
    [sym_identifier] = ACTIONS(81),
    [anon_sym_bool] = ACTIONS(81),
    [anon_sym_boolean] = ACTIONS(81),
    [anon_sym_Bool] = ACTIONS(81),
    [anon_sym_Boolean] = ACTIONS(81),
    [anon_sym_int] = ACTIONS(81),
    [anon_sym_uint] = ACTIONS(81),
    [anon_sym_void] = ACTIONS(81),
    [anon_sym_DOTptr] = ACTIONS(83),
    [anon_sym_DOTref] = ACTIONS(83),
    [anon_sym_LBRACK] = ACTIONS(83),
    [anon_sym_RBRACK] = ACTIONS(83),
    [anon_sym_cshort] = ACTIONS(81),
    [anon_sym_cushort] = ACTIONS(81),
    [anon_sym_cint] = ACTIONS(81),
    [anon_sym_cuint] = ACTIONS(81),
    [anon_sym_clong] = ACTIONS(81),
    [anon_sym_culong] = ACTIONS(81),
    [anon_sym_clonglong] = ACTIONS(81),
    [anon_sym_culonglong] = ACTIONS(81),
    [anon_sym_struct] = ACTIONS(81),
    [sym__hard_expression_separator] = ACTIONS(81),
    [sym__soft_expression_separator] = ACTIONS(83),
    [sym__number_dec] = ACTIONS(81),
    [sym__number_hex] = ACTIONS(83),
    [sym__number_oct] = ACTIONS(81),
    [sym_comment] = ACTIONS(3),
  },
  [13] = {
    [sym__type] = STATE(25),
    [sym_type_primitive] = STATE(25),
    [sym_type_pointer] = STATE(25),
    [sym_type_reference] = STATE(25),
    [sym__type_array] = STATE(25),
    [sym_type_dynamic_array] = STATE(25),
    [sym_type_fixed_array] = STATE(25),
    [sym_type_ffi] = STATE(25),
    [sym_type_struct] = STATE(25),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(85),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(85),
    [anon_sym_int] = ACTIONS(85),
    [anon_sym_uint] = ACTIONS(85),
    [anon_sym_void] = ACTIONS(85),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_cshort] = ACTIONS(87),
    [anon_sym_cushort] = ACTIONS(87),
    [anon_sym_cint] = ACTIONS(87),
    [anon_sym_cuint] = ACTIONS(87),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(87),
    [anon_sym_culonglong] = ACTIONS(87),
    [anon_sym_struct] = ACTIONS(89),
    [sym_comment] = ACTIONS(3),
  },
  [14] = {
    [sym_identifier] = ACTIONS(91),
    [anon_sym_bool] = ACTIONS(91),
    [anon_sym_boolean] = ACTIONS(91),
    [anon_sym_Bool] = ACTIONS(91),
    [anon_sym_Boolean] = ACTIONS(91),
    [anon_sym_int] = ACTIONS(91),
    [anon_sym_uint] = ACTIONS(91),
    [anon_sym_void] = ACTIONS(91),
    [anon_sym_DOTptr] = ACTIONS(93),
    [anon_sym_DOTref] = ACTIONS(93),
    [anon_sym_LBRACK] = ACTIONS(93),
    [anon_sym_RBRACK] = ACTIONS(93),
    [anon_sym_cshort] = ACTIONS(91),
    [anon_sym_cushort] = ACTIONS(91),
    [anon_sym_cint] = ACTIONS(91),
    [anon_sym_cuint] = ACTIONS(91),
    [anon_sym_clong] = ACTIONS(91),
    [anon_sym_culong] = ACTIONS(91),
    [anon_sym_clonglong] = ACTIONS(91),
    [anon_sym_culonglong] = ACTIONS(91),
    [anon_sym_struct] = ACTIONS(91),
    [sym__hard_expression_separator] = ACTIONS(91),
    [sym__soft_expression_separator] = ACTIONS(93),
    [sym__number_dec] = ACTIONS(91),
    [sym__number_hex] = ACTIONS(93),
    [sym__number_oct] = ACTIONS(91),
    [sym_comment] = ACTIONS(3),
  },
  [15] = {
    [sym_identifier] = ACTIONS(95),
    [anon_sym_bool] = ACTIONS(95),
    [anon_sym_boolean] = ACTIONS(95),
    [anon_sym_Bool] = ACTIONS(95),
    [anon_sym_Boolean] = ACTIONS(95),
    [anon_sym_int] = ACTIONS(95),
    [anon_sym_uint] = ACTIONS(95),
    [anon_sym_void] = ACTIONS(95),
    [anon_sym_DOTptr] = ACTIONS(97),
    [anon_sym_DOTref] = ACTIONS(97),
    [anon_sym_LBRACK] = ACTIONS(97),
    [anon_sym_RBRACK] = ACTIONS(97),
    [anon_sym_cshort] = ACTIONS(95),
    [anon_sym_cushort] = ACTIONS(95),
    [anon_sym_cint] = ACTIONS(95),
    [anon_sym_cuint] = ACTIONS(95),
    [anon_sym_clong] = ACTIONS(95),
    [anon_sym_culong] = ACTIONS(95),
    [anon_sym_clonglong] = ACTIONS(95),
    [anon_sym_culonglong] = ACTIONS(95),
    [anon_sym_struct] = ACTIONS(95),
    [sym__hard_expression_separator] = ACTIONS(95),
    [sym__soft_expression_separator] = ACTIONS(97),
    [sym__number_dec] = ACTIONS(95),
    [sym__number_hex] = ACTIONS(97),
    [sym__number_oct] = ACTIONS(95),
    [sym_comment] = ACTIONS(3),
  },
  [16] = {
    [sym_identifier] = ACTIONS(99),
    [anon_sym_bool] = ACTIONS(99),
    [anon_sym_boolean] = ACTIONS(99),
    [anon_sym_Bool] = ACTIONS(99),
    [anon_sym_Boolean] = ACTIONS(99),
    [anon_sym_int] = ACTIONS(99),
    [anon_sym_uint] = ACTIONS(99),
    [anon_sym_void] = ACTIONS(99),
    [anon_sym_DOTptr] = ACTIONS(101),
    [anon_sym_DOTref] = ACTIONS(101),
    [anon_sym_LBRACK] = ACTIONS(101),
    [anon_sym_RBRACK] = ACTIONS(101),
    [anon_sym_cshort] = ACTIONS(99),
    [anon_sym_cushort] = ACTIONS(99),
    [anon_sym_cint] = ACTIONS(99),
    [anon_sym_cuint] = ACTIONS(99),
    [anon_sym_clong] = ACTIONS(99),
    [anon_sym_culong] = ACTIONS(99),
    [anon_sym_clonglong] = ACTIONS(99),
    [anon_sym_culonglong] = ACTIONS(99),
    [anon_sym_struct] = ACTIONS(99),
    [sym__hard_expression_separator] = ACTIONS(99),
    [sym__soft_expression_separator] = ACTIONS(101),
    [sym__number_dec] = ACTIONS(99),
    [sym__number_hex] = ACTIONS(101),
    [sym__number_oct] = ACTIONS(99),
    [sym_comment] = ACTIONS(3),
  },
  [17] = {
    [sym_identifier] = ACTIONS(103),
    [anon_sym_bool] = ACTIONS(103),
    [anon_sym_boolean] = ACTIONS(103),
    [anon_sym_Bool] = ACTIONS(103),
    [anon_sym_Boolean] = ACTIONS(103),
    [anon_sym_int] = ACTIONS(103),
    [anon_sym_uint] = ACTIONS(103),
    [anon_sym_void] = ACTIONS(103),
    [anon_sym_DOTptr] = ACTIONS(105),
    [anon_sym_DOTref] = ACTIONS(105),
    [anon_sym_LBRACK] = ACTIONS(105),
    [anon_sym_RBRACK] = ACTIONS(105),
    [anon_sym_cshort] = ACTIONS(103),
    [anon_sym_cushort] = ACTIONS(103),
    [anon_sym_cint] = ACTIONS(103),
    [anon_sym_cuint] = ACTIONS(103),
    [anon_sym_clong] = ACTIONS(103),
    [anon_sym_culong] = ACTIONS(103),
    [anon_sym_clonglong] = ACTIONS(103),
    [anon_sym_culonglong] = ACTIONS(103),
    [anon_sym_struct] = ACTIONS(103),
    [sym__hard_expression_separator] = ACTIONS(103),
    [sym__soft_expression_separator] = ACTIONS(105),
    [sym__number_dec] = ACTIONS(103),
    [sym__number_hex] = ACTIONS(105),
    [sym__number_oct] = ACTIONS(103),
    [sym_comment] = ACTIONS(3),
  },
  [18] = {
    [sym_identifier] = ACTIONS(107),
    [anon_sym_bool] = ACTIONS(107),
    [anon_sym_boolean] = ACTIONS(107),
    [anon_sym_Bool] = ACTIONS(107),
    [anon_sym_Boolean] = ACTIONS(107),
    [anon_sym_int] = ACTIONS(107),
    [anon_sym_uint] = ACTIONS(107),
    [anon_sym_void] = ACTIONS(107),
    [anon_sym_DOTptr] = ACTIONS(109),
    [anon_sym_DOTref] = ACTIONS(109),
    [anon_sym_LBRACK] = ACTIONS(109),
    [anon_sym_RBRACK] = ACTIONS(109),
    [anon_sym_cshort] = ACTIONS(107),
    [anon_sym_cushort] = ACTIONS(107),
    [anon_sym_cint] = ACTIONS(107),
    [anon_sym_cuint] = ACTIONS(107),
    [anon_sym_clong] = ACTIONS(107),
    [anon_sym_culong] = ACTIONS(107),
    [anon_sym_clonglong] = ACTIONS(107),
    [anon_sym_culonglong] = ACTIONS(107),
    [anon_sym_struct] = ACTIONS(107),
    [sym__hard_expression_separator] = ACTIONS(107),
    [sym__soft_expression_separator] = ACTIONS(109),
    [sym__number_dec] = ACTIONS(107),
    [sym__number_hex] = ACTIONS(109),
    [sym__number_oct] = ACTIONS(107),
    [sym_comment] = ACTIONS(3),
  },
  [19] = {
    [sym_identifier] = ACTIONS(111),
    [anon_sym_bool] = ACTIONS(111),
    [anon_sym_boolean] = ACTIONS(111),
    [anon_sym_Bool] = ACTIONS(111),
    [anon_sym_Boolean] = ACTIONS(111),
    [anon_sym_int] = ACTIONS(111),
    [anon_sym_uint] = ACTIONS(111),
    [anon_sym_void] = ACTIONS(111),
    [anon_sym_DOTptr] = ACTIONS(113),
    [anon_sym_DOTref] = ACTIONS(113),
    [anon_sym_LBRACK] = ACTIONS(113),
    [anon_sym_RBRACK] = ACTIONS(113),
    [anon_sym_cshort] = ACTIONS(111),
    [anon_sym_cushort] = ACTIONS(111),
    [anon_sym_cint] = ACTIONS(111),
    [anon_sym_cuint] = ACTIONS(111),
    [anon_sym_clong] = ACTIONS(111),
    [anon_sym_culong] = ACTIONS(111),
    [anon_sym_clonglong] = ACTIONS(111),
    [anon_sym_culonglong] = ACTIONS(111),
    [anon_sym_struct] = ACTIONS(111),
    [sym__hard_expression_separator] = ACTIONS(111),
    [sym__soft_expression_separator] = ACTIONS(113),
    [sym__number_dec] = ACTIONS(111),
    [sym__number_hex] = ACTIONS(113),
    [sym__number_oct] = ACTIONS(111),
    [sym_comment] = ACTIONS(3),
  },
  [20] = {
    [sym_identifier] = ACTIONS(115),
    [anon_sym_bool] = ACTIONS(115),
    [anon_sym_boolean] = ACTIONS(115),
    [anon_sym_Bool] = ACTIONS(115),
    [anon_sym_Boolean] = ACTIONS(115),
    [anon_sym_int] = ACTIONS(115),
    [anon_sym_uint] = ACTIONS(115),
    [anon_sym_void] = ACTIONS(115),
    [anon_sym_DOTptr] = ACTIONS(117),
    [anon_sym_DOTref] = ACTIONS(117),
    [anon_sym_LBRACK] = ACTIONS(117),
    [anon_sym_RBRACK] = ACTIONS(117),
    [anon_sym_cshort] = ACTIONS(115),
    [anon_sym_cushort] = ACTIONS(115),
    [anon_sym_cint] = ACTIONS(115),
    [anon_sym_cuint] = ACTIONS(115),
    [anon_sym_clong] = ACTIONS(115),
    [anon_sym_culong] = ACTIONS(115),
    [anon_sym_clonglong] = ACTIONS(115),
    [anon_sym_culonglong] = ACTIONS(115),
    [anon_sym_struct] = ACTIONS(115),
    [sym__hard_expression_separator] = ACTIONS(115),
    [sym__soft_expression_separator] = ACTIONS(117),
    [sym__number_dec] = ACTIONS(115),
    [sym__number_hex] = ACTIONS(117),
    [sym__number_oct] = ACTIONS(115),
    [sym_comment] = ACTIONS(3),
  },
  [21] = {
    [sym__type] = STATE(2),
    [sym_type_primitive] = STATE(2),
    [sym_type_pointer] = STATE(2),
    [sym_type_reference] = STATE(2),
    [sym__type_array] = STATE(2),
    [sym_type_dynamic_array] = STATE(2),
    [sym_type_fixed_array] = STATE(2),
    [sym_type_ffi] = STATE(2),
    [sym_type_struct] = STATE(2),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_boolean] = ACTIONS(85),
    [anon_sym_Bool] = ACTIONS(9),
    [anon_sym_Boolean] = ACTIONS(85),
    [anon_sym_int] = ACTIONS(85),
    [anon_sym_uint] = ACTIONS(85),
    [anon_sym_void] = ACTIONS(85),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_cshort] = ACTIONS(87),
    [anon_sym_cushort] = ACTIONS(87),
    [anon_sym_cint] = ACTIONS(87),
    [anon_sym_cuint] = ACTIONS(87),
    [anon_sym_clong] = ACTIONS(13),
    [anon_sym_culong] = ACTIONS(13),
    [anon_sym_clonglong] = ACTIONS(87),
    [anon_sym_culonglong] = ACTIONS(87),
    [anon_sym_struct] = ACTIONS(89),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
    ACTIONS(121), 17,
      anon_sym_bool,
      anon_sym_boolean,
      anon_sym_Bool,
      anon_sym_Boolean,
      anon_sym_int,
      anon_sym_uint,
      anon_sym_void,
      anon_sym_cshort,
      anon_sym_cushort,
      anon_sym_cint,
      anon_sym_cuint,
      anon_sym_clong,
      anon_sym_culong,
      anon_sym_clonglong,
      anon_sym_culonglong,
      anon_sym_struct,
      sym_identifier,
  [28] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 1,
      anon_sym_LBRACK,
    ACTIONS(123), 18,
      anon_sym_bool,
      anon_sym_boolean,
      anon_sym_Bool,
      anon_sym_Boolean,
      anon_sym_int,
      anon_sym_uint,
      anon_sym_void,
      anon_sym_cshort,
      anon_sym_cushort,
      anon_sym_cint,
      anon_sym_cuint,
      anon_sym_clong,
      anon_sym_culong,
      anon_sym_clonglong,
      anon_sym_culonglong,
      anon_sym_struct,
      sym__hard_expression_separator,
      sym_identifier,
  [55] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_DOTptr,
    ACTIONS(19), 1,
      anon_sym_DOTref,
    ACTIONS(33), 1,
      sym__hard_expression_separator,
    ACTIONS(31), 2,
      anon_sym_RBRACK,
      sym__soft_expression_separator,
  [72] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_DOTptr,
    ACTIONS(19), 1,
      anon_sym_DOTref,
    ACTIONS(129), 1,
      sym__hard_expression_separator,
    ACTIONS(127), 2,
      anon_sym_RBRACK,
      sym__soft_expression_separator,
  [89] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(133), 1,
      sym__hard_expression_separator,
    ACTIONS(131), 2,
      anon_sym_RBRACK,
      sym__soft_expression_separator,
  [100] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(137), 1,
      sym__hard_expression_separator,
    ACTIONS(135), 2,
      anon_sym_RBRACK,
      sym__soft_expression_separator,
  [111] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 1,
      sym__hard_expression_separator,
    ACTIONS(141), 1,
      sym__soft_expression_separator,
    STATE(22), 1,
      sym__expression_separator,
  [124] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      anon_sym_RBRACK,
  [131] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(145), 1,
      anon_sym_RBRACK,
  [138] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      anon_sym_RBRACK,
  [145] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(149), 1,
      sym_identifier,
  [152] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      sym__soft_expression_separator,
  [159] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_LBRACE,
  [166] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(155), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(22)] = 0,
  [SMALL_STATE(23)] = 28,
  [SMALL_STATE(24)] = 55,
  [SMALL_STATE(25)] = 72,
  [SMALL_STATE(26)] = 89,
  [SMALL_STATE(27)] = 100,
  [SMALL_STATE(28)] = 111,
  [SMALL_STATE(29)] = 124,
  [SMALL_STATE(30)] = 131,
  [SMALL_STATE(31)] = 138,
  [SMALL_STATE(32)] = 145,
  [SMALL_STATE(33)] = 152,
  [SMALL_STATE(34)] = 159,
  [SMALL_STATE(35)] = 166,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__expression_call_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__expression_call_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__expression_call_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__expression_call_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__expression_call_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__expression_call_repeat1, 2, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_fixed_array, 4, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_fixed_array, 4, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_primitive, 1, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_primitive, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_struct, 4, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_struct, 4, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_dynamic_array, 4, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_dynamic_array, 4, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_struct, 5, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_struct, 5, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_pointer, 2, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_pointer, 2, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_reference, 2, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_reference, 2, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_ffi, 1, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_ffi, 1, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_dynamic_array, 3, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_dynamic_array, 3, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr, 2, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expr, 2, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expr_soft, 2, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr_soft, 2, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 3, 0, 1),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 3, 0, 1),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration_type_inferred, 3, 0, 2),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration_type_inferred, 3, 0, 2),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression_call, 3, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression_call, 3, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_literal, 1, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [155] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_glint(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
