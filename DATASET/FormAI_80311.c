//FormAI DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>

int factorial(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1); // recursive statement
  }
}

int main() {
  int num = 5;
  int result = factorial(num);
  printf("%d! = %d", num, result);
  return 0;
}