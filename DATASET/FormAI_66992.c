//FormAI DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>

void divide(int num1, int num2) {
  // Check if the divisor is zero
  if (num2 == 0) {
    // Throw an error message
    printf("Error: Cannot divide by zero!\n");
    // Return control to the caller
    return;
  }
  // Calculate the quotient
  int result = num1 / num2;
  // Print the result
  printf("%d divided by %d is %d\n", num1, num2, result);
}

int main() {
  // Take two integers as input
  int a, b;
  printf("Enter the dividend: ");
  scanf("%d", &a);
  printf("Enter the divisor: ");
  scanf("%d", &b);
  // Call the divide function
  divide(a, b);
  // Return 0 to indicate successful termination of the program
  return 0;
}