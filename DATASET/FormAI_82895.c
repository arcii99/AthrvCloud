//FormAI DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>

int main() {
  int i, j, rows; 
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  for (i = 1; i <= rows; i++) {
    for (j = i; j <= rows; j++) {
      printf(" ");
    }
    for (j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  for (i = rows - 1; i >= 1; i--) {
    for (j = rows; j >= i; j--) {
      printf(" ");
    }
    for (j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}