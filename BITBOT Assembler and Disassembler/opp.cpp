#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string, string> dict = {};
    
    dict["ADD"] = "0000";
    dict["ADDI"] = "0001";
    dict["SUB"] = "0010";
    dict["SUBI"] = "0011";
    dict["NAND"] = "010*";
    dict["NOR"] = "011*";
    dict["READ"] = "1000";
    dict["WRITE"] = "1010";
    dict["JMP"]  = "1011";
    dict["BEQ"] = "1001";
    dict["INP"] = "1110";
    dict["OUT"] = "1100";
    
    string x = "";

    while(cin>>x){
        if (dict[x]!=""){
            cout<<dict[x]<<endl;
        }
    }
     
}
