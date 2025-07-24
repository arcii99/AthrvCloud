//FormAI DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>

int main() {
  int rows, i, j, spaces;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  for (i = 1; i <= rows; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d", i);
    }
    spaces = 2 * (rows - i);
    for (j = 1; j <= spaces; j++) {
      printf(" ");
    }
    for (j = i; j >= 1; j--) {
      printf("%d", i);
    }
    printf("\n");
  }
  for (i = rows-1; i >= 1; i--) {
    for (j = 1; j <= i; j++) {
      printf("%d", i);
    }
    spaces = 2 * (rows-i);
    for (j = 1; j <= spaces; j++) {
      printf(" ");
    }
    for (j = i; j >= 1; j--) {
      printf("%d", i);
    }
    printf("\n");
  }
  return 0;
}