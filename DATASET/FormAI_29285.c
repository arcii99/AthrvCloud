//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  int width, height;

  printf("Enter the width of the pixel art: ");
  scanf("%d", &width);

  printf("Enter the height of the pixel art: ");
  scanf("%d", &height);

  char *pixel_art = (char *) calloc(width * height, sizeof(char));

  // Generating Pixel Art
  for (int i = 0; i < width * height; i++) {
    if (i % 2 == 0) {
        *(pixel_art + i) = '#';
    } else {
        *(pixel_art + i) = ' ';
    }
  }

  // Displaying Pixel Art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c ", *(pixel_art + i * width + j));
    }
    printf("\n");
  }

  free(pixel_art);
  return 0;
}