//Seshadithya Saravanan 533007949
// File name: gcd.asm

// This program calculates the greatest common divisor (gcd) of two given 
// non-negative integers, which are stored in RAM[0] (R0) and RAM[1] (R1). 
// The gcd is stored in RAM[2] (R2).



// Put your code below this line

// create copies of ram 0 and ram 1
// divide ram 0 by ram 1
//replace ram0 with ram1 and store the remainder in ram 1
// if ram1 is 0 return ram0

@R0
D=M



@copyR0
M=D

@R1
D=M

@copyR1
M=D



(UPDATE)
    (LOOP)

        @copyR0
        D=M

        @copyR1
        D=D-M

        @REMAINDER
        D;JLT

        @copyR0
        M=D

        @FINISH1
        D;JEQ

        @LOOP
        0;JMP

    (REMAINDER)
        @copyR0
        D=M
        @temp
        M=D

        @copyR1
        D=M
        @copyR0
        M=D

        @temp
        D=M
        @copyR1
        M=D

        @UPDATE
        0;JMP
        
    (FINISH1)
        @copyR1
        D=M
        @R2
        M=D
        @EXIT
        0;JMP

(EXIT)
@EXIT
0;JMP
