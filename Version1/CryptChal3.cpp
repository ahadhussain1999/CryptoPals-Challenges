#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "utils.h"



int challenge_3() {
    string hex_String = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    vector<string> binary128 = {"00000000","00000001","00000010","00000011","00000100","00000101","00000110","00000111","00001000","00001001","00001010","00001011","00001100","00001101","00001110","00001111","00010000","00010001","00010010","00010011","00010100","00010101","00010110","00010111","00011000","00011001","00011010","00011011","00011100","00011101","00011110","00011111","00100000","00100001","00100010","00100011","00100100","00100101","00100110","00100111","00101000","00101001","00101010","00101011","00101100","00101101","00101110","00101111","00110000","00110001","00110010","00110011","00110100","00110101","00110110","00110111","00111000","00111001","00111010","00111011","00111100","00111101","00111110","00111111","01000000","01000001","01000010","01000011","01000100","01000101","01000110","01000111","01001000","01001001","01001010","01001011","01001100","01001101","01001110","01001111","01010000","01010001","01010010","01010011","01010100","01010101","01010110","01010111","01011000","01011001","01011010","01011011","01011100","01011101","01011110","01011111","01100000","01100001","01100010","01100011","01100100","01100101","01100110","01100111","01101000","01101001","01101010","01101011","01101100","01101101","01101110","01101111","01110000","01110001","01110010","01110011","01110100","01110101","01110110","01110111","01111000","01111001","01111010","01111011","01111100","01111101","01111110","01111111"};
    // vector<string> binary128_2 = {"10000000","10000001","10000010","10000011","10000100","10000101","10000110","10000111","10001000","10001001","10001010","10001011","10001100","10001101","10001110","10001111","10010000","10010001","10010010","10010011","10010100","10010101","10010110","10010111","10011000","10011001","10011010","10011011","10011100","10011101","10011110","10011111","10100000","10100001","10100010","10100011","10100100","10100101","10100110","10100111","10101000","10101001","10101010","10101011","10101100","10101101","10101110","10101111","10110000","10110001","10110010","10110011","10110100","10110101","10110110","10110111","10111000","10111001","10111010","10111011","10111100","10111101","10111110","10111111","11000000","11000001","11000010","11000011","11000100","11000101","11000110","11000111","11001000","11001001","11001010","11001011","11001100","11001101","11001110","11001111","11010000","11010001","11010010","11010011","11010100","11010101","11010110","11010111","11011000","11011001","11011010","11011011","11011100","11011101","11011110","11011111","11100000","11100001","11100010","11100011","11100100","11100101","11100110","11100111","11101000","11101001","11101010","11101011","11101100","11101101","11101110","11101111","11110000","11110001","11110010","11110011","11110100","11110101","11110110","11110111","11111000","11111001","11111010","11111011","11111100","11111101","11111110","11111111"};
    vector<string> likely_Chars = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"," "};
    vector<string> hex_Vec;
    vector<string> binary_Vec;
    string binary_String = "";
    string test_XOR = "";
    string binary_XOR = "";
    vector<string> binary_Vector;
    float charCount = 0;
    float charRatio = 0.80;
    int stringsFoundCount = 0;
    int count = 0;
    string temp_binary_Vec = "";
    string ascii_key;
    
    cout << ("To find the hidden message, we are looking for the count of common English characters in the string.") << endl;
    // cout << ("Please enter the ratio of English characters to the entire string you would like to test as a decimal.") << endl;
    // cout << ("Range is 0.01 to 0.99. Higher ratios are less sensitive and more strict. Adjust the sensitivity as needed") << endl;
    // cout << ("Enter your ratio now: ");
    // cin >> charRatio;

    cout << ("Initial Hex String:\n") << hex_String << endl << endl;
    for (int i = 0; i < hex_String.length(); i++) { // converts hex string to hex vector. each address has one hex value i.e. 4 bits 
        hex_Vec.push_back(hex_String.substr(i,1)); 
    }

    for (int i = 0; i < hex_String.length(); i++) { // converts the hex Vector to a binary string
        binary_String.append(HexToBinary(hex_Vec[i]));
    }

    for (int i = 0; i < binary_String.length() / 8; i++) { // converts the binary string into a binary vector. n/8 bytes with each vector address pointing to 8 bits each
        binary_Vec.push_back(binary_String.substr(i*8,8)); 
    }

    cout << ("Initial Binary String: ") << endl;
    for (int i = 0; i < binary_Vec.size(); i++) { // used to output the full binary vector
        cout << binary_Vec[i];
    }
    cout << ("\n");

    for (int a = 0; a < binary128.size(); a++) {
        for (int i = 0; i < binary_Vec.size(); i++) {
            temp_binary_Vec = binary_Vec[i];
            test_XOR = binary128[a];
            for (int j = 0; j < temp_binary_Vec.length(); j++) {
                if(temp_binary_Vec[j] == '1' and test_XOR[j] == '1') {
                    binary_XOR.append("0");
                } else if (temp_binary_Vec[j] == '0' and test_XOR[j] == '0')
                {
                    binary_XOR.append("0");
                } else {
                    binary_XOR.append("1");
                }
            }
        }

        for (int k = 0; k < binary_XOR.length() / 8; k++) { // converts the binary string into a binary vector. n/8 bytes with each vector address pointing to 8 bits each
            binary_Vector.push_back(binary_XOR.substr(k*8,8)); 
        }
        ascii_key = binary128[count];

        for (int l = 0; l < binary_Vector.size(); l++) {
            for(int i = 0; i < likely_Chars.size(); i++) {
                if (likely_Chars[i] == BinaryToText(binary_Vector[l])) {
                    charCount++;
                }
            }
        }

        if (charCount / binary_Vector.size() > charRatio) {
            cout << ("\ntest #: ") << count << endl;
            cout << ("Key value in Binary: ") << BinaryToText(ascii_key) << endl;
            for (int m = 0; m < binary_Vector.size(); m++) {
                cout << BinaryToText(binary_Vector[m]);
            }
            cout << ("\nRatio: ") << charCount/binary_Vector.size() << endl;
            stringsFoundCount++;
        }
        binary_XOR = "";
        binary_Vector.clear();
        count++;
        charCount = 0;
    }
    cout << ("\nTotal Tests Run: ") << count << endl;
    cout << ("Successful Strings Found: ") << stringsFoundCount << endl;

    return 0;
}   
