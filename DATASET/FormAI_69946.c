//FormAI DATASET v1.0 Category: Benchmarking ; Style: Ada Lovelace
#include <stdio.h>
#include <time.h>

// Recursive factorial function
int recursive_factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * recursive_factorial(n - 1);
  }
}

// Iterative factorial function
int iterative_factorial(int n) {
  int factorial = 1;

  for (int i = n; i > 0; i--) {
    factorial *= i;
  }

  return factorial;
}

int main() {
  int n = 12; // The number we'll calculate the factorial for

  clock_t start, end;

  // Time the recursive factorial function
  start = clock();
  int recursive_result = recursive_factorial(n);
  end = clock();
  double recursive_time = ((double) (end - start)) / CLOCKS_PER_SEC;

  // Time the iterative factorial function
  start = clock();
  int iterative_result = iterative_factorial(n);
  end = clock();
  double iterative_time = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Recursive factorial result: %d\n", recursive_result);
  printf("Recursive factorial runtime: %f seconds\n", recursive_time);

  printf("Iterative factorial result: %d\n", iterative_result);
  printf("Iterative factorial runtime: %f seconds\n", iterative_time);

  return 0;
}