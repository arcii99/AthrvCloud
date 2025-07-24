//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cyberpunk
#include <stdio.h>

int main() {
  // Define the size of the canvas
  int width = 50, height = 25;
  // Create the pixel art array
  char pixelArt[height][width];

  // Loop through each row and column of the array
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      // Check if the current pixel is on the border of the canvas
      if (row == 0 || col == 0 || row == height-1 || col == width-1) {
        // If yes, set the pixel to white (ASCII 219)
        pixelArt[row][col] = 219;
      }
      else {
        // If no, randomly set the pixel to either white (ASCII 219) or green (ASCII 64)
        int random = rand() % 2 + 1;
        if (random == 1) {
          pixelArt[row][col] = 219;
        }
        else {
          pixelArt[row][col] = 64;
        }
      }
    }
  }

  // Display the pixel art on the console
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      printf("%c", pixelArt[row][col]);
    }
    printf("\n");
  }

  return 0;
}