//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>

int fib(int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  printf("Enter a number to generate Fibonacci sequence: ");
  scanf("%d", &n);
  
  printf("Fibonacci sequence:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", fib(i));
  }
  
  printf("\n");

  // Create Fibonacci sequence visualizer
  int sequence[n];
  for (int i = 0; i < n; i++) {
    sequence[i] = fib(i);
  }
  
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (sequence[i] > max) {
      max = sequence[i];
    }
  }

  for (int i = max; i >= 1; i--) {
    for (int j = 0; j < n; j++) {
      if (i <= sequence[j]) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}