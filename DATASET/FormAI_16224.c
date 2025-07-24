//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6
#define COL 6

bool visited[ROW][COL];
int goalRow = 5, goalCol = 5;
int startRow = 0, startCol = 0;

void printPath(bool path[ROW][COL]) {
  printf("The path from start to end is:\n");
  for(int i=0; i<ROW; i++) {
    for(int j=0; j<COL; j++) {
      if(path[i][j]) {
        printf("* ");
      } else {
        printf("- ");
      }
    }
    printf("\n");
  }
}

bool isValidPath(int row, int col, int maze[ROW][COL]) {
  // check if row and col are within limits
  // check if maze[row][col] is not 0 (wall)
  // if these conditions are satisfied, return true
  if(row >= 0 && col >= 0 && row < ROW && col < COL && maze[row][col] != 0) {
    return true;
  }
  return false;
}

void findPath(int maze[ROW][COL], bool path[ROW][COL], int row, int col) {
  // mark current cell as visited
  visited[row][col] = true;
  // mark current cell in path
  path[row][col] = true;
  // if current cell is the goal, print path and return
  if(row == goalRow && col == goalCol) {
    printPath(path);
    return;
  }
  // check top
  if(isValidPath(row-1, col, maze) && !visited[row-1][col]) {
    findPath(maze, path, row-1, col);
  }
  // check right
  if(isValidPath(row, col+1, maze) && !visited[row][col+1]) {
    findPath(maze, path, row, col+1);
  }
  // check bottom
  if(isValidPath(row+1, col, maze) && !visited[row+1][col]) {
    findPath(maze, path, row+1, col);
  }
  // check left
  if(isValidPath(row, col-1, maze) && !visited[row][col-1]) {
    findPath(maze, path, row, col-1);
  }
  // if no valid path found, mark current cell as unvisited
  visited[row][col] = false;
  path[row][col] = false;
}

int main() {
  int maze[ROW][COL] = {{1,1,1,1,0,1},
                        {1,0,1,1,0,1},
                        {1,1,0,1,1,1},
                        {1,0,1,1,0,0},
                        {1,1,1,0,1,1},
                        {1,0,1,1,1,1}};
  bool path[ROW][COL] = {0};
  findPath(maze, path, startRow, startCol);
  return 0;
}