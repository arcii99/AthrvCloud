//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>

void printFibonacci(int num) {
  int fib[num], i;
  fib[0] = 0;
  fib[1] = 1;
  printf("Fibonacci: %d %d ", fib[0], fib[1]);
  for (i = 2; i < num; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    printf("%d ", fib[i]);
  }
}

int main() {
  int num;
  printf("Enter the number of Fibonacci terms to display: ");
  scanf("%d", &num);
  printFibonacci(num);
  return 0;
}