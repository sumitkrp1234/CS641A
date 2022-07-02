#include <bits/stdc++.h>
#include <fstream>
using namespace std;

string convertpair_original(vector<int> &vec){
    // converts to the string in the alphabet system pairwise as given in the assignment
    char frst,scnd;
    string str_inp(16,'f');
    int i=0;

    while(i<8){
        frst = (vec[i] >> 4) +'f';
        str_inp[2*i] = frst;
        char scnd_and = (15 & vec[i]); 
        scnd = scnd_and +'f';
        str_inp[2*i+1] = scnd;
        i++;
    }
    return str_inp;
}

vector<int> convertpair(string text){
    vector<int> v;
    int i=0;
    while(i<8){
        v.push_back(0);
        i++;
    }
    // covert pairwise
    i=0;
    while(i<8){
        int frst = text[2*i]-'f';     // first character of pair 
        frst= frst<<4;               // left shift by 4 posiitons so that this cab bed added to b to get final value
        int secnd = text[2*i+1]-'f'; //second character of pair
        v[i] = frst + secnd;
        i++;           
    }

    return v;
}

void fetch_inp(char *argv[], int argc){
    int itr=0;
    vector<int> str1;
    int i=0;
    while(i<8){
        str1.push_back(0);
        i++;
    }

    if (argc <= 2) {
        itr = 0; i = 0;
        while(i<8){
            str1[i]=0; i++;
        }
    }
    else{
        itr = stoi(string(argv[1]))-1;
        int diff=16-2*(itr);
        string append_zero;
        i=0;
        while(i<diff){
            append_zero.push_back('f');
            i++;
        }
        string final_string=string(argv[2])+append_zero;
        str1 = convertpair(final_string);
    }
    string inputfile = "./inputs/inputs" + to_string(itr + 1) + ".txt";
    ofstream out(inputfile);
    i=0;
    while(i<128){
        string iBlock1;
        str1[itr] = i;
        iBlock1 = convertpair_original(str1);
        out << iBlock1 << endl;
        i++;
    }
}

int main(int argc, char *argv[]){
    fetch_inp(argv, argc);              // call fetch_inp function to generate the input files


    return 0;
}