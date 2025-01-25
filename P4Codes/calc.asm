//Seshadithya Saravanan 533007949

// File name: calc.asm

// The program develops a calculator application. 
// The operands a and b are integer numbers stored in RAM[0] (R0) and RAM[1] (R1), respectively.
// The operation choice c is stored in RAM[2] (R2), respectively
// if c == 1, do a + b
// if c == 2, do a - b
// if c == 3, do a * b
// if c == 4, do a / b
// For Addition and Subtraction operations the operands a and b can be positive or negative.
// For Multiplication operation only ONE operand can be negative.
// For Division operation BOTH operands must be positive and must be greater than 0.
// Store the final result (quotient for Division) in RAM[3] (R3). Only the Division operation 
// stores the remainder in RAM[4] (R4).


// Put your code below this line

//
// if (c==3){
//     if(a>=0){
//         repeat addition of b,  a times
//     }
//     else if(b>=0){
//         repeat addition of a, b times
//     }
//     else{
//         throw exception at R3
//     }
// }

// else if (c==4){
//     if(b<0||a<0){
//         throw error at R3
//     }
//     else{
//         while(a-b>0){
//             count+=1
//             a-=b
//         }
//         quotient is  count
//         remainder is any value left in a

//     }
// }

//


@1024
M=0
@R4
M=0

@R2
D=M

@1
D=D-A

@ADD
D;JEQ

D=D-1

@SUBTRACT
D;JEQ

D=D-1

@MULTIPLY 
D;JEQ

D=D-1

@DIVIDE 
D;JEQ

(ADD)
    @R0
    D=M
    @R1
    D=D+M
    @R3
    M=D
    @EXIT
    0;JMP

(SUBTRACT)
    @R0
    D=M
    @R1
    D=D-M
    @R3
    M=D
    @EXIT
    0;JMP


(MULTIPLY)
    @R0
    D=M

    @APOSITIVE
    D;JGE

    @R1
    D=M

    @BPOSITIVE
    D;JGE

    @BOTHNEGATIVE
    0;JMP

    (APOSITIVE)
        @R0
        D=M
        @temp
        M=D
        
        (LOOP1)
            @temp
            D=M
            
            @EXIT
            D;JEQ

            @R1
            D=M

            @R3
            M=D+M

            @temp
            M=M-1

            @LOOP1
            0;JMP

    
        
        (BPOSITIVE)

        @R1
        D=M
        @temp
        M=D

        (LOOP2)

            @temp
            D=M
            
            @EXIT
            D;JEQ

            @R0
            D=M

            @R3
            M=D+M

            @temp
            M=M-1

            @LOOP2
            0;JMP
    
    (BOTHNEGATIVE)
        @1024
        M=-1
        @EXIT
        0;JMP
    
    @EXIT
    0;JMP

(DIVIDE)
    @R0
    D=M

    @NEGATIVES
    D;JLE

    @R1
    D=M

    @NEGATIVES
    D;JLE

    @quotient
    M=0

    @R0
    D=M

    @temp
    M=D

    (LOOP)

    @temp
    D=M

    @tempremainder
    M=D

    @R1
    D=D-M

    @REMAINDER
    D;JLT

    @temp
    M=D

    @quotient
    M=M+1

    @FINISH
    D;JEQ

    @LOOP
    0;JMP
    
    (REMAINDER)
        @tempremainder
        D=M
        @R4
        M=D

        @quotient
        D=M

        @R3
        M=D

        @EXIT
        0;JMP

    (FINISH)
    @quotient
    D=M
    @R3
    M=D


    @EXIT
    0;JMP

    (NEGATIVES)
        @1024
        M=-1
        @EXIT
        0;JMP
(EXIT)
    @EXIT
    0;JMP


