//FormAI DATASET v1.0 Category: Pattern printing ; Style: random
#include <stdio.h>

int main() {
  int height, width;
  printf("Enter height of C : ");
  scanf("%d", &height);
  width = height / 2 + 1;

  int i, j;
  for(i = 1; i <= height; i++) {
    for(j = 1; j <= width; j++) {
      if((i > 1 && i < height - 1 && j == 1) ||
         (i == 1 && j == 1) || 
         (i == height && j == 1) || 
         (i == height / 2 + 1 && j <= width)) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}