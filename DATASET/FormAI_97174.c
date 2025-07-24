//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int num;

  printf("Enter a positive integer: ");
  scanf("%d", &num);

  printf("Fibonacci series of %d:\n", num);

  for (int i = 0; i < num; i++) {
    printf("%d ", fibonacci(i));
  }

  return 0;
}