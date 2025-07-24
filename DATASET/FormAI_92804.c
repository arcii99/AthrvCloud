//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>

#define WIDTH 16
#define HEIGHT 16

// You can modify the colors as per your choice
#define COLOR_BLACK ' '
#define COLOR_DARK_GRAY '.'
#define COLOR_LIGHT_GRAY ':'
#define COLOR_WHITE '#'

// This function will generate a random pixel art
void generatePixelArt(char pixelArt[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int random = rand() % 4;
      switch(random) {
        case 0: pixelArt[y][x] = COLOR_BLACK; break;
        case 1: pixelArt[y][x] = COLOR_DARK_GRAY; break;
        case 2: pixelArt[y][x] = COLOR_LIGHT_GRAY; break;
        case 3: pixelArt[y][x] = COLOR_WHITE; break;
      }
    }
  }
}

// This function will display the pixel art on the console
void displayPixelArt(char pixelArt[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", pixelArt[y][x]);
    }
    printf("\n");
  }
}

int main() {
  char pixelArt[HEIGHT][WIDTH];

  // Generate and display the pixel art
  generatePixelArt(pixelArt);
  displayPixelArt(pixelArt);

  return 0;
}