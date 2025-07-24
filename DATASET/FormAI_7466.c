//FormAI DATASET v1.0 Category: Arithmetic ; Style: surprised
#include <stdio.h>

int main() {
  // Declare variables
  int num1, num2, sum, diff, prod, quo, rem;

  // Get input from user
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Calculate the sum of two numbers
  sum = num1 + num2;
  printf("The sum of %d and %d is %d\n", num1, num2, sum);

  // Calculate the difference of two numbers
  diff = num1 - num2;
  printf("The difference of %d and %d is %d\n", num1, num2, diff);

  // Calculate the product of two numbers
  prod = num1 * num2;
  printf("The product of %d and %d is %d\n", num1, num2, prod);

  // Check if second number is not zero
  if (num2 != 0) {
    // Calculate the quotient of two numbers
    quo = num1 / num2;
    printf("The quotient of %d and %d is %d\n", num1, num2, quo);

    // Calculate the remainder of two numbers
    rem = num1 % num2;
    printf("The remainder of %d and %d is %d\n", num1, num2, rem);
  } else {
    printf("Cannot divide by zero!\n");
  }

  printf("Woah! Did you see that?! I calculated the sum, difference, product, quotient and remainder of two numbers in just one program!\n");

  return 0;
}