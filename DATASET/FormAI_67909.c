//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>

int main() {
  printf("Welcome to the Arithmetic program!\n");

  // Declare two input variables
  int num1, num2;

  printf("Please enter two numbers: ");

  // Read input from user and assign it to variables
  scanf("%d %d", &num1, &num2);

  printf("You entered %d and %d\n", num1, num2);

  // Perform addition and display result
  int sum = num1 + num2;
  printf("%d + %d = %d\n", num1, num2, sum);

  // Perform subtraction and display result
  int difference = num1 - num2;
  printf("%d - %d = %d\n", num1, num2, difference);

  // Perform multiplication and display result
  int product = num1 * num2;
  printf("%d * %d = %d\n", num1, num2, product);

  // Perform division and display result
  if (num2 == 0) {
    printf("Division by zero is not allowed.\n");
  } else {
    float quotient = (float) num1 / num2;
    printf("%d / %d = %.2f\n", num1, num2, quotient);
  }

  printf("Thank you for using the Arithmetic program!\n");

  return 0;
}