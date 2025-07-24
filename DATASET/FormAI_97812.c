//FormAI DATASET v1.0 Category: Image Editor ; Style: retro
/* Retro style C image editor program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant values for image dimensions
#define WIDTH 10
#define HEIGHT 10

// Define struct for RGB color value
typedef struct {
  int r;
  int g;
  int b;
} Color;

// Declare function to create and initialize an image
void init_image(Color image[HEIGHT][WIDTH], Color color);

int main() {
  // Declare variables for image and default color
  Color image[HEIGHT][WIDTH];
  Color default_color = { 255, 255, 255 };

  // Initialize image with default color
  init_image(image, default_color);

  // Print initial image state
  printf("Initial image state:\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("(%d,%d,%d) ", image[i][j].r, image[i][j].g, image[i][j].b);
    }
    printf("\n");
  }

  // TODO: Implement image editing functions here

  return 0;
}

void init_image(Color image[HEIGHT][WIDTH], Color color) {
  // Iterate over each pixel in image and set color to default color
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      image[i][j] = color;
    }
  }
}