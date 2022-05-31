#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "utils.h"



int challenge_5() {
    string String1 = ("Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal");
    vector<string> string1_Vec;
    string binary_From_Ascii = "";
    string binary_Key = "";
    string key_String = "ICE";
    vector<string> key_Vec;
    vector<string> newString1Bytes;
    vector<string> newKeyBytes;
    string test_XOR = "";
    string binary_XOR = "";
    string temp_Key_Vec = "";
    int modIncrement = 0;

    // converts the initial string1 to a vector of the same length
    for (int i = 0; i < String1.length(); i++) {
        string1_Vec.push_back(String1.substr(i,1)); 
    }

    // converts the vector into a binary string translation
    for (int i = 0; i < string1_Vec.size(); i++) {
        binary_From_Ascii.append(AsciiToBinary(string1_Vec[i]));
        // binary_From_Ascii.append(tobinary_8(string1_Vec[i][0]));
    }

    // converts the key to a vector of the same length
    for (int i = 0; i < key_String.length(); i++) {
        key_Vec.push_back(key_String.substr(i,1)); 
    }

    // converts the vector into a binary string translation
    for (int i = 0; i < key_Vec.size(); i++) {
        binary_Key.append(AsciiToBinary(key_Vec[i]));
        // binary_Key.append(tobinary_8(key_Vec[i][0]));
    }

    // converts the binary string to a binary vector with 8 bits in an element
    for (int i = 0; i < binary_From_Ascii.length() / 8; i++) {
        newString1Bytes.push_back(binary_From_Ascii.substr(i*8,8)); 
    }

    // converts the binary key string to a binary key vector with 8 bits in an element
    for (int i = 0; i < binary_Key.length() / 8; i++) {
        newKeyBytes.push_back(binary_Key.substr(i*8,8)); 
    }

    for (int i = 0; i < newString1Bytes.size(); i++) {
        modIncrement = i % newKeyBytes.size();
        // cout << ("Using this element from newString1Bytes: ") << i << endl;
        // cout << ("Using this element from newKeyBytes: ") << modIncrement << endl;

        temp_Key_Vec = newKeyBytes[modIncrement];
        test_XOR = newString1Bytes[i];

        // cout << ("tempKeyVec: ") << temp_Key_Vec << endl;
        // cout << ("test_XOR: ") << test_XOR << endl;
        for (int j = 0; j < temp_Key_Vec.length(); j++) {
            if(temp_Key_Vec[j] == '1' and test_XOR[j] == '1') {
                binary_XOR.append("0");
            } else if (temp_Key_Vec[j] == '0' and test_XOR[j] == '0') {
                binary_XOR.append("0");
            } else {
                binary_XOR.append("1");
            }
        }
    }

    cout << ("Binary XOR: ") << endl;
    for (int i = 0; i < binary_XOR.length(); i++) {
        if (i % 8 == 0 ) {
            cout << (" ");
        }
        cout << binary_XOR[i];
    }
    cout << endl;
  
    return 0;
}
