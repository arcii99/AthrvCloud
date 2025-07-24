//FormAI DATASET v1.0 Category: Recursive ; Style: intelligent
#include <stdio.h>

int factorial(int n) {
  if (n < 1) {  // base case
    return 1;
  } else {  // recursive case
    return n * factorial(n - 1);
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  printf("Factorial of %d is %d", num, factorial(num));
  return 0;
}