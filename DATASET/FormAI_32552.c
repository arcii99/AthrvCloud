//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

int main()
{
  int num; // a variable to store a number
  printf("Enter a number : ");
  scanf("%d", &num);

  // Bitwise left shift operator example
  int shifted_num = num << 3;
  printf("Number after shift by 3 bits : %d\n", shifted_num);

  // Bitwise right shift operator example
  int shifted_num2 = num >> 2;
  printf("Number after shift by 2 bits : %d\n", shifted_num2);

  // Bitwise OR operator example
  int num1 = 10;
  int num2 = 20;
  int result = num1 | num2;
  printf("Bitwise OR result of %d and %d is : %d\n", num1, num2, result);

  // Bitwise AND operator example
  result = num1 & num2;
  printf("Bitwise AND result of %d and %d is : %d\n", num1, num2, result);

  // Bitwise XOR operator example
  result = num1 ^ num2;
  printf("Bitwise XOR result of %d and %d is : %d\n", num1, num2, result);

  // Bitwise NOT operator example
  result = ~num;
  printf("Bitwise NOT of %d is : %d\n", num, result);

  // Bitwise AND NOT operator example
  result = num1 & ~num2;
  printf("Bitwise AND NOT result of %d and %d is : %d\n", num1, num2, result);

  return 0;
}