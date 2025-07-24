//FormAI DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>

int main() {
  int size;
  printf("Enter the size of the pattern:\n");
  scanf("%d", &size);

  int center = (size - 1) / 2;
  int i, j;

  // upper half
  for (i = 0; i <= center; i++) {
    for (j = 0; j < size; j++) {
      if (j == center || j == center - i || j == center + i) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // lower half
  for (i = center + 1; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (j == center || j == center - (size - 1 - i) || j == center + (size - 1 - i)) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}