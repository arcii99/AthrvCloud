//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include <stdio.h>

int fibonacci(int n) {
  if (n <= 1)
    return n;
  else
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  int n, i;
  printf("Enter the number of terms you want in your Fibonacci sequence: ");
  scanf("%d", &n);
  printf("Your Fibonacci sequence is: ");
  for (i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }
  return 0;
}