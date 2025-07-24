//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define M 10

typedef struct Cell {
  int x, y;   // cell position
  int f, g, h; // evaluation variables
  struct Cell* parent; // parent cell
  int obstacle; // boolean indicating obstacle presence
} Cell;

Cell* getBestCell(Cell** openSet) {
  // returns the cell with lowest f value from the open set
  Cell* bestCell = openSet[0];
  int i = 0;
  while (openSet[i] != NULL) {
    if (openSet[i]->f < bestCell->f) bestCell = openSet[i];
    i++;
  }
  return bestCell;
}

int heuristic(int x1, int y1, int x2, int y2) {
  // Manhattan distance as heuristic function
  return abs(x2-x1) + abs(y2-y1);
}

void findPath(Cell grid[N][M], Cell* startCell, Cell* goalCell) {
  Cell* currentCell = startCell;
  Cell* openSet[N*M] = {0};
  Cell* closedSet[N*M] = {0};
  int nOpenSet = 0, nClosedSet = 0;
  
  // while the goal was not reached yet...
  while (currentCell != goalCell) {
    // evaluate each adjacent cell
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        // ignore the current cell and diagonals
        if ((i == 0 && j == 0) || (i != 0 && j != 0)) continue;
        int x = currentCell->x + i, y = currentCell->y + j;
        // verify if the cell is inside the grid
        if (x >= 0 && x < N && y >= 0 && y < M) {
          Cell* neighbor = &grid[x][y];
          // ignore obstacles and already closed neighbors
          if (!neighbor->obstacle && !closedSet[neighbor->x*N+neighbor->y]) {
            int tentativeG = currentCell->g + heuristic(currentCell->x, currentCell->y, neighbor->x, neighbor->y);
            if (!openSet[neighbor->x*N+neighbor->y] || tentativeG < neighbor->g) {
              // if the neighbor is not opened yet or a shorter path was found, update it
              neighbor->parent = currentCell;
              neighbor->g = tentativeG;
              neighbor->h = heuristic(neighbor->x, neighbor->y, goalCell->x, goalCell->y);
              neighbor->f = neighbor->g + neighbor->h;
              if (!openSet[neighbor->x*N+neighbor->y]) {
                openSet[neighbor->x*N+neighbor->y] = neighbor;
                nOpenSet++;
              }
            }
          }
        }
      }
    }
    // move current cell from open to closed set
    openSet[currentCell->x*N+currentCell->y] = NULL;
    nOpenSet--;
    closedSet[currentCell->x*N+currentCell->y] = currentCell;
    nClosedSet++;
    // update current cell with the best from the open set
    currentCell = getBestCell(openSet);
    // if there's no more cells in the open set, abort
    if (nOpenSet == 0) {
      printf("Could not reach the goal!\n");
      return;
    }
  }
  
  // print the found path
  while (currentCell != startCell) {
    printf("(%d,%d) <- ", currentCell->x, currentCell->y);
    currentCell = currentCell->parent;
  }
  printf("(%d,%d)\n", startCell->x, startCell->y);
}

int main() {
  Cell grid[N][M] = {0};
  // initialize grid with obstacles
  grid[3][1].obstacle = 1;
  grid[3][2].obstacle = 1;
  grid[3][3].obstacle = 1;
  grid[5][8].obstacle = 1;
  grid[6][8].obstacle = 1;
  grid[7][8].obstacle = 1;
  printf("Start: (1,1) Goal: (7,4)\n");
  findPath(grid, &grid[1][1], &grid[7][4]);
  return 0;
}