//FormAI DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, k;
  int rows = 7; // Change this value to adjust the size of the pattern
  int spaces = (rows * 2) - 2;
  int stars = 1;

  printf("Here's a unique pattern printed in C:\n");

  // First section of the pattern
  for (i = 1; i <= rows; i++) {
    for (j = 1; j <= stars; j++) {
      printf("*");
    }
    for (k = 1; k <= spaces; k++) {
      printf(" ");
    }
    for (j = 1; j <= stars; j++) {
      printf("*");
    }
    stars++;
    spaces -= 2;
    printf("\n");
  }

  // Second section of the pattern
  stars = (rows * 2) - 1;
  spaces = 1;
  for (i = 1; i <= rows; i++) {
    for (j = 1; j <= stars; j++) {
      printf("*");
    }
    for (k = 1; k <= spaces; k++) {
      printf(" ");
    }
    for (j = 1; j <= stars; j++) {
      printf("*");
    }
    stars--;
    spaces += 2;
    printf("\n");
  }

  printf("Pattern completed!");
  return 0;
}