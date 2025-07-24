//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];

void initializeGrid() {
  // Set all grid values to 0
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      grid[i][j] = 0;
    }
  }
}

void printGrid() {
  // Print current grid values
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

void pathfinder(int sx, int sy, int ex, int ey) {
  // Set start and end positions
  grid[sx][sy] = 1;
  grid[ex][ey] = 2;
  
  // Define movement directions
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {-1, 0, 1, 0};
  
  // Initialize queue for pathfinding algorithm
  int queue[ROWS*COLS][2];
  int front = 0;
  int rear = 0;
  queue[rear][0] = sx;
  queue[rear][1] = sy;
  rear++;
  
  // Pathfinding algorithm
  while (front != rear) {
    int currentPos[2] = {queue[front][0], queue[front][1]};
    front++;
    for (int i = 0; i < 4; ++i) {
      int nextPos[2] = {currentPos[0]+dx[i], currentPos[1]+dy[i]};
      if (nextPos[0] < 0 || nextPos[0] >= ROWS || nextPos[1] < 0 || nextPos[1] >= COLS) {
        continue;
      }
      if (grid[nextPos[0]][nextPos[1]] == 2) {
        printf("Path found!\n");
        grid[nextPos[0]][nextPos[1]] = grid[currentPos[0]][currentPos[1]]+1;
        printGrid();
        return;
      }
      if (grid[nextPos[0]][nextPos[1]] == 0) {
        grid[nextPos[0]][nextPos[1]] = grid[currentPos[0]][currentPos[1]]+1;
        queue[rear][0] = nextPos[0];
        queue[rear][1] = nextPos[1];
        rear++;
      }
    }
  }
  
  // No path found
  printf("No path found.\n");
  printGrid();
}

int main() {
  initializeGrid();
  pathfinder(0, 0, 9, 9);
  return 0;
}