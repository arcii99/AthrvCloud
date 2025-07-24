//FormAI DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>

int factorial(int num) {
  // base case
  if (num == 0) {
    return 1;
  }
  // recursive case
  return num * factorial(num - 1);
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  int fact = factorial(num);
  printf("The factorial of %d is %d.\n", num, fact);

  return 0;
}