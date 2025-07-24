//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>

int main() {
  int num1, num2, sum, difference, product, quotient, remainder;

  printf("Welcome to the visionary calculator!\n");

  printf("Please enter two numbers to perform arithmetic operations on:\n");
  scanf("%d %d", &num1, &num2);

  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;

  printf("The sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The difference between %d and %d is %d.\n", num1, num2, difference);
  printf("The product of %d and %d is %d.\n", num1, num2, product);
  printf("The quotient of %d and %d is %d with a remainder of %d.\n", num1, num2, quotient, remainder);

  if(num1 == 0 || num2 == 0) {
    printf("Visionary Mode ON!\n");
    if(num1 == 0) {
      num1 = 1;
    }
    if(num2 == 0) {
      num2 = 1;
    }

    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;

    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    printf("The difference between %d and %d is %d.\n", num1, num2, difference);
    printf("The product of %d and %d is %d.\n", num1, num2, product);
    printf("The quotient of %d and %d is %d with a remainder of %d.\n", num1, num2, quotient, remainder);
  }

  printf("Thank you for using the visionary calculator!\n");

  return 0;
}