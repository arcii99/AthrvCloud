//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10
#define MAX 100

// Structure for each cell in the grid
typedef struct cell {
  int x;
  int y;
  int gCost;
  int hCost;
  int fCost;
  struct cell *parent;
  int isObstacle;
} cell_t;

// Create the grid with random obstacle cells
void createGrid(cell_t grid[][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      grid[i][j].x = i;
      grid[i][j].y = j;
      grid[i][j].isObstacle = 0;
      if (rand() % 100 <= 20) {
        grid[i][j].isObstacle = 1;
      }
    }
  }
}

// Get the manhattan distance
int getManhattanDistance(cell_t current, cell_t end) {
  return abs(current.x - end.x) + abs(current.y - end.y);
}

// Check if the cell is within the bounds of the grid
int isWithinBounds(int x, int y) {
  return x >= 0 && x < ROW && y >= 0 && y < COL;
}

// Find the cell with the lowest fCost in the open list
cell_t *getLowestFCost(cell_t openList[], int count) {
  cell_t *lowest = &openList[0];
  for (int i = 0; i < count; i++) {
    if (openList[i].fCost < lowest->fCost) {
      lowest = &openList[i];
    }
  }
  return lowest;
}

// Check if the cell is in the given list
int isInList(cell_t list[], int count, cell_t current) {
  for (int i = 0; i < count; i++) {
    if (list[i].x == current.x && list[i].y == current.y) {
      return 1;
    }
  }
  return 0;
}

// Find the path from start to end using A* algorithm
cell_t *findPath(cell_t grid[][COL], cell_t start, cell_t end) {
  cell_t openList[MAX];
  cell_t closedList[MAX];
  int openCount = 0;
  int closedCount = 0;
  cell_t *current;

  // Add start node to open list
  start.gCost = 0;
  start.hCost = getManhattanDistance(start, end);
  start.fCost = start.gCost + start.hCost;
  openList[openCount++] = start;

  // Loop until end node is found or open list is empty
  while (openCount > 0) {
    // Get the cell with the lowest fCost from the open list
    current = getLowestFCost(openList, openCount);
    if (current->x == end.x && current->y == end.y) {
      return current;
    }

    // Move current cell from open to closed list
    for (int i = 0; i < openCount; i++) {
      if (openList[i].x == current->x && openList[i].y == current->y) {
        openList[i] = openList[--openCount];
        break;
      }
    }
    closedList[closedCount++] = *current;

    // Check all neighbors of current cell
    for (int x = -1; x <= 1; x++) {
      for (int y = -1; y <= 1; y++) {
        if (x == 0 && y == 0) {
          continue;
        }
        int neighborX = current->x + x;
        int neighborY = current->y + y;
        if (!isWithinBounds(neighborX, neighborY)) {
          continue;
        }
        cell_t *neighbor = &grid[neighborX][neighborY];
        if (isInList(closedList, closedCount, *neighbor) || neighbor->isObstacle) {
          continue;
        }

        // Calculate gCost, hCost, and fCost for neighbor cell
        int gCost = current->gCost + 1;
        int hCost = getManhattanDistance(*neighbor, end);
        int fCost = gCost + hCost;

        // Check if neighbor cell is already in open list
        if (!isInList(openList, openCount, *neighbor)) {
          neighbor->gCost = gCost;
          neighbor->hCost = hCost;
          neighbor->fCost = fCost;
          neighbor->parent = current;
          openList[openCount++] = *neighbor;
        } else if (fCost < neighbor->fCost) {
          neighbor->gCost = gCost;
          neighbor->hCost = hCost;
          neighbor->fCost = fCost;
          neighbor->parent = current;
        }
      }
    }
  }

  return NULL;
}

// Print the grid with the path from start to end
void printGrid(cell_t grid[][COL], cell_t start, cell_t end) {
  printf(" 0123456789\n");
  for (int i = 0; i < ROW; i++) {
    printf("%d", i);
    for (int j = 0; j < COL; j++) {
      if (grid[i][j].isObstacle) {
        printf("#");
      } else if (grid[i][j].x == start.x && grid[i][j].y == start.y) {
        printf("S");
      } else if (grid[i][j].x == end.x && grid[i][j].y == end.y) {
        printf("E");
      } else if (grid[i][j].parent != NULL) {
        printf(".");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  cell_t grid[ROW][COL];
  createGrid(grid);

  cell_t start = { 0, 0 };
  cell_t end = { ROW - 1, COL - 1 };

  cell_t *path = findPath(grid, start, end);
  if (path != NULL) {
    printGrid(grid, start, end);
  } else {
    printf("No path found\n");
  }

  return 0;
}