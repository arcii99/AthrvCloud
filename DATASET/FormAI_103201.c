//FormAI DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, n = 11; // n is the size of the pattern
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j || i + j == n - 1) {
        printf("*"); // print * when row equal to column or sum of row and column equal to n - 1
      } else if (i == n / 2 || j == n / 2) {
        printf("#"); // print # when row or column equal to n / 2
      } else if (i < j && i + j < n - 1) {
        printf("^"); // print ^ when row greater than column and sum of row and column less than n - 1
      } else if (i > j && i + j > n - 1) {
        printf("&"); // print & when row less than column and sum of row and column greater than n - 1
      } else {
        printf(" "); // print space for all other cases
      }
    }
    printf("\n"); // move to next line
  }
  
  return 0;
}