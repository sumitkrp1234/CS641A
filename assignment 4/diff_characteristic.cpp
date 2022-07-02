#include <iostream>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
using BYTE = unsigned char;
using INT = unsigned int;

INT S[8][64] =
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
         0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
         4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
         15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},

        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
         3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
         0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
         13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},

        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
         13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
         13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
         1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},

        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
         13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
         10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
         3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},

        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
         14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
         4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
         11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},

        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
         10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
         9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
         4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},

        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
         13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
         1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
         6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},

        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
         1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
         7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
         2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};

INT Sbox_mapping[64] = {
    1, 17, 2, 18, 3, 19, 4, 20, 5, 21, 6, 22, 7, 23, 8, 24,
    9, 25, 10, 26, 11, 27, 12, 28, 13, 29, 14, 30, 15, 31, 16, 32,
    33, 49, 34, 50, 35, 51, 36, 52, 37, 53, 38, 54, 39, 55, 40, 56,
    41, 57, 42, 58, 43, 59, 44, 60, 45, 61, 46, 62, 47, 63, 48, 64};

// INITIAL PERMUTATION

INT IP_[] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7};

// REVERSE PERMUTATION
INT RFP[] = {
    8, 40, 16, 48, 24, 56, 32, 64,
    7, 39, 15, 47, 23, 55, 31, 63,
    6, 38, 14, 46, 22, 54, 30, 62,
    5, 37, 13, 45, 21, 53, 29, 61,
    4, 36, 12, 44, 20, 52, 28, 60,
    3, 35, 11, 43, 19, 51, 27, 59,
    2, 34, 10, 42, 18, 50, 26, 58,
    1, 33, 9, 41, 17, 49, 25, 57};

// E BIT_SELECTION TABLE
INT Ebit[] = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1};

// PERMUTATION FUNCTION P
INT P_[] = {
    16, 7, 20, 21,
    29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31, 10,
    2, 8, 24, 14,
    32, 27, 3, 9,
    19, 13, 30, 6,
    22, 11, 4, 25};

// Inverse of P
INT INV_P_[] = {
    9, 17, 23, 31,
    13, 28, 2, 18,
    24, 16, 30, 6,
    26, 20, 10, 1,
    8, 14, 25, 3,
    4, 29, 11, 19,
    32, 12, 22, 7,
    5, 27, 15, 21};

void from_hex_to_binary(string hex_str, int bin_digit[64])
{
    int hex_digit = 0;
    int i = 0;
    while (i < hex_str.size())
    {
        hex_digit = 0;
        if (hex_str[i] >= '0' && hex_str[i] <= '9')
        {
            hex_digit = hex_str[i] - '0';
        }
        else
        {
            if (hex_str[i] >= 'A' && hex_str[i] <= 'F')
            {
                hex_digit = hex_str[i] + 10 - 'A';
            }
        }
        for (int j = 0; j < 4; j++)
        {
            bin_digit[4 * i + j] = (hex_digit / int(pow(2, 3 - j))) % 2;
        }
        i++;
    }
}

void get_str(int binary_str[64], int L[32], int R[32])
{
    for (int i = 0; i < 64; i++)
    {
        if (i < 32)
        {
            L[i] = binary_str[i];
        }
        else
        {
            R[i - 32] = binary_str[i];
        }
    }
}

string hexa_conversion(const string hex_original)
{
    string hex_str;
    for (int i = 0; i < hex_original.size(); i++)
    {
        if (hex_original[i] - 'd' <= 9 && hex_original[i] - 'd' >= 0)
            hex_str.push_back(hex_original[i] - 'd' + '0');
        else if (hex_original[i] - 'd' <= 15 && hex_original[i] - 'd' >= 10)
            hex_str.push_back(hex_original[i] - 'd' + 'A' - 10);
    }
    return hex_str;
}

void Inv_Final_perm(int binary_str[64])
{
    vector<int> v;
    for (int i = 0; i < 64; i++)
    {
        v.push_back(binary_str[i]);
    }
    for (int i = 63; i >= 0; i--)
    {
        binary_str[RFP[i] - 1] = v[i];
    }
}

void bitwise_xor(const int A[], const int B[], int xor_str[], int size)
{
    for (int i = 0; i < size; i++)
    {
        xor_str[i] = (A[i] ^ B[i]);
    }
}

void E(int input[32], int inp_exp[48])
{
    for (int i = 0; i < 48; i++)
    {
        inp_exp[i] = input[Ebit[i] - 1];
    }
}

void partition(int input[], int part[], int input_size, int size_sbox)
{
    int count = 0;
    int temp = 1;
    int size = input_size / size_sbox;
    for (int i = 0; i < size_sbox; i++)
    {
        count = 0;
        temp = 1;
        for (int j = 0; j < size; j++)
        {
            count += input[size * (i + 1) - j - 1] * temp;
            temp = temp * 2;
        }
        part[i] = count;
    }
}

