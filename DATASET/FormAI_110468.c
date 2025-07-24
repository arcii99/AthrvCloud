//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include <stdio.h>

int main() {
  printf("Holy cow, check out this cool C pattern printing program!\n\n");

  int rows, cols, i, j, counter = 1;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  for (i = 1; i <= rows; i++) {
    for (j = 1; j <= cols; j++) {
      if (i % 2 == 1) {
        printf("%d ", counter++);
      } else {
        printf("* ");
      }
    }
    printf("\n");
  }

  printf("\nWoohoo! That was fun!\n");

  return 0;
}