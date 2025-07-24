//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int rows = 10, cols = 20;
  int maze[rows][cols], visited[rows][cols];
  int x = 0, y = 0, next_x, next_y;
  int stack_x[rows * cols], stack_y[rows * cols], top = 0;

  // Initialize the maze and visited matrices
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      maze[i][j] = (i == 0 || i == rows - 1 || j == 0 || j == cols - 1);
      visited[i][j] = 0;
    }
  }

  // Seed the random number generator
  srand(time(NULL));

  // Create the maze using a randomized DFS algorithm
  while (1) {
    visited[y][x] = 1;

    // Check if all neighbors have been visited
    if (visited[y-1][x] && visited[y+1][x] && visited[y][x-1] && visited[y][x+1]) {
      if (top == 0) break; // Done!
      // Pop the previous cell off the stack
      top--;
      x = stack_x[top];
      y = stack_y[top];
      continue;
    }

    // Choose a random unvisited neighbor to visit next
    while (1) {
      int direction = rand() % 4;
      if (direction == 0 && !visited[y-1][x]) { // North
        next_x = x;
        next_y = y - 1;
        break;
      } else if (direction == 1 && !visited[y+1][x]) { // South
        next_x = x;
        next_y = y + 1;
        break;
      } else if (direction == 2 && !visited[y][x-1]) { // West
        next_x = x - 1;
        next_y = y;
        break;
      } else if (direction == 3 && !visited[y][x+1]) { // East
        next_x = x + 1;
        next_y = y;
        break;
      }
    }

    // Carve a path to the next cell
    if (next_x < x) { // West
      maze[y][x] &= ~1; // Remove west wall
      maze[next_y][next_x] &= ~4; // Remove east wall
    } else if (next_x > x) { // East
      maze[y][x] &= ~4; // Remove east wall
      maze[next_y][next_x] &= ~1; // Remove west wall
    } else if (next_y < y) { // North
      maze[y][x] &= ~2; // Remove north wall
      maze[next_y][next_x] &= ~8; // Remove south wall
    } else if (next_y > y) { // South
      maze[y][x] &= ~8; // Remove south wall
      maze[next_y][next_x] &= ~2; // Remove north wall
    }

    // Push the current cell onto the stack and move to the next cell
    stack_x[top] = x;
    stack_y[top] = y;
    top++;
    x = next_x;
    y = next_y;
  }

  // Print the maze
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (maze[i][j] & 1) printf("|"); else printf(" ");
      if (maze[i][j] & 2) printf("_"); else printf(" ");
    }
    printf("|\n");
  }

  return 0;
}