//FormAI DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>

int factorial(int n) {
  if (n <= 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int n, f;
  printf("Welcome to the recursive program!\n\n");
  printf("Please enter a number for factorial calculation: ");
  scanf("%d", &n);
  f = factorial(n);
  printf("The factorial of %d is %d\n\n", n, f);
  printf("Please enter a number for fibonacci calculation: ");
  scanf("%d", &n);
  f = fibonacci(n);
  printf("The %dth fibonacci number is %d\n\n", n, f);
  printf("Thank you for using the program!\n");
  return 0;
}