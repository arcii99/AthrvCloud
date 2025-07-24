//FormAI DATASET v1.0 Category: Arithmetic ; Style: light-weight
/* 
  A lightweight program that generates the first n Fibonacci numbers using a recursive function.
  Author: Your Name
*/

#include <stdio.h>

/* Function prototype */
int fib(int n);

int main() {
  int n, i;

  printf("Enter the number of Fibonacci numbers to generate: ");
  scanf("%d", &n);

  printf("The first %d Fibonacci numbers are:\n", n);

  for (i = 0; i < n; i++) {
    printf("%d ", fib(i));
  }

  return 0;
}

/* Recursive function to calculate Fibonacci sequence */
int fib(int n) {
  if (n == 0 || n == 1)
    return n;
  else
    return (fib(n - 1) + fib(n - 2));
}