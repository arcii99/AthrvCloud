//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int a = 0xAA;
  unsigned int b = 0x55;
  
  printf("Initial values: a = %#x, b = %#x\n\n", a, b);
  
  // Bitwise AND
  unsigned int result = a & b;
  printf("Bitwise AND: a & b = %#x\n\n", result);
  
  // Bitwise OR
  result = a | b;
  printf("Bitwise OR: a | b = %#x\n\n", result);
  
  // Bitwise XOR
  result = a ^ b;
  printf("Bitwise XOR: a ^ b = %#x\n\n", result);
  
  // Bitwise NOT
  result = ~a;
  printf("Bitwise NOT: ~a = %#x\n\n", result);
  
  // Left Shift
  result = a << 1;
  printf("Left Shift: a << 1 = %#x\n\n", result);
  
  // Right Shift
  result = b >> 1;
  printf("Right Shift: b >> 1 = %#x\n\n", result);
  
  // Bitwise AND with an immediate value
  result = a & 0xF0;
  printf("Bitwise AND with an immediate value: a & 0xF0 = %#x\n\n", result);
  
  // Bitwise OR with an immediate value
  result = b | 0xF0;
  printf("Bitwise OR with an immediate value: b | 0xF0 = %#x\n\n", result);
  
  // Bitwise XOR with an immediate value
  result = a ^ 0xFF;
  printf("Bitwise XOR with an immediate value: a ^ 0xFF = %#x\n\n", result);
  
  // Set a specific bit in a
  result = a | (1 << 3);
  printf("Set a specific bit in a: a | (1 << 3) = %#x\n\n", result);
  
  // Clear a specific bit in a
  result = a & ~(1 << 2);
  printf("Clear a specific bit in a: a & ~(1 << 2) = %#x\n\n", result);
  
  // Toggle a specific bit in a
  result = a ^ (1 << 5);
  printf("Toggle a specific bit in a: a ^ (1 << 5) = %#x\n\n", result);
  
  return 0;
}