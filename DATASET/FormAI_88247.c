//FormAI DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>

int factorial(int n) {
  if (n == 0 || n == 1) { // base case
    return 1;
  } else {
    return n * factorial(n-1); // recursive call
  }
}

int fibonacci(int n) {
  if (n == 0 || n == 1) { // base case
    return n;
  } else {
    return fibonacci(n-1) + fibonacci(n-2); // recursive call
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  printf("Factorial of %d is %d\n", num, factorial(num));
  printf("Fibonacci sequence up to %d: ", num);
  for (int i = 0; i <= num; i++) {
    printf("%d ", fibonacci(i));
  }

  return 0;
}