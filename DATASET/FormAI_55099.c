//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

// This program demonstrates various bitwise operations in C

int main() {
  unsigned int x = 0b110011; // Binary representation of the number 51
  unsigned int y = 0b101010; // Binary representation of the number 42

  printf("x: %u\n", x);  // Prints 51
  printf("y: %u\n", y);  // Prints 42

  unsigned int or_result = x | y;
  printf("x | y: %u\n", or_result); // Prints 63

  unsigned int and_result = x & y;
  printf("x & y: %u\n", and_result); // Prints 32

  unsigned int xor_result = x ^ y;
  printf("x ^ y: %u\n", xor_result); // Prints 31

  unsigned int complement_x = ~x;
  printf("~x: %u\n", complement_x); // Prints 4294967244 (the binary representation of this number is 11111111111111111111111100010011)

  unsigned int shift_left = x << 1;
  printf("x << 1: %u\n", shift_left); // Prints 102 (the binary representation of this number is 1100110)

  unsigned int shift_right = y >> 1;
  printf("y >> 1: %u\n", shift_right); // Prints 21 (the binary representation of this number is 10101)

  return 0;
}