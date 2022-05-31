#include <string.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include "functions.h"
using namespace std;

int main()
{
    string initialHex1 = "1c0111001f010100061a024b53535009181c";
    string initialHex2 = "686974207468652062756c6c277320657965";
    string binaryString1 = "";
    string binaryString2 = "";

    int mod = initialHex1.length() % 8;
    if (mod == 0) {mod = 8;}

    initialHex1.insert(0, "000000000", 0, 8 - mod);

    cout << "Hex String1: \n" << initialHex1 << endl << endl;

    for (int i = 0; i < initialHex1.length()/8; i++)
    {
        binaryString1.append(HexToDecimal(initialHex1.substr(i*8,8)));
    }

    cout << "Binary String1: \n" << binaryString1 << endl << endl;

    initialHex2.insert(0, "000000000", 0, 8 - mod);

    cout << "Hex String2: \n" << initialHex2 << endl << endl;

    for (int i = 0; i < initialHex2.length()/8; i++)
    {
        binaryString2.append(HexToBinary(initialHex2.substr(i*8,8)));
    }
    cout << "Binary String2: \n" << binaryString2 << endl << endl;

    string binaryXOR = "";
    string hexXOR = "";

    for (int i = 0; i < binaryString1.length(); i++)
    {
        if((binaryString1[i] == '1' and binaryString2[i] == '1') or (binaryString1[i] == '0' and binaryString2[i] == '0'))
        {
            binaryXOR.append("0");
        }
        else
        {
            binaryXOR.append("1");
        }
    }

    cout << "Binary XOR: \n" << binaryXOR << endl << endl;

    for (int i = 0; i < binaryXOR.length()/4; i++)
    {
        hexXOR.append(BinaryToHex(binaryXOR.substr(i*4,4)));
    }
        hexXOR.erase(0, hexXOR.find_first_not_of('0'));
        cout << "Hex XOR: \n" << hexXOR << endl;
}