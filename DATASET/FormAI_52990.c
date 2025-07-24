//FormAI DATASET v1.0 Category: Pattern printing ; Style: content
/* This program prints a unique C pattern */
#include <stdio.h>

int main() {
  int rows, col;

  printf("Enter the number of rows (odd number): ");
  scanf("%d", &rows);

  // check if the entered number is odd
  if(rows % 2 == 0) {
    printf("Please enter an odd number. Try again!");
    return 0;
  }
  
  col = (rows / 2) + 1; // calculate the number of columns in the C pattern
  
  // print the pattern
  for(int i = 1; i <= rows; i++) {
    for(int j = 1; j <= col; j++) {
      if((i == 1 || i == rows) && (j != col)) {
        printf("*");
      } else if(j == col && (i != 1 && i != rows)) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}