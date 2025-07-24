//FormAI DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>

void countDown(int n) {
  if (n < 0) {
    return;
  }
  printf("%d ", n);
  countDown(n-1);
}

void countUp(int n) {
  if (n < 0) {
    return;
  }
  countUp(n-1);
  printf("%d ", n);
}

int sum(int n) {
  if (n == 1) {
    return 1;
  }
  return n + sum(n-1);
}

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n-1);
}

int fibonacci(int n) {
  if (n < 2) {
    return n;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  printf("Counting down from 5:\n");
  countDown(5);
  
  printf("\nCounting up to 5:\n");
  countUp(5);
  
  printf("\nSum of first 5 numbers: %d\n", sum(5));
  
  printf("Factorial of 5: %d\n", factorial(5));
  
  printf("Fibonacci sequence up to 8: ");
  for (int i = 0; i < 8; i++) {
    printf("%d ", fibonacci(i));
  }
  printf("\n");
  
  return 0;
}