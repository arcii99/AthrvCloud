//FormAI DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>

int main() {
  // Declare variables
  unsigned int a = 0b10110010; // Binary value 10110010
  unsigned int b = 0b01001101; // Binary value 01001101
  unsigned int c;

  // Use bitwise AND operator &
  c = a & b; // 10110010 & 01001101 = 00000000
  printf("a & b = %u\n", c);

  // Use bitwise OR operator |
  c = a | b; // 10110010 | 01001101 = 11111111
  printf("a | b = %u\n", c);

  // Use bitwise XOR operator ^
  c = a ^ b; // 10110010 ^ 01001101 = 11111111
  printf("a ^ b = %u\n", c);

  // Use bitwise NOT operator ~
  c = ~a; // ~10110010 = 01001101
  printf("~a = %u\n", c);

  // Use left shift operator <<
  c = a << 2; // 10110010 << 2 = 11001000
  printf("a << 2 = %u\n", c);

  // Use right shift operator >>
  c = b >> 3; // 01001101 >> 3 = 00001001
  printf("b >> 3 = %u\n", c);

  return 0;
}