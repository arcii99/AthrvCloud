//FormAI DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
  if (n <= 1) { // base case
    return n;
  } else { // recursive case
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int n;
  
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  
  // check if the input is valid
  if (n <= 0) {
    printf("Invalid input! Please enter a positive integer.\n");
    return 1; // exit with error code
  }
  
  // calculate the nth Fibonacci number
  int result = fibonacci(n);
  
  printf("The %dth Fibonacci number is %d.\n", n, result);
  
  return 0; // exit with success code
}