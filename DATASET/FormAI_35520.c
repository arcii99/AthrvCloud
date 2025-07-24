//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  char canvas[10][10]; // 10 x 10 pixel canvas
  char colors[7] = { 'R', 'O', 'Y', 'G', 'B', 'I', 'V' }; // rainbow colors

  // initialize canvas with white color
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      canvas[i][j] = 'W';
    }
  }

  // generate random pixels of different colors
  for(int i = 0; i < 50; i++) {
    int x = rand() % 10;
    int y = rand() % 10;
    char color = colors[rand() % 7];
    canvas[x][y] = color;
  }

  // print canvas
  printf("     PIXEL ART\n");
  printf("--------------------\n");
  for(int i = 0; i < 10; i++) {
    printf("|");
    for(int j = 0; j < 10; j++) {
      printf(" %c ", canvas[i][j]);
    }
    printf("|\n");
  }
  printf("--------------------\n");

  return 0;
}