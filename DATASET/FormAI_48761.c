//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

// This is a program that shows our gratitude for the wonderful tool that is recursion!

void countdown(int n) {
  if (n < 1) {
    printf("Blast off!\n");
  } else {
    printf("%d\n", n);
    countdown(n-1);
  }
}

int factorial(int n) {
  if (n == 1) {
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
  // Let's show our gratitude by counting down from 10 and printing the factorial and Fibonacci sequence for 10.
  printf("Thank you, recursion!\n\n");
  countdown(10);
  printf("\n10! = %d\n", factorial(10));
  printf("Fibonacci sequence up to 10: ");
  for (int i = 0; i <= 10; i++) {
    printf("%d ", fibonacci(i));
  }
  printf("\n");

  return 0;
}