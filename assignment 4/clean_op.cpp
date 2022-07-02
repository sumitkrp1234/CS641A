#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ofstream out; ifstream in;
    for(int i = 1; i <= 2; i++){
        string str;
        in.open("initial_output" + to_string(i) + ".txt");
        out.open("clean_output" + to_string(i) + ".txt");
        while(getline(in,str)){
            if(str.size()==19) out<<str.substr(2,19)<<endl;
        }
        in.close(); out.close();    
    }
    return 0;
}
