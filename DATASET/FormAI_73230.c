//FormAI DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>

/* This program reads in two integers and performs basic arithmetic operations */

int main() {
  int num1, num2;
  printf("Enter two integers separated by a space: ");
  scanf("%d %d", &num1, &num2); // read in two integers from user
  
  printf("Sum: %d\n", num1 + num2);
  printf("Difference: %d\n", num1 - num2);
  printf("Product: %d\n", num1 * num2);

  if (num2 != 0) { // check for division by zero error
    printf("Division: %.2f\n", (float)num1 / num2);
  } else {
    printf("Cannot divide by zero.\n");
  }

  printf("Reminder of the division: %d\n", num1 % num2);
  
  printf("Bitwise and: %d\n", num1 & num2);
  printf("Bitwise or: %d\n", num1 | num2);
  printf("Bitwise xor: %d\n", num1 ^ num2);
  printf("Bitwise complement of the first number: %d\n", ~num1);

  if (num2 != 0) { // check for shift by zero error
    printf("Left shift of the first number by the second number: %d\n", num1 << num2);
    printf("Right shift of the first number by the second number: %d\n", num1 >> num2);
  } else {
    printf("Cannot shift by zero.\n");
  }

  printf("Greater than operator: %d\n", num1 > num2);
  printf("Greater than or equal to operator: %d\n", num1 >= num2);
  printf("Less than operator: %d\n", num1 < num2);
  printf("Less than or equal to operator: %d\n", num1 <= num2);
  printf("Equal to operator: %d\n", num1 == num2);
  printf("Not equal to operator: %d\n", num1 != num2);

  return 0;
}