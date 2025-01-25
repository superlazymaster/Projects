#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string trim(string input) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int comment_index = input.find("//");
        string nocomment_str = input.substr(0, comment_index);
        
        string no_beginning_whitespace = "";
        for(int i=0; i<nocomment_str.length(); i++){
            if(nocomment_str[i]!=' '){
                no_beginning_whitespace += nocomment_str.substr(i, nocomment_str.length());
                break;
            }
            continue;
        }

        string no_trailing = "";
        
        for(int i=0; i<no_beginning_whitespace.length(); i++){
            if(no_beginning_whitespace[i]==' '){
                if(i+1>=no_beginning_whitespace.length()){
                    continue;
                }
                else if(no_beginning_whitespace[i+1]==' '){
                    break;
                }
                else{
                    no_trailing += no_beginning_whitespace[i];
                }
            }
            else{
                no_trailing += no_beginning_whitespace[i];
            }
        }
        
        if(no_trailing!=""){
            return no_trailing;
        }
        return "";
}

string tokens(string input){
    vector<string> list;
    string temp_string = "";
    for(int i=0; i<input.length(); i++){
        if(input[i]==' '){
            list.push_back(temp_string);
            temp_string = "";
            continue;
        }
        temp_string += input[i];
    }
    list.push_back(temp_string);
    bool valid = true;
    for(int i=0; i<list.size(); i++){
        if(i==0 && list[i].find(",")!=-1){
            valid = false;
            break;
        }
        else if(i>0 && i<list.size()-1 && list[i].find(",")==-1){
            valid = false;
            break;
        }
        else if(i<list.size()-1 && list[i].find_first_of(",")!=list[i].find_last_of(",")){
            valid = false;
            break;
        }
        else if(i==list.size()-1 && list[i].find(",")!=-1){
            valid = false;
            break;
        }
    }
    if(valid){
        if((list[0] == "BEQ" && list.size()!=3)||(list[0]=="WRITE"&&list.size()>3)){
            return "invalid arguments";
        }
        string output_string = "";
        output_string += list[0] + " ";
        for(int i=1; i<list.size()-1; i++){
            list[i].erase(list[i].begin()+list[i].find(","));
            output_string += list[i] + " ";
        }
        output_string += list[list.size()-1];

        return output_string;
    }
    return "";
}

string opp(string input){
    map<string, string> dict;
    
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
    dict["R0"] = "000";
    dict["R1"] = "001";
    dict["R2"] = "010";
    dict["R3"] = "011";
    dict["R4"] = "100";
    dict["R5"] = "101";
    dict["R6"] = "110";
    dict["R7"] = "111";
    dict["0"] = "000000";
    dict["1"] = "000001";
    dict["2"] = "000010";
    dict["3"] = "000011";
    dict["4"] = "000100";
    dict["5"] = "000101";
    dict["6"] = "000110";
    dict["7"] = "000111";
    dict["8"] = "001000";
    dict["9"] = "001001";
    dict["10"] = "001010";
    dict["11"] = "001011";
    dict["12"] = "001100";
    dict["13"] = "001101";
    dict["14"] = "001110";
    dict["15"] = "001111";
    dict["16"] = "010000";
    dict["17"] = "010001";
    dict["18"] = "010010";
    dict["19"] = "010011";
    dict["20"] = "010100";
    dict["21"] = "010101";
    dict["22"] = "010110";
    dict["23"] = "010111";
    dict["24"] = "011000";
    dict["25"] = "011001";
    dict["26"] = "011010";
    dict["27"] = "011011";
    dict["28"] = "011100";
    dict["29"] = "011101";
    dict["30"] = "011110";
    dict["31"] = "011111";
    dict["32"] = "100000";
    dict["33"] = "100001";
    dict["34"] = "100010";
    dict["35"] = "100011";
    dict["36"] = "100100";
    dict["37"] = "100101";
    dict["38"] = "100110";
    dict["39"] = "100111";
    dict["40"] = "101000";
    dict["41"] = "101001";
    dict["42"] = "101010";
    dict["43"] = "101011";
    dict["44"] = "101100";
    dict["45"] = "101101";
    dict["46"] = "101110";
    dict["47"] = "101111";
    dict["48"] = "110000";
    dict["49"] = "110001";
    dict["50"] = "110010";
    dict["51"] = "110011";
    dict["52"] = "110100";
    dict["53"] = "110101";
    dict["54"] = "110110";
    dict["55"] = "110111";
    dict["56"] = "111000";
    dict["57"] = "111001";
    dict["58"] = "111010";
    dict["59"] = "111011";
    dict["60"] = "111100";
    dict["61"] = "111101";
    dict["62"] = "111110";
    dict["63"] = "111111";
    return dict[input];
}


int main(){
    string input = "";
    int line_number = 1;
    while(getline(cin, input)){
        string trimmed = trim(input);
        // cout<<trimmed<<endl;
        if (trimmed == ""){
            line_number++;
            continue;
        }

        string tokens_string = tokens(trimmed);
        // cout<<tokens_string<<endl;
        if(tokens_string == "invalid arguments"){
            cout<<"ERROR: line "<<line_number<<" (invalid argument)"<<endl;
            break;
        }
        if (tokens_string == ""){
            cout<<"ERROR: line "<<line_number<<" (invalid syntax)"<<endl;
            break;
        }
        string temp_string = "";
        string final_string = "";
        bool valid = true;
        // cout<<"Tokens: "<<tokens_string<<endl;
        for (int i=0; i<tokens_string.length(); i++){
            if(tokens_string[i] == ' '){
                string op_string = opp(temp_string);
                // cout<<"Temp: "<<temp_string<<endl;
                // cout<<"Op: "<<op_string<<endl;
                if(op_string == ""){
                    cout<<"ERROR: line "<<line_number<<" (invalid operation)"<<endl;
                    valid = false;
                    break;
                }
                else{
                    final_string += op_string;
                    // cout<<final_string<<endl;
                    temp_string = "";
                }
            }
            else{
                temp_string += tokens_string[i];
            }
        }
        if (!valid){
            break;
        }
        // cout<<temp_string;
        string op_string = opp(temp_string);
        // cout<<"Temp: "<<temp_string<<endl;
        // cout<<"Op: "<<op_string<<endl;
        if(op_string == ""){
            cout<<"ERROR: line "<<line_number<<" (invalid syntax)"<<endl;
            break;
        }
        else{
            final_string += op_string;
        }
        int count = 16-final_string.length();
        if(final_string.length()<16){
            for(int i=0; i<count; i++){
                final_string += "*";
                // cout<<final_string<<endl;
            }
        }
        cout<<final_string<<endl;
        line_number++;
    }
    return 0;
}


