//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main(void) {
  int maze[ROWS][COLS];
  int visited[ROWS][COLS];
  int start_row = 0;
  int start_col = 0;
  int end_row = ROWS - 1;
  int end_col = COLS - 1;

  // Fill the maze with random values
  srand(time(NULL));
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      maze[row][col] = rand() % 2;
      visited[row][col] = 0;
    }
  }

  // Place the start and end points
  maze[start_row][start_col] = 0;
  maze[end_row][end_col] = 0;

  // Print the maze and start/end points
  printf("Starting maze:\n");
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (row == start_row && col == start_col) {
        printf("S ");
      } else if (row == end_row && col == end_col) {
        printf("E ");
      } else {
        printf("%d ", maze[row][col]);
      }
    }
    printf("\n");
  }
  printf("\n");

  // Run the pathfinding algorithm
  int path_found = 0;
  int current_row = start_row;
  int current_col = start_col;
  while (!path_found) {
    visited[current_row][current_col] = 1;
    if (current_row == end_row && current_col == end_col) {
      path_found = 1;
      break;
    }

    int north_row = current_row - 1;
    int south_row = current_row + 1;
    int west_col = current_col - 1;
    int east_col = current_col + 1;

    int has_unvisited_neighbors = 0;
    if (north_row >= 0 && !visited[north_row][current_col] && maze[north_row][current_col] == 0) {
      has_unvisited_neighbors = 1;
    }
    if (south_row < ROWS && !visited[south_row][current_col] && maze[south_row][current_col] == 0) {
      has_unvisited_neighbors = 1;
    }
    if (west_col >= 0 && !visited[current_row][west_col] && maze[current_row][west_col] == 0) {
      has_unvisited_neighbors = 1;
    }
    if (east_col < COLS && !visited[current_row][east_col] && maze[current_row][east_col] == 0) {
      has_unvisited_neighbors = 1;
    }
    if (!has_unvisited_neighbors) {
      printf("ERROR: No unvisited neighbors at (%d, %d)!\n", current_row, current_col);
      break;
    }

    while (1) {
      int direction = rand() % 4;
      switch (direction) {
        case 0:  // North
          if (north_row >= 0 && !visited[north_row][current_col] && maze[north_row][current_col] == 0) {
            current_row = north_row;
            goto FOUND_DIRECTION;
          }
          break;
        case 1:  // South
          if (south_row < ROWS && !visited[south_row][current_col] && maze[south_row][current_col] == 0) {
            current_row = south_row;
            goto FOUND_DIRECTION;
          }
          break;
        case 2:  // West
          if (west_col >= 0 && !visited[current_row][west_col] && maze[current_row][west_col] == 0) {
            current_col = west_col;
            goto FOUND_DIRECTION;
          }
          break;
        case 3:  // East
          if (east_col < COLS && !visited[current_row][east_col] && maze[current_row][east_col] == 0) {
            current_col = east_col;
            goto FOUND_DIRECTION;
          }
          break;
      }
    }

    FOUND_DIRECTION:
    // Do nothing, just jump to the next iteration
    ;
  }

  // Print the solution
  printf("Solution:\n");
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (row == start_row && col == start_col) {
        printf("S ");
      } else if (row == end_row && col == end_col) {
        printf("E ");
      } else if (visited[row][col]) {
        printf(". ");
      } else {
        printf("%d ", maze[row][col]);
      }
    }
    printf("\n");
  }

  return 0;
}