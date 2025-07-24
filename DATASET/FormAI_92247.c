//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

char pixel[WIDTH][HEIGHT];

void generatePixelArt() {
  int i, j;
  srand(time(0)); // seed for random number generation

  // fill pixel array with random characters
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      pixel[i][j] = rand() % 2 ? '#' : '_'; // 50-50 chance of either character
    }
  }
}

void printPixelArt() {
  int i, j;

  // print each character in pixel array
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      printf("%c ", pixel[i][j]);
    }
    printf("\n");
  }
}

int main() {
  generatePixelArt();
  printPixelArt();

  return 0;
}