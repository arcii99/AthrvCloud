//FormAI DATASET v1.0 Category: Pattern printing ; Style: ephemeral
#include <stdio.h>

int main() {
  int n = 5; // number of rows
  int i, j, k;

  // printing C
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == 0 || i == n - 1) {
        printf("*");
      }
      else if (j == 0) {
        printf("*");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }

  // adding pattern
  for (i = n - 2; i > 0; i--) {
    for (j = n - i; j > 0; j--) {
      printf(" ");
    }
    for (k = 0; k < i; k++) {
      printf("#");
    }
    printf("\n");
  }

  return 0;
}