//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: intelligent
#include <stdio.h>

int main() {
  int n;

  // Ask user for the number of terms in the sequence
  printf("Enter the number of terms in the Fibonacci sequence: ");
  scanf("%d", &n);

  // Initialize the first two terms of the sequence
  int term1 = 0, term2 = 1;

  // Print the first two terms of the sequence
  printf("%d %d ", term1, term2);

  // Calculate and print the rest of the sequence
  for (int i = 3; i <= n; i++) {
    int nextTerm = term1 + term2;
    printf("%d ", nextTerm);
    term1 = term2;
    term2 = nextTerm;
  }

  return 0;
}