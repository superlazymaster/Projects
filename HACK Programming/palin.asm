// Seshadithya Saravanan 533007949

// File name: palin.asm

// The program develops a Palindrome checker application. 
// The input to the program is a 5 digit integer A and is stored in RAM[0] (R0).
// A helper value of 10 is stored in RAM[8] (R8) by virtue of the tst file command.
// Number A is a positive integer.
// A has exactly 5 digits and no more no less.

// Program functions as follows: 
// Extract the individual digits from number A and store them in R2-R6 registers in that order.
// Result of 1 is stored in R1 if the number A is a Palindrome else result of 0 is stored in R1

// Put your code below this line

@R2
M=0

@R3
M=0

@R4
M=0

@R5
M=0

@R6 
M=0

@R0
D=M

@copy
M=D

@address
M=1
M=M+1

(DIVIDE)
    @quotient
    M=0
    (LOOP)

        @copy
        D=M

        @tempremainder
        M=D

        @10
        D=D-A

        @REMAINDER
        D;JLT

        @copy
        M=D

        @quotient
        M=M+1

        @FINISH1
        D;JEQ

        @LOOP
        0;JMP

        (REMAINDER)
            @tempremainder
            D=M
            @address
            A=M
            M=D

            @quotient
            D=M

            @copy
            M=D

            @address 
            M=M+1
        
            @CHECKDONE
            0;JMP
        
        (FINISH1)

            @address 
            A=M 
            M=0
            @quotient
            D=M
            @copy
            M=D
            @address 
            M=M+1

            @CHECKDONE
            0;JMP
// if number is not zero
// Go back and continue extracting digits
(CHECKDONE)
    @copy
        D=M
        @DIVIDE
        D;JGT

// You are now done extracting digits 
// check if the match 
    @CHECKNUMBERS
    0;JMP

(CHECKNUMBERS)
    @R2
    D=M
    @R6
    D=D-M

    @EXIT
    D;JNE

    @R3
    D=M
    @R5
    D=D-M

    @EXIT
    D;JNE

    @R1
    M=1
    @FINISH
    0;JMP
(EXIT)
    @R1
    M=0
    @EXIT
    0;JMP

(FINISH)
@FINISH
0;JMP