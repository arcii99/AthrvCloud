//FormAI DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>

int main() {
  int size, i, j;
  
  printf("Enter the size of the pattern: ");
  scanf("%d", &size);

  for (i = size; i >= 1; i--) {
    for (j = 1; j <= size; j++) {
      if (j >= i)
        printf("*");
      else
        printf(" ");
    }

    for (j = 1; j <= size; j++) {
      if (j >= size - (i - 1))
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }

  for (i = 1; i <= size; i++) {
    for (j = 1; j <= size; j++) {
      if (j >= i)
        printf("*");
      else
        printf(" ");
    }

    for (j = 1; j <= size; j++) {
      if (j >= size - (i - 1))
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }

  return 0;
}