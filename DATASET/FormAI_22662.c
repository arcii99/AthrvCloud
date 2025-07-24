//FormAI DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include <stdio.h>

int main() {
  int rows = 6;
  int i, j, k, m;

  for (i = 1; i <= rows - 1; i++) {
    for (j = 1; j <= i; j++)
      printf("*");
    for (k = 1; k <= 2 * rows - 2 * i; k++)
      printf(" ");
    for (m = 1; m <= i; m++)
      printf("*");
    printf("\n");
  }

  for (i = rows - 1; i >= 1; i--) {
    for (j = 1; j <= i; j++)
      printf("*");
    for (k = 1; k <= 2 * rows - 2 * i; k++)
      printf(" ");
    for (m = 1; m <= i; m++)
      printf("*");
    printf("\n");
  }

  return 0;
}