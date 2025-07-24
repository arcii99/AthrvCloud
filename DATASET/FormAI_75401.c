//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include<stdio.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
  {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void printMaze() {
  for(int i=0;i<ROW;i++) {
    for(int j=0;j<COL;j++) {
      if(maze[i][j] == 1) {
        printf("# ");
      } else { 
        printf(". ");
      }         
    }
    printf("\n");     
  }
}

int findPath(int x, int y) {
  if (x<0 || x>=ROW || y<0 || y>=COL) {
    return 0; // out of maze
  }
  if (maze[x][y] == 0) {
    return 0; // wall   
  }
  if (maze[x][y] == 2) {
    return 0; // already visited
  }
  if (x == ROW-1 && y == COL-1) {
    maze[x][y] = 2; // mark as visited
    return 1; // destination reached
  }
  maze[x][y] = 2; // mark as visited
  if (findPath(x+1, y) || findPath(x, y+1) || findPath(x-1, y) || findPath(x, y-1)) {
    return 1; // successful path
  }
  maze[x][y] = 0; // unmark as visited
  return 0; // unsuccessful path
}

int main() {
  printf("The Original Maze:\n");
  printMaze();
  printf("\n");

  if(findPath(0, 0)) {
    printf("Path Found!\n");
    printf("\n");

    printf("The Modified Maze:\n");
    printMaze();
    printf("\n");
  } else {
    printf("Path not Found!\n");
  }

  return 0;
}