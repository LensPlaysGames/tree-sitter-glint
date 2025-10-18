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

   supplant foo;
;; ^^^^^^^^ keyword

   match foo {};
;; ^^^^^ keyword

   print;
;; ^^^^^ keyword

   print 0;
;; ^^^^^ keyword

   print 0 0;
;; ^^^^^ keyword

   print 0, 0;
;; ^^^^^ keyword

   cfor 0, 0, 0, 0;
;; ^^^^ keyword

   for x in y, z;
;; ^^^ keyword
;;       ^^ keyword
