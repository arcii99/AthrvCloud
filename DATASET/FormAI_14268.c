//FormAI DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>

int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  
  printf("Fibonacci sequence:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }
  
  return 0;
}