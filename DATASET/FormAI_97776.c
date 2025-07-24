//FormAI DATASET v1.0 Category: Recursive ; Style: excited
#include <stdio.h>

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n;
  printf("Enter the n-th term of the Fibonacci series: ");
  scanf("%d", &n);
  printf("The %d-th term of the Fibonacci series is: %d\n", n, fibonacci(n));
  return 0;
}