//FormAI DATASET v1.0 Category: Pattern printing ; Style: optimized
#include <stdio.h>

int main() {

  int i, j, rows, k = 0;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  for (i = 1; i <= rows; i++) {

    k = i;

    for (j = 1; j <= rows; j++) {

      if (j <= i) {

        printf("%d", k);
        k--;

      } else {

        printf(" ");
      }
    }

    k = i;

    for (j = rows; j > i; j--) {

      printf(" ");

    }

    for (j = rows; j >= i; j--) {

      printf("%d", k);
      k++;

    }

    printf("\n");

  }

  return 0;
}