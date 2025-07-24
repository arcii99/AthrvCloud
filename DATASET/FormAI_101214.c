//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16 // width of art in pixels
#define HEIGHT 16 // height of art in pixels

int main() {
  srand(time(NULL)); // seed random number generator with current time
  char pixels[WIDTH][HEIGHT]; // 2D array to store pixel art
  
  // loop through each pixel and assign a random value (0-9) to represent the color
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      pixels[i][j] = rand() % 10;
    }
  }
  
  // output the pixel art in a matrix format
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      printf("%d ", pixels[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}