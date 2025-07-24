//FormAI DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>

// Program to calculate the factorial of a positive integer using recursion

int factorial(int num) {
  if (num == 0 || num == 1) { // base cases
    return 1;
  }
  else {
    return num * factorial(num - 1); // recursion
  }
}

int main() {
  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);
  printf("Factorial of %d is: %d", num, factorial(num));
  return 0;
}