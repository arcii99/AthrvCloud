//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int map[ROW][COL] = {
  {1, 1, 1, 1, 1}, 
  {0, 1, 0, 0, 1}, 
  {0, 1, 1, 0, 1}, 
  {0, 0, 0, 0, 1}, 
  {1, 1, 1, 1, 1}
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool visited[ROW][COL];

void dfs(int x, int y) {
  visited[x][y] = true;
  printf("(%d, %d)\n", x, y);

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= ROW || ny >= COL)
      continue;

    if (visited[nx][ny] || map[nx][ny] == 0)
      continue;

    dfs(nx, ny);
  }
}

int main() {
  dfs(0, 0);

  return 0;
}