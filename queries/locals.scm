; https://tree-sitter.github.io/tree-sitter/3-syntax-highlighting.html#local-variables

; Scopes
; Introduces a new scope, within which variables may be defined.
(source_file) @local.scope
(block) @local.scope
(declaration
 type: (type_function)
 init: _ @local.scope)

; Definitions
; Defines a named variable
(declaration name: (identifier) @local.definition)
(param_decl name: (identifier) @local.definition)

; References
; References a defined variable
(identifier) @local.reference
