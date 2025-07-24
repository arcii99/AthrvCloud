//FormAI DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
/* A unique C Pattern printing program */
/* inspired by Donald E. Knuth */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 5; // number of rows
  int i, j, k;

  // Print upper half of the pattern
  for (i = 1; i <= n; i++) {
    // Print spaces
    for (k = 1; k <= n - i; k++) {
      printf(" ");
    }

    // Print numbers
    for (j = i; j >= 1; j--) {
      printf("%d", j);
    }

    // Print spacing
    for (k = 1; k <= i - 1; k++) {
      printf(" ");
    }

    // Print numbers
    for (j = 1; j <= i; j++) {
      printf("%d", j);
    }

    // Go to next line
    printf("\n");
  }

  // Print lower half of the pattern
  for (i = n - 1; i >= 1; i--) {
    // Print spaces
    for (k = 1; k <= n - i; k++) {
      printf(" ");
    }

    // Print numbers
    for (j = i; j >= 1; j--) {
      printf("%d", j);
    }

    // Print spacing
    for (k = 1; k <= i - 1; k++) {
      printf(" ");
    }

    // Print numbers
    for (j = 1; j <= i; j++) {
      printf("%d", j);
    }

    // Go to next line
    printf("\n");
  }

  return 0;
}