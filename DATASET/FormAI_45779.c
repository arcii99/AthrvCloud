//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate pixel art
void pixel_art_generator(int width, int height, int color) {
  // create 2D array of size width x height
  int art[height][width];
  
  // set the seed for random number generator
  srand(time(NULL));
  
  // generate random values for each pixel
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      art[row][col] = rand() % color;
    }
  }
  
  // print the pixel art
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      printf("%d ", art[row][col]);
    }
    printf("\n");
  }
}

// main function
int main() {
  int width = 10; // width of the pixel art
  int height = 5; // height of the pixel art
  int color = 3; // number of colors to choose from (0, 1, 2)
  
  // generate and print pixel art
  pixel_art_generator(width, height, color);
  
  return 0;
}