//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

#define ROW 8
#define COL 8

int maze[ROW][COL] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 1, 0, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 1, 1, 0},
  {0, 1, 0, 1, 1, 0, 1, 0}
};

void printSolution(int sol[ROW][COL]) {
  for(int i = 0; i < ROW; i++) {
    for(int j = 0; j < COL; j++) {
      printf("%d ", sol[i][j]);
    }
    printf("\n");
  }
}

bool canMove(int x, int y) {
  if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1)
    return true;
  return false;
}

bool findRoute(int x, int y, int sol[ROW][COL]) {
  if (x == ROW - 1 && y == COL - 1) {
    sol[x][y] = 1;
    return true;
  }

  if (canMove(x, y)) {
    sol[x][y] = 1;

    if (findRoute(x+1, y, sol))
      return true;

    if (findRoute(x, y+1, sol))
      return true;

    sol[x][y] = 0;
    return false;
  }

  return false;
}

int main() {
  int sol[ROW][COL] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0} };

  if (findRoute(0, 0, sol) == false) {
    printf("There is no solution for this maze.");
    return 0;
  }

  printSolution(sol);

  return 0;
}