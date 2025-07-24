//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

typedef struct {
  int x;
  int y;
} Point;

bool visited[ROWS][COLS];

char maze[ROWS][COLS] = {
  {'S', '#', '.', '.', '.'},
  {'.', '#', '.', '#', '.'},
  {'.', '.', '.', '.', '.'},
  {'.', '#', '.', '#', '.'},
  {'.', '.', '.', '#', 'E'}
};

Point directions[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isValidMove(int row, int col) {
  return row >= 0 && row < ROWS
    && col >= 0 && col < COLS
    && maze[row][col] != '#'
    && !visited[row][col];
}

bool findPath(int row, int col) {
  if (maze[row][col] == 'E') {
    return true;
  }

  for (int i = 0; i < 4; i++) {
    Point newMove = {row + directions[i].x, col + directions[i].y};
    if (isValidMove(newMove.x, newMove.y)) {
      visited[newMove.x][newMove.y] = true;
      if (findPath(newMove.x, newMove.y)) {
        printf("(%d, %d)\n", newMove.x, newMove.y);
        return true;
      }
    }
  }

  return false;
}

int main() {
  Point start = {0, 0};
  printf("Start: (%d, %d)\n", start.x, start.y);
  visited[start.x][start.y] = true;
  
  if (findPath(start.x, start.y)) {
    printf("Path found!\n");
  } else {
    printf("No path found.\n");
  }
  
  return 0;
}