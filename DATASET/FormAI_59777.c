//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>

// Function to calculate and print the Fibonacci sequence
void fibonacci(int n) {
  int fib_nminus2 = 0; // Initialize first two numbers of sequence
  int fib_nminus1 = 1;

  for (int i = 0; i < n; i++) {
    int current_fib; // Calculate next number in sequence
    if (i == 0) {
      current_fib = fib_nminus2;
    } else if (i == 1) {
      current_fib = fib_nminus1;
    } else {
      current_fib = fib_nminus2 + fib_nminus1;
      fib_nminus2 = fib_nminus1;
      fib_nminus1 = current_fib;
    }

    // Print current number in sequence as a bar graph with asterisks
    for (int j = 0; j < current_fib; j++) {
      printf("*");
    }
    printf("\n");
  }
}

int main() {
  int n; // Get input from user
  printf("Enter the number of terms in the Fibonacci sequence to visualize: ");
  scanf("%d", &n);
  printf("Visualizing the first %d terms in the Fibonacci sequence...\n", n);

  fibonacci(n); // Call function to calculate and print sequence

  return 0;
}