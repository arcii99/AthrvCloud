//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>

int main() {
  int num1 = 23;
  int num2 = 43;
  printf("Hey there! I just generated two random numbers for you: %d and %d\n", num1, num2);

  int andResult = num1 & num2;
  printf("Let's try AND operation on them:\n  %d & %d = %d\n", num1, num2, andResult);

  int orResult = num1 | num2;
  printf("Now, let's try OR operation on them:\n  %d | %d = %d\n", num1, num2, orResult);

  int xorResult = num1 ^ num2;
  printf("Next, let's try XOR operation on them:\n  %d ^ %d = %d\n", num1, num2, xorResult);

  int leftShiftResult = num1 << 2;
  printf("Now, let's try left shift operation on %d: \n  %d << 2 = %d\n", num1, num1, leftShiftResult);

  int rightShiftResult = num1 >> 2;
  printf("Now, let's try right shift operation on %d: \n  %d >> 2 = %d\n", num1, num1, rightShiftResult);

  int complementResult = ~num1;
  printf("Finally, let's try complement operation on %d: \n  ~%d = %d\n", num1, num1, complementResult);

  return 0;
}