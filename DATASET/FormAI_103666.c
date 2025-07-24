//FormAI DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 25;
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == 0 || i == n - 1)
        printf("*");
      else if (j == 0 && i > 0 && i < n - 1)
        printf("*");
      else if (j == n - 1 && i > 0 && i < n - 1)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }

  return 0;
}