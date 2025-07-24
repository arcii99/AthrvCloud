//FormAI DATASET v1.0 Category: Bitwise operations ; Style: happy
#include <stdio.h>

int main() {
  printf("Hello there, let's do some Bitwise operations!\n");

  unsigned char a = 0x32;
  unsigned char b = 0x28;
  unsigned char c;

  // logical AND
  c = a & b;
  printf("a & b = %02X\n", c);

  // logical OR
  c = a | b;
  printf("a | b = %02X\n", c);

  // logical XOR
  c = a ^ b;
  printf("a ^ b = %02X\n", c);

  // bitwise NOT
  c = ~a;
  printf("~a = %02X\n", c);

  // left shift
  c = a << 2;
  printf("a << 2 = %02X\n", c);

  // right shift
  c = b >> 3;
  printf("b >> 3 = %02X\n", c);

  // compliment the right shift
  c = ~b >> 3;
  printf("~b >> 3 = %02X\n", c);
  
  printf("Wowza, look at all these operations we can do in C with just some simple code!\n");

  return 0;
}