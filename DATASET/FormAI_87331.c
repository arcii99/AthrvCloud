//FormAI DATASET v1.0 Category: Pattern printing ; Style: minimalist
#include <stdio.h>

int main() {
  int size;
  printf("Enter size: ");
  scanf("%d", &size);

  //Upper Section of C
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == 0 || j == 0)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }

  //Lower Section of C
  for (int i = 0; i < size; i++) {
    printf("*");
  }
  printf("\n");

  return 0;
}