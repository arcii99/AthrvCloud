//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

// Function to generate the maze
void generateMaze() {
  // Set all elements of the maze to 1
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      maze[i][j] = 1;
    }
  }

  // Set the starting position to 0
  maze[0][0] = 0;

  // Set the seed for the random number generator
  srand(time(NULL));

  // Generate the maze
  int x = 0;
  int y = 0;
  while(x != ROWS - 1 || y != COLS - 1) {
    int direction = rand() % 4;
    switch(direction) {
      case 0: // UP
        if(x > 0 && maze[x - 1][y] == 1) {
          maze[--x][y] = 0;
        }
        break;
      case 1: // RIGHT
        if(y < COLS - 1 && maze[x][y + 1] == 1) {
          maze[x][++y] = 0;
        }
        break;
      case 2: // DOWN
        if(x < ROWS - 1 && maze[x + 1][y] == 1) {
          maze[++x][y] = 0;
        }
        break;
      case 3: // LEFT
        if(y > 0 && maze[x][y - 1] == 1) {
          maze[x][--y] = 0;
        }
        break;
    }
  }
}

// Function to print the maze
void printMaze() {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  generateMaze();
  printMaze();
  return 0;
}