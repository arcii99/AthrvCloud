//FormAI DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Let's print a colorful C pattern!\n\n");

  int rows = 8;
  int cols = 5;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == 0 || i == rows - 1) {
        printf("*");
      } else if (j == 0 && i != 0) {
        printf("*");
      } else if (j == cols - 1 && i != rows - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }

    if (i == 0) {
      printf("\t\t\tC is for Courage!\n");
    } else if (i == 2) {
      printf("\t\t\tC is for Creativity!\n");
    } else if (i == 4) {
      printf("\t\t\tC is for Compassion!\n");
    } else if (i == 6) {
      printf("\t\t\tWay to go, C!\n");
    } else {
      printf("\n");
    }
  }

  printf("\nNice job printing the C pattern!");
  return 0;
}