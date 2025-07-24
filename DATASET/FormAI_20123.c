//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

int fibonacci(int n);

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  printf("Fibonacci of %d: %d", n, fibonacci(n));
  return 0;
}

int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  } else {
    // Use multiple variables to track previous results
    int first = 0, second = 1, result;
    for (int i = 2; i <= n; i++) {
      result = first + second;
      first = second;
      second = result;
    }
    return result;
  }
}