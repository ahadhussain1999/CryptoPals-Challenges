#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "utils.h"


int challenge_2() { 
    string binary_XOR = "";
    string binary_String1 = "";
    string binary_String2 = "";
    string base64_String = "";
    vector<string> vec_XOR;
    vector<string> hex_Vec1;
    vector<string> hex_Vec2;

    string hex_String1 = "1c0111001f010100061a024b53535009181c";
    string hex_String2 = "686974207468652062756c6c277320657965";

    for (int i = 0; i < hex_String1.length(); i++) {
        hex_Vec1.push_back(hex_String1.substr(i,1)); 
    }

    for (int i = 0; i < hex_String2.length(); i++) {
        hex_Vec2.push_back(hex_String2.substr(i,1)); 
    }

    for (int i = 0; i < hex_Vec1.size(); i++) {
        binary_String1.append(HexToBinary(hex_Vec1[i]));
    }

    for (int i = 0; i < hex_Vec2.size(); i++) {
        binary_String2.append(HexToBinary(hex_Vec2[i]));
    }
    
    cout << ("First Hex String: \n") <<  hex_String1 << endl;
    cout << ("Second Hex String: \n") << hex_String2 << endl << endl;
    cout << ("First Hex String in Binary: \n") << binary_String1 << endl;
    cout << ("Second Hex String in Binary: \n") << binary_String2 << endl << endl;

    if (binary_String1.length() == binary_String2.length()) {
        for (int i = 0; i < binary_String1.length(); i++) {
            if(binary_String1[i] == '1' and binary_String2[i] == '1') {
                binary_XOR.append("0");
            } else if (binary_String1[i] == '0' and binary_String2[i] == '0') {
                binary_XOR.append("0");
            } else {
                binary_XOR.append("1");
            }
        }
        
        for (int i = 0; i < binary_XOR.length() / 4; i++) {
            vec_XOR.push_back(binary_XOR.substr(i*4,4)); 
        }

        cout << ("Binary XOR of String1 and String2:") << endl;
        
        for (int i = 0; i < vec_XOR.size(); i++) {
            cout << vec_XOR[i]; 
        }
        cout << ("\nXOR in Hex:") << endl;
        for (int i = 0; i < vec_XOR.size(); i++) {
            base64_String.append(BinaryToHex(vec_XOR[i]));
        }    
        cout << base64_String << endl;
    } else if (binary_String1.length() != binary_String2.length()){
        cout << ("Please Enter Hex Strings of Equal Length\n");
    }

    return 0;
}
