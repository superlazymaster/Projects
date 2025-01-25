//addn.asm

//NAME: Seshadithya Saravanan
//UIN: 533007949

//This asm computes the sum of n numbers
//Assuming RAM[0] stores the value n (how many numbers to sum)
//and the numbers are stored in consecutive addresses starting at address 1.
//The result will be stored in RAM[0], overwriting the original value of n.
//It may be useful to use variables when solving this problem.
//Write your code below.
///////////////////////////////////////////////////////////////////////////////



@index
M = 1

@R0
D = M

@n
M = D

@sum
M=0

(LOOP)

    //get index
    @index
    D=M
    
    // get difference between n and index (n-index)
    @n
    D = M-D

    // exit if n-index<0
    @EXIT
    D;JLT

    // else get the value at address i
    @index
    A = M
    D = M

    @sum
    M = D + M

    @index
    M = M + 1

    @LOOP
    0;JMP

(EXIT)
    @EXIT
    @sum
    D = M
    
    @R0
    M = D
    0;JMP





