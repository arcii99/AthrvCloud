//FormAI DATASET v1.0 Category: Educational ; Style: immersive
#include <stdio.h>

int main() {
  printf("Welcome to the Immersive C Programming Example!\n\n");

  int num1, num2, sum, diff, prod, quo, rem;

  printf("Please enter the first number: ");
  scanf("%d", &num1);
  printf("Please enter the second number: ");
  scanf("%d", &num2);

  sum = num1 + num2; // calculating sum
  printf("\n%d + %d = %d\n", num1, num2, sum);

  diff = num1 - num2; // calculating difference
  printf("%d - %d = %d\n", num1, num2, diff);

  prod = num1 * num2; // calculating product
  printf("%d x %d = %d\n", num1, num2, prod);

  quo = num1 / num2; // calculating quotient
  rem = num1 % num2; // calculating remainder
  printf("%d ÷ %d = %d with a remainder of %d\n", num1, num2, quo, rem);

  printf("\nThank you for trying the Immersive C Programming Example. Return any time for more fun and learning!\n");

  return 0;
}