//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: genious
#include <stdio.h>

int main() {
  int n, i, t1 = 0, t2 = 1, nextTerm;

  printf("Enter the number of terms: ");
  scanf("%d", &n);

  // Main loop to generate fibonacci sequence
  for (i = 1; i <= n; i++) {
    printf("%d, ", t1);
    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
  }
  printf("\n\n");

  // Visualize the sequence using asterisks
  printf("Fibonacci Sequence Visualizer:\n\n");
  for (i = 1; i <= n; i++) {
    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
    for (int j = 1; j <= t1; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}