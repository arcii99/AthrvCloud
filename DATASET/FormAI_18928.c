//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_fibonacci_sequence(int n) {
  int fibonacci_seq[n];
  fibonacci_seq[0] = 0;
  fibonacci_seq[1] = 1;

  // Calculate the Fibonacci sequence
  for (int i = 2; i < n; i++) {
    fibonacci_seq[i] = fibonacci_seq[i-1] + fibonacci_seq[i-2];
  }

  // Print out the sequence in a colorful way!
  printf("\nFibonacci Sequence: ");
  for (int i = 0; i < n; i++) {
    if (fibonacci_seq[i] % 3 == 0) {
      printf("\033[0;32m%d\033[0m ", fibonacci_seq[i]); // Print in green
    } else if (fibonacci_seq[i] % 2 == 0) {
      printf("\033[0;33m%d\033[0m ", fibonacci_seq[i]); // Print in yellow
    } else {
      printf("\033[0;35m%d\033[0m ", fibonacci_seq[i]); // Print in magenta
    }
  }
  printf("\n\n");
}

int main() {
  int n;

  printf("\n\nWelcome to the Fibonacci Sequence Visualizer!\n");
  printf("Please enter the length of the sequence you want to generate: ");
  scanf("%d", &n);

  // Check input
  if (n <= 0 || n > 100) {
    printf("\033[0;31mError: Invalid input. Please enter a number between 1 and 100.\033[0m\n");
    return 1;
  }

  print_fibonacci_sequence(n);

  printf("Thank you for using the Fibonacci Sequence Visualizer!\n\n");

  return 0;
}