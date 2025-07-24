//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 8
#define COL 8

#define WALL 1

// heuristic function for A* algorithm
double heuristic(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// function to check if a position is valid
bool isValid(int row, int col, int grid[][COL]) {
  if (row < 0 || row >= ROW || col < 0 || col >= COL || grid[row][col] == WALL) {
    return false;
  }
  return true;
}

// A* algorithm to find the shortest path
void A_star(int grid[][COL], int sx, int sy, int dx, int dy) {
  bool closed[ROW][COL];
  memset(closed, false, sizeof(closed));

  int parent[ROW][COL];
  memset(parent, -1, sizeof(parent));

  double f[ROW][COL];
  memset(f, INFINITY, sizeof(f));
  f[sx][sy] = 0.0;

  int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  while (true) {
    double min_f = INFINITY;
    int curr_row = -1, curr_col = -1;

    // find the position with lowest f value
    for (int row = 0; row < ROW; row++) {
      for (int col = 0; col < COL; col++) {
        if (!closed[row][col] && f[row][col] < min_f) {
          min_f = f[row][col];
          curr_row = row;
          curr_col = col;
        }
      }
    }

    if (curr_row == -1 || curr_col == -1) {
      break;
    }

    if (curr_row == dx && curr_col == dy) {
      // goal reached, construct the path and print it
      int path[ROW * COL][2];
      int path_len = 0;

      int row = dx, col = dy;
      while (row != -1 && col != -1) {
        path[path_len][0] = row;
        path[path_len][1] = col;
        path_len++;

        int temp = parent[row][col];
        row = temp / COL;
        col = temp % COL;
      }

      printf("Shortest path: ");
      for (int i = path_len - 1; i >= 0; i--) {
        printf("(%d,%d) ", path[i][0], path[i][1]);
      }
      printf("\n");

      return;
    }

    closed[curr_row][curr_col] = true;

    // update the f, g and parent values of the neighboring positions
    for (int i = 0; i < 8; i++) {
      int neighbor_row = curr_row + dr[i];
      int neighbor_col = curr_col + dc[i];

      if (!isValid(neighbor_row, neighbor_col, grid)) {
        continue;
      }

      double tentative_g = f[curr_row][curr_col] + heuristic(curr_row, curr_col, neighbor_row, neighbor_col);

      if (tentative_g < f[neighbor_row][neighbor_col]) {
        parent[neighbor_row][neighbor_col] = curr_row * COL + curr_col;
        f[neighbor_row][neighbor_col] = tentative_g + heuristic(neighbor_row, neighbor_col, dx, dy);
      }
    }
  }

  printf("No path found!\n");
}

int main() {
  int grid[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 0}
  };

  int sx = 0, sy = 0;
  int dx = 7, dy = 7;

  printf("Starting position: (%d,%d)\n", sx, sy);
  printf("Destination: (%d,%d)\n", dx, dy);

  A_star(grid, sx, sy, dx, dy);

  return 0;
}