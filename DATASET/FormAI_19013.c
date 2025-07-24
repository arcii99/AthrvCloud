//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

char maze[ROWS][COLS+1];

void printMaze() {
  for (int i=0; i<ROWS; i++) {
    printf("%s\n", maze[i]);
  }
}

int findPath(int row, int col) {
  if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
    return 0;
  }
  if (maze[row][col] != ' ') {
    return 0;
  }
  if (row == ROWS-1 && col == COLS-1) {
    maze[row][col] = '.';
    return 1;
  }
  maze[row][col] = '.';
  if (findPath(row+1, col)) {
    return 1;
  }
  if (findPath(row, col+1)) {
    return 1;
  }
  if (findPath(row-1, col)) {
    return 1;
  }
  if (findPath(row, col-1)) {
    return 1;
  }
  maze[row][col] = ' ';
  return 0;
}

int main() {
  for (int i=0; i<ROWS; i++) {
    for (int j=0; j<COLS; j++) {
      maze[i][j] = ' ';
    }
    maze[i][COLS] = '\0';
  }

  for (int j=0; j<COLS; j++) {
    maze[0][j] = '.';
    maze[ROWS-1][j] = '.';
  }

  for (int i=0; i<ROWS; i++) {
    maze[i][0] = '.';
    maze[i][COLS-1] = '.';
  }

  for (int i=1; i<100; i++) {
    int row = rand() % (ROWS-2) + 1;
    int col = rand() % (COLS-2) + 1;
    maze[row][col] = '.';
  }

  printf("Maze before finding path:\n");
  printMaze();
  printf("\n");

  if (findPath(0, 0)) {
    printf("Path found!\n");
  } else {
    printf("Path not found.\n");
  }

  printf("Maze after finding path:\n");
  printMaze();

  return 0;
}