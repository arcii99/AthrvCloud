//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {
  // Let's declare a few unsigned integers
  // We'll use hexadecimal notation to make it look cooler
  unsigned int x = 0xAAAA;
  unsigned int y = 0x5555;
  unsigned int z = 0xFF;

  // Bitwise OR operation |
  printf("0x%X | 0x%X = 0x%X\n", x, y, x | y);

  // Bitwise AND operation &
  printf("0x%X & 0x%X = 0x%X\n", x, y, x & y);

  // Bitwise XOR operation ^
  printf("0x%X ^ 0x%X = 0x%X\n", x, y, x ^ y);

  // Bitwise NOT operation ~
  printf("~0x%X = 0x%X\n", x, ~x);
  
  // Bitwise left shift operation <<
  printf("0x%X << 4 = 0x%X\n", z, z << 4);

  // Bitwise right shift operation >>
  printf("0x%X >> 2 = 0x%X\n", x, x >> 2);

  // Combination of bitwise operations
  printf("(0x%X & 0x%X) | (~0x%X << 8) = 0x%X\n", x, y, z, (x & y) | (~z << 8));

  return 0;
}