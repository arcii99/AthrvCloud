//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

int main() {
  int size, i, j, k, l;
  
  printf("Enter the size of the pattern: ");
  scanf("%d", &size);
  
  // Top half of the pattern
  for (i = size; i >= 1; i--) {
    for (j = 1; j < i; j++) {
      printf(" ");
    }
    for (k = 1; k <= ((size - i) * 2) + 1; k++) {
      printf("*");
    }
    printf("\n");
  }

  // Bottom half of the pattern
  for (i = 1; i <= size; i++) {
    for (j = 1; j < i; j++) {
      printf(" ");
    }
    for (k = 1; k <= ((size - i) * 2) + 1; k++) {
      printf("*");
    }
    printf("\n");
  }

  // Create the center line
  for (l = 1; l <= (size * 2) + 1; l++) {
    printf("*");
  }
  printf("\n");
  
  return 0;
}