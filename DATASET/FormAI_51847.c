//FormAI DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>

int main() {
  int a = 5;
  int b = 3;
  int c;
  
  // Bitwise AND operation
  c = a & b;
  printf("Bitwise AND operation result: %d\n", c);
  
  // Bitwise OR operation
  c = a | b;
  printf("Bitwise OR operation result: %d\n", c);
  
  // Bitwise XOR operation
  c = a ^ b;
  printf("Bitwise XOR operation result: %d\n", c);
  
  // Bit shifting for right shift
  c = a >> 1;
  printf("Bit shifting for right shift result: %d\n", c);
  
  // Bit shifting for left shift
  c = a << 1;
  printf("Bit shifting for left shift result: %d\n", c);
  
  // Bitwise NOT operation
  c = ~a;
  printf("Bitwise NOT operation result: %d\n", c);
  
  return 0;
}