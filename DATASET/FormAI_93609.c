//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

int main() {
  int height, width, i, j, space;
  printf("Enter the height of the pattern (odd number): ");
  scanf("%d", &height);
  width = height / 2 + 1;
  for (i = 0; i <= height / 2; i++) {
    for (space = 0; space <= (height / 2) - i; space++) {
      printf(" ");
    }
    for (j = 0; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }
  for (i = height / 2 + 1; i <= height; i++) {
    for (space = 0; space <= i - (height / 2) - 1; space++) {
      printf(" ");
    }
    for (j = 0; j <= height - i - 1; j++) {
      printf("* ");
    }
    printf("\n");
  }
  
  return 0;
}