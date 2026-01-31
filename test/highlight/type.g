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

   float
;; ^^^^^ type

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


;; ================
;; Composite Types
;; ================

   enum {};
;; ^^^^ type

   enum(u32) {};
;; ^^^^ type
;;     ^ !type
;;      ^^^ type

   struct {};
;; ^^^^^^ type

   union {};
;; ^^^^^ type

   sum {};
;; ^^^ type
