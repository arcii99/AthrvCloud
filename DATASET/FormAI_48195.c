//FormAI DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main() {
  int nrows, i, j, k;

  printf("Enter the number of rows: ");
  scanf("%d", &nrows);

  // check if the number of rows is valid
  if (nrows < 1) {
    printf("Invalid number of rows. Please enter a positive integer.\n");
    return 1; // exit the program with an error code
  }

  // print upper half of the pattern
  for (i = 1; i <= nrows; i++) {
    // print 'i' spaces at the beginning of each row
    for (j = 1; j < i; j++) {
      printf(" ");
    }
    // print 'nrows - i + 1' stars
    for (k = 1; k <= nrows - i + 1; k++) {
      printf("*");
    }
    printf("\n");
  }

  // print lower half of the pattern
  for (i = nrows - 1; i >= 1; i--) {
    // print 'i' spaces at the beginning of each row
    for (j = 1; j < i; j++) {
      printf(" ");
    }
    // print 'nrows - i + 1' stars
    for (k = 1; k <= nrows - i + 1; k++) {
      printf("*");
    }
    printf("\n");
  }

  return 0; // exit the program with a success code
}