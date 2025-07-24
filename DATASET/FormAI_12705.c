//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {
  int num1 = 5, num2 = 9;
  printf("num1 = %d, num2 = %d\n\n", num1, num2);

  // Bitwise Operations
  printf("num1 & num2 = %d\n", num1 & num2);
  printf("num1 | num2 = %d\n", num1 | num2);
  printf("num1 ^ num2 = %d\n", num1 ^ num2);
  printf("~num1 = %d\n", ~num1);
  printf("num2 << 2 = %d\n", num2 << 2);
  printf("num2 >> 1 = %d\n", num2 >> 1);

  // Unique Custom Operations
  printf("\nCustom Operations:\n");
  printf("num1 | (num2 << 16) = %d\n", num1 | (num2 << 16));
  printf("(num1 & 0x3) ^ (num2 & 0xF) = %d\n", (num1 & 0x3) ^ (num2 & 0xF));

  return 0;
}