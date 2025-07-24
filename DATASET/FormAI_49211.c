//FormAI DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the Happy Arithmetic program!\n\n");

  int num1, num2, sum, diff, prod, quo, rem;

  printf("Please enter two integer values:\n");
  scanf("%d %d", &num1, &num2);

  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;
  quo = num1 / num2;
  rem = num1 % num2;

  printf("\n\nThe results are in!\n\n");
  printf("The sum of %d and %d is %d\n", num1, num2, sum);
  printf("The difference between %d and %d is %d\n", num1, num2, diff);
  printf("The product of %d and %d is %d\n", num1, num2, prod);
  printf("The quotient of %d divided by %d is %d with a remainder of %d\n", num1, num2, quo, rem);

  printf("\n\nHooray! Your happy arithmetic program has completed successfully!");

  return 0;
}