void invP(int binary_str[32])
{
    vector<int> v;
    for (int i = 0; i < 32; i++)
    {
        v.push_back(binary_str[i]);
    }
    for (int i = 0; i < 32; i++)
    {
        binary_str[i] = v[INV_P_[i] - 1];
    }
}

void decimal_to_bin(long long int x, int bin[], int size)
{
    for (int i = 0; i < size; i++)
        bin[i] = 0;
    for (int i = 0; i < size && x >= 0; i++)
    {
        bin[size - i - 1] = x % 2;
        x = x / 2;
    }
}

void output(const int bin[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << bin[i];
    }
    cout << endl;
}

int main(){
    for (int i = 1; i <= 2; i++){

        string index = to_string(i);
        string out1, out2;
        string char_in;
        int chrac[64];
        int left[32];
        int right[32];
        ll key_cnt[8][64];

        cout<<"Characteristic Index: "<<index<<endl;

        ifstream out("clean_output" + index + ".txt");
        ofstream key_text("key_dist" + index + ".txt"), key_6bit("key_6bit" + index + ".txt");

        if (index == "1")char_in = "4008000004000000";   
        else if(index == "2")char_in = "0020000800000400";
            
        from_hex_to_binary(char_in, chrac);
        get_str(chrac, left, right);

        
        for (int row = 0; row < 8; row++){
            for (int col = 0; col < 64; col++) key_cnt[row][col] = 0;
        }

        int cnt = 0, rep = 0;

        while (getline(out, out1)){
            getline(out, out2);

            int out_A[64], out_B[64];
            int out_XOR[64], left_XOR[32], right_XOR[32];
            int left_A[32], right_A[32];
            int left_B[32], right_B[32];
            int expansion_A[48], expansion_B[48], expansion_XOR[48];

            out1 = hexa_conversion(out1);
            out2 = hexa_conversion(out2);
            from_hex_to_binary(out1, out_A);
            from_hex_to_binary(out2, out_B);

            // inverse final permutation
            Inv_Final_perm(out_A);
            Inv_Final_perm(out_B);

            // get left and right halves of the ciphertexts
            get_str(out_A, left_A, right_A);
            get_str(out_B, left_B, right_B);

            // get XOR value of cihpertexts, along with left and right halves
            bitwise_xor(out_A, out_B, out_XOR, 64);
            get_str(out_XOR, left_XOR, right_XOR);

            // apply expansion to left half of output (right half of input to 5th round)
            E(left_A, expansion_A);
            E(left_B, expansion_B);
            bitwise_xor(expansion_A, expansion_B, expansion_XOR, 48);

            int alpha[8];
            int beta_xor[8], gamma_xor[8];
            partition(expansion_A, &alpha[0], 48, 8);
            partition(expansion_XOR, beta_xor, 48, 8);

            int Sbox_output[32];
            bitwise_xor(right_XOR, right, Sbox_output, 32);
            invP(Sbox_output);
            partition(Sbox_output, gamma_xor, 32, 8);

            int i = 0;
            while(i<8){
                int beta[2], sbox1, sbox2, key, j = 0;
                while(j<64){
                    beta[0] = j;
                    beta[1] = beta_xor[i]^beta[0];
                    sbox1 = S[i][Sbox_mapping[beta[0]]-1];
                    sbox2 = S[i][Sbox_mapping[beta[1]]-1];

                    if ((sbox1 ^ sbox2) == gamma_xor[i]){
                        key = alpha[i]^beta[0];
                        key_cnt[i][key]++;
                    }j++;
                    
                }i++;
                
            }rep++;
            
        }

        // output distribution of keys for further processing
        for (int i = 1; i <= 8; i++){
            key_text << "S" << i << "\t";
            for (int j = 0; j < 64; j++){
                key_text << setw(5) << key_cnt[i-1][j] << "  ";
            }
            key_text << "\n";
        }

        // get max key
        for (int i = 1; i <= 8; i++){
            int indice = -1, key_i[6];
            int maximum = -1e9;   
            double sum = 0.0;

            int j = 0;
            while(j<64){
                sum += key_cnt[i-1][j];
                if (maximum<key_cnt[i-1][j]){
                    maximum = key_cnt[i-1][j];
                    indice = j;
                    j++;
                }
                else j++;
                
            }
            decimal_to_bin(indice, key_i, 6);
            output(key_i, 6);

            cout << "S Box" << i  << "\t key_max = " << indice << " = ";
            cout << "frequency = " << maximum << "\t average = " << sum / 64.0 << endl;

            for (int k = 0; k < 6; k++){
                key_6bit << key_i[k];
            }
            key_6bit << endl;
        }
    }
    return 0;
}