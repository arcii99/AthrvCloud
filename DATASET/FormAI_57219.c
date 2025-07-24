//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

int main() {
  // Initializing variables
  unsigned int a = 60; // 0011 1100
  unsigned int b = 13; // 0000 1101
  int c = 0;

  // Bitwise AND operator
  c = a & b; // 0000 1100 (12)
  printf("a & b = %d\n", c);
  
  // Bitwise OR operator
  c = a | b; // 0011 1101 (61)
  printf("a | b = %d\n", c);
  
  // Bitwise XOR operator
  c = a ^ b; // 0011 0001 (49)
  printf("a ^ b = %d\n", c);
  
  // Bitwise left shift operator
  c = a << 2; // 1111 0000 (240)
  printf("a << 2 = %d\n", c);

  // Bitwise right shift operator
  c = a >> 2; // 0000 1111 (15)
  printf("a >> 2 = %d\n", c);

  return 0;
}