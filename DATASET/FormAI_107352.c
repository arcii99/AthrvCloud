//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

int main() {
  int a = 23, b = 15, result;

  result = a & b; // Bitwise AND
  printf("Bitwise AND of %d and %d is %d\n", a, b, result);

  result = a | b; // Bitwise OR
  printf("Bitwise OR of %d and %d is %d\n", a, b, result);

  result = ~a; // Bitwise NOT
  printf("Bitwise NOT of %d is %d\n", a, result);

  result = a ^ b; // Bitwise XOR
  printf("Bitwise XOR of %d and %d is %d\n", a, b, result);

  result = a << 2; // Bitwise left shift
  printf("Bitwise left shift of %d by 2 is %d\n", a, result);

  result = b >> 1; // Bitwise right shift
  printf("Bitwise right shift of %d by 1 is %d\n", b, result);

  return 0;
}