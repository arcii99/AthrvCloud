//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

int fibonacci(int n) {
  if (n == 0 || n == 1) { // Base case
    return n;
  } else { // Recursive case
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  printf("The %dth Fibonacci number is %d.\n", n, fibonacci(n));
  return 0;
}