//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

int main() {
  int size, i, j, k;

  printf("Enter the size of the pattern: ");
  scanf("%d", &size);

  for (i = 0; i < size; i++) {
    // print first half
    for (j = 0; j <= i; j++) {
        if (j == 0 || j == i) { // print asterisk for first and last column
            printf("* ");
        } else if (i == size - 1) { // print asterisk for last row
            printf("* ");
        } else { // print spaces for the rest
            printf("  ");
        }
    }

    // print second half
    for (k = size - 1; k > i; k--) {
        if (k == size - 1 || k == i + 1) { // print asterisk for last and second to last columns
            printf("* ");
        } else { // print spaces for the rest
            printf("  ");
        }
    }

    printf("\n"); // move to next line
  }

  return 0;
}