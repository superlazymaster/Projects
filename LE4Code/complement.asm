//complement.asm

//NAME: Seshadithya Saravanan
//UIN: 533007949

//This asm checks whether two numbers a and b are complements;
//that is, each bit active in a is inactive b, and vice-versa.
//Other ways of saying this are:
// (a & b) = 0 and (a | b) = 0b111..., where & is bitwise AND and | is bitwise OR
// (a + b) = -1
// and any other technique you come up with is ok, as long as it functions properly.
//The two numbers are given in RAM[0] and RAM[1]
//and the result will be stored to RAM[2].
//The result should be 1 if a and b are complements,
//and 0 if they are not.
//Write your code below.
///////////////////////////////////////////////////////////////////////////////

@R0
D = M

@R1
D = D + M

@FINISH
    D+1;JEQ

@NOTCOMPLEMENT
    D+1;JNE

(NOTCOMPLEMENT)
    @R2
    M = 0
    @EXIT
    0;JMP

(FINISH)
    @R2
    M = 1
    @EXIT
    0;JMP

@39
0;JMP




// @R1
// D = D & M

// @checkOR
// D;JEQ

// (CHECKOR)
//     @R0
//     D=M

//     @R1
//     D = D | M

//     @ISCOMPLEMENT
//     D-1;JEQ

//     @R2
//     M = 0
//     @EXIT

// (ISCOMPLEMENT)
//     @R2
//     M = 1
//     @EXIT

// (EXIT)
//     @46
//     0;JMP