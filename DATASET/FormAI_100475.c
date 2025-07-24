//FormAI DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>

int main() {
  int rows = 7; // set number of rows
  int midRow = rows / 2; // find middle row

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < rows; j++) {
      if(i == 0 || i == rows - 1 || j == 0) { // top and bottom rows, and left column
        printf("*");
      } else if(i == midRow) { // middle row
        printf("C");
      } else if(j == rows - 1) { // right column
        printf("*");
      } else { // spaces
        printf(" ");
      }
    }
    printf("\n"); // new line for each row
  }

  return 0;
}