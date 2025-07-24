//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS];

void printMaze() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }
}

int randomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}

int main() {
  srand(time(NULL));

  // Initialize maze
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
        maze[i][j] = '#';
      } else {
        maze[i][j] = '.';
      }
    }
  }

  // Add obstacles
  int numObstacles = randomNumber(10, 20);
  for (int i = 0; i < numObstacles; i++) {
    int row = randomNumber(1, ROWS-2);
    int col = randomNumber(1, COLS-2);
    maze[row][col] = '#';
  }

  // Choose start and end points
  int startRow = randomNumber(1, ROWS-2);
  int startCol = 0;
  maze[startRow][startCol] = 'S';

  int endRow = randomNumber(1, ROWS-2);
  int endCol = COLS-1;
  maze[endRow][endCol] = 'E';

  // Print initial maze
  printf("Initial maze:\n");
  printMaze();

  // Find path using DFS
  int stackX[ROWS*COLS];
  int stackY[ROWS*COLS];
  int top = -1;

  stackX[++top] = startRow;
  stackY[top] = startCol;

  while (top >= 0) {
    int curRow = stackX[top];
    int curCol = stackY[top--];

    if (curRow == endRow && curCol == endCol) {
      break;
    }

    // Check adjacent cells
    if (curRow+1 < ROWS && maze[curRow+1][curCol] == '.') {
      stackX[++top] = curRow+1;
      stackY[top] = curCol;
      maze[curRow+1][curCol] = '>';
    }
    if (curCol+1 < COLS && maze[curRow][curCol+1] == '.') {
      stackX[++top] = curRow;
      stackY[top] = curCol+1;
      maze[curRow][curCol+1] = 'v';
    }
    if (curRow-1 >= 0 && maze[curRow-1][curCol] == '.') {
      stackX[++top] = curRow-1;
      stackY[top] = curCol;
      maze[curRow-1][curCol] = '<';
    }
    if (curCol-1 >= 0 && maze[curRow][curCol-1] == '.') {
      stackX[++top] = curRow;
      stackY[top] = curCol-1;
      maze[curRow][curCol-1] = '^';
    }
  }

  // Print final maze
  printf("\nFinal maze:\n");
  printMaze();

  if (top >= 0) {
    printf("\nPath found!\n");
  } else {
    printf("\nNo path found.\n");
  }

  return 0;
}