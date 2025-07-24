//FormAI DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>

int main() {
  int n, i, j;

  printf("Enter the number of rows for C pattern (odd numbers only): ");
  scanf("%d", &n);

  // Check if the number of rows is odd
  if (n % 2 != 0) {
    // Print the top half of the C shape
    for (i = 1; i <= n / 2 + 1; i++) {
      for (j = 1; j <= n; j++) {
        if ((j == 1 && i == 1) || (j == n && i <= n / 2 + 1)) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }

    // Print the bottom half of the C shape
    for (i = n / 2 + 2; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if ((j == 1 && i == n) || (j == n && i > n / 2 + 1)) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  } else {
    printf("Number of rows should be odd.");
  }

  return 0;
}