//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
  {'#','#','#','#','#','#','#','#','#','#'},
  {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
  {'#',' ','#',' ','#',' ','#','#','#','#'},
  {'#',' ','#',' ',' ',' ',' ',' ',' ','#'},
  {'#','#','#',' ','#',' ','#','#','#','#'},
  {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
  {'#','#','#','#','#',' ','#','#','#','#'},
  {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
  {'#',' ','#','#','#','#','#',' ','#','#'},
  {'#','#','#','#','#','#','#','#','#','#'}
};

int start_row = 2;
int start_col = 0;
int end_row = 7;
int end_col = 9;

void printMaze() {
  printf("\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }
}

int solveMaze(int row, int col) {
  if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
    return 0;
  } else if (maze[row][col] == '#') {
    return 0;
  } else if (row == end_row && col == end_col) {
    maze[row][col] = '*';
    return 1;
  } else {
    maze[row][col] = '*';
    if (solveMaze(row - 1, col) || solveMaze(row, col + 1) || solveMaze(row + 1, col) || solveMaze(row, col - 1)) {
      return 1;
    } else {
      maze[row][col] = ' ';
      return 0;
    }
  }
}

int main() {
  printf("Starting maze:\n");
  printMaze();

  if (solveMaze(start_row, start_col)) {
    printf("Solution found:\n");
    printMaze();
  } else {
    printf("No solution found.\n");
  }
  
  return 0;
}