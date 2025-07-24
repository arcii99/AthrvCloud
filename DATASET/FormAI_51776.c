//FormAI DATASET v1.0 Category: Recursive ; Style: portable
#include <stdio.h>

int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n-1) + fib(n-2);
  }
}

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Error: Invalid input. Must be a positive integer.\n");
    return 1;
  }

  printf("The %dth Fibonacci number is %d.\n", n, fib(n));

  return 0;
}