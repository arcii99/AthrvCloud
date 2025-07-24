//FormAI DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>

int fibonacci(int n);

int main() {
  int input;

  printf("Enter the nth term of the Fibonacci sequence: ");
  scanf("%d", &input);

  printf("The %dth term of the Fibonacci sequence is %d\n", input, fibonacci(input));

  return 0;
}

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}