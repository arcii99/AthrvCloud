//FormAI DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>

int main() {

  int num1, num2, sum, difference, product, quotient, remainder;

  printf("Welcome to the Arithmetic Program!\n");
  printf("Please enter two integers: ");

  scanf("%d %d", &num1, &num2);

  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;

  printf("\n\nThe sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The difference of %d and %d is %d.\n", num1, num2, difference);
  printf("The product of %d and %d is %d.\n", num1, num2, product);
  printf("The quotient of %d and %d is %d with a remainder of %d.\n", num1, num2, quotient, remainder);

  printf("\nThanks for using the Arithmetic Program!\n");
  return 0;
}