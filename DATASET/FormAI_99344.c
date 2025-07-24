//FormAI DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>

int factorial(int n);

int main() {
  int n, result;
  printf("Enter a number: ");
  scanf("%d", &n);
  result = factorial(n);
  printf("Factorial of %d is %d", n, result);
  return 0;
}

int factorial(int n) {
  if (n < 0) {
    printf("Factorial of negative number is not defined");
    return -1;
  } else if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}