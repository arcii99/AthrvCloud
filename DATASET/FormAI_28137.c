//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void drawPixel(char pixel) {
  if (pixel == '1')
    printf("\u2588\u2588"); // Full block glyph
  else
    printf("  ");
}

int main() {
  char image[8][8] = {
    {'0', '0', '0', '0', '0', '0', '0', '0'},
    {'0', '1', '1', '1', '1', '1', '1', '0'},
    {'0', '1', '0', '0', '0', '0', '1', '0'},
    {'0', '1', '0', '1', '1', '0', '1', '0'},
    {'0', '1', '0', '1', '1', '0', '1', '0'},
    {'0', '1', '0', '0', '0', '0', '1', '0'},
    {'0', '1', '1', '1', '1', '1', '1', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '0'}
  };

  for (int row = 0; row < 8; ++row) {
    for (int col = 0; col < 8; ++col) {
      drawPixel(image[row][col]);
    }
    putchar('\n');
  }

  return 0;
}