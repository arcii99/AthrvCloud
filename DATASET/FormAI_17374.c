//FormAI DATASET v1.0 Category: Pattern printing ; Style: random
#include <stdio.h>
int main() {
  int i, j, rows = 7;

  for(i = 1; i <= rows; ++i) {

    for(j = 1; j <= i; ++j) {
      if(j == 1 || j == i)
        printf("*");
      else
        printf(" ");
    }

    for(j = i; j < rows; ++j) {
      printf(" ");
    }

    printf("*");

    for(j = i; j < rows; ++j) {
      printf(" ");
    }

    for(j = 1; j <= i; ++j) {
      if(j == 1 || j == i)
        printf("*");
      else
        printf(" ");
    }

    printf("\n");
  }
  return 0;
}