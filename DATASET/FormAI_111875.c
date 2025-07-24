//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  int n, i = 0, j = 1, k = 1; // initialization of the starting values

  printf("Enter the length of Fibonacci Sequence: ");
  scanf("%d", &n);

  printf("\n"); // leave a line

  while (i <= n) {
    if (i == 0) {
      printf("%d, ", i);
      i += j; // update values
    } else if (i == 1) {
      printf("%d, ", i);
      i += j; // update values
    } else {
      printf("%d, ", i);
      k = j; // temporary variable to hold previous value of j
      j = i; // update values
      i += k; // update values
    }
  }

  return 0;
}