//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

int main() {
  unsigned int a = 0b10101010;
  unsigned int b = 0b01010101;
  unsigned int c = 0b11110000;
  unsigned int d = 0b00001111;
  
  printf("a = %u\n", a);
  printf("b = %u\n", b);
  printf("c = %u\n", c);
  printf("d = %u\n", d);
  
  // Bitwise OR
  printf("a | b = %u\n", a | b);
  
  // Bitwise AND
  printf("a & b = %u\n", a & b);
  
  // Bitwise XOR
  printf("a ^ b = %u\n", a ^ b);
  
  // Bitwise NOT
  printf("~a = %u\n", ~a);
  
  // Bitwise shift left by 2
  printf("c << 2 = %u\n", c << 2);
  
  // Bitwise shift right by 4
  printf("d >> 4 = %u\n", d >> 4);
  
  // Set bit 5 in a
  a |= (1 << 5);
  printf("a = %u\n", a);
  
  // Clear bit 6 in b
  b &= ~(1 << 6);
  printf("b = %u\n", b);
  
  // Toggle bit 4 in c
  c ^= (1 << 4);
  printf("c = %u\n", c);
  
  // Check if bit 3 is set in d
  if (d & (1 << 3)) {
    printf("Bit 3 in d is set\n");
  } else {
    printf("Bit 3 in d is not set\n");
  }
  
  return 0;
}