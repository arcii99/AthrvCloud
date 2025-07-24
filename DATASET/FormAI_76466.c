//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>

int factorial(int n) {
  if (n == 0) { // base case
    return 1;
  } else {
    return n * factorial(n - 1); // recursive call
  }
}

int main() {
  int n = 5;
  int result = factorial(n); // calling the recursive function

  printf("The factorial of %d is %d\n", n, result);

  return 0;
}