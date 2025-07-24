//FormAI DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>

int factorial (int x) {
  if (x == 1) {
    return 1;
  } else {
    return x * factorial(x - 1);
  }
}

int fibonacci(int x) {
  if (x == 0) {
    return 0;
  } else if (x == 1) {
    return 1;
  } else {
    return fibonacci(x-1) + fibonacci(x-2);
  }
}

int main() {
  int input;
  int output1, output2;

  printf("Enter a number: ");
  scanf("%d", &input);

  output1 = factorial(input);
  output2 = fibonacci(input);

  printf("Factorial of %d is %d\n", input, output1);
  printf("Fibonacci number of %d is %d\n", input, output2);

  return 0;
}