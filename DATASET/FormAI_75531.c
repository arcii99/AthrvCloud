//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int height = 500;
  int width = 500;
  int max_color = 255;
  int image[height][width];

  // Fill image with some noise
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j] = rand() % max_color;
    }
  }

  // Flip image horizontally
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      int temp = image[i][j];
      image[i][j] = image[i][width - j - 1];
      image[i][width - j - 1] = temp;
    }
  }

  // Change brightness and contrast
  int brightness_offset = 50;
  int contrast_factor = 2;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int new_value = (image[i][j] * contrast_factor) + brightness_offset;
      if (new_value > max_color) {
        image[i][j] = max_color;
      } else if (new_value < 0) {
        image[i][j] = 0;
      } else {
        image[i][j] = new_value;
      }
    }
  }

  // Print image
  printf("P2\n");
  printf("%d %d\n", width, height);
  printf("%d\n", max_color);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", image[i][j]);
    }
    printf("\n");
  }

  printf("Haha! Looks like we've got a flipped and brightened image.\n");

  return 0;
}