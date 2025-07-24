//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

int main() {
  int num1 = 7;
  int num2 = 9;

  printf("For num1 = %d and num2 = %d\n", num1, num2);
  // bitwise AND operator
  int val = num1 & num2;
  printf("num1 & num2 = %d\n", val);

  // bitwise OR operator
  val = num1 | num2;
  printf("num1 | num2 = %d\n", val);

  // bitwise compliment operator
  val = ~num1;
  printf("~num1 = %d\n", val);

  // left shift operator
  val = num1 << 2;
  printf("num1 << 2 = %d\n", val);

  // right shift operator
  val = num2 >> 1;
  printf("num2 >> 1 = %d\n", val);

  // bitwise XOR operator
  val = num1 ^ num2;
  printf("num1 ^ num2 = %d\n", val);

  return 0;
}