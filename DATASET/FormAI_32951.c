//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return n * factorial(n-1);
}

int main() {
  int choice, n;
  printf("Enter your choice:\n1. Fibonacci \n2. Factorial\n");
  scanf("%d", &choice);
  printf("Enter n: ");
  scanf("%d", &n);

  switch (choice) {
    case 1:
      printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
      break;
    case 2:
      printf("Factorial(%d) = %d\n", n, factorial(n));
      break;
    default:
      printf("Invalid choice\n");
  }
  
  return 0;
}