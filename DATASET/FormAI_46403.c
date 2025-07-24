//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WALL 'X'
#define PATH ' '
#define START 'S'
#define END 'E'

void generateMaze(char maze[ROWS][COLS], int x, int y);
void printMaze(char maze[ROWS][COLS]);

int main(void) {
  char maze[ROWS][COLS];
  srand(time(NULL)); // seed random number generator
  int x = rand() % ROWS;
  int y = rand() % COLS;
  generateMaze(maze, x, y);
  printMaze(maze);
  return 0;
}

void generateMaze(char maze[ROWS][COLS], int x, int y) {
  // initialize maze with walls
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      maze[i][j] = WALL;
    }
  }
  // set start and end points
  maze[x][y] = START;
  int end_x = (x + rand() % (ROWS - x));
  int end_y = (y + rand() % (COLS - y));
  maze[end_x][end_y] = END;
  // generate paths
  int pathCount = 0;
  while (pathCount < ROWS * COLS / 2) {
    int direction = rand() % 4;
    if (direction == 0 && x > 1) {
      if (maze[x-1][y] == WALL && maze[x-2][y] == WALL && x-2 != end_x && y != end_y) {
        maze[x-1][y] = PATH;
        maze[x-2][y] = PATH;
        x -= 2;
        pathCount++;
      }
    }
    else if (direction == 1 && x < ROWS - 2) {
      if (maze[x+1][y] == WALL && maze[x+2][y] == WALL && x+2 != end_x && y != end_y) {
        maze[x+1][y] = PATH;
        maze[x+2][y] = PATH;
        x += 2;
        pathCount++;
      }
    }
    else if (direction == 2 && y > 1) {
      if (maze[x][y-1] == WALL && maze[x][y-2] == WALL && x != end_x && y-2 != end_y) {
        maze[x][y-1] = PATH;
        maze[x][y-2] = PATH;
        y -= 2;
        pathCount++;
      }
    }
    else if (direction == 3 && y < COLS - 2) {
      if (maze[x][y+1] == WALL && maze[x][y+2] == WALL && x != end_x && y+2 != end_y) {
        maze[x][y+1] = PATH;
        maze[x][y+2] = PATH;
        y += 2;
        pathCount++;
      }
    }
  }
}

void printMaze(char maze[ROWS][COLS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}