//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main() {
  //declare variables
  int rows, cols;

  //get user input for rows
  printf("Enter number of rows: ");
  scanf("%d", &rows);

  //get user input for columns
  printf("Enter number of columns: ");
  scanf("%d", &cols);

  //create ASCII art
  int i = 0;
  for (i = 0; i < rows; i++) {
    int j = 0;
    for (j = 0; j < cols; j++) {
      //add characters to create desired pattern
      if ((i == 0 && j == 3) || (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 && j == 3) || (i == 3 && j == 0) || (i == 3 && j == 4) || (i == 4 && j == 5) || (i == 5 && j == 3)) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n"); //move to next row
  }
  return 0;
}