//FormAI DATASET v1.0 Category: Recursive ; Style: complete
#include <stdio.h>

int factorial(int n) {
  if (n == 1 || n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int num;
  char choice;

  printf("Please choose a function:\n");
  printf("F - Fibonacci\n");
  printf("R - Factorial\n");
  printf("Enter your choice: ");
  scanf("%c", &choice);

  printf("Enter a number: ");
  scanf("%d", &num);

  switch (choice) {
    case 'f':
    case 'F':
      printf("The %d-th fibonacci number is %d\n", num, fibonacci(num));
      break;
    case 'r':
    case 'R':
      printf("The factorial of %d is %d\n", num, factorial(num));
      break;
    default:
      printf("Invalid choice!\n");
  }

  return 0;
}