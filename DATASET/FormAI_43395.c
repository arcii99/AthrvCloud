//FormAI DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>

int main() {
  // Displaying a message to the user asking for input
  printf("Please enter two numbers: ");

  // Accepting user input
  int num1, num2;
  scanf("%d %d", &num1, &num2);

  // Performing arithmetic operations
  int sum = num1 + num2;
  int difference = num1 - num2;
  int product = num1 * num2;
  float quotient = (float)num1 / (float)num2;
  int remainder = num1 % num2;

  // Displaying the results to the user
  printf("Sum of %d and %d is %d\n", num1, num2, sum);
  printf("Difference between %d and %d is %d\n", num1, num2, difference);
  printf("Product of %d and %d is %d\n", num1, num2, product);
  printf("Quotient of %d and %d is %0.1f\n", num1, num2, quotient);
  printf("Remainder when %d is divided by %d is %d\n", num1, num2, remainder);

  // Displaying a message to the user
  printf("I hope you found this arithmetic program helpful!\n");

  return 0;
}