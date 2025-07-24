//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 8
#define COL 8

int maze[ROW][COL] = {
              {1, 0, 0, 0, 0, 1, 1, 1},
              {1, 1, 0, 1, 1, 1, 0, 0},
              {0, 1, 1, 1, 0, 0, 0, 1},
              {0, 1, 0, 1, 1, 1, 1, 0},
              {1, 1, 0, 0, 0, 1, 0, 1},
              {1, 0, 1, 1, 1, 1, 1, 1},
              {0, 1, 0, 0, 1, 0, 1, 0},
              {1, 1, 1, 0, 1, 1, 1, 1}
            };


bool is_valid(int row, int col) {
  return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (maze[row][col] != 0);
}

bool path_finder(int row, int col, int visited[ROW][COL]) {
  if (row == ROW-1 && col == COL-1) {
    return true;
  }

  if (is_valid(row, col) && !visited[row][col]) {
    visited[row][col] = 1;

    if (path_finder(row, col+1, visited)) {
      return true;
    }

    if (path_finder(row+1, col, visited)) {
      return true;
    }

    if (path_finder(row, col-1, visited)) {
      return true;
    }

    if (path_finder(row-1, col, visited)) {
      return true;
    }

    visited[row][col] = 0;
    return false;
  }

  return false;
}


int main() {
  int visited[ROW][COL];

  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      visited[i][j] = 0;
    }
  }

  if (path_finder(0, 0, visited)) {
    printf("Path found\n");
  } else {
    printf("Path not found\n");
  }

  return 0;
}