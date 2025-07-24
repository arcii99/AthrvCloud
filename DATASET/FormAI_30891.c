//FormAI DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>

int main() {
  int rows, i, j, space, k = 0;

  printf("Please enter the number of rows in the pattern: ");
  scanf("%d", &rows);

  for (i = 1; i <= rows; ++i, k = 0) {
    for (space = 1; space <= rows - i; ++space) {
      printf("  ");
    }

    while (k != 2 * i - 1) {
      printf("* ");
      ++k;
    }

    printf("\n");
  }

  k = 1;

  for (i = rows - 1; i >= 1; --i, k = 0) {
    for (space = 1; space <= rows - i; ++space) {
      printf("  ");
    }

    while (k != 2 * i - 1) {
      printf("* ");
      ++k;
    }

    printf("\n");
  }

  return 0;
}