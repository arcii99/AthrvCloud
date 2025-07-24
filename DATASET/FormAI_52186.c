//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int map[HEIGHT][WIDTH];

void generateMap() {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (i == 0 || j == 0 || i == HEIGHT-1 || j == WIDTH-1) {
        map[i][j] = 1;
      } else {
        map[i][j] = rand() % 2;
      }
    }
  }
}

void printMap() {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (map[i][j] == 1) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(0));
  generateMap();
  printMap();
  return 0;
}