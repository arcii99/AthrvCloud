//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void generatePixelArt(int pixels[HEIGHT][WIDTH]);

int main(void) {
  int pixels[HEIGHT][WIDTH];
  generatePixelArt(pixels);

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%d ", pixels[i][j]);
    }
    printf("\n");
  }

  return 0;
}

void generatePixelArt(int pixels[HEIGHT][WIDTH]) {
  srand(time(NULL));
  
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      pixels[i][j] = rand() % 2;
    }
  }
}