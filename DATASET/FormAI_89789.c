//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>

#define ROW 5
#define COL 5

// Global variables
int maze[ROW][COL] = {{0, 0, 0, 0, 0},
                      {0, 1, 1, 1, 0},
                      {0, 1, 0, 1, 0},
                      {0, 1, 1, 1, 0},
                      {0, 0, 0, 0, 0}};
int visited[ROW][COL] = {{0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0}};
int destination = 0;

// Function Declaration
int findPath(int x, int y);

int main() {
  int startX = 2;
  int startY = 1;

  printf("Starting position: (%d, %d)\n", startX, startY);
  
  destination = ROW * COL;
  
  if (findPath(startX, startY) == 0) {
    printf("Cannot find path to destination\n");
    return 1;
  }
  
  printf("Path:");
  for(int i=1; i<=destination; i++)
    printf(" %d,", i);
  
  return 0;
}

// Function Definition
int findPath(int x, int y) {
  if (maze[x][y] == 0 || visited[x][y] == 1)
    return 0;
    
  visited[x][y] = 1;
  
  if (destination == maze[x][y])
    return 1;
  
  // Go North
  if (findPath(x-1, y) == 1) {
    printf(" (%d, %d)", x-1, y);
    return 1;
  }
  
  // Go South
  if (findPath(x+1, y) == 1) {
    printf(" (%d, %d)", x+1, y);
    return 1;
  }
  
  // Go West
  if (findPath(x, y-1) == 1) {
   printf(" (%d, %d)", x, y-1);
   return 1;
  }
  
  // Go East
  if (findPath(x, y+1) == 1) {
    printf(" (%d, %d)", x, y+1);
    return 1;
  }
  
  return 0;
}