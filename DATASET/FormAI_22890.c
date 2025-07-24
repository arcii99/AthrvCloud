//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];
int startX, startY, endX, endY;

void generateMaze() {
  srand(time(NULL));  // seed random number generator

  // initialize maze with zeros
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      maze[i][j] = 0;
    }
  }

  // randomly generate maze walls
  for (int i = 1; i < ROWS - 1; i++) {
    for (int j = 1; j < COLS - 1; j++) {
      if (i % 2 == 1 && j % 2 == 1) {  // every other cell is a wall
        maze[i][j] = 1;
        if (rand() % 2 == 0) {  // randomly place another wall in same row or column
          maze[i][j-1] = 1;
        } else {
          maze[i-1][j] = 1;
        }
      }
    }
  }

  // randomly generate start and end points
  do {
    startX = rand() % (ROWS - 2) + 1;
    startY = rand() % (COLS - 2) + 1;
  } while (maze[startX][startY] == 1);

  do {
    endX = rand() % (ROWS - 2) + 1;
    endY = rand() % (COLS - 2) + 1;
  } while (maze[endX][endY] == 1 || (endX == startX && endY == startY));

  // set start and end points
  maze[startX][startY] = 2;
  maze[endX][endY] = 3;
}

void printMaze() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (maze[i][j] == 0) {
        printf("  ");  // empty cell
      } else if (maze[i][j] == 1) {
        printf("##");  // wall
      } else if (maze[i][j] == 2) {
        printf("S ");  // start point
      } else if (maze[i][j] == 3) {
        printf("E ");  // end point
      } else if (maze[i][j] == 4) {
        printf(". ");  // cell on final path
      }
    }
    printf("\n");
  }
}

int isVisited(int i, int j, int visited[][COLS]) {
  for (int k = 0; k < ROWS; k++) {
    for (int l = 0; l < COLS; l++) {
      if (visited[k][l] == 1 && k == i && l == j) {
        return 1;
      }
    }
  }
  return 0;
}

int isSafe(int i, int j) {
  return (i >= 0 && i < ROWS && j >= 0 && j < COLS && maze[i][j] != 1);
}

int findPath(int i, int j, int visited[][COLS]) {
  visited[i][j] = 1;

  if (i == endX && j == endY) {
    maze[i][j] = 4;  // mark final cell
    return 1;
  }

  if (isSafe(i+1, j) && !isVisited(i+1, j, visited) && findPath(i+1, j, visited)) {
    maze[i][j] = 4;  // mark cell on final path
    return 1;
  }

  if (isSafe(i, j+1) && !isVisited(i, j+1, visited) && findPath(i, j+1, visited)) {
    maze[i][j] = 4;  // mark cell on final path
    return 1;
  }

  if (isSafe(i-1, j) && !isVisited(i-1, j, visited) && findPath(i-1, j, visited)) {
    maze[i][j] = 4;  // mark cell on final path
    return 1;
  }

  if (isSafe(i, j-1) && !isVisited(i, j-1, visited) && findPath(i, j-1, visited)) {
    maze[i][j] = 4;  // mark cell on final path
    return 1;
  }

  return 0;
}

int main() {
  generateMaze();
  printf("Maze:\n");
  printMaze();

  int visited[ROWS][COLS] = {0};
  if (findPath(startX, startY, visited)) {
    printf("Path found!\n");
    printf("Maze with path:\n");
    printMaze();
  } else {
    printf("No path found.\n");
  }

  return 0;
}