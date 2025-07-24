//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
  {0, 0, 1, 1, 1},
  {0, 1, 1, 0, 0},
  {0, 0, 0, 0, 0},
  {1, 0, 1, 1, 0},
  {1, 0, 0, 1, 0}
};

void printMaze() {
  printf("\nMaze:\n\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int findPath(int row, int col) {
  if (row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == 1) {
    return 0;
  }

  maze[row][col] = 1;

  if (row == ROWS - 1 && col == COLS - 1) {
    printf("%d,%d\n", row, col);
    return 1;
  }

  if (findPath(row + 1, col) || findPath(row, col + 1) || findPath(row - 1, col) || findPath(row, col - 1)) {
    printf("%d,%d\n", row, col);
    return 1;
  }

  return 0;
}

int main() {
  printMaze();

  printf("\nPath:\n\n");
  if (findPath(0, 0)) {
    printMaze();
  }
  else {
    printf("No path found.\n");
  }

  return 0;
}