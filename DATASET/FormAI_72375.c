//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator

  // Define dimensions of the image
  int width = 10;
  int height = 10;

  // Create pixel array
  int image[height][width];

  // Fill pixel array with random color values
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j] = rand() % 2; // Set each pixel to either 0 or 1
    }
  }

  // Print out the pixel array as a visual representation of the image
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (image[i][j] == 0) {
        printf(" "); // Print a space for a white pixel
      } else {
        printf("*"); // Print an asterisk for a black pixel
      }
    }
    printf("\n"); // Start a new line for every row of pixels
  }

  return 0;
}