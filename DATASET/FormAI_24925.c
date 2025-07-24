//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>

int main() {
  int n;
  printf("Enter the value of n: ");
  scanf("%d", &n);

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  printf("Sum of the first %d natural numbers is %d\n", n, sum);

  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  printf("Factorial of %d is %d\n", n, fact);

  int fib1 = 0, fib2 = 1;
  printf("Fibonacci Series up to %d terms: ", n);
  printf("%d, %d, ", fib1, fib2);
  for (int i = 3; i <= n; i++) {
    int fib = fib1 + fib2;
    printf("%d, ", fib);
    fib1 = fib2;
    fib2 = fib;
  }
  printf("\n");

  printf("Prime numbers up to %d are: ", n);
  for (int i = 2; i <= n; i++) {
    int prime = 1;
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}