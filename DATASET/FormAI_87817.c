//FormAI DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>

int main() {
  int rows, i, j, k, count = 0;

  printf("Enter the number of rows for C pattern printing: ");
  scanf("%d", &rows);

  printf("\nC pattern:\n\n");

  for (i = 1; i <= rows; i++) {
    for (j = 1; j <= rows; j++) {
      if ((i == 1 || i == rows) && (j > 1 && j < rows)) {
        printf("*");
      } else if (i > 1 && i < rows && j == 2) {
        printf("*");
      } else {
        printf(" ");
      }
    }

    for (k = 1; k <= rows; k++) {
      if ((k == 1 && i != 1 && i != rows) || (i == rows && k <= rows - 2)) {
        printf("*");
      } else {
        printf(" ");
      }
    }

    printf("\n");
    count++;
  }

  printf("\nTotal lines printed: %d", count);

  return 0;
}