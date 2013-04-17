#include <iostream>
#include <string.h>
//#include <stdio.h>




const char a[] = "12345";

int main() {
  char* b = new char[sizeof(a)];
  strncpy(b, a, sizeof(a));
  char* c = new(b) char('5');
    
  std::cout << a << std::endl << b << std::endl << c;
}
