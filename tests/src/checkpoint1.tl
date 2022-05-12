# Thunderlisp Checkpoint 1 - Basic functionality

(+ 1 3)
(- 4 1)
(/ 4 2)
(* 2)
(^ 2 2)

(let x 0)
(let y (+ x 1))

# One kind of loop
(loop
   (if (= y 5)
       (return))
    (++ y))