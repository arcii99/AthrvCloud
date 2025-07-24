//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>

int main() {
  int a = 10;
  int b = 5;
  int c = 0;
  
  // Bitwise AND
  c = a & b;
  printf("a & b = %d\n", c);
  
  // Bitwise OR
  c = a | b;
  printf("a | b = %d\n", c);
  
  // Bitwise XOR
  c = a ^ b;
  printf("a ^ b = %d\n", c);
  
  // Bitwise NOT
  c = ~a;
  printf("~a = %d\n", c);
  
  // Bitwise Left Shift
  c = a << 2;
  printf("a << 2 = %d\n", c);
  
  // Bitwise Right Shift
  c = a >> 2;
  printf("a >> 2 = %d\n", c);
  
  return 0;
}