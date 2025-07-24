//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
  {'S', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'E'}
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void print_maze() {
  for (int i = 0; i < ROW; i++) {
    printf("%s\n", maze[i]);
  }
}

bool is_valid(int x, int y) {
  if (x < 0 || x >= ROW) {
    return false;
  }
  if (y < 0 || y >= COL) {
    return false;
  }
  if (maze[x][y] == '#') {
    return false;
  }
  return true;
}

bool dfs(int x, int y) {
  if (maze[x][y] == 'E') {
    return true;
  }
  maze[x][y] = '#';
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (is_valid(nx, ny)) {
      if (dfs(nx, ny)) {
        return true;
      }
    }
  }
  maze[x][y] = '.';
  return false;
}

int main() {
  printf("Original Maze:\n");
  print_maze();
  printf("Maze Routing:\n");
  if (dfs(0, 0)) {
    print_maze();
    printf("Route Found!\n");
  } else {
    printf("No Route Found\n");
  }
  return 0;
}