//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define ROWS 10
#define COLS 20

// Function prototypes
void printMaze(char maze[ROWS][COLS]);
bool solveMaze(char maze[ROWS][COLS], int row, int col);
bool isValid(char maze[ROWS][COLS], int row, int col);

// Main function
int main() {
  // Seed the random number generator for maze creation
  srand(time(0));

  // Create the maze with random walls
  char maze[ROWS][COLS];
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
        maze[i][j] = '|';
      } else if (rand() % 3 == 0) {
        maze[i][j] = '|';
      } else {
        maze[i][j] = ' ';
      }
    }
  }

  // Set the start and end points
  int startRow = rand() % (ROWS-2) + 1;
  int startCol = rand() % (COLS-2) + 1;
  int endRow, endCol;
  do {
    endRow = rand() % (ROWS-2) + 1;
    endCol = rand() % (COLS-2) + 1;
  } while (endRow == startRow && endCol == startCol);
  maze[startRow][startCol] = 'S';
  maze[endRow][endCol] = 'E';

  // Print the maze
  printMaze(maze);

  // Find and print the solution
  if (solveMaze(maze, startRow, startCol)) {
    printf("\nFound a path!\n");
  } else {
    printf("\nNo path found.\n");
  }
  printMaze(maze);

  return 0;
}

// Prints the given maze
void printMaze(char maze[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

// Solves the given maze starting at the specified row and column
bool solveMaze(char maze[ROWS][COLS], int row, int col) {
  // Base cases: out of bounds or hit a wall
  if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
    return false;
  } else if (maze[row][col] == '|') {
    return false;
  } else if (maze[row][col] == 'E') {
    return true;
  } else if (maze[row][col] == 'S') {
    // Don't mark the start cell as visited
  } else {
    maze[row][col] = '.';
  }

  // Try moving up, down, left, and right
  bool foundPath = false;
  #pragma omp task shared(foundPath) firstprivate(maze, row, col-1)
  if (isValid(maze, row, col-1)) {
    foundPath |= solveMaze(maze, row, col-1);
  }
  #pragma omp task shared(foundPath) firstprivate(maze, row, col+1)
  if (isValid(maze, row, col+1)) {
    foundPath |= solveMaze(maze, row, col+1);
  }
  #pragma omp task shared(foundPath) firstprivate(maze, row-1, col)
  if (isValid(maze, row-1, col)) {
    foundPath |= solveMaze(maze, row-1, col);
  }
  #pragma omp task shared(foundPath) firstprivate(maze, row+1, col)
  if (isValid(maze, row+1, col)) {
    foundPath |= solveMaze(maze, row+1, col);
  }

  // Mark dead ends with X's
  if (!foundPath) {
    maze[row][col] = 'X';
  }

  // Return whether or not a path was found
  return foundPath;
}

// Helper function to determine if the given cell is valid for pathfinding
bool isValid(char maze[ROWS][COLS], int row, int col) {
  return row >= 0 && row < ROWS && col >= 0 && col < COLS &&
         maze[row][col] != '|' && maze[row][col] != '.';
}