//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
  // Bitwise AND operator(&)
  int num1 = 10;   // 1010
  int num2 = 14;   // 1110
  int andResult = num1 & num2;  // 1010 & 1110 = 1010
  printf("%d & %d = %d\n", num1, num2, andResult);

  // Bitwise OR operator(|)
  int orResult = num1 | num2;  // 1010 | 1110 = 1110
  printf("%d | %d = %d\n", num1, num2, orResult);

  // Bitwise XOR operator(^)
  int xorResult = num1 ^ num2;  // 1010 ^ 1110 = 0100
  printf("%d ^ %d = %d\n", num1, num2, xorResult);

  // Bitwise Complement operator(~)
  int complement = ~num1;  // ~1010 = 0101 (two's complement)
  printf("~%d = %d\n", num1, complement);

  // Bitwise Left Shift operator(<<)
  int leftShift = num1 << 2;  // 1010 << 2 = 101000
  printf("%d << 2 = %d\n", num1, leftShift);

  // Bitwise Right Shift operator(>>)
  int rightShift = num2 >> 2;  // 1110 >> 2 = 0011
  printf("%d >> 2 = %d\n", num2, rightShift);

  return 0;
}