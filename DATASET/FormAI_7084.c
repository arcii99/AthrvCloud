//FormAI DATASET v1.0 Category: Pattern printing ; Style: complete
#include <stdio.h>

int main() {

  // Declare variables for size of pattern and counter variables
  int size, i, j, k, l;

  printf("Enter the size of the pattern: ");
  scanf("%d", &size);

  // Print upper half of the pattern
  for (i = 0; i < size/2; i++) {
    for (j = 0; j <= i; j++) {
      printf("*");
    }
    for (k = 0; k < size - (2*i); k++) {
      printf(" ");
    }
    for (l = 0; l <= i; l++) {
      printf("*");
    }
    printf("\n");
  }

  // Print center row of pattern
  for (i = 0; i < size; i++) {
    printf("*");
  }
  printf("\n");

  // Print lower half of pattern
  for (i = size/2 - 1; i >= 0; i--) {
    for (j = 0; j <= i; j++) {
      printf("*");
    }
    for (k = 0; k < size - (2*i); k++) {
      printf(" ");
    }
    for (l = 0; l <= i; l++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}