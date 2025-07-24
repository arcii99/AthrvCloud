//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>

int main() {
  int rows;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  for (int i = 0; i <= rows; i++) {

    for (int j = 0; j <= i; j++) {
      printf("%c ", 65 + i);
    }

    printf("\n");
  }

  for (int i = rows - 1; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      printf("%c ", 65 + i);
    }

    printf("\n");
  }

  return 0;
}