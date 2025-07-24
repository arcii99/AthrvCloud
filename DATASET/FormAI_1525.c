//FormAI DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

int factorial(int n) {
  if (n < 0) {
    printf("Factorial of negative numbers is undefined\n");
    return 0;
  } else if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int num;

  printf("Enter a number to find its factorial: ");
  scanf("%d", &num);

  int result = factorial(num);

  if (result != 0) {
    printf("The factorial of %d is %d\n", num, result);
  }

  return 0;
}