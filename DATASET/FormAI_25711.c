//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS]; // Initialize empty maze grid
int visited[ROWS][COLS]; // Initialize visited grid

int canGo(int x, int y) {
  if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
    return 0; // Out of bounds
  }
  if (visited[x][y]) {
    return 0; // Already visited
  }
  return 1;
}

void generateMaze(int x, int y) {
  visited[x][y] = 1; // Mark cell as visited

  // Define possible directions
  int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for (int i = 0; i < 4; i++) {
    int dx = directions[i][0];
    int dy = directions[i][1];
    int nx = x + dx;
    int ny = y + dy;

    if (canGo(nx, ny)) {
      maze[x][y] |= 1 << i;
      maze[nx][ny] |= 1 << (i ^ 1); // Opposite direction
      generateMaze(nx, ny);
      // Recursive backtracking
    }
  }
}

void printMaze() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("+");
      if (maze[i][j] & 1) {
        printf("---");
      } else {
        printf("   ");
      }
    }
    printf("+\n");
    for (int j = 0; j < COLS; j++) {
      if (maze[i][j] & 2) {
        printf("|   ");
      } else {
        printf("    ");
      }
    }
    printf("|\n");
  }
  for (int j = 0; j < COLS; j++) {
    printf("+---");
  }
  printf("+\n");
}

int main() {
  srand(time(NULL)); // Seed random number generator
  int startX = rand() % ROWS;
  int startY = rand() % COLS;

  generateMaze(startX, startY);
  printMaze();

  return 0;
}