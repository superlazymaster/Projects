load Computer.hdl,
output-file CPUOverflowtest.out,
output-list time%S0.4.0 fromM%D0.16.0 In%B0.26.0 Reset%B2.1.2 toM%D1.16.0 writeM%B3.1.3 addressM%D0.16.0 PCOut%D0.16.0 RAM32K[1]%D1.7.1  RAM32K[2]%D1.7.1  RAM32K[3]%D1.7.1 RAM32K[4]%D1.7.1 RAM32K[5]%D1.7.1 RAM32K[6]%D1.7.1 RAM32K[7]%D1.7.1;

// Load a program written in the BITBOT machine language.
// The program multiplies two numbers at RAM[0] and RAM[1] and 
// outputs the result in RAM[2].
ROM32K load CPUOverflowtest.hack,

// Perform the Multiplication
set RAM32K[1] 32767,
set RAM32K[2] -32768,
set RAM32K[3] -32767,
output;

repeat 1000000 {
    tick, output, tock, output;
}
