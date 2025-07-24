//FormAI DATASET v1.0 Category: Bitwise operations ; Style: active
#include <stdio.h>

int main() {

  int a = 12; // 1100 in binary
  int b = 5;  // 0101 in binary
  int result;

  // bitwise AND
  result = a & b;
  printf("a & b = %d\n", result);

  // bitwise OR
  result = a | b;
  printf("a | b = %d\n", result);

  // bitwise XOR
  result = a ^ b;
  printf("a ^ b = %d\n", result);

  // bitwise NOT
  result = ~a;
  printf("~a = %d\n", result);

  // left shift
  result = a << 2;
  printf("a << 2 = %d\n", result);

  // right shift
  result = a >> 2;
  printf("a >> 2 = %d\n", result);

  // logical AND
  result = (a > 2) && (b < 10);
  printf("(a > 2) && (b < 10) = %d\n", result);

  // logical OR
  result = (a > 2) || (b > 10);
  printf("(a > 2) || (b > 10) = %d\n", result);

  return 0;
}