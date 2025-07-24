//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>

int Factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * Factorial(n - 1);
  }
}

int main() {
  int input, result;
  printf("Enter a number to calculate its factorial: ");
  scanf("%d", &input);
  result = Factorial(input);
  printf("The factorial of %d is %d\n", input, result);
  return 0;
}