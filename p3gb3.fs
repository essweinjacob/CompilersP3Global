start
let x : 1
let y : 2
main {
  let w : 3
  printf [ x + y + w ] .
  if [  x : : y ] then 
  { let y : 4 
    iter [ w =< y ] 
    { printf [ x ] .
     } .
    printf [ w ] . 
   } .
} stop