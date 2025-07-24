//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

int main() {
  int a = 15;
  int b = 10;

  /* Shift Left Operation */
  printf("a << 2 = %d\n", a << 2);
  printf("b << 3 = %d\n\n", b << 3);

  /* Shift Right Operation */
  printf("a >> 2 = %d\n", a >> 2);
  printf("b >> 3 = %d\n\n", b >> 3);

  /* Bitwise AND Operation */
  printf("a & b = %d\n", a & b);

  /* Bitwise OR Operation */
  printf("a | b = %d\n", a | b);

  /* Bitwise XOR Operation */
  printf("a ^ b = %d\n", a ^ b);

  /* Bitwise Complement Operation */
  printf("~a = %d\n", ~a);
  printf("~b = %d\n\n", ~b);

  /* Setting a Bit */
  printf("%d with bit 2 set: %d\n", a, a | (1 << 2));

  /* Clearing a Bit */
  printf("%d with bit 3 cleared: %d\n", a, a & ~(1 << 3));

  /* Toggling a Bit */
  printf("%d with bit 4 toggled: %d\n", a, a ^ (1 << 4));

  return 0;
}