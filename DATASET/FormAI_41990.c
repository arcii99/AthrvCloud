//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// Function prototype
void printMaze(int [][COL], int, int);
void findRoute(int [][COL], int, int, int, int);

int main()
{
  int maze[ROW][COL] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                        {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
                        {1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                        {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
                        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

  // Print the maze
  printMaze(maze, ROW, COL);

  // Find the route
  findRoute(maze, ROW, COL, 1, 1);

  return 0;
}

// Prints the maze
void printMaze(int maze[][COL], int r, int c)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

// Finds the route to the end of the maze
void findRoute(int maze[][COL], int r, int c, int row, int col)
{
  // If we have reached the end of the maze
  if (row == r - 2 && col == c - 2)
  {
    printf("Reached the end of the maze!\n");
    maze[row][col] = 2;
    printMaze(maze, r, c);
    return;
  }

  // If we are at a valid location
  if (maze[row][col] == 0)
  {
    // Mark the current location as visited
    maze[row][col] = 2;

    // Move right
    findRoute(maze, r, c, row, col + 1);

    // Move down
    findRoute(maze, r, c, row + 1, col);

    // Move left
    findRoute(maze, r, c, row, col - 1);

    // Move up
    findRoute(maze, r, c, row - 1, col);

    // Mark the current location as visited (backtracking)
    maze[row][col] = 0;
  }
}