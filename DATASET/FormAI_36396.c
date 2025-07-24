//FormAI DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include <stdio.h>

int main() {
  int height, width, mid;
  printf("Enter the height of the pattern: ");
  scanf("%d", &height);
  
  width = height + (height - 1);
  mid = width / 2;
  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if ((j >= mid - i) && (j <= mid + i)) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
}