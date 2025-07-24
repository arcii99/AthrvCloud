//FormAI DATASET v1.0 Category: Pattern printing ; Style: realistic
#include <stdio.h>

int main() {
  int size, i, j;
  printf("Enter the size of the pattern: ");
  scanf("%d", &size);
  
   /* First half of the pattern */
  for (i = 1; i <= size; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d ", j);
    }
    for (j = i + 1; j <= size; j++) {
      printf("  ");
    }
    for (j = size; j > i; j--) {
      printf("  ");
    }
    for (j = i; j > 0; j--) {
      printf("%d ", j);
    }
    printf("\n");
  }
  
   /* Second half of the pattern */
  for (i = size - 1; i >= 1; i--) {
    for (j = 1; j <= i; j++) {
      printf("%d ", j);
    }
    for (j = i + 1; j <= size; j++) {
      printf("  ");
    }
    for (j = size; j > i; j--) {
      printf("  ");
    }
    for (j = i; j > 0; j--) {
      printf("%d ", j);
    }
    printf("\n");
  }
  
  return 0;
}