//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25

void clear(char canvas[HEIGHT][WIDTH]);
void draw(char canvas[HEIGHT][WIDTH]);
void generatePixelArt(char canvas[HEIGHT][WIDTH]);

int main() {
  char canvas[HEIGHT][WIDTH];

  srand(time(NULL));
  clear(canvas);
  generatePixelArt(canvas);
  draw(canvas);

  return 0;
}

void clear(char canvas[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      canvas[i][j] = ' ';
    }
  }
}

void draw(char canvas[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", canvas[i][j]);
    }
    printf("\n");
  }
}

void generatePixelArt(char canvas[HEIGHT][WIDTH]) {
  int startRow = rand() % HEIGHT;
  int startCol = rand() % WIDTH;

  for (int i = 0; i < 10; i++) {
    int row = startRow + (rand() % 3) - 1;
    int col = startCol + (rand() % 3) - 1;

    if (row >= 0 && row < HEIGHT && col >= 0 && col < WIDTH) {
      canvas[row][col] = '+';
      startRow = row;
      startCol = col;
    }
  }
}