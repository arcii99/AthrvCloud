//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 15

void printMaze(char maze[][COL]) {
  int i, j;

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

void generateMaze(char maze[][COL]) {
  int i, j;

  srand(time(NULL));

  /* Fill maze with walls */
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      maze[i][j] = '#';
    }
  }

  /* Pick random starting point */
  int x = rand() % ROW;
  int y = rand() % COL;
  maze[x][y] = 'S';

  /* Pick random ending point */
  x = rand() % ROW;
  y = rand() % COL;
  maze[x][y] = 'E';

  /* Generate maze */
  for (i = 2; i < ROW - 2; i += 2) {
    for (j = 2; j < COL - 2; j += 2) {
      maze[i][j] = ' ';
      int dir = rand() % 4;
      switch (dir) {
        case 0: // Up
          if (maze[i - 1][j] == '#') {
            maze[i - 1][j] = ' ';
          }
          break;
        case 1: // Right
          if (maze[i][j + 1] == '#') {
            maze[i][j + 1] = ' ';
          }
          break;
        case 2: // Down
          if (maze[i + 1][j] == '#') {
            maze[i + 1][j] = ' ';
          }
          break;
        case 3: // Left
          if (maze[i][j - 1] == '#') {
            maze[i][j - 1] = ' ';
          }
          break;
      }
    }
  }
}

int main() {
  char maze[ROW][COL];
  generateMaze(maze);
  printMaze(maze);
  return 0;
}