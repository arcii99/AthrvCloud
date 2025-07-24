//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>

int main() {
  int a = 42, b = 27;

  // Bitwise AND operator
  int c = a & b;
  printf("%d & %d = %d\n", a, b, c);

  // Bitwise OR operator
  int d = a | b;
  printf("%d | %d = %d\n", a, b, d);

  // Bitwise XOR operator
  int e = a ^ b;
  printf("%d ^ %d = %d\n", a, b, e);

  // Bitwise NOT operator
  int f = ~a;
  printf("~%d = %d\n", a, f);

  // Left shift operator
  int g = a << 2;
  printf("%d << 2 = %d\n", a, g);

  // Right shift operator
  int h = a >> 2;
  printf("%d >> 2 = %d\n", a, h);

  // Bitwise AND assignment operator
  a &= b;
  printf("a &= %d; a = %d\n", b, a);

  // Bitwise OR assignment operator
  a |= b;
  printf("a |= %d; a = %d\n", b, a);

  // Bitwise XOR assignment operator
  a ^= b;
  printf("a ^= %d; a = %d\n", b, a);

  // Left shift assignment operator
  a <<= 2;
  printf("a <<= 2; a = %d\n", a);

  // Right shift assignment operator
  a >>= 2;
  printf("a >>= 2; a = %d\n", a);

  return 0;
}