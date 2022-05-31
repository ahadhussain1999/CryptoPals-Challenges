#include <string>
#include <iostream>
#include <cstdlib>


int getbit(unsigned x, unsigned n) { return (x >> n) & 1; }

char* tobinary(unsigned long x, int bits) { 
  static char buf[BUFSIZ];
  memset(buf, 0, sizeof(char));

  char* p = buf;
  for (int i = bits - 1; i >= 0; --i) { 
    *p++ = (getbit(x, i) == 1 ? '1' : '0');
    if (i % 8 == 0) { *p++ = ' ';  }
  }
  if (*(p - 1) == ' ') { --p; }
  *p = '\0';
  return buf;
}

char* tobinary_4( unsigned long x) { return tobinary(x, 4); }
char* tobinary_8( unsigned long x) { return tobinary(x, 8); }
char* tobinary_16(unsigned long x) { return tobinary(x, 16); }
char* tobinary_24(unsigned long x) { return tobinary(x, 24); }
char* tobinary_32(unsigned long x) { return tobinary(x, 32); }

char toascii_frombinary(const char* s) {
  int n = strlen(s);
  const char* p = s + n - 1;
  char c = 0;
  unsigned power = 1;
  while (*p != '\0' && p >= s) { 
    if (*p != '0' && *p != '1') { throw new std::invalid_argument("invalid binary number"); }
    if (*p-- == '1') { 
      c += power;
    }
    power <<= 1;
  }
  return c;
}

char tobase64(char c) { 
  if (c < 26) { return c + 65; 
  } else if (c < 52) { return c + 71; 
  } else if (c < 62) { return c - 4; 
  } else if (c == 62) { return 43; 
  } else { return 47; }
}

std::string BinaryToHex(std::string Binary) {    // e.g., 1101 --> D
  static char buf[16];
  unsigned c = toascii_frombinary(Binary.c_str());
  snprintf(buf, sizeof(buf), "%x", c);
  return std::string(buf);
}

std::string HexToBinary(std::string Hex) {      // e.g., D --> 1101
  unsigned x = strtol(Hex.c_str(), NULL, 16);
  return std::string(tobinary_4(x));
}

std::string AsciiToBinary(std::string Ascii) {   // e.g., 'A' --> 01000001
  char c = Ascii.c_str()[0];
  const char* s = tobinary_8(c);
  return std::string(s);
}

std::string BinaryToText(std::string Binary) {
  static char buf[16];
  char c = toascii_frombinary(Binary.c_str());
  if (c == 127) { return std::string("DELETE"); }
  if (c > 127) { return std::string(); }

  snprintf(buf, sizeof(buf), "%c", c);
  return std::string(buf);
}

std::string BinaryToBase64(std::string Binary) {
  static char buf[16];
  memset(buf, 0, sizeof(buf));
  char c = toascii_frombinary(Binary.c_str());
  char cbase64 = tobase64(c);
  snprintf(buf, sizeof(buf), "%c", cbase64);
  return std::string(buf);
}


//==================================================================================
// TESTS 
//==================================================================================

void test_BinaryToText() { 
  for (unsigned int x = 33; x < 200; ++x) { 
    const char* s = tobinary_8(x);
    std::string binary(s);
    std::string text = BinaryToText(binary);
    std::cout << s << " is " << text << "\n";
  }
}

void test_tobinary_8() { 
  printf("TESTING test_tobinary8()............................\n");
  printf("A is: %s\n", tobinary_8('A'));
  printf("B is: %s\n", tobinary_8('B'));
  printf("C is: %s\n", tobinary_8('C'));
  printf("D is: %s\n", tobinary_8('D'));
  printf("E is: %s\n", tobinary_8('E'));
  printf("F is: %s\n", tobinary_8('F'));

  printf("end testing test_tobinary8()............................\n");
}

void test_toascii_frombinary() { 
  // std::initializer_list<std::string> li = { "00110000", "00110001", "00110010", "00110011", "00110100" };
  // for (const std::string el : li) { 
  //   std::cout << el << " is " << toascii_frombinary(el.c_str()) << "\n";
  // }

  for (unsigned int x = 48; x < 122; ++x) { 
    char* s = tobinary_8(x);
    std::cout << "'" << s << "' is " << toascii_frombinary(s) << "\n";
  }
}

