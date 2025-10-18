;; SYNTAX TEST

;; ================
;; Glint Built-in Types
;; ================

   byte
;; ^^^^ type

   bool
;; ^^^^ type

   int
;; ^^^ type

   uint
;; ^^^^ type

   void
;; ^^^^ type

;; ================
;; Types with Modifiers
;; ================

   byte.ptr;
;; ^^^^^^^^ type

   byte.pptr;
;; ^^^^^^^^^ type

   byte.ref;
;; ^^^^^^^^ type

   [byte].ref;
;; ^^^^^^^^^^ type

   [byte view].ref;
;; ^^^^^^^^^^^^^^^ type
