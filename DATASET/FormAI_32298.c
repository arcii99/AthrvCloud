//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>

int main() {
  
  printf("Welcome to the happy world of arithmetic!\n");
  printf("Today we are going to play some games.\n");
  printf("Are you ready to have some fun?\n");

  int num1, num2, sum, difference, product, quotient, remainder;

  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  sum = num1 + num2;
  printf("%d + %d = %d\n", num1, num2, sum);

  difference = num1 - num2;
  printf("%d - %d = %d\n", num1, num2, difference);

  product = num1 * num2;
  printf("%d * %d = %d\n", num1, num2, product);

  quotient = num1 / num2;
  printf("%d / %d = %d\n", num1, num2, quotient);

  remainder = num1 % num2;
  printf("%d %% %d = %d\n", num1, num2, remainder);

  printf("That was so much fun!\n");
  printf("Let's do it again sometime.\n");
  printf("Bye for now!\n");

  return 0;
}