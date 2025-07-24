//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
  int a = 17;   // This variable holds decimal value 17
  int b = 6;    // This variable holds decimal value 6

  printf("The binary value of 17 is %d\n", a);
  printf("The binary value of 6 is %d\n", b);

  /* Performing bitwise AND operation */
  int c = a & b;
  printf("17 & 6 = %d\n", c);  // The result will be 00000100 in binary = 4 in decimal
  printf("Result in binary: %d%d%d%d%d%d%d%d\n", 
         !!(c & 128), !!(c & 64), !!(c & 32), !!(c & 16), 
         !!(c & 8), !!(c & 4), !!(c & 2), !!(c & 1));
  printf("\n");

  /* Performing bitwise OR operation */
  c = a | b;
  printf("17 | 6 = %d\n", c);  // The result will be 00010001 in binary = 21 in decimal
  printf("Result in binary: %d%d%d%d%d%d%d%d\n", 
         !!(c & 128), !!(c & 64), !!(c & 32), !!(c & 16), 
         !!(c & 8), !!(c & 4), !!(c & 2), !!(c & 1));
  printf("\n");

  /* Performing bitwise XOR operation */
  c = a ^ b;
  printf("17 ^ 6 = %d\n", c);  // The result will be 00010101 in binary = 21 in decimal
  printf("Result in binary: %d%d%d%d%d%d%d%d\n", 
         !!(c & 128), !!(c & 64), !!(c & 32), !!(c & 16), 
         !!(c & 8), !!(c & 4), !!(c & 2), !!(c & 1));
  printf("\n");

  /* Performing bitwise NOT operation */
  c = ~a;
  printf("~17 = %d\n", c);    // The result will be 11101110 in binary
  printf("Result in binary: %d%d%d%d%d%d%d%d\n", 
         !!(c & 128), !!(c & 64), !!(c & 32), !!(c & 16), 
         !!(c & 8), !!(c & 4), !!(c & 2), !!(c & 1));
  printf("\n");

  /* Performing bitwise left shift operation */
  c = a << 2;
  printf("17 << 2 = %d\n", c);  // The result will be 0b10001 << 2 = 0b1000100 = 68 in decimal
  printf("Result in binary: %d%d%d%d%d%d%d%d\n", 
         !!(c & 128), !!(c & 64), !!(c & 32), !!(c & 16), 
         !!(c & 8), !!(c & 4), !!(c & 2), !!(c & 1));
  printf("\n");

  /* Performing bitwise right shift operation */
  c = a >> 2;
  printf("17 >> 2 = %d\n", c);  // The result will be 0b10001 >> 2 = 0b00100 = 4 in decimal
  printf("Result in binary: %d%d%d%d%d%d%d%d\n", 
         !!(c & 128), !!(c & 64), !!(c & 32), !!(c & 16), 
         !!(c & 8), !!(c & 4), !!(c & 2), !!(c & 1));
  printf("\n");

  return 0;
}