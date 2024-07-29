;; SYNTAX TEST

   if false {};
;; ^^ keyword

   if false, {};
;; ^^ keyword

   if false; {};
;; ^^ keyword

   if false {} else {};
;; ^^ keyword
;;             ^^^^ keyword

   if false, {} else {};
;; ^^ keyword
;;              ^^^^ keyword

   if false, {}, else {};
;; ^^ keyword
;;               ^^^^ keyword

   if false; {} else {};
;; ^^ keyword
;;              ^^^^ keyword

   if false; {}; else {};
;; ^^ keyword
;;               ^^^^ keyword

   if false, {}; else {};
;; ^^ keyword
;;               ^^^^ keyword

   if false; {}, else {};
;; ^^ keyword
;;               ^^^^ keyword

   while false {};
;; ^^^^^ keyword

   while false, {};
;; ^^^^^ keyword

   while false; {};
;; ^^^^^ keyword
