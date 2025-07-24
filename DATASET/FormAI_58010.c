//FormAI DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>

int factorial(int);

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  int result = factorial(n);
  printf("Factorial of %d is %d", n, result);
  return 0;
}

int factorial(int n) {
  if (n == 0) {
    printf("Calculating factorial of 0...\n");
    printf("Factorial of 0 is 1\n");
    return 1;
  }
  else {
    int fact = n * factorial(n - 1);
    printf("Calculating factorial of %d...\n", n);
    printf("Factorial of %d is %d\n", n, fact);
    return fact;
  }
}