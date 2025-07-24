//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  int height;
  printf("Enter the height of the pattern:");
  scanf("%d", &height);

  for(int i = 0; i < height; i++) {
    for(int j = 0; j < height; j++) {
      if(i==j || (i+j)==height-1) {
        printf("%d ", abs(i-j)+1);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
  return 0;
}