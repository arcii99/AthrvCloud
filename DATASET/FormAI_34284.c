//FormAI DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>

int main() {
  int shape = 0; // prompt user for shape 1 for square, 2 for triangle

  printf("What shape would you like to create?\n");
  printf("1 - Square\n");
  printf("2 - Triangle\n");
  scanf("%d", &shape);

  if(shape == 1) { // create square shape
    int size = 0;

    printf("What size would you like your square to be?\n");
    scanf("%d", &size);

    for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
        printf("*");
      }
      printf("\n");
    }

  } else if(shape == 2) { // create triangle shape
    int height = 0;

    printf("What height would you like your triangle to be?\n");
    scanf("%d", &height);

    for(int i = 0; i < height; i++) {
      int num_spaces = height - i - 1;
      for(int j = 0; j < num_spaces; j++) {
        printf(" ");
      }
      for(int j = 0; j < i * 2 + 1; j++) {
        printf("*");
      }
      printf("\n");
    }
  }

  return 0;
}