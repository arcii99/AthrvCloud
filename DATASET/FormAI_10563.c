//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Define the dimensions of the maze
#define ROWS 10
#define COLS 10

// Define the walls of the maze
#define WALL 1
#define EMPTY 0

// Define the route types
#define CURRENT 2
#define VISITED 3

// Define the starting and ending points of the maze
#define START_ROW 0
#define START_COL 0
#define END_ROW ROWS-1
#define END_COL COLS-1

// Define the maze array
int maze[ROWS][COLS] = {
  {EMPTY, WALL, EMPTY, EMPTY, WALL, WALL, WALL, EMPTY, WALL, WALL},
  {EMPTY, WALL, WALL, EMPTY, EMPTY, WALL, WALL, EMPTY, EMPTY, WALL},
  {EMPTY, WALL, WALL, WALL, EMPTY, WALL, WALL, EMPTY, WALL, WALL},
  {EMPTY, EMPTY, WALL, EMPTY, EMPTY, WALL, EMPTY, WALL, WALL, WALL},
  {WALL, EMPTY, EMPTY, WALL, WALL, WALL, EMPTY, EMPTY, EMPTY, WALL},
  {WALL, EMPTY, WALL, WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL},
  {WALL, EMPTY, WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL},
  {EMPTY, EMPTY, WALL, WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL},
  {WALL, WALL, EMPTY, EMPTY, EMPTY, WALL, WALL, EMPTY, EMPTY, WALL},
  {WALL, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, EMPTY, EMPTY}
};

// Define the route search function
int findRoute(int row, int col) {

  // Check if the current location is the destination
  if (row == END_ROW && col == END_COL) {
    maze[row][col] = CURRENT;
    return 1;
  }

  // Check if the current location is a wall or has been visited before
  if (maze[row][col] != EMPTY) {
    return 0;
  }

  // Mark the current location as visited
  maze[row][col] = CURRENT;

  // Check if there is a route to the right
  if (col < COLS-1 && findRoute(row, col+1)) {
    return 1;
  }

  // Check if there is a route down
  if (row < ROWS-1 && findRoute(row+1, col)) {
    return 1;
  }

  // Check if there is a route to the left
  if (col > 0 && findRoute(row, col-1)) {
    return 1;
  }

  // Check if there is a route up
  if (row > 0 && findRoute(row-1, col)) {
    return 1;
  }

  // Mark the current location as visited
  maze[row][col] = VISITED;

  // Return false if no route was found
  return 0;

}

// Define the display function
void displayMaze() {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      switch(maze[row][col]) {
        case WALL:
          printf("# ");
          break;
        case VISITED:
          printf(". ");
          break;
        case CURRENT:
          printf("X ");
          break;
        default:
          printf("  ");
      }
    }
    printf("\n");
  }
}

// Define main function
int main() {

  // Find the route through the maze
  findRoute(START_ROW, START_COL);

  // Display the maze with the found route
  displayMaze();

  return 0;
}