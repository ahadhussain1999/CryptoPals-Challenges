#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "utils.h"



int challenge_1() {
    string hex_String = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    vector<string> hex_Vec;
    string binary_From_Hex;
    vector<string> newBytes;
    string base64_String = "";

    // pushes each value of the hex_String to an element in hex_Vec
    // hex_Vec is now the length of hex_String
    for (int i = 0; i < hex_String.length(); i++) {
        hex_Vec.push_back(hex_String.substr(i,1)); 
    }

    // passes each element through HexToBinary and appends it to a string called binary_From_Hex
    // binary_From_Hex now contains the binary equivalent of the initial hex_String
    for (int i = 0; i < hex_Vec.size(); i++) {
        binary_From_Hex.append(HexToBinary(hex_Vec[i]));
        // std::cout << HexToBinary(hex_Vec[i]) << " ";
    }
    std::cout << "done printing initial check...\n";

    
    // checks if all of the binary bytes will translate directly to the base64 equivalent
    int remainder = binary_From_Hex.length() % 6;

    if (remainder == 0) {
        // divides the binary_From_Hex string into a vector, newBytes, which has 6 bits in each element
        for (int i = 0; i < binary_From_Hex.length() / 6; i++) {
            newBytes.push_back(binary_From_Hex.substr(i*6,6)); 
        }
        cout << ("Initial Hex String is:\n") << hex_String << endl << endl;
        cout << ("Hex String in Binary is:\n") << binary_From_Hex << endl << endl;
        cout << ("Hex String in Base64 is:") << endl;

        // converts each element in newBytes to the Base64 equivalent and outputs it
        for (int i = 0; i < newBytes.size(); i++) {
            base64_String.append(BinaryToBase64(newBytes[i]));
        }
        cout << base64_String << endl;
    }
    else if (remainder == 2 or remainder == 4) {
        cout << ("\nThe hex bytes do not evenly divide into 6 bit sections. Will deal with it later") << endl;
    }
    std::cout << "\n\n";
    
    return 0;
}

