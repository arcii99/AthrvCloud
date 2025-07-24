//FormAI DATASET v1.0 Category: Recursive ; Style: scientific
#include <stdio.h>

// This is a recursive function that finds the factorial of an integer input.
// If input is negative, it returns -1 to indicate an error.
int factorial(int n) {
  // Base case: if n is 0 or 1, return 1.
  if (n <= 1) {
    return 1;
  }
  // Recursive case: compute the factorial of n-1 and multiply by n.
  else {
    int result = factorial(n-1) * n;
    return result;
  }
}

int main() {
  // Declare variables.
  int n, result;
  
  // Prompt user for input.
  printf("Enter an integer: ");
  scanf("%d", &n);
  
  // Call the recursive function to compute the factorial.
  result = factorial(n);
  
  // Check for errors (-1) and print result.
  if (result == -1) {
    printf("Error: Input must be a non-negative integer.\n");
  }
  else {
    printf("The factorial of %d is %d.\n", n, result);
  }
  
  return 0;
}