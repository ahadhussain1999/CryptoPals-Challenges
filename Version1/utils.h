#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

std::string AsciiToBinary(std::string Ascii);

std::string BinaryToBase64(std::string Binary); 

std::string BinaryToHex(std::string Binary);

std::string BinaryToText(std::string Binary);

std::string HexToBinary(std::string Hex);



int getbit(unsigned x, unsigned n);

char* tobinary(unsigned long x, int bits);
char* tobinary_8(unsigned long x);
char* tobinary_16(unsigned long x);
char* tobinary_24(unsigned long x);
char* tobinary_32(unsigned long x);

char tobase64(char c); 
char toascii_frombinary(char* s);




void test_AsciiToBinary();
void test_BinaryToText();
void test_BinaryToBase64();

void test_tobinary_8();
void test_toascii_frombinary() ;

void test_BinaryToHex();
void test_HexToBinary();

#endif