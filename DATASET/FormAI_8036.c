//FormAI DATASET v1.0 Category: Recursive ; Style: systematic
#include <stdio.h>

int fibonacci(int n);

int main() {
  int n;

  printf("Enter a positive integer: ");
  scanf("%d", &n);

  printf("Fibonacci series till %d terms: \n", n);
  for (int i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }

  return 0;
}

int fibonacci(int n) {
  // base cases
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }

  // recursive case
  return fibonacci(n - 1) + fibonacci(n - 2);
}