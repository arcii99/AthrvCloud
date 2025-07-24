//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

int fibonacci(int n) {
  if (n < 2) {
    return n;
  }

  return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  int n;
  printf("Let's generate some energy through recursion. Gimme a number: ");
  scanf("%d", &n);
  printf("Here we gooooo! The Fibonacci number at position %d is %d\n", n, fibonacci(n));
  printf("Can you feel the energy flowing through you now?\n");

  return 0;
}