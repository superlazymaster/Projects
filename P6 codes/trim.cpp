#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string x = "";
    
    while (getline(cin, x)){

        // get rid of comments
        string new_str = "";
        int comment_index = x.find("//");
        string nocomment_str = x.substr(0, comment_index);
        

        
        string no_beginning_whitespace = "";
        for(int i=0; i<nocomment_str.length(); i++){
            if(nocomment_str[i]!=' '){
                no_beginning_whitespace += nocomment_str.substr(i, nocomment_str.length());
                break;
            }
            continue;
        }
        
        int space_count = 0;
        string no_between_spaces = "";
        // get rid of in between space
        for(int i=0; i<no_beginning_whitespace.length(); i++){
            if(space_count>0&&no_beginning_whitespace[i]==' '){
                continue;
            }
            else if(space_count==0&&no_beginning_whitespace[i]==' '){
                space_count++;
                no_between_spaces+=no_beginning_whitespace[i];
            }
            else{
                no_between_spaces+=no_beginning_whitespace[i];
                space_count=0;
            }
        }

        string no_trailing = "";
        
        for(int i=0; i<no_between_spaces.length(); i++){
            if(no_between_spaces[i]==' '){
                if(i+1>=no_between_spaces.length()){
                    continue;
                }
                else if(no_between_spaces[i+1]==' '){
                    break;
                }
                else{
                    no_trailing += no_between_spaces[i];
                }
            }
            else{
                no_trailing += no_between_spaces[i];
            }
        }
        
        if(no_trailing!=""){
            cout<<'"'<<no_trailing<<'"'<<endl;
        }
    }
    
    
    return 0;
}
