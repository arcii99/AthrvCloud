//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>

int main() {
  
  int width = 10;   // Width of pixel art
  int height = 10;  // Height of pixel art
  
  int pixels[height][width]; // Create array for pixel art
  
  // Fill array with random values (0-1)
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixels[i][j] = rand() % 2;
    }
  }
  
  // Print out pixel art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (pixels[i][j]) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0; // End program
}