load calc.asm,
output-file calc.out,
compare-to calc.cmp,
output-list RAM[0]%D2.6.2 RAM[1]%D2.6.2 RAM[2]%D2.6.2 RAM[3]%D2.6.2 RAM[4]%D2.6.2 RAM[1024]%D2.6.2;

set PC 0,
set RAM[0] 32767,
set RAM[1] 1,
set RAM[2] 1,  
set RAM[3] 0; 
repeat 1000 {
  ticktock;
}
set RAM[0] -1,   // Restore arguments in case program used them as loop counter
set RAM[1] -1,
set RAM[2] 3,
output;