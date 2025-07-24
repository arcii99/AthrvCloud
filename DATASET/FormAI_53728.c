//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void generateMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);

int main() {
  char maze[ROWS][COLS];
  
  // Seed the random number generator
  srand(time(NULL));
  
  // Generate the maze and print it
  generateMaze(maze);
  printMaze(maze);
  
  return 0;
}

void generateMaze(char maze[ROWS][COLS]) {
  int i, j;
  
  // Initialize the maze with walls
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      maze[i][j] = '#';
    }
  }
  
  // Carve out the maze starting from the top-left corner
  int row = 1, col = 1;
  maze[row][col] = ' ';
  while (row != ROWS - 2 || col != COLS - 2) {
    switch (rand() % 4) {
      case 0: // Try to move up
        if (maze[row - 1][col] == '#' && maze[row - 2][col] == '#') {
          maze[row - 1][col] = ' ';
          maze[row - 2][col] = ' ';
          row -= 2;
        }
        break;
      case 1: // Try to move down
        if (maze[row + 1][col] == '#' && maze[row + 2][col] == '#') {
          maze[row + 1][col] = ' ';
          maze[row + 2][col] = ' ';
          row += 2;
        }
        break;
      case 2: // Try to move left
        if (maze[row][col - 1] == '#' && maze[row][col - 2] == '#') {
          maze[row][col - 1] = ' ';
          maze[row][col - 2] = ' ';
          col -= 2;
        }
        break;
      case 3: // Try to move right
        if (maze[row][col + 1] == '#' && maze[row][col + 2] == '#') {
          maze[row][col + 1] = ' ';
          maze[row][col + 2] = ' ';
          col += 2;
        }
        break;
    }
  }
}

void printMaze(char maze[ROWS][COLS]) {
  int i, j;
  
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}