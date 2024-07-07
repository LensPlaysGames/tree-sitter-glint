(number_literal) @constant

[
  ;; Function attributes
  "discardable"
  ;; Storage specifiers
  "external" "export"

  "module"
  "return"
] @keyword

[
  ;; Builtins
  "bool" "boolean" "Bool" "Boolean"
  "Byte"
  "int" "uint"
  "void"

  ;; C FFI
  "cshort" "cushort"
  "cint" "cuint"
  "clong" "culong"
  "clonglong" "culonglong"
  "csize" "cusize"

  (type_pointer)
  (type_reference)
  (type_dynamic_array)
  (type_fixed_array)
] @type

[
  "(" ")"
  "{" "}"
] @punctuation.bracket