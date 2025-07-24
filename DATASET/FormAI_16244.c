//FormAI DATASET v1.0 Category: Recursive ; Style: safe
#include<stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int n) {
  // Base case: factorial of 0 is 1
  if (n == 0) {
    return 1;
  }
  // Recursive case: factorial of n is n * factorial(n-1)
  else {
    return n * factorial(n-1);
  }
}

int main() {
  int num, result;
  printf("Enter a non-negative integer: ");
  scanf("%d", &num);
  // Error checking: make sure num is non-negative
  if (num < 0) {
    printf("Error: entered value is negative.\n");
    return 1;
  }
  // Calculate the factorial of the input number using the factorial function
  result = factorial(num);
  printf("The factorial of %d is %d\n", num, result);
  return 0;
}