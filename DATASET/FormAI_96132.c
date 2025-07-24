//FormAI DATASET v1.0 Category: Pattern printing ; Style: irregular
#include <stdio.h>

int main() {
  int rows = 6;
  int cols = 8;
  int stars = 1;
  int spaces = 4;
  int i, j;

  for (i = 1; i <= rows; i++) {
    if (i == 1 || i == rows) {
      for (j = 1; j <= cols; j++) {
        printf("*");
      }
      printf("\n");
    } else if (i == 2 || i == rows - 1) {
      for (j = 1; j <= cols / 2; j++) {
        printf("*");
      }
      for (j = 1; j <= cols / 2 + stars; j++) {
        printf("C");
      }
      for (j = 1; j <= cols / 2; j++) {
        printf("*");
      }
      printf("\n");
    } else {
      for (j = 1; j <= spaces; j++) {
        printf(" ");
      }
      for (j = 1; j <= stars; j++) {
        printf("*");
      }
      for (j = 1; j <= cols - spaces * 2 - stars * 2; j++) {
        printf(" ");
      }
      for (j = 1; j <= stars; j++) {
        printf("*");
      }
      for (j = 1; j <= spaces; j++) {
        printf(" ");
      }
      printf("\n");

      if (i < rows / 2 + 1) {
        stars += 2;
        spaces--;
      } else {
        stars -= 2;
        spaces++;
      }
    }
  }

  return 0;
}