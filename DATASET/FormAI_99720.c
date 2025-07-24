//FormAI DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>

int main() {
  int a, b, x;

  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);

  x = a & b;

  printf("Result of Bitwise AND: %d & %d = %d\n", a, b, x);

  x = a | b;

  printf("Result of Bitwise OR: %d | %d = %d\n", a, b, x);

  x = a ^ b;

  printf("Result of Bitwise XOR: %d ^ %d = %d\n", a, b, x);

  x = ~a;

  printf("Result of Bitwise NOT (First Number): ~%d = %d\n", a, x);

  x = b << 1;

  printf("Result of Left Shift (Second Number): %d << 1 = %d\n", b, x);

  x = b >> 1;

  printf("Result of Right Shift (Second Number): %d >> 1 = %d\n", b, x);

  return 0;
}