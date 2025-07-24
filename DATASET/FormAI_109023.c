//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

int main() {

  int num, row, col, space;

  printf("Enter a number: ");
  scanf("%d", &num);

  for (row = 1; row <= num; row++) {

    // Printing spaces
    for (space = 1; space <= (num - row); space++) {
      printf(" ");
    }

    // Printing digits
    for (col = 1; col <= row; col++) {
      printf("%d ", col);
    }

    printf("\n");

  }

  for (row = num; row >= 1; row--) {

    // Printing spaces
    for (space = 1; space <= (num - row); space++) {
      printf(" ");
    }

    // Printing digits
    for (col = 1; col <= row; col++) {
      printf("%d ", col);
    }

    printf("\n");

  }

  return 0;
}