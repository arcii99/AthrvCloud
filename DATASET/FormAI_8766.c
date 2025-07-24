//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>

int main() {
  int num1 = 42;                // binary: 00101010
  int num2 = 24;                // binary: 00011000
  int result_and = num1 & num2; // binary: 00001000 (8)
  int result_or = num1 | num2;  // binary: 00111010 (58)
  int result_xor = num1 ^ num2; // binary: 00110010 (50)
  int result_not = ~num1;       // binary: 11010101 (-43)

  printf("num1 & num2 = %d\n", result_and);
  printf("num1 | num2 = %d\n", result_or);
  printf("num1 ^ num2 = %d\n", result_xor);
  printf("~num1 = %d\n", result_not);

  // shifting operations
  int num3 = 10;               // binary: 00001010
  int result_left = num3 << 2; // binary: 00101000 (40)
  int result_right = num3 >> 1;// binary: 00000101 (5)

  printf("num3 << 2 = %d\n", result_left);
  printf("num3 >> 1 = %d\n", result_right);

  return 0;
}