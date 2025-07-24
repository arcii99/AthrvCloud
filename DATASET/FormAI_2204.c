//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 6
#define COL 6

int maze[ROW][COL] = {
  {1, 0, 1, 1, 1, 0},
  {1, 1, 1, 0, 1, 1},
  {0, 1, 0, 0, 1, 1},
  {1, 1, 1, 1, 1, 0},
  {1, 0, 0, 0, 0, 1},
  {0, 1, 1, 1, 1, 1}
};

int sol[ROW][COL] = {0}; // to store the solution

bool isSafe(int x, int y) // check whether (x, y) is within the maze and is not a wall
{
  if(x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1)
    return true;

  return false;
}

bool solveMaze(int x, int y)
{
  if(x == ROW-1 && y == COL-1) // reached the destination
  {
    sol[x][y] = 1;
    return true;
  }

  if(isSafe(x, y))
  {
    sol[x][y] = 1; // mark (x, y) as part of solution

    if(solveMaze(x+1, y)) // check for right
      return true;

    if(solveMaze(x, y+1)) // check for down
      return true;

    sol[x][y] = 0; // if none of the above worked, backtrack
  }

  return false;
}

void printSolution()
{
  for(int i=0; i<ROW; i++)
  {
    for(int j=0; j<COL; j++)
      printf("%d ", sol[i][j]);

    printf("\n");
  }
}

int main()
{
  if(solveMaze(0, 0)) // start from (0, 0)
    printSolution();

  else
    printf("No solution exists!");

  return 0;
}