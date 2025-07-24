//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

char canvas[HEIGHT][WIDTH];

void initCanvas() {
  int x, y;

  for(y = 0; y < HEIGHT; y++) {
    for(x = 0; x < WIDTH; x++) {
        canvas[y][x] = '.';
    }
  }
}

void drawPixel(int x, int y, char color) {
  if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    canvas[y][x] = color;
  }
}

void printCanvas() {
  int x, y;

  for(y = 0; y < HEIGHT; y++) {
    for(x = 0; x < WIDTH; x++) {
        printf("%c", canvas[y][x]);
    }
    printf("\n");
  }
}

int main() {
  int x, y;

  srand(time(NULL));

  initCanvas();

  for(y = 0; y < HEIGHT; y++) {
    for(x = 0; x < WIDTH; x++) {
      if(rand() % 2 == 0) {
        drawPixel(x, y, '#');
      }
    }
  }

  printCanvas();
  
  return 0;
}