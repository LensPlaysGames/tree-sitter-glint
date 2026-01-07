;; SYNTAX TEST

   module foo;
;; ^^^^^^ keyword

   import foo;
;; ^^^^^^ keyword

   xmodule;
;; ^^^^^^^ !keyword

   ximport;
;; ^^^^^^^ !keyword

   return;
;; ^^^^^^ keyword

   xreturn;
;; ^^^^^^^ !keyword

   external foo :void;
;; ^^^^^^^^ keyword

   xexternal;
;; ^^^^^^^^^ !keyword

   export foo :void;
;; ^^^^^^ keyword

   xexport;
;; ^^^^^^^ !keyword

   supplant foo;
;; ^^^^^^^^ keyword

   xsupplant;
;; ^^^^^^ !keyword

   match foo {};
;; ^^^^^ keyword

   xmatch;
;; ^^^^^^ !keyword

   print;
;; ^^^^^ keyword

   print 0;
;; ^^^^^ keyword

   print 0 0;
;; ^^^^^ keyword

   print 0, 0;
;; ^^^^^ keyword

   xprint;
;; ^^^^^^ !keyword

   cfor 0, 0, 0, 0;
;; ^^^^ keyword

   xcfor;
;; ^^^^^ !keyword

   for x in y, z;
;; ^^^ keyword
;;       ^^ keyword

   xfor;
;; ^^^^ !keyword

   apply foo;
;; ^^^^^ keyword

   apply foo, (bar, baz);
;; ^^^^^ keyword

   apply foo, (bar, baz), (goo, jaz);
;; ^^^^^ keyword

   xapply;
;; ^^^^^^ !keyword

