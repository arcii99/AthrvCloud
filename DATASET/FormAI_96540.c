//FormAI DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>

int main() {
  int num1, num2;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  printf("\n-------------Bitwise Operators in C-------------\n");

  // Bitwise AND Operator
  printf("\nBitwise AND (&):\n");
  printf("%d & %d = %d\n", num1, num2, num1 & num2);

  // Bitwise OR Operator
  printf("\nBitwise OR (|):\n");
  printf("%d | %d = %d\n", num1, num2, num1 | num2);

  // Bitwise XOR Operator
  printf("\nBitwise XOR (^):\n");
  printf("%d ^ %d = %d\n", num1, num2, num1 ^ num2);

  // Bitwise Complement Operator
  printf("\nBitwise Complement (~):\n");
  printf("~%d = %d\n", num1, ~num1);
  printf("~%d = %d\n", num2, ~num2);

  // Bitwise Left Shift Operator
  printf("\nBitwise Left Shift (<<):\n");
  printf("%d << %d = %d\n", num1, num2, num1 << num2);

  // Bitwise Right Shift Operator
  printf("\nBitwise Right Shift (>>):\n");
  printf("%d >> %d = %d\n", num1, num2, num1 >> num2);

  printf("\n---------------End of Program---------------\n");
  return 0;
}