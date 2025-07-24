//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>

int main() {
  int a = 19; // 0001 0011 in binary format
  int b = 27; // 0001 1011 in binary format
  
  // Bitwise AND operation
  int c = a & b; // 0001 0011 & 0001 1011 = 0001 0011 = 19 in decimal format
  printf("a & b = %d\n", c);
  
  // Bitwise OR operation
  int d = a | b; // 0001 0011 | 0001 1011 = 0001 1011 = 27 in decimal format
  printf("a | b = %d\n", d);
  
  // Bitwise XOR operation
  int e = a ^ b; // 0001 0011 ^ 0001 1011 = 0000 1000 = 8 in decimal format
  printf("a ^ b = %d\n", e);
  
  // Bitwise NOT operation
  int f = ~a; // ~0001 0011 = 1110 1100 = -20 in decimal format (due to two's complement representation)
  printf("~a = %d\n", f);
  
  // Left shift operation
  int g = a << 2; // 0001 0011 << 2 = 0100 1100 = 76 in decimal format
  printf("a << 2 = %d\n", g);
  
  // Right shift operation
  int h = b >> 3; // 0001 1011 >> 3 = 0000 0011 = 3 in decimal format
  printf("b >> 3 = %d\n", h);

  return 0;
}