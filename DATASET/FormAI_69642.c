//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: realistic
#include <stdio.h>

int fibonacci(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n, i;
  printf("Enter the number of terms for the Fibonacci sequence: ");
  scanf("%d", &n);

  printf("Here is the Fibonacci sequence with %d terms:\n", n);
  printf("0, "); // The first two terms of the sequence are always 0 and 1
  for (i = 1; i < n-1; i++) {
    printf("%d, ", fibonacci(i));
  }
  printf("%d\n", fibonacci(i));

  return 0;
}