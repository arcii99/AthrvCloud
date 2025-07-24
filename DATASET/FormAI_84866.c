//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(char pixelArt[][16], int numPixels) {
  // randomly place pixels on the canvas
  srand(time(NULL));
  for(int i = 0; i < numPixels; i++) {
    int x = rand() % 16;
    int y = rand() % 16;
    pixelArt[x][y] = 'X';
  }
}

void printPixelArt(char pixelArt[][16]) {
  // print the pixel art to the console
  for(int i = 0; i < 16; i++) {
    for(int j = 0; j < 16; j++) {
      printf("%c ", pixelArt[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char pixelArt[16][16];
  
  // initialize the canvas
  for(int i = 0; i < 16; i++) {
    for(int j = 0; j < 16; j++) {
      pixelArt[i][j] = '-';
    }
  }
  
  // generate and print some pixel art
  generatePixelArt(pixelArt, 32);
  printPixelArt(pixelArt);
  
  return 0;
}