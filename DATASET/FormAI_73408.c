//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: high level of detail
#include <stdio.h>

int main() {
  int width, height;
  printf("Enter width: ");
  scanf("%d", &width);
  printf("Enter height: ");
  scanf("%d", &height);

  int pixel[height][width][3];

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("Enter R, G, B values for pixel [%d][%d]: ", i, j);
      scanf("%d %d %d", &pixel[i][j][0], &pixel[i][j][1], &pixel[i][j][2]);
    }
  }

  printf("\nPixel Art:\n");

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (pixel[i][j][0] == 0 && pixel[i][j][1] == 0 && pixel[i][j][2] == 0) {
        printf(" ");
      } else if (pixel[i][j][0] == 255 && pixel[i][j][1] == 0 && pixel[i][j][2] == 0) {
        printf("R");
      } else if (pixel[i][j][0] == 0 && pixel[i][j][1] == 255 && pixel[i][j][2] == 0) {
        printf("G");
      } else if (pixel[i][j][0] == 0 && pixel[i][j][1] == 0 && pixel[i][j][2] == 255) {
        printf("B");
      } else if (pixel[i][j][0] == 255 && pixel[i][j][1] == 255 && pixel[i][j][2] == 255) {
        printf("W");
      } else {
        printf("?");
      }
    }
    printf("\n");
  }

  return 0;
}