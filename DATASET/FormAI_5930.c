//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set up the canvas dimensions
  int width = 40;
  int height = 30;

  // Seed the random number generator
  srand(time(0));

  // Define the possible pixel characters
  char pixels[] = {' ', '.', '*', '#', '@'};

  // Loop through all the pixels and randomly select one
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixel_index = rand() % 5;
      char pixel = pixels[pixel_index];
      printf("%c ", pixel);
    }
    printf("\n");
  }

  return 0;
}