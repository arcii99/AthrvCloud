//FormAI DATASET v1.0 Category: Recursive ; Style: portable
#include <stdio.h>

int factorial(int n);

int main() {
  int num;
  printf("Enter a number to find its factorial: ");
  scanf("%d", &num);
  if (num < 0) {
    printf("Error: Factorial of negative number does not exist.");
  } else {
    int fact = factorial(num);
    printf("The factorial of %d is %d.\n", num, fact);
  }
  return 0;
}

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}