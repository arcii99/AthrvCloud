//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11
#define COLS 11

void printMaze(int maze[ROWS][COLS]);

int main() {
  int maze[ROWS][COLS];
  srand(time(NULL)); // seed random number generator

  // initialize maze to all walls
  for(int row=0; row<ROWS; row++) {
    for(int col=0; col<COLS; col++) {
      if(row == 0 || col == 0 || row == ROWS-1 || col == COLS-1) {
        maze[row][col] = 1; // boundary walls
      }
      else {
        maze[row][col] = rand()%2; // random walls
      }
    }
  }

  // start at top left and carve out maze
  int row = 1, col = 1;
  maze[row][col] = 0; // remove wall for starting point

  while(row != ROWS-2 || col != COLS-2) { // end at bottom right
    int direction = rand()%4; // randomly choose direction

    if(direction == 0 && row > 1 && maze[row-2][col] != 0) { // up
      maze[row-1][col] = 0; // remove wall
      row -= 2; // move
    }
    else if(direction == 1 && col < COLS-2 && maze[row][col+2] != 0) { // right
      maze[row][col+1] = 0; // remove wall
      col += 2; // move
    }
    else if(direction == 2 && row < ROWS-2 && maze[row+2][col] != 0) { // down
      maze[row+1][col] = 0; // remove wall
      row += 2; // move
    }
    else if(direction == 3 && col > 1 && maze[row][col-2] != 0) { // left
      maze[row][col-1] = 0; // remove wall
      col -= 2; // move
    }
  }

  printMaze(maze); // print finished maze

  return 0;
}

void printMaze(int maze[ROWS][COLS]) {
  for(int row=0; row<ROWS; row++) {
    for(int col=0; col<COLS; col++) {
      if(maze[row][col] == 1) {
        printf("# "); // wall
      }
      else {
        printf(". "); // path
      }
    }
    printf("\n");
  }
}