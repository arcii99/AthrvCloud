//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>

int main() {
  int n = 5; // n determines the number of rows

  printf("Printing C Pattern with %d rows\n\n", n);

  // loop for printing upper part of C
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == 1 || i == 1 || i == n) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // loop for printing lower part of C
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == 1 || i == n) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}