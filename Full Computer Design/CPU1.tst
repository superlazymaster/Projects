load CPU.hdl,
output-file CPU2.out,
output-list time%S0.4.0 fromM%D0.16.0 In%B0.26.0 Reset%B2.1.2 toM%D1.16.0 writeM%B3.1.3 addressM%D0.16.0 PCOut%D0.16.0;

set In %B0001000001111111, // ADDI R0, R1, 63
tick, output, tock, output;
//R0 now contains 63

// lets say R1 contains 32767, R2 contains -32768, and R3 contains -32767

// 32767+1
set In %B0001100001000001, // ADDI R4, R1, 1
tick, output, tock, output;
//R4 now contains -32768



// -32768 - 1
set In %B0011101010000001, // SUBI R5, R2, 1
tick, output, tock, output;
//R5 now contains 32767

//  32767 + -32768
set In %B0000110001010111, // ADD R6, R1, R2
tick, output, tock, output;
//R6 now contains -1

// 32767 + (-32767)
set In %B0000111001011111, // ADD R7, R1, R3
tick, output, tock, output;
//R7 now contains -1

// lets say R7 contains 32767 and R8 contains 

set In %B1010100100111111, // WRITE R0, R1
tick, output, tock, output;
//MEM[R0] = R1 I.e. MEM[7] = 7