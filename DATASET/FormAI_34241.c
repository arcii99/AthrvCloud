//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>

int fibonacci(int num) {
  if (num <= 1) {
    return num;
  } else {
    return fibonacci(num - 1) + fibonacci(num - 2);
  }
}

void printFibonacciSeries(int num) {
  int i;
  printf("Fibonacci series: ");

  for (i = 0; i < num; i++) {
    printf("%d ", fibonacci(i));
  }
}

int main() {
  int num;

  printf("Enter the number of terms: ");
  scanf("%d", &num);

  printFibonacciSeries(num);

  return 0;
}