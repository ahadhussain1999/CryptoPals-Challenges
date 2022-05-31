#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "functions.h"
using namespace std;

int main()
{
    srand(time(NULL));
    // int initialKey[4][4];
    // int initialArray[4][4];
    // int encryptedArray[4][4];
    // int expandedKey[4][44];
    string initialString = "5379646E69654C6F7665734168616421"; // SydnieLovesAhad!

    // // create random key
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         initialKey[i][j] = rand() % 16;
    //     }
    // }
    // print4x4Array(initialKey);

    // ExpandKey(initialKey, expandedKey);

    // HexStringto4x4Array(initialString, initialArray);

    // EncryptAES128Bit(initialArray, expandedKey, encryptedArray);

    // cout << hexArraytoAscii(encryptedArray) << endl;

    // append random 5-10 before 
   int amountBefore = rand() % 6 + 5;
   cout<< "how many before: "<<amountBefore<<endl;
   int amountAfter = rand() % 6 + 5;
   string addBefore;
   for (int i=0; i<amountBefore;i++){
        int randHex = rand() % 16;
        addBefore.push_back(randHex);
        
   }
   cout<< "adding this before: "<<addBefore<<endl; 
   string afterBeforeWithInitial= addBefore+ initialString; 
   cout<< "before+initial= "<<afterBeforeWithInitial<<endl;
   //come up randomly with 2 time amountBefore of hex characters
                                                  
 //  cout << " amount before : " << amountBefore << endl;

//for(i=5, i<=rand(5-10), i++)

}