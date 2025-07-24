//FormAI DATASET v1.0 Category: Pattern printing ; Style: realistic
#include <stdio.h>

int main() {
  int size, i, j;

  printf("Enter size: ");
  scanf("%d", &size);

  for(i = 0; i < size; i++) {
    for(j = 0; j < size; j++) {
      if(i == 0 || i == size - 1 || j == 0 || j == size - 1 || i == j || i + j == size - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}