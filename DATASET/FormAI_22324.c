//FormAI DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define rows and columns of the grid
#define ROWS 20
#define COLS 50

// function to initialize the grid randomly
void initGrid(int grid[][COLS]) {
  int i, j;
  srand(time(NULL));
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      grid[i][j] = rand() % 2;
    }
  }
}

// function to print the grid
void printGrid(int grid[][COLS]) {
  int i, j;
  printf("\n");
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      if (grid[i][j] == 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// function to count the number of live neighbours of a cell
int countNeighbours(int grid[][COLS], int row, int col) {
  int i, j, count = 0;
  for (i = row - 1; i <= row + 1; i++) {
    for (j = col - 1; j <= col + 1; j++) {
      if ((i >= 0 && i < ROWS) && (j >= 0 && j < COLS)) {
        if (grid[i][j] == 1) {
          count++;
        }
      }
    }
  }
  count -= grid[row][col];
  return count;
}

// function to update the grid based on the rules of the game
void updateGrid(int grid[][COLS]) {
  int i, j, neighbours;
  int newGrid[ROWS][COLS];

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      neighbours = countNeighbours(grid, i, j);
      if (grid[i][j] == 1) {
        if (neighbours < 2 || neighbours > 3) {
          newGrid[i][j] = 0;
        } else {
          newGrid[i][j] = 1;
        }
      } else {
        if (neighbours == 3) {
          newGrid[i][j] = 1;
        } else {
          newGrid[i][j] = 0;
        }
      }
    }
  }

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      grid[i][j] = newGrid[i][j];
    }
  }
}

int main() {
  int grid[ROWS][COLS];
  int i;

  initGrid(grid);

  for (i = 0; i < 10; i++) {
    printGrid(grid);
    updateGrid(grid);
    printf("\n");
  }

  return 0;
}