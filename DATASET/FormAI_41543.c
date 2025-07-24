//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20           // The size of the maze
#define ODDS 4         // The number of walls to create in each cell

#define WALL 1         // Values for the cell state
#define EMPTY 0        

#define NORTH 1        // Directions
#define EAST 2
#define SOUTH 4
#define WEST 8

// The maze grid
int maze[N][N];

// Function to randomly choose a direction
int choose_direction(int x, int y) {
  int directions[4];
  int count = 0;
  
  if (x > 0 && maze[x-1][y] == EMPTY) directions[count++] = WEST;
  if (y > 0 && maze[x][y-1] == EMPTY) directions[count++] = NORTH;
  if (x < N-1 && maze[x+1][y] == EMPTY) directions[count++] = EAST;
  if (y < N-1 && maze[x][y+1] == EMPTY) directions[count++] = SOUTH;
  
  if (count == 0) return 0;
  int r = rand() % count;
  return directions[r];
}

// Function to create the maze
void create_maze() {
  // Initialize the maze
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      maze[i][j] = WALL;
    }
  }
  
  // Choose a random starting point
  int x = rand() % N;
  int y = rand() % N;
  maze[x][y] = EMPTY;
  
  // Create the maze
  int count = 0;
  while (count < N*N) {
    int direction = choose_direction(x, y);
    if (direction != 0) {
      switch (direction) {
        case WEST:
          maze[x-1][y] = EMPTY;
          x--;
          break;
        case NORTH:
          maze[x][y-1] = EMPTY;
          y--;
          break;
        case EAST:
          maze[x+1][y] = EMPTY;
          x++;
          break;
        case SOUTH:
          maze[x][y+1] = EMPTY;
          y++;
          break;
      }
      count++;
    } else {
      // Backtrack to a cell with available directions
      int backtrack = 0;
      do {
        x = rand() % N;
        y = rand() % N;
        backtrack++;
      } while (maze[x][y] == WALL || choose_direction(x, y) == 0);
      count -= backtrack;
    }
  }
}

// Function to print the maze
void print_maze() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (maze[i][j] == WALL) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  srand(time(NULL));
  create_maze();
  print_maze();
  return 0;
}