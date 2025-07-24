//FormAI DATASET v1.0 Category: Recursive ; Style: genious
#include <stdio.h>

int factorial(int n) {
  if(n <= 1) { // base case
    return 1;
  } else { // recursive case
    return n * factorial(n-1);
  }
}

int fibonacci(int n) {
  if(n == 0) { // base case
    return 0;
  } else if(n == 1) { // base case
    return 1;
  } else { // recursive case
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {

  printf("Welcome to the Recursive Functions!\n");

  // Factorial Example
  printf("Factorial of 5: %d\n", factorial(5));
  printf("Factorial of 7: %d\n", factorial(7));

  // Fibonacci Example
  printf("Fibonacci of 5: %d\n", fibonacci(5));
  printf("Fibonacci of 8: %d\n", fibonacci(8));

  return 0;
}