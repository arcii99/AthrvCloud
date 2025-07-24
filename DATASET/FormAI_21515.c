//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define WIDTH 50
#define HEIGHT 50
#define PIXEL_SIZE 10

int main() {
  int pixels[WIDTH][HEIGHT];

  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      pixels[x][y] = (sin(x * 0.1) + sin(y * 0.1)) * 127 + 128;
    }
  }

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      for (int i = 0; i < PIXEL_SIZE; i++) {
        for (int j = 0; j < PIXEL_SIZE; j++) {
          printf("%d ", pixels[x][y]);
        }
      }
      printf("\n");
    }
  }

  return 0;
}