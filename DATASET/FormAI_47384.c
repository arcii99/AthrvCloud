//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

void printbin(int x){
  for (int i=sizeof(x)*8-1; i>=0; --i)
      putchar(x&(1u<<i) ? '1' : '0');
}

int main() {
  unsigned char a = 170; // 10101010 in binary
  unsigned char b = 85; // 01010101 in binary
  
  printf("a in binary: ");
  printbin(a);
  putchar('\n');
  
  printf("b in binary: ");
  printbin(b);
  putchar('\n');
  
  printf("a & b in binary: ");
  printbin(a & b);
  putchar('\n');
  
  printf("a | b in binary: ");
  printbin(a | b);
  putchar('\n');
  
  printf("~a in binary: ");
  printbin(~a);
  putchar('\n');
  
  printf("a ^ b in binary: ");
  printbin(a ^ b);
  putchar('\n');
  
  printf("b << 1 in binary: ");
  printbin(b << 1);
  putchar('\n');
  
  printf("a >> 2 in binary: ");
  printbin(a >> 2);
  putchar('\n');
  
  return 0;
}