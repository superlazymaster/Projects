load CPU.hdl,
output-file CPU2.out,
compare-to CPU2.cmp,
output-list time%S0.4.0 fromM%D0.16.0 In%B0.26.0 Reset%B2.1.2 toM%D1.16.0 writeM%B3.1.3 addressM%D0.16.0 PCOut%D0.16.0;

set In %B0001000001000111, // ADDI R0, R1, 7
tick, output, tock, output;

set In %B0000001000000111, // ADD R1, R0, R0
tick, output, tock, output;

set In %B1010000001111111, // WRITE R0, R1
tick, output, tock, output;

set fromM %D14,
set In %B1000110000111111, // READ R6, R0
tick, output, tock, output;

set In %B0010001110000111, // SUB R1, R6, R0
tick, output, tock, output;

set In %B1010000001111111, // WRITE R0, R1
tick, output, tock, output;

set fromM %D7,
set In %B1000110000111111, // READ R6, R0
tick, output, tock, output;

set In %B0011001110000111, // SUBI R1, R6, 7
tick, output, tock, output;

set In %B1010000001111111, // WRITE R0, R1
tick, output, tock, output;

set In %B0101001001001111, // NAND R1, R1, R1
tick, output, tock, output;

set In %B1010000001111111, // WRITE R0, R1
tick, output, tock, output;

set In %B0111001001001111, // NOR R1, R1, R1
tick, output, tock, output;

set In %B1010000001111111, // WRITE R0, R1
tick, output, tock, output;

set fromM %D221,
set In %B1000001100000011, // READ R1, R4
tick, output, tock, output;

set fromM %D0,
set In %B1000011010000011, // READ R3, R2
tick, output, tock, output;

set In %B1001001011000111, // BEQ R1, R3
tick, output, tock, output;

set In %B1001011001000111, // BEQ R3, R1
tick, output, tock, output;

set fromM %D312,
set In %B1000101101000011, // READ R5, R5
tick, output, tock, output;

set In %B1011101000000000, // JMP R5
tick, output, tock, output;

set fromM -32768,
set In %B1000000111000000,
tick, output, tock, output;

set In %B1100000000000000, // OUT r0, r0
tick, output, tock, output;

set In %B1110110000000000, // INP R6
set fromM 65,
tick, output, tock, output;

set In %B1010110110000000, // WRITE R6, R6
tick, output, tock, output;

set In %B0000000000000000,
set Reset 1, // RESET
tick, tock, output;
