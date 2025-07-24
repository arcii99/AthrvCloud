//FormAI DATASET v1.0 Category: Recursive ; Style: optimized
#include <stdio.h>

// define a recursive function to calculate factorial
int factorial(int num) {
  if (num == 1 || num == 0) {
    return 1;
  } else {
    return num * factorial(num-1);
  }
}

int main() {
  int n = 5;
  int fact = factorial(n);
  printf("Factorial of %d is %d", n, fact);
  return 0;
}