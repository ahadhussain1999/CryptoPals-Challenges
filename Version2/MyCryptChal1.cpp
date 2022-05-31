#include <string.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "functions.h"
using namespace std;

int main()
{
    string initialHex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    string binaryString = "";
    int mod = initialHex.length() % 8;
    if (mod == 0) {mod = 8;}

    initialHex.insert(0, "000000000", 0, 8 - mod);

    cout << "Hex String: \n" << initialHex << endl << endl;

    for (int i = 0; i < initialHex.length()/8; i++)
    {
        binaryString.append(HexToBinary(initialHex.substr(i*8,8)));
        // binaryString.append(" ");
    }
    cout << "Binary String: \n" << binaryString << endl << endl;

    cout << "Base64 String:  \n";
    for (int i = 0; i < binaryString.length()/6; i++)
    {
        cout << BinaryToBase64(binaryString.substr(i*6,6));
    }
    cout << endl;
}