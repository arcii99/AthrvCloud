//FormAI DATASET v1.0 Category: Recursive ; Style: imaginative
#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int num;
  printf("Welcome to the Magic Recursive Factorial Calculator!\n");
  printf("Enter a positive integer: ");
  scanf("%d", &num);
  if (num < 0) {
    printf("Sorry, we can only calculate factorials of positive integers.\n");
    printf("Please come back when you have a positive integer!\n");
  } else {
    printf("Calculating the factorial of %d...\n", num);
    int result = factorial(num);
    printf("The factorial of %d is: %d\n", num, result);
    printf("Thank you for using the Magic Recursive Factorial Calculator!\n");
  }
  return 0;
}