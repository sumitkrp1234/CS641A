#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
#include<vector>

using namespace std;
using BYTE = unsigned char;
using INT = unsigned int;

INT S[8][64]=
{
  {14, 4, 13, 1, 2, 15, 11, 8, 3 , 10, 6, 12, 5, 9, 0, 7,
  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
  4, 1 , 14, 8, 13, 6, 2, 11, 15, 12, 9, 7,3, 10, 5, 0,
  15, 12, 8,2,4, 9, 1,7 , 5, 11, 3, 14, 10, 0, 6, 13},
  
  {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0,5, 10,
  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
  0, 14, 7, 11, 10, 4, 13, 1, 5, 8,12, 6, 9, 3, 2, 15,
  13, 8, 10, 1, 3, 15, 4, 2,11,6, 7, 12, 0,5, 14, 9},
  
  {10, 0, 9,14,6,3,15,5, 1, 13, 12, 7, 11, 4,2,8,
  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12,5, 10, 14, 7,
  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},
  
  {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
  10, 6, 9, 0, 12, 11, 7, 13, 15, 1 , 3, 14, 5, 2, 8, 4, 
  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
    
  {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 
  14, 11,2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 
  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 
  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}, 
    
  {12, 1, 10, 15, 9, 2, 6,8, 0, 13, 3, 4, 14, 7, 5, 11, 
  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 
  9, 14, 15, 5, 2,8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 
  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}, 
  
  {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 
  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
  
  {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12,7, 
  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 
  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 
  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};


/* PERMUTED CHOICE  PC1 */
INT PC1[] = {
  57, 49, 41, 33, 25, 17, 9,
  1, 58, 50, 42, 34, 26, 18,
  10,  2, 59, 51, 43, 35, 27,
  19, 11,  3, 60, 52, 44, 36,
  63, 55, 47, 39, 31, 23, 15, 
  7, 62, 54, 46, 38, 30, 22, 
  14,  6, 61, 53, 45, 37, 29, 
  21, 13,  5, 28, 20, 12,  4
};

// REVERSE PERMUTATION
INT RFP[] = {
  8, 40, 16, 48, 24, 56, 32, 64,
  7, 39, 15, 47, 23, 55, 31, 63,
  6, 38, 14, 46, 22, 54, 30, 62,
  5, 37, 13, 45, 21, 53, 29, 61,
  4, 36, 12, 44, 20, 52, 28, 60,
  3, 35, 11, 43, 19, 51, 27, 59,
  2, 34, 10, 42, 18, 50, 26, 58,
  1, 33, 9,  41, 17, 49, 25, 57
};


unsigned short shifts[] = {
1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

/* PERMUTED CHOICE 2 (PC2) */
INT PC2[] = {
  14, 17, 11, 24,  1, 5, 
  3, 28 ,15,  6, 21, 10, 
  23, 19, 12,  4, 26, 8, 
  16,  7, 27, 20, 13, 2, 
  41, 52, 31, 37, 47, 55, 
  30, 40, 51, 45, 33, 48, 
  44, 49, 39, 56, 34, 53, 
  46, 42, 50, 36, 29, 32
};

INT IP[] = {
  58, 50, 42, 34, 26, 18, 10, 2,
  60, 52, 44, 36, 28, 20, 12, 4,
  62, 54, 46, 38, 30, 22, 14, 6,
  64, 56, 48, 40, 32, 24, 16, 8,
  57, 49, 41, 33, 25, 17, 9,  1,
  59, 51, 43, 35, 27, 19, 11, 3,
  61, 53, 45, 37, 29, 21, 13, 5,
  63, 55, 47, 39, 31, 23, 15, 7
};

// E BIT_SELECTION TABLE 
INT Ebit[] = {
  32, 1, 2, 3, 4, 5,
  4,  5, 6, 7, 8, 9,
  8,  9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17, 
  16, 17, 18, 19, 20, 21, 
  20, 21, 22, 23, 24, 25, 
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32, 1
};

// PERMUTATION FUNCTION P 
INT P[] = {
  16, 7, 20, 21, 
  29, 12, 28, 17,
  1, 15, 23, 26,
  5, 18, 31,10,
  2, 8, 24, 14,
  32, 27, 3, 9,
  19, 13, 30, 6,
  22, 11, 4, 25
};

// Inverse of P
INT INV_P_[] = {
	9, 17, 23, 31,
	13, 28, 2, 18,
	24, 16, 30, 6,
	26, 20, 10, 1,
	8, 14, 25, 3,
	4, 29, 11, 19,
	32, 12, 22, 7,
	5, 27, 15, 21
};

string hexa_conversion(const string hex_original){
    string hex_str;
    for(int i = 0; i < hex_original.size(); i++){
        if(hex_original[i] - 'd' <= 9 && hex_original[i] - 'd' >= 0)
            hex_str.push_back(hex_original[i] - 'd' + '0');
        else if(hex_original[i] - 'd' <= 15 && hex_original[i] - 'd' >= 10)
            hex_str.push_back(hex_original[i] - 'd' + 'A' - 10);
    }
    return hex_str;
}

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

/* Key Scedule of 16 48-bit subkey generated from 64-bit key */
BYTE KS[16][48];

void set_the_key(int sw1, BYTE *key, int r)
{
    register INT i, j, k, t1, t2;
    static BYTE CD[56];

    /* permute unpacked key with PC1 to generate C and D*/
    for (i=0; i<56; i++) {
    CD[i] = key[PC1[i] -1];
    }
    
    /* Rotate and permute C and D to generate 16 subkeys */
    for (i = 0; i < r; i++) {
        /* Rotate C and D */
        for (j = 0; j < shifts[i]; j++)
        {
            t1 = CD[0];
            t2 = CD[28];
            for (k = 0; k < 27; k++){
                CD[k] = CD[k+1];
                CD[k+28] = CD[k+29];
            }
            CD[27] = t1;
            CD[55] = t2;
        }
        /* Set the order of subkeys for type of encryption */
        j = sw1 ? r - 1 - i : i;

        /* Permute C and D with PC2 to generate KS[i] */
        for (k = 0; k < 48; k++)
            KS[j][k] = CD[PC2[k] - 1];
    }

    return;
}


/********************************************************************
 *UNPACK8()  Unpack 8 bytes at 8bits/byte into 64 bytes at 1 bit/byte
 ********************************************************************/

void unpack8(BYTE *packed, BYTE *binary)
    /* BYTE *packed;
     BYTE *binary;*/
{
  register INT i, j, k;

  for (i=0; i<8; i++) {
    k = *packed++;
    for (j=0; j<8;j++) *binary++ = (k>>(7-j)) &01 ;
  }
}

/********************************************************************
 *PACK8() Pack 64 bytes at 1 bits/byte into 8 bytes at 8 bit/byte
 ********************************************************************/

void pack8(BYTE *packed,BYTE *binary)
   /*  BYTE *packed;
     BYTE *binary;*/
{
  register INT i, j, k;

  for (i=0; i<8; i++) {
    k = 0;
    for (j=0; j<8;j++) k  = (k<<1)+ *binary++;
    *packed++ = k;
  }
}

/****************************************************************
		       DES
****************************************************************/


void des(BYTE *in,BYTE *out,INT r,char flag)
    /* BYTE *in;              /* packed 64 bit Input block */
    // BYTE *out;             /* packed 64 bit output block */
    // INT r;                                  /* number of rounds */
	// char flag;
{
  	register INT i, j, k, t;
  	static BYTE block[64]; /* unpacked 64-bit input/output block */
  	static BYTE LR[64], f[32], preS[48];

  	/* Unpack the INPUT block */
   	unpack8(in, block);

  	/* Permute unpacked input block with IP to generate L and R */
  	/*
    	printf("\nThe block after the initial permutation IP \n");
  	*/
   	for (j =0; j<64 ; j++){
        LR[j] = block[IP[j] -1];
        /*printf("%d", LR[j]);*/
    }

    /* Perform r rounds */
    /*
    printf(" In des 3rd round expandes block is \n");
    */

    for (i=0; i<r; i++) {  /**--*/
      		/* expand R to 48 bits with E and XOR  with ith subkey */
	  	for( j=0; j<48; j++) {
	    	preS[j] = LR[Ebit[j]+31]^KS[i][j];
	    }
	  	/* Map 8 6-bit blocks into 8 4-bit bolcks using S-boxes */
	  	for (j=0; j<8; j++) {
	    	/* Compute index t into jth s box */
	    	k= 6*j;
	    	t= preS[k];
	    	t = (t<<1) | preS[k+5];
	    	t = (t<<1)| preS[k+1];
	    	t = (t<<1)| preS[k+2];
	    	t = (t<<1)| preS[k+3];
	    	t = (t<<1)| preS[k+4];
	    	/* fetch t th entry fron jth sbox */
	    		t = S[j][t];
	    	/* generate 4-bit block from s-box entry */
	    	k= 4*j;
	    	f[k] = (t>>3)&1;
	    	f[k+1] = (t >> 2) & 1;
	    	f[k+2] = (t >> 1) & 1;
	    	f[k+3] = t &1;

	  	}


	 	for (j=0; j <32; j++) {
	    	/* Copy R */
	    	t = LR[j+32];
	    	/* Permute Permute f w/ P and XOR w/ L to generate new R*/
			if (flag == 'N')
	    		LR[j+32] = LR[j]^f[P[j] -1];
			else
	    		LR[j+32] = LR[j]^f[INV_P_[j] -1];
	    	/*LR[j+32] = LR[j]^f[j];*/
	    	/* copy original R to new L */
	    	LR[j] =t;
	  	}
	}

    /* Permute L and R with reverse IP-1 to generate output block*/
    for (j=0; j < 64; j++) block [j] = LR[RFP[j]-1];
        /* Pack data into 8 bits per byte */

    pack8(out, block);
	out[8] = '\0';

}
/******************************************************
                       DES ENDS
*******************************************************/



int main(){
	// Only 8th segment of key_6 is unknown 
	string key6th_round = "";
	ifstream key6_1("key_6bit1.txt"), key6_2("key_6bit2.txt");
	vector<string> key6_i1(8,""), key6_i2(8,"");
	int key_6[] = {3,44,27,17,42,10,26,50,60,2,
					41,35,25,57,19,18,1,51,52,
					59,58,49,11,34,13,23,30,45,
					63,62,38,21,31,12,14,55,20,
					47,29,54,6,15,4,5,39,53,46,22};
	int i = 0;
	while(i<8){
		getline(key6_1, key6_i1[i]);getline(key6_2, key6_i2[i]);
		i++;
	}
	i = 1;
	while(i<=8){//Since 8th segment is unknown
		if(i != 8) key6th_round += key6_i1[i-1];		
		else if(i == 8) key6th_round += "xxxxxx";	
		i++;
	}

	char required_key[65];
	i = 0;
	while(i<64){required_key[i] = 'x';i++;}
	i = 0;
	while(i<48){required_key[key_6[i]-1] = key6th_round[i];i++;}	
	i = 0;
	while(i<8){required_key[8*i+7] = '0';i++;}
	required_key[64] = '\0';
	
	// 14 unknown bits
	int count = 0;
	int unknown_bits[14];
	i = 0;
	while(i<64){
		if(required_key[i]=='x'){
			unknown_bits[count]=i;
			count++;
		}
		i++;
	}
	

	//BRUTE FORCE 
	BYTE key_i[64];
	BYTE DES_KEY[64];
	BYTE plaintext[9], ciphertext[9], cipherout[9];
	int input_binary[64], output_binary[64];
	
	string plaintxt_inp = "dddddddddddddddd";
	string ciphertxt_out="mikqgokjkegijmhe";

	plaintxt_inp = hexa_conversion(plaintxt_inp);
	ciphertxt_out = hexa_conversion(ciphertxt_out);

	
	
	from_hex_to_binary(plaintxt_inp, input_binary);
	from_hex_to_binary(ciphertxt_out, output_binary);
	i = 0;
	int mul_2, input_dec, out_dec; 
	while(i<8){	
		mul_2=1;
		out_dec=0;
		input_dec=0;
		for(int j=0; j<8; j++){
			out_dec = out_dec + output_binary[8*i-j+7]*mul_2;
			input_dec = input_dec + input_binary[8*i-j+7]*mul_2;
			mul_2 = mul_2*2;
		}
		plaintext[i] = input_dec;
		ciphertext[i] = out_dec;
		i++;
	}
	plaintext[8]='\0';ciphertext[8]='\0';
	
	//*********************** KEY BRUTE FORCE LOOP **********************//
	int k = 0;
	while(k<16384){
		mul_2 = 1;
		count = 13;
		while(count>=0){
			required_key[unknown_bits[count]] = (k/mul_2)%2 +48 ;
			mul_2 = mul_2*2;
			count--;
		}
		// converting char to int
		for(int i=0; i<64; i++){	
			key_i[i] = required_key[i] - 48;
		}

		set_the_key(0, key_i, 6);
		des(plaintext, cipherout, 6, 'N');

		bool flag = true;
		for(int i=0; i<8; i++){
			if(int(ciphertext[i]) !=int(cipherout[i])) flag = 0;
		}

		if(flag == true){
			cout << "The DES KEY is computed as follows : ";
			i = 0;
			while(i<64){
				DES_KEY[i] = key_i[i];
				cout << int(DES_KEY[i]);
				i++;
			}cout << endl;		
		}k++;	
	}

	// Final Decryption using the DES key
	int input1_bin[64], input2_bin[64];
	int input1_decimal, input2_decimal;
	BYTE plaintext_1[9], plaintext_2[9], cipherout_1[9], cipherout_2[9];
	string input1="iqknjkdljjegrjhj";
	string input2="qnnegkrpdrejkqrr";

	input1 = hexa_conversion(input1);
	input2 = hexa_conversion(input2);
	
	from_hex_to_binary(input1, input1_bin);
	from_hex_to_binary(input2, input2_bin);
	i = 0;
	while(i<8){	
		mul_2=1;
		input1_decimal=0;
		input2_decimal=0;
		int j = 0;
		while(j<8){
			input1_decimal = input1_decimal + input1_bin[8*i-j+7]*mul_2;
			input2_decimal = input2_decimal + input2_bin[8*i-j+7]*mul_2;
			mul_2  = mul_2*2;
			j++;
		}
		plaintext_1[i] = input1_decimal;
		plaintext_2[i] = input2_decimal;
		i++;
	}
	plaintext_1[8]='\0';
	plaintext_1[8]='\0';

	set_the_key(1, DES_KEY, 6);

	cout << "The final password after decryption is: ";

	des(plaintext_1, cipherout_1, 6, 'N');
	for(int i=0; i<8; i++) cout << (cipherout_1[i]);
		
	des(plaintext_2, cipherout_2, 6, 'N');
	for(int i=0; i<8; i++)cout << (cipherout_2[i]);
	cout << endl;
}