void test_HexToBinary() { 
  char buf[10];

  for (unsigned x = 0; x < 16; ++x) { 
    snprintf(buf, sizeof(buf), "%x", x);  
    std::string hex(buf);
    std::cout << buf << " is " << HexToBinary(hex) << "\n";
  }
}

void test_BinaryToHex() { 
  std::cout << "TESTING BinaryToHex()======================\n";
  for (unsigned x = 0; x < 16; ++x) { 
    const char* s = tobinary_4(x);
    std::string binary(s);
    std::cout << s << " is " << BinaryToHex(binary) << "\n";
  }
}
 
void test_AsciiToBinary() { 
  char buf[16];
  memset(buf, 0, sizeof(buf));

  for (int x = 48; x < 125; ++x) { 
    snprintf(buf, sizeof(buf), "%c", x);
    std::string s(buf);
    std::cout << s << " is " << AsciiToBinary(s) << "\n";
  }
}



// std::string AsciiToBinary(std::string Ascii) {       // e.g., 'A' --> 01000001
  
//     if (Ascii == " "){return "00100000";}
//     if (Ascii == "!"){return "00100001";}
//     if (Ascii == "\""){return "00100010";}
//     if (Ascii == "#"){return "00100011";}
//     if (Ascii == "$"){return "00100100";}
//     if (Ascii == "%"){return "00100101";}
//     if (Ascii == "&"){return "00100110";}
//     if (Ascii == "\'"){return "00100111";}
//     if (Ascii == "("){return "00101000";}
//     if (Ascii == ")"){return "00101001";}
//     if (Ascii == "*"){return "00101010";}
//     if (Ascii == "+"){return "00101011";}
//     if (Ascii == ","){return "00101100";}
//     if (Ascii == "-"){return "00101101";}
//     if (Ascii == "."){return "00101110";}
//     if (Ascii == "/"){return "00101111";}
//     if (Ascii == "0"){return "00110000";}
//     if (Ascii == "1"){return "00110001";}
//     if (Ascii == "2"){return "00110010";}
//     if (Ascii == "3"){return "00110011";}
//     if (Ascii == "4"){return "00110100";}
//     if (Ascii == "5"){return "00110101";}
//     if (Ascii == "6"){return "00110110";}
//     if (Ascii == "7"){return "00110111";}
//     if (Ascii == "8"){return "00111000";}
//     if (Ascii == "9"){return "00111001";}
//     if (Ascii == ":"){return "00111010";}
//     if (Ascii == ";"){return "00111011";}
//     if (Ascii == "<"){return "00111100";}
//     if (Ascii == "="){return "00111101";}
//     if (Ascii == ">"){return "00111110";}
//     if (Ascii == "?"){return "00111111";}
//     if (Ascii == "@"){return "01000000";}
//     if (Ascii == "A"){return "01000001";}
//     if (Ascii == "B"){return "01000010";}
//     if (Ascii == "C"){return "01000011";}
//     if (Ascii == "D"){return "01000100";}
//     if (Ascii == "E"){return "01000101";}
//     if (Ascii == "F"){return "01000110";}
//     if (Ascii == "G"){return "01000111";}    
//     if (Ascii == "H"){return "01001000";}
//     if (Ascii == "I"){return "01001001";}
//     if (Ascii == "J"){return "01001010";}
//     if (Ascii == "K"){return "01001011";}
//     if (Ascii == "L"){return "01001100";}
//     if (Ascii == "M"){return "01001101";}
//     if (Ascii == "N"){return "01001110";}
//     if (Ascii == "O"){return "01001111";}
//     if (Ascii == "P"){return "01010000";}
//     if (Ascii == "Q"){return "01010001";}
//     if (Ascii == "R"){return "01010010";}    
//     if (Ascii == "S"){return "01010011";}
//     if (Ascii == "T"){return "01010100";}
//     if (Ascii == "U"){return "01010101";}
//     if (Ascii == "V"){return "01010110";}
//     if (Ascii == "W"){return "01010111";}
//     if (Ascii == "X"){return "01011000";}
//     if (Ascii == "Y"){return "01011001";}
//     if (Ascii == "Z"){return "01011010";}
//     if (Ascii == "["){return "01011011";}
//     if (Ascii == "\\"){return "01011100";}
//     if (Ascii == "]"){return "01011101";}
//     if (Ascii == "^"){return "01011110";}
//     if (Ascii == "_"){return "01011111";}
//     if (Ascii == "`"){return "01100000";}
//     if (Ascii == "a"){return "01100001";}
//     if (Ascii == "b"){return "01100010";}
//     if (Ascii == "c"){return "01100011";}
//     if (Ascii == "d"){return "01100100";}
//     if (Ascii == "e"){return "01100101";}
//     if (Ascii == "f"){return "01100110";}
//     if (Ascii == "g"){return "01100111";}
//     if (Ascii == "h"){return "01101000";}
//     if (Ascii == "i"){return "01101001";}
//     if (Ascii == "j"){return "01101010";}
//     if (Ascii == "k"){return "01101011";}
//     if (Ascii == "l"){return "01101100";}
//     if (Ascii == "m"){return "01101101";}
//     if (Ascii == "n"){return "01101110";}
//     if (Ascii == "o"){return "01101111";}
//     if (Ascii == "p"){return "01110000";}
//     if (Ascii == "q"){return "01110001";}
//     if (Ascii == "r"){return "01110010";}
//     if (Ascii == "s"){return "01110011";}
//     if (Ascii == "t"){return "01110100";}
//     if (Ascii == "u"){return "01110101";}
//     if (Ascii == "v"){return "01110110";}
//     if (Ascii == "w"){return "01110111";}
//     if (Ascii == "x"){return "01111000";}
//     if (Ascii == "y"){return "01111001";}
//     if (Ascii == "z"){return "01111010";} 
//     if (Ascii == "{"){return "01111011";} 
//     if (Ascii == "|"){return "01111100";} 
//     if (Ascii == "}"){return "01111101";} 
//     if (Ascii == "~"){return "01111110";}
//     return Ascii;
// }


