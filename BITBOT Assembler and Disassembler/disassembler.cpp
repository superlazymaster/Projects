#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){


    map<string, string> opdict;
    
    opdict["0000"] = "ADD";
    opdict["0001"] = "ADDI";
    opdict["0010"] = "SUB";
    opdict["0011"] = "SUBI";
    opdict["010"] = "NAND";
    opdict["010"] = "NOR";
    opdict["1000"] = "READ";
    opdict["1010"] = "WRITE";
    opdict["1011"] = "JMP";
    opdict["1001"] = "BEQ";
    opdict["1110"] = "INP";
    opdict["1100"] = "OUT";


    map<string, string> regdict;

    regdict["000"] = "R0";
    regdict["001"] = "R1";
    regdict["010"] = "R2";
    regdict["011"] = "R3";
    regdict["100"] = "R4";
    regdict["101"] = "R5";
    regdict["110"] = "R6";
    regdict["111"] = "R7";

    map<string, string> numdict;

    numdict["000000"] = "0";
    numdict["000001"] = "1";
    numdict["000010"] = "2";
    numdict["000011"] = "3";
    numdict["000100"] = "4";
    numdict["000101"] = "5";
    numdict["000110"] = "6";
    numdict["000111"] = "7";
    numdict["001000"] = "8";
    numdict["001001"] = "9";
    numdict["001010"] = "10";
    numdict["001011"] = "11";
    numdict["001100"] = "12";
    numdict["001101"] = "13";
    numdict["001110"] = "14";
    numdict["001111"] = "15";
    numdict["010000"] = "16";
    numdict["010001"] = "17";
    numdict["010010"] = "18";
    numdict["010011"] = "19";
    numdict["010100"] = "20";
    numdict["010101"] = "21";
    numdict["010110"] = "22";
    numdict["010111"] = "23";
    numdict["011000"] = "24";
    numdict["011001"] = "25";
    numdict["011010"] = "26";
    numdict["011011"] = "27";
    numdict["011100"] = "28";
    numdict["011101"] = "29";
    numdict["011110"] = "30";
    numdict["011111"] = "31";
    numdict["100000"] = "32";
    numdict["100001"] = "33";
    numdict["100010"] = "34";
    numdict["100011"] = "35";
    numdict["100100"] = "36";
    numdict["100101"] = "37";
    numdict["100110"] = "38";
    numdict["100111"] = "39";
    numdict["101000"] = "40";
    numdict["101001"] = "41";  
    numdict["101010"] = "42";
    numdict["101011"] = "43";
    numdict["101100"] = "44";
    numdict["101101"] = "45";
    numdict["101110"] = "46";
    numdict["101111"] = "47";
    numdict["110000"] = "48";
    numdict["110001"] = "49";
    numdict["110010"] = "50";
    numdict["110011"] = "51";
    numdict["110100"] = "52";
    numdict["110101"] = "53";
    numdict["110110"] = "54";
    numdict["110111"] = "55";
    numdict["111000"] = "56";
    numdict["111001"] = "57";
    numdict["111010"] = "58";
    numdict["111011"] = "59";
    numdict["111100"] = "60";
    numdict["111101"] = "61";
    numdict["111110"] = "62";
    numdict["111111"] = "63";


    string x = "";
    int line = 1;
    while(getline(cin, x)){

        bool valid = true;
        for(int i=0; i<x.length(); i++){
            if(x[i]!='1' && x[i]!='0' && x[i]!='?' && x[i]!='*'){
                valid = false;
                cout<<"ERROR: line " << line << " (invalid operation)"<<endl;
                break;
            }
        }
        if (valid){
            int star_count=0;
            for(int i=0; i<x.size(); i++){
                if(x[i]=='*' or x[i]=='?'){
                    star_count++;
                }
            }
            if (star_count==4){
                string op = x.substr(0, 3);
                string dest = x.substr(3, 6);
                string r1 = x.substr(6, 9);
                string r2 = x.substr(9, 12);
                if(opdict[op]==""||regdict[dest]==""||regdict[r1]==""||regdict[r2]==""){
                    valid = false;
                    cout<<"ERROR: line " << line << " (invalid operation)";
                    continue;
                }
                cout<<opdict[op]<<" "<<opdict[dest]<<" "<<opdict[r1]<<" "<<opdict[r2]<<endl;
                continue;
            }
            else{
                string op = x.substr(0, 4);
                string r1=x.substr(4, 3);
                string r2=x.substr(7, 3);
                string r3=x.substr(10, 3);
                string r4=x.substr(13, 3);
                // cout<<op<<endl;
                // cout<<r1<<endl;
                // cout<<r2<<endl;
                // cout<<r3<<endl;
                // cout<<r4<<endl;
                if(opdict[op]==""){
                    valid = false;
                    cout<<"ERROR: line " << line << " (invalid operation)"<<endl;
                    continue;
                }
                else if(opdict[op] == "ADDI" || opdict[op] == "SUBI"){
                    string value = x.substr(10, 6);
                    cout<<opdict[op]<<" "<<regdict[r1]<<", "<<regdict[r2]<<", "<<numdict[value]<<endl;
                                line++;

                    continue;
                }
                if(regdict[r3]!=""){
                    cout<<opdict[op]<<" "<<regdict[r1]<<", "<<regdict[r2]<<", "<<regdict[r3]<<endl;
                                line++;

                    continue;
                }
                if(regdict[r2]!=""){
                    cout<<opdict[op]<<" "<<regdict[r1]<<", "<<regdict[r2]<<endl;
                                line++;

                    continue;
                }
                cout<<opdict[op]<<" "<<regdict[r1]<<endl;
                            line++;

                continue;
            }
        }
        break;
    }
}