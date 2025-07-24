//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Seed the random number generator with current time

  char pixels[16][16]; // 16x16 pixel canvas

  // Fill the canvas with random pixels
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      int random = rand() % 2; // Generate random number either 0 or 1
      if (random == 0) {
        pixels[i][j] = ' '; // If zero, pixel is empty
      } else {
        pixels[i][j] = '*'; // If one, pixel is filled
      }
    }
  }

  // Draw the pixel art on the console
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      printf("%c ", pixels[i][j]); // Print each pixel on console
    }
    printf("\n"); // Move to the next line after 16 pixels in a row
  }

  return 0;
}