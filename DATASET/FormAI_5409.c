//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed the random number generator with current time

  // define variables for the size of the pixel art canvas
  int width = 10;
  int height = 10;

  // define the colors we will use for our pixel art
  char colors[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

  // generate the pixel art by randomly choosing a color for each pixel
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int colorIndex = rand() % 10; // choose a random color index from 0-9
      printf("%c ", colors[colorIndex]); // print the character representation of the color
    }
    printf("\n"); // start a new row
  }

  return 0;
}