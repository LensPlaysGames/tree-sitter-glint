;; SYNTAX TEST

   module foo;
;; ^^^^^^ keyword

   import foo;
;; ^^^^^^ keyword

   return;
;; ^^^^^^ keyword

   external foo :void;
;; ^^^^^^^^ keyword

   export foo :void;
;; ^^^^^^ keyword
