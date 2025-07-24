//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

// Math function to calculate Fibonacci sequence
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
  scanf("%d", &n); // Get integer from user

  // Print Fibonacci sequence
  printf("Fibonacci sequence:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", fib(i));
  }
  return 0;
}