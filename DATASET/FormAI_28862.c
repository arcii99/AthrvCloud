//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: dynamic
#include <stdio.h>

// function to generate Fibonacci sequence
int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return (fibonacci(n-1) + fibonacci(n-2));
  }
}

int main() {
  int n, i;

  // user input for number of terms in sequence
  printf("Enter the number of terms in the Fibonacci sequence: ");
  scanf("%d", &n);

  // guard clause to ensure positive integer input
  if (n <= 0) {
    printf("Invalid input. Number of terms must be a positive integer.\n");
    return 0;
  }

  printf("\nThe Fibonacci sequence: \n\n");

  // print Fibonacci sequence using for loop and fibonacci function
  for (i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }

  return 0;
}