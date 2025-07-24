//FormAI DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, i, j, k, col, row, space, x;
  int mid, side, top, bottom;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  mid = n / 2;
  side = mid - 1;

  /* Print top half */
  for (row = 1; row <= mid; row++) {
    /* Print spaces */
    for (space = 1; space <= mid - row; space++) {
      printf(" ");
    }

    /* Print pattern */
    for (col = 1; col <= row * 2 - 1; col++) {
      printf("*");
    }

    printf("\n");
  }

  /* Print bottom half */
  for (row = 1; row <= side; row++) {
    /* Print spaces */
    for (space = 1; space <= row; space++) {
      printf(" ");
    }

    /* Print pattern */
    for (col = 1; col <= (side - row) * 2 + 1; col++) {
      printf("*");
    }

    printf("\n");
  }

  return 0;
}