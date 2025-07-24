//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WALL 1
#define PATH 0

void generateMaze(int arr[][COLS]);
void printMaze(int arr[][COLS]);
void dfs(int arr[][COLS], int row, int col);

int main() {
  int maze[ROWS][COLS];
  
  // seed random number generator
  srand(time(NULL));
  
  // generate maze
  generateMaze(maze);
  
  // solve maze
  dfs(maze, 1, 0);
  
  // print maze
  printMaze(maze);
  
  return 0;
}

void generateMaze(int arr[][COLS]) {
  int i, j;
  
  // set all cells to wall
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      arr[i][j] = WALL;
    }
  }
  
  // generate random paths
  for(i = 1; i < ROWS-1; i++) {
    for(j = 1; j < COLS-1; j++) {
      if(rand() % 2 == 0) {
        arr[i][j] = PATH;
      }
    }
  }
}

void printMaze(int arr[][COLS]) {
  int i, j;
  
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      if(arr[i][j] == WALL) {
        printf("X ");
      }
      else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void dfs(int arr[][COLS], int row, int col) {
  // check if we have arrived at the end
  if(row == ROWS-2 && col == COLS-1) {
    arr[row][col] = PATH;
    return;
  }
  
  // mark current position as visited
  arr[row][col] = PATH;
  
  // check neighbouring cells
  if(arr[row+1][col] == WALL) {
    // move down
    dfs(arr, row+1, col);
  }
  if(arr[row][col+1] == WALL) {
    // move right
    dfs(arr, row, col+1);
  }
  if(arr[row-1][col] == WALL) {
    // move up
    dfs(arr, row-1, col);
  }
  if(arr[row][col-1] == WALL) {
    // move left
    dfs(arr, row, col-1);
  }
}