//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

int main() {
  int a = 246; // 11110110 in binary
  int b = 198; // 11000110 in binary

  // bitwise AND
  int c = a & b; // 11000110 in binary
  printf("The result of bitwise AND: %d\n", c);

  // bitwise OR
  int d = a | b; // 11110110 in binary
  printf("The result of bitwise OR: %d\n", d);

  // bitwise XOR
  int e = a ^ b; // 00110000 in binary
  printf("The result of bitwise XOR: %d\n", e);

  // bitwise complement
  int f = ~a; // 00001001 in binary
  printf("The result of bitwise complement: %d\n", f);

  // left shift
  int g = a << 2; // 1111011000 in binary
  printf("The result of left shift: %d\n", g);

  // right shift
  int h = a >> 2; // 111101 in binary
  printf("The result of right shift: %d\n", h);

  printf("Cheerful Bitwise Operations Complete! Have a great day!");

  return 0;
}