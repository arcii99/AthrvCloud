//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>

int factorial(int n) {
  if (n == 1) { // base case
    return 1;
  } else {
    return n * factorial(n - 1); // recursive case
  }
}

int fibonacci(int n) {
  if (n == 0) { // base case
    return 0;
  } else if (n == 1) { // base case
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2); // recursive case
  }
}

int main() {
  int n, choice;
  printf("Enter an integer: ");
  scanf("%d", &n);
  printf("Enter 1 to calculate factorial or 2 to calculate fibonacci: ");
  scanf("%d", &choice);
  if (choice == 1) {
    int result = factorial(n);
    printf("Factorial of %d is %d\n", n, result);
  } else if (choice == 2) {
    int result = fibonacci(n);
    printf("Fibonacci number at position %d is %d\n", n, result);
  } else {
    printf("Invalid choice\n");
  }
  return 0;
}