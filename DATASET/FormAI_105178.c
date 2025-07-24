//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>

int fib(int n) {
  if (n == 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  else {
    return fib(n-1) + fib(n-2);
  }
}

int main() {
  int n, i, j;
  printf("Enter number of terms:\n");
  scanf("%d", &n);
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
      printf("%d ", fib(j));
    }
    printf("\n");
  }
  return 0;
}