//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define WALL 1
#define PATH 0

void printMaze(int maze[ROWS][COLS]) {
  int i, j;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%c", maze[i][j] == WALL ? '#' : ' ');
    }
    printf("\n");
  }
}

void generateMaze(int maze[ROWS][COLS]) {
  srand(time(NULL)); // seed random number generator

  // set maze to all walls
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      maze[i][j] = WALL;
    }
  }

  // create the starting and ending points
  int start_x = rand() % (COLS / 2);
  int start_y = rand() % ROWS;
  maze[start_y][start_x] = PATH;

  int end_x = (COLS / 2) + (rand() % (COLS / 2));
  int end_y = rand() % ROWS;
  maze[end_y][end_x] = PATH;

  // randomly create paths in the maze
  int x = start_x, y = start_y;
  while (x != end_x || y != end_y) {
    // randomly choose which direction to move in
    int dir = rand() % 4;
    switch (dir) {
      // move up
      case 0:
        if (y - 1 >= 0 && maze[y - 1][x] == WALL) {
          y--;
          maze[y][x] = PATH;
        }
        break;

      // move down
      case 1:
        if (y + 1 < ROWS && maze[y + 1][x] == WALL) {
          y++;
          maze[y][x] = PATH;
        }
        break;

      // move left
      case 2:
        if (x - 1 >= 0 && maze[y][x - 1] == WALL) {
          x--;
          maze[y][x] = PATH;
        }
        break;

      // move right
      case 3:
        if (x + 1 < COLS && maze[y][x + 1] == WALL) {
          x++;
          maze[y][x] = PATH;
        }
        break;
    }
  }
}

// recursively find a path through the maze
int findPath(int maze[ROWS][COLS], int x, int y) {
  if (x < 0 || y < 0 || x >= COLS || y >= ROWS) {
    // out of bounds
    return 0;
  }

  if (maze[y][x] == WALL) {
    // hit a wall
    return 0;
  }

  if (maze[y][x] == PATH + 2) {
    // already visited this path
    return 0;
  }

  if (x == (COLS / 2) && y == ROWS / 2) {
    // reached the end
    return 1;
  }

  maze[y][x] = PATH + 2; // mark this path as visited

  // try to move up, down, left, right in turn
  int ret = findPath(maze, x, y - 1) ||
            findPath(maze, x, y + 1) ||
            findPath(maze, x - 1, y) ||
            findPath(maze, x + 1, y);

  if (ret) {
    // this path leads to the end
    maze[y][x] = PATH + 1;
    return 1;
  }

  return 0; // no path from this point leads to the end
}

int main() {
  int maze[ROWS][COLS];

  generateMaze(maze);

  printf("Generated maze:\n");
  printMaze(maze);
  printf("\n");

  if (findPath(maze, 0, 0)) {
    printf("Found a path through the maze!\n\n");
    printMaze(maze);
  } else {
    printf("Could not find a path through the maze.\n");
  }

  return 0;
}