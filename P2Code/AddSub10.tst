//Starter Test stimulus file for AddSub10 

load AddSub10.hdl,
output-file AddSub10.out,
compare-to AddSub10.cmp,
output-list a%B1.10.1 b%B1.10.1 sub%B1.1.1 out%B1.10.1 overflow%B4.1.4;

set a %B0000010001;
set b %B1111101111;
set sub 0;
eval;
output;

set a %B0000010001;
set b %B1111101111;
set sub 1;
eval;
output;

set a %B1100010001;
set b %B0111101111;
set sub 0;
eval;
output;

set a %B0000010110;
set b %B1111101011;
set sub 1;
eval;
output;

set a %B0001110010;
set b %B1111110100;
set sub 0;
eval;
output;