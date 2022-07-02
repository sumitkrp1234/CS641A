#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

string convertpair(string text){
    string arr(text.length()/2 ,'f');       //intialize arr
    int i = 0;
    while(i<text.length()/2){               // convert pairwise
        int frst = text[2*i]-'f';
        frst=(frst<<4);                     //left shift by 4 positions
        int scnd = text[2*i+1]-'f';
        arr[i]=frst+scnd;              
        i++;
    }
    return arr;
}

int main(int argc, char* argv[]){
    string inp_str = string(argv[1]);
    string str;
    int i=0;
    str=convertpair(inp_str);
    while(i< inp_str.size()/2){
        cout<<str[i];
        i++;
    }
    cout << endl;
    cout<<"The password is:";
    for(int i=0;i<inp_str.size()/2 && str[i]!='0';i++){
	    cout<<str[i];
    }
    cout <<endl;
    return 0;
}