void test_BinaryToBase64() {
  for (unsigned x = 0; x < 64; ++x) { 
    const char* binary = tobinary_8(x);
    std::string base64 = BinaryToBase64(binary);
    std::cout << binary << " is " << base64 << "\n";
  } 
 }

// std::string BinaryToBase64(std::string Binary) {
//     if (Binary == "000000"){return "A";}
//     if (Binary == "000001"){return "B";}
//     if (Binary == "000010"){return "C";}
//     if (Binary == "000011"){return "D";}
//     if (Binary == "000100"){return "E";}
//     if (Binary == "000101"){return "F";}
//     if (Binary == "000110"){return "G";}    
//     if (Binary == "000111"){return "H";}
//     if (Binary == "001000"){return "I";}
//     if (Binary == "001001"){return "J";}
//     if (Binary == "001010"){return "K";}
//     if (Binary == "001011"){return "L";}
//     if (Binary == "001100"){return "M";}
//     if (Binary == "001101"){return "N";}
//     if (Binary == "001110"){return "O";}
//     if (Binary == "001111"){return "P";}
//     if (Binary == "010000"){return "Q";}
//     if (Binary == "010001"){return "R";}    
//     if (Binary == "010010"){return "S";}
//     if (Binary == "010011"){return "T";}
//     if (Binary == "010100"){return "U";}
//     if (Binary == "010101"){return "V";}
//     if (Binary == "010110"){return "W";}
//     if (Binary == "010111"){return "X";}
//     if (Binary == "011000"){return "Y";}
//     if (Binary == "011001"){return "Z";}
//     if (Binary == "011010"){return "a";}
//     if (Binary == "011011"){return "b";}
//     if (Binary == "011100"){return "c";}
//     if (Binary == "011101"){return "d";}
//     if (Binary == "011110"){return "e";}
//     if (Binary == "011111"){return "f";}
//     if (Binary == "100000"){return "g";}
//     if (Binary == "100001"){return "h";}
//     if (Binary == "100010"){return "i";}
//     if (Binary == "100011"){return "j";}
//     if (Binary == "100100"){return "k";}
//     if (Binary == "100101"){return "l";}
//     if (Binary == "100110"){return "m";}
//     if (Binary == "100111"){return "n";}
//     if (Binary == "101000"){return "o";}
//     if (Binary == "101001"){return "p";}
//     if (Binary == "101010"){return "q";}
//     if (Binary == "101011"){return "r";}
//     if (Binary == "101100"){return "s";}
//     if (Binary == "101101"){return "t";}
//     if (Binary == "101110"){return "u";}
//     if (Binary == "101111"){return "v";}
//     if (Binary == "110000"){return "w";}
//     if (Binary == "110001"){return "x";}
//     if (Binary == "110010"){return "y";}
//     if (Binary == "110011"){return "z";}
//     if (Binary == "110100"){return "0";}
//     if (Binary == "110101"){return "1";}
//     if (Binary == "110110"){return "2";}
//     if (Binary == "110111"){return "3";}
//     if (Binary == "111000"){return "4";}
//     if (Binary == "111001"){return "5";}
//     if (Binary == "111010"){return "6";}
//     if (Binary == "111011"){return "7";}
//     if (Binary == "111100"){return "8";}
//     if (Binary == "111101"){return "9";}
//     if (Binary == "111110"){return "+";}
//     if (Binary == "111111"){return "/";}
  
//      return Binary;
//  }

// std::string BinarytoHex(const std::string& Binary) {
//     if (Binary == "0000"){return "0";}
//     if (Binary == "0001"){return "1";}
//     if (Binary == "0010"){return "2";}
//     if (Binary == "0011"){return "3";}
//     if (Binary == "0100"){return "4";}
//     if (Binary == "0101"){return "5";}
//     if (Binary == "0110"){return "6";}
//     if (Binary == "0111"){return "7";}
//     if (Binary == "1000"){return "8";}
//     if (Binary == "1001"){return "9";}
//     if (Binary == "1010"){return "a";}
//     if (Binary == "1011"){return "b";}
//     if (Binary == "1100"){return "c";}
//     if (Binary == "1101"){return "d";}
//     if (Binary == "1110"){return "e";}
//     if (Binary == "1111"){return "f";}
//     return Binary;
// }


// std::string BinarytoText(const std::string& Binary) {
//     if (Binary == "00000000"){return "";}
//     if (Binary == "00000001"){return "";}
//     if (Binary == "00000010"){return "";}
//     if (Binary == "00000011"){return "";}
//     if (Binary == "00000100"){return "";}
//     if (Binary == "00000101"){return "";}
//     if (Binary == "00000110"){return "";}    
//     if (Binary == "00000111"){return "";}
//     if (Binary == "00001000"){return "";}
//     if (Binary == "00001001"){return "";}
//     if (Binary == "00001010"){return "";}
//     if (Binary == "00001011"){return "";}
//     if (Binary == "00001100"){return "";}
//     if (Binary == "00001101"){return "";}
//     if (Binary == "00001110"){return "";}
//     if (Binary == "00001111"){return "";}
//     if (Binary == "00010000"){return "";}
//     if (Binary == "00010001"){return "";}    
//     if (Binary == "00010010"){return "";}
//     if (Binary == "00010011"){return "";}
//     if (Binary == "00010100"){return "";}
//     if (Binary == "00010101"){return "";}
//     if (Binary == "00010110"){return "";}
//     if (Binary == "00010111"){return "";}
//     if (Binary == "00011000"){return "";}
//     if (Binary == "00011001"){return "";}
//     if (Binary == "00011010"){return "";}
//     if (Binary == "00011011"){return "";}
//     if (Binary == "00011100"){return "";}
//     if (Binary == "00011101"){return "";}
//     if (Binary == "00011110"){return "";}
//     if (Binary == "00011111"){return "";}
//     if (Binary == "00100000"){return " ";}
//     if (Binary == "00100001"){return "!";}
//     if (Binary == "00100010"){return "\"";}
//     if (Binary == "00100011"){return "#";}
//     if (Binary == "00100100"){return "$";}
//     if (Binary == "00100101"){return "%";}
//     if (Binary == "00100110"){return "&";}
//     if (Binary == "00100111"){return "\'";}
//     if (Binary == "00101000"){return "(";}
//     if (Binary == "00101001"){return ")";}
//     if (Binary == "00101010"){return "*";}
//     if (Binary == "00101011"){return "+";}
//     if (Binary == "00101100"){return ",";}
//     if (Binary == "00101101"){return "-";}
//     if (Binary == "00101110"){return ".";}
//     if (Binary == "00101111"){return "/";}
//     if (Binary == "00110000"){return "0";}
//     if (Binary == "00110001"){return "1";}
//     if (Binary == "00110010"){return "2";}
//     if (Binary == "00110011"){return "3";}
//     if (Binary == "00110100"){return "4";}
//     if (Binary == "00110101"){return "5";}
//     if (Binary == "00110110"){return "6";}
//     if (Binary == "00110111"){return "7";}
//     if (Binary == "00111000"){return "8";}
//     if (Binary == "00111001"){return "9";}
//     if (Binary == "00111010"){return ":";}
//     if (Binary == "00111011"){return ";";}
//     if (Binary == "00111100"){return "<";}
//     if (Binary == "00111101"){return "=";}
//     if (Binary == "00111110"){return ">";}
//     if (Binary == "00111111"){return "?";}
//     if (Binary == "01000000"){return "@";}
//     if (Binary == "01000001"){return "A";}
//     if (Binary == "01000010"){return "B";}
//     if (Binary == "01000011"){return "C";}
//     if (Binary == "01000100"){return "D";}
//     if (Binary == "01000101"){return "E";}
//     if (Binary == "01000110"){return "F";}
//     if (Binary == "01000111"){return "G";}    
//     if (Binary == "01001000"){return "H";}
//     if (Binary == "01001001"){return "I";}
//     if (Binary == "01001010"){return "J";}
//     if (Binary == "01001011"){return "K";}
//     if (Binary == "01001100"){return "L";}
//     if (Binary == "01001101"){return "M";}
//     if (Binary == "01001110"){return "N";}
//     if (Binary == "01001111"){return "O";}
//     if (Binary == "01010000"){return "P";}
//     if (Binary == "01010001"){return "Q";}
//     if (Binary == "01010010"){return "R";}    
//     if (Binary == "01010011"){return "S";}
//     if (Binary == "01010100"){return "T";}
//     if (Binary == "01010101"){return "U";}
//     if (Binary == "01010110"){return "V";}
//     if (Binary == "01010111"){return "W";}
//     if (Binary == "01011000"){return "X";}
//     if (Binary == "01011001"){return "Y";}
//     if (Binary == "01011010"){return "Z";}
//     if (Binary == "01011011"){return "[";}
//     if (Binary == "01011100"){return "\\";}
//     if (Binary == "01011101"){return "]";}
//     if (Binary == "01011110"){return "^";}
//     if (Binary == "01011111"){return "_";}
//     if (Binary == "01100000"){return "`";}
//     if (Binary == "01100001"){return "a";}
//     if (Binary == "01100010"){return "b";}
//     if (Binary == "01100011"){return "c";}
//     if (Binary == "01100100"){return "d";}
//     if (Binary == "01100101"){return "e";}
//     if (Binary == "01100110"){return "f";}
//     if (Binary == "01100111"){return "g";}
//     if (Binary == "01101000"){return "h";}
//     if (Binary == "01101001"){return "i";}
//     if (Binary == "01101010"){return "j";}
//     if (Binary == "01101011"){return "k";}
//     if (Binary == "01101100"){return "l";}
//     if (Binary == "01101101"){return "m";}
//     if (Binary == "01101110"){return "n";}
//     if (Binary == "01101111"){return "o";}
//     if (Binary == "01110000"){return "p";}
//     if (Binary == "01110001"){return "q";}
//     if (Binary == "01110010"){return "r";}
//     if (Binary == "01110011"){return "s";}
//     if (Binary == "01110100"){return "t";}
//     if (Binary == "01110101"){return "u";}
//     if (Binary == "01110110"){return "v";}
//     if (Binary == "01110111"){return "w";}
//     if (Binary == "01111000"){return "x";}
//     if (Binary == "01111001"){return "y";}
//     if (Binary == "01111010"){return "z";} 
//     if (Binary == "01111011"){return "{";} 
//     if (Binary == "01111100"){return "|";} 
//     if (Binary == "01111101"){return "}";} 
//     if (Binary == "01111110"){return "~";}
//     if (Binary == "01111111"){return "DELETE";}    
//     return Binary;
// }
