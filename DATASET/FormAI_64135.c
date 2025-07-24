//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>

int main() {
  int current_term = 1;
  int previous_term = 0;
  int temp_term;

  // Print the first two terms of the sequence
  printf("%d\n%d\n", previous_term, current_term);

  // Keep generating terms until 20 have been printed
  for (int i = 0; i < 18; i++) {
    // Calculate the next term in the sequence
    temp_term = current_term;
    current_term += previous_term;
    previous_term = temp_term;

    // Print the term using ASCII characters
    for (int j = 0; j < current_term; j++) {
      printf("*");
    }
    printf("\n");
  }
}