#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

using namespace std;
using INT = unsigned int;

INT IP[] = {
  58,50,42, 34,26,18,10,2,
  60,52,44,36,28,20,12,4,
  62,54, 46, 38, 30, 22, 14,6,
  64, 56, 48, 40,32,24, 16, 8,
  57, 49, 41, 33,25,17, 9,1,
  59, 51,43,35,27,19,11,3,
  61,53,45,37,29,21,13, 5,
  63,55, 47,39,31,23,15,7
};

/* REVERSE PERMUTATION (RFP) */

INT RFP[] = {
  8,40,16,48,24,56,32,64,
  7, 39,15,47,23,55,31,63,
  6,38,14,46,22,54,30,62,
  5,37,13,45, 21,53,29,61,
  4,36,12,44,20,52,28,60,
  3, 35, 11,43,19,51,27,59,
  2, 34, 10, 42,18, 50,26,58,
  1,33,9,41, 17, 49, 25,57
};

void from_hex_to_binary(string hex_str, int bin_digit[64]){
    int hex_digit = 0;
    int i = 0;
    while(i<hex_str.size()){
        hex_digit = 0;
        if(hex_str[i] >= '0' && hex_str[i] <= '9'){hex_digit = hex_str[i] - '0';}    
        else{
            if(hex_str[i] >= 'A' && hex_str[i] <= 'F'){hex_digit = hex_str[i] +10 - 'A';}    
        } 
        for(int j =0;j<4;j++){
            bin_digit[4*i+j] = (hex_digit/int(pow(2,3-j)))%2;
        }
        i++;
    }
}


void from_binary_to_hexa(string &hex_str,int bin_digit[64]){
    int digit = 0;
    // Resize the hex_str to size of 16 if not already
    hex_str.resize(16);
    int i = 0;
    while(i<16){
        digit = 0;
        for(int j = 0;j<4;j++){
            digit += int(pow(2,3-j))*bin_digit[4*i+j];
        }

        if(digit <= 9 && digit >= 0)hex_str[i] = '0' + digit;   
        else{
            if(digit <= 15 && digit >= 10)hex_str[i] = digit -10+'A';      
        } 
        i++;
    }
}


string hexa_conversion(const string hex_original){
    string hex_str;
    for(int i = 0; i < hex_original.size(); i++){
        if(hex_original[i] >= '0' && hex_original[i] <= '9')hex_str.push_back(hex_original[i] + 'd'- '0' );   
        else if(hex_original[i] >= 'A' && hex_original[i] <= 'F')hex_str.push_back(hex_original[i] + 'd' + 10 - 'A' );      
    }
    return hex_str;
}

void decimal_to_bin(long long int x, int bin[], int size){
    for(int i = 0; i < size; i++)bin[i] = 0;
    for(int i = 0; i < size && x >= 0; i++){
        bin[size - i - 1] = x%2;
        x = x/2;
    }
}

void inv_Initial_perm(int binary_str[64]){
    vector<int> v;
    for(int i = 0; i < 64; i++){
        v.push_back(binary_str[i]);
    }
    for(int i = 63; i >= 0; i--){
        binary_str[IP[i]-1] = v[i];
    }
}

// Saves A xor B in result (all in binary)
void bitwise_xor(const int A[], const int B[], int xor_str[], int size){
    for(int i = 0; i < size; i++){
        xor_str[i] = (A[i]^B[i]);
    }
}

int main(){

    int char_1[64], char_2[64];
    int ipt_1[64], ipt_2[64], ipt_3[64];
    string characteristic_1 = "4008000004000000", characteristic_2 = "0020000800000400";
    string input, input1, input2;
    ofstream fi1("input_1.txt"), fi2("input_2.txt");
    
    from_hex_to_binary(characteristic_1, char_1);
    from_hex_to_binary(characteristic_2, char_2);

    // Generating random input string pairs for each characteristic
    for(int i = 0; i < 512; i++){
        decimal_to_bin(int(pow(i,3)), ipt_1,64);

        // Find required pair such that xor with above input is the characteristic
        bitwise_xor(ipt_1, char_1, ipt_2,64);
        bitwise_xor(ipt_1, char_2, ipt_3,64);

        // inverse initial permutation
        inv_Initial_perm(ipt_1);
        inv_Initial_perm(ipt_2); 
        inv_Initial_perm(ipt_3);

        // binary to hexadecimal conversion
        from_binary_to_hexa(input, ipt_1);
        from_binary_to_hexa(input1, ipt_2);
        from_binary_to_hexa(input2, ipt_3);

        // convertion to special hexadecimal
        fi1 << hexa_conversion(input) << endl;
        fi1 << hexa_conversion(input1) << endl;
        fi2 << hexa_conversion(input) << endl;
        fi2 << hexa_conversion(input2) << endl;
    }

    fi1.close();
    fi2.close();

    return 0;
}
