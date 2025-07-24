//FormAI DATASET v1.0 Category: Bitwise operations ; Style: decentralized
#include <stdio.h>

int main() {
  int num1 = 8; // binary: 00001000
  int num2 = 3; // binary: 00000011

  // Bitwise AND
  int result1 = num1 & num2; // binary result: 00000000

  printf("%d & %d = %d\n", num1, num2, result1);

  // Bitwise OR
  int result2 = num1 | num2; // binary result: 00001011

  printf("%d | %d = %d\n", num1, num2, result2);

  // Bitwise XOR
  int result3 = num1 ^ num2; // binary result: 00001011

  printf("%d ^ %d = %d\n", num1, num2, result3);

  // Bitwise NOT
  int result4 = ~num1; // binary result: 11110111

  printf("~%d = %d\n", num1, result4);

  // Left shift by 2
  int result5 = num1 << 2; // binary result: 00100000

  printf("%d << 2 = %d\n", num1, result5);

  // Right shift by 2
  int result6 = num1 >> 2; // binary result: 00000010

  printf("%d >> 2 = %d\n", num1, result6);

  return 0;
}