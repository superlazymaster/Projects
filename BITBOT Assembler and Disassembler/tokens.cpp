#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    string x = "";
    
    while(getline(cin, x)){
        vector<string> list;
        string temp_string = "";
        for(int i=0; i<x.length(); i++){
            if(x[i]==' '){
                list.push_back(temp_string);
                temp_string = "";
                continue;
            }
            temp_string += x[i];
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
                string output_string = "";
                output_string += list[0] + " ";
                for(int i=1; i<list.size()-1; i++){
                    list[i].erase(list[i].begin()+list[i].find(","));
                    output_string += list[i] + " ";
                }
                output_string += list[list.size()-1];

                cout<<output_string<<endl;
        }
    }

    return 0;
}