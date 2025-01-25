// Filename = gcd.tst

load gcd.asm,
output-file gcd.out,
compare-to gcd.cmp,
output-list RAM[0]%D2.6.2 RAM[1]%D2.6.2 RAM[2]%D2.6.2;

set RAM[0] 9,
set RAM[1] 6,
set RAM[2] 0,
repeat 400 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 11,
set RAM[1] 21,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 18,
set RAM[1] 66,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

// Write your own testcases below:
set PC 0,
set RAM[0] 100,
set RAM[1] 25,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 49,
set RAM[1] 14,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 56,
set RAM[1] 98,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 123,
set RAM[1] 456,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 512,
set RAM[1] 1024,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 15,
set RAM[1] 35,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 101,
set RAM[1] 103,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 7,
set RAM[1] 7,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 13,
set RAM[1] 17,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 32767,
set RAM[1] 32767,
set RAM[2] 0,
repeat 1000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 1,
set RAM[1] 32767,
set RAM[2] 0,
repeat 400000 {
	ticktock;
}
output;

set PC 0,
set RAM[0] 1,
set RAM[1] 1,
set RAM[2] 0,
repeat 500000 {
	ticktock;
}
output;
