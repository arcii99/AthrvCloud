//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Asynchronous generate pixel art for a random shape
void generatePixelArt() {
  int width = rand() % MAX_WIDTH + 1;
  int height = rand() % MAX_HEIGHT + 1;

  char pixelArt[height][width];

  // Fill with random pixels from set of characters
  char pixelSet[] = {'+', '-', '/', '\\', '|', '$', '%', '&', '*', '?'};

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      pixelArt[y][x] = pixelSet[rand() % (sizeof(pixelSet)/sizeof(char))];
    }
  }

  // Print out pixel art
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c ", pixelArt[y][x]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  // Generate multiple pixel arts asynchronously
  for (int i = 0; i < 5; i++) {
    printf("Generating pixel art #%d...\n", i+1);

    // Asynchronous call to generatePixelArt
    generatePixelArt();

    printf("Pixel art #%d done!\n\n", i+1);
  }

  return 0;
}