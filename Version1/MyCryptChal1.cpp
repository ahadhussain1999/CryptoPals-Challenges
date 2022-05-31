using namespace std;
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