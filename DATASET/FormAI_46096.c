//FormAI DATASET v1.0 Category: Scientific ; Style: curious
#include <stdio.h>

// Declare a function to calculate the factorial of a number
int factorial(int num) {
  int fact = 1;
  for (int i = num; i >= 1; i--) {
    fact *= i;
  }
  return fact;
}

int main() {
  int input;
  printf("Welcome to the factorial calculator!\n");
  printf("Please enter a number to calculate its factorial: ");
  scanf("%d", &input);

  // Check if the input is a negative number
  if (input < 0) {
    printf("Sorry, factorial of negative numbers does not exist.");
    return 1;
  }

  // Calculate the factorial of the input number
  int fact_result = factorial(input);

  // Print the result to the screen
  printf("The factorial of %d is %d.", input, fact_result);

  return 0;
}