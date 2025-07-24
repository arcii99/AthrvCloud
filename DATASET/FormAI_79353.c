//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int grid[ROW][COL] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
                      {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                      {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
                      {0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
                      {0, 1, 1, 1, 0, 1, 0, 0, 1, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 1, 1, 1, 1, 1, 0}};
// A grid representing the input graph

void printGrid() { // A function to print the grid
  printf("\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

bool isValid(int x, int y) { // A function to check whether a given node is valid or not
  if (x < 0 || x >= ROW || y < 0 || y >= COL) {
    return false; // Out of bounds
  } else if (grid[x][y] == 0) {
    return false; // Blocked
  } else {
    return true;
  }
}

bool findPath(int x, int y, int path[ROW][COL]) { // A recursive function to find the path
  if (x == ROW - 1 && y == COL - 1) { // Reached the end
    path[x][y] = 1;
    return true;
  }
  if (isValid(x, y)) { // Valid node
    path[x][y] = 1; // Mark the node as part of the path

    if (findPath(x + 1, y, path)) { // Check down
      return true;
    }
    if (findPath(x, y + 1, path)) { // Check right
      return true;
    }
    if (findPath(x - 1, y, path)) { // Check up
      return true;
    }
    if (findPath(x, y - 1, path)) { // Check left
      return true;
    }

    path[x][y] = 0; // Remove this node from the path
    return false;
  }
  return false;
}

int main() {
  int path[ROW][COL] = {0}; // Initializing all values as 0
  printGrid(); // Prints the initial grid
  if (findPath(0, 0, path)) { // Finding the path
    printf("\nPath found:");
    for (int i = 0; i < ROW; i++) { // Printing the path
      printf("\n");
      for (int j = 0; j < COL; j++) {
        printf("%d ", path[i][j]);
      }
    }
  } else { // No path found
    printf("\nNo path found");
  }
  printf("\n");
  return 0;
}