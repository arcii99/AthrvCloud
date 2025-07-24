//FormAI DATASET v1.0 Category: Recursive ; Style: unmistakable
#include <stdio.h>

int factorial(int num) {
  if (num == 0) {
    return 1;
  } else {
    return num * factorial(num - 1);
  }
}

int main() {
  int input;

  printf("Enter a number: ");
  scanf("%d", &input);

  if (input < 0) {
    printf("Error! Factorial of negative number doesn't exist.");
  } else {
    int result = factorial(input);
    printf("The factorial of %d is %d\n", input, result);
  }

  return 0;
}