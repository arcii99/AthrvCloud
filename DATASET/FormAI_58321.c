//FormAI DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>

int main() {
  int rows = 7, cols = 7;

  // iterate over rows
  for (int i = 0; i < rows; i++) {
    // iterate over columns
    for (int j = 0; j < cols; j++) {
      if (i == 0 || i == rows - 1) { // print full row for first and last row
        printf("*");
      } else if (j == 0 && i <= rows / 2) { // print star for first column in first half of rows
        printf("*");
      } else if (j == i) { // print star for diagonal line
        printf("*");
      } else if (j == cols - 1 && i > rows / 2) { // print star for last column in second half of rows
        printf("*");
      } else { // print space for every other position
        printf(" ");
      }
    }
    printf("\n"); // move to next row
  }

  return 0;
}