//FormAI DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>

int main() {
  unsigned int x = 0b01010101010101010101010101010101; // Define our number
  unsigned int y = 0b10101010101010101010101010101010; // Define another number

  // Bitwise AND operator example:
  printf("x & y = %u\n", x & y); // Will output 0

  // Bitwise OR operator example:
  printf("x | y = %u\n", x | y); // Will output 0xFFFFFFFF

  // Bitwise XOR operator example:
  printf("x ^ y = %u\n", x ^ y); // Will output 0xFFFFFFFF

  // Bitwise NOT operator example:
  printf("~x = %u\n", ~x); // Will output 0b10101010101010101010101010101010

  // Bitwise SHIFT LEFT operator example:
  printf("x << 3 = %u\n", x << 3); // Will output 0b01010101010101010101010101010000

  // Bitwise SHIFT RIGHT operator example:
  printf("x >> 2 = %u\n", x >> 2); // Will output 0b00010101010101010101010101010101

  return 0;
}