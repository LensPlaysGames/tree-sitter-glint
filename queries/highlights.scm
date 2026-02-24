; https://tree-sitter.github.io/tree-sitter/3-syntax-highlighting.html#highlights
; Used highlight names:
; comment, variable, number, constant, string, function, type, keyword, operator, punctuation.bracket, module

; Modules
(module_declaration name: (_) @module)

; Comments
(comment) @comment

; Variables
(identifier) @variable

; Numbers
(integer_literal) @number

; Constants
; Bool literals like 'true' and 'false' are built-in constants.
(bool_literal) @constant
(byte_literal) @constant

; Strings
(string_literal) @string

; Declarations with names are variables.
(declaration name: (identifier) @variable)
; Declarations of function type, function pointer type, and function
; reference type are functions.
(declaration
 name: (identifier) @function
 type:
 [(type_function)
  (type_pointer (type_function))
  (type_reference (type_function))])

;; Parameter Declarations
(param_decl name: (identifier) @variable.parameter)
(param_decl type: (identifier) @type)

;; Highlight the type of a declaration if it's an identifier.
(declaration
 name: (identifier) @variable
 type: _ @type)

;; Highlight the name of a declaration if it's a type declaration.
(declaration
 name: (identifier) @type
 init: [(type_array) (type_enum)
        (type_ffi) (type_pointer)
        (type_pointer_to_pointer)
        (type_primitive) (type_reference)
        (type_struct) (type_sum)
        (type_union) (type_function)])

;; Keywords
[
  ;; Header
  "import" "module"

  ;; Control Flow
  "if" "else" "while"
  "cfor" "for" "in"

  ;; Function attributes
  "nomangle" "discardable"
  "pure" "used"
  "maps_arguments"

  ;; Unary Operators
  "not"

  ;; Binary Operators
  "and" "or"

  ;; Storage specifiers
  "export" "external"

  "supplant"
  "match"
  "switch"
  "print"
  "template"

  "return"

  "apply"
] @keyword

[
  ;; Builtins
  "bool"
  "byte"
  "int" "uint"
  "void"

  ;; C FFI
  "cshort" "cushort"
  "cint" "cuint"
  "clong" "culong"
  "clonglong" "culonglong"
  "csize" "cusize"

  ;; Composite Types
  "enum" "struct" "sum" "union"

  (type_array)
  (type_enum)
  (type_ffi)
  (type_pointer)
  (type_pointer_to_pointer)
  (type_primitive)
  (type_reference)
  (type_struct)
  (type_sum)
  (type_union)
  (type_function)
] @type

(type_enum underlying: (_) @type)
(type_function return_type: (_) @type)

[
 "@" "!" ;; "~"
 "+" "-" "*" "/" "&" "=" "!=" "<" "<=" ">" ">="
 "::" ":" ":="
 "++" "--"
 "+=" "-=" "*=" "/=" "%=" "~="
 "bit&" "bit|" "bit^" "bit~"
] @operator

[
  "(" ")"
  "{" "}"
  ;; "[" "]"
] @punctuation.bracket
