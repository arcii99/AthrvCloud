//FormAI DATASET v1.0 Category: Pattern printing ; Style: Alan Touring
#include <stdio.h>

int main() {
  int height, width, i, j;

  printf("Enter height of pattern: ");
  scanf("%d", &height);
  printf("Enter width of pattern: ");
  scanf("%d", &width);

  for (i = 1; i <= height; i++) {
    for (j = 1; j <= width; j++) {
      if (i == 1 || i == height || j == 1 || j == width) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}