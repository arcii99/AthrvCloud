//FormAI DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
#include <stdio.h>

int main() {
  int rows = 7; //change the rows and columns to adjust pattern
  int cols = 7;

  int row, col;
  for (row = 0; row < rows; row++) {
    for (col = 0; col < cols; col++) {
      if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
        printf("*");
      } else if (row == col) {
        printf("\\");
      } else if (row + col == rows - 1) {
        printf("/");
      } else if (col == cols / 2 && row < rows / 2) {
        printf("|");
      } else if (col == cols / 2 && row > rows / 2) {
        printf("|");
      } else if (row == rows / 2 && col < cols / 2) {
        printf("-");
      } else if (row == rows / 2 && col > cols / 2) {
        printf("-");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}