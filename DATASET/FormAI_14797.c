//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>

int main() {
  int num_one, num_two, sum, difference, product, quotient, remainder;

  // Ask user for input
  printf("Enter first number: ");
  scanf("%d", &num_one);

  printf("Enter second number: ");
  scanf("%d", &num_two);

  // Perform arithmetic operations
  sum = num_one + num_two;
  difference = num_one - num_two;
  product = num_one * num_two;
  quotient = num_one / num_two;
  remainder = num_one % num_two;

  // Display results
  printf("Sum: %d\n", sum);
  printf("Difference: %d\n", difference);
  printf("Product: %d\n", product);
  printf("Quotient: %d\n", quotient);
  printf("Remainder: %d\n", remainder);

  // Check if num_one is even or odd
  if (num_one % 2 == 0) {
    printf("%d is even.\n", num_one);
  } else {
    printf("%d is odd.\n", num_one);
  }

  // Check if num_two is positive, negative or zero
  if (num_two > 0) {
    printf("%d is positive.\n", num_two);
  } else if (num_two < 0) {
    printf("%d is negative.\n", num_two);
  } else {
    printf("%d is zero.\n", num_two);
  }

  return 0;
}