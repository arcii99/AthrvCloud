//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

int main() {
  int a = 10; // binary: 1010
  int b = 5;  // binary: 0101
  int c;

  // Bitwise AND
  c = a & b;
  printf("a & b = %d\n", c); // Output: 0

  // Bitwise OR
  c = a | b;
  printf("a | b = %d\n", c); // Output: 15

  // Bitwise XOR
  c = a ^ b;
  printf("a ^ b = %d\n", c); // Output: 15

  // Bitwise Complement
  c = ~a;
  printf("~a = %d\n", c); // Output: -11

  // Left Shift
  c = a << 1;  // binary: 10100, Decimal: 20
  printf("a << 1 = %d\n", c); // Output: 20

  // Right Shift
  c = a >> 1;  // binary: 101, Decimal: 5
  printf("a >> 1 = %d\n", c); // Output: 5
  
  return 0;
}