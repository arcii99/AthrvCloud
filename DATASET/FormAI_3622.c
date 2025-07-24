//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 21

int main(){

  srand(time(NULL));

  int maze[ROWS][COLS];
  int row, col;
  int i, j;

  // Initialize the maze cells as walls.
  for (row = 0; row < ROWS; row++) {
    for (col = 0; col < COLS; col++) {
      maze[row][col] = 1;
    }
  }

  // Pick a random starting cell.
  int start_row = rand() % ROWS;
  int start_col = rand() % COLS;
  maze[start_row][start_col] = 0;

  // Loop through all the cells in the maze.
  for (row = 0; row < ROWS; row++) {
    for (col = 0; col < COLS; col++) {

      // If the cell is a wall, skip it.
      if (maze[row][col] == 1) {
        continue;
      }

      // Randomly decide which walls to remove.
      if (row > 0 && maze[row-1][col] == 0 && rand() % 2 == 0) {
        maze[row][col] |= 8;
        maze[row-1][col] |= 2;
      }
      if (col < COLS-1 && maze[row][col+1] == 0 && rand() % 2 == 0) {
        maze[row][col] |= 4;
        maze[row][col+1] |= 1;
      }
      if (row < ROWS-1 && maze[row+1][col] == 0 && rand() % 2 == 0) {
        maze[row][col] |= 2;
        maze[row+1][col] |= 8;
      }
      if (col > 0 && maze[row][col-1] == 0 && rand() % 2 == 0) {
        maze[row][col] |= 1;
        maze[row][col-1] |= 4;
      }
    }
  }

  // Print out the maze.
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      if (maze[i][j] == 1) {
        printf("X ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}