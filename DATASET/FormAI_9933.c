//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

int main() {
  int a = 12, b = 25;

  // Bitwise AND
  int result = a & b;
  printf("Bitwise AND of %d and %d is %d\n", a, b, result);

  // Bitwise OR
  result = a | b;
  printf("Bitwise OR of %d and %d is %d\n", a, b, result);

  // Bitwise XOR
  result = a ^ b;
  printf("Bitwise XOR of %d and %d is %d\n", a, b, result);

  // Bitwise NOT
  result = ~a;
  printf("Bitwise NOT of %d is %d\n", a, result);

  // Left shift
  result = a << 2;
  printf("Left shift of %d by 2 is %d\n", a, result);

  // Right shift
  result = b >> 3;
  printf("Right shift of %d by 3 is %d\n", b, result);

  return 0;
}