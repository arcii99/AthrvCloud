//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

typedef struct {
  int x;
  int y;
} point;

void print_maze(int maze[MAZE_HEIGHT][MAZE_WIDTH], point curr) {
  int x, y;
  for (y = 0; y < MAZE_HEIGHT; y++) {
    for (x = 0; x < MAZE_WIDTH; x++) {
      if (curr.x == x && curr.y == y) {
        printf("o ");
      } else if (maze[y][x] == 1) {
        printf("# ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

int main() {
  point directions[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // right, down, left, up
  int maze[MAZE_HEIGHT][MAZE_WIDTH];
  int visited[MAZE_HEIGHT][MAZE_WIDTH];
  int i, j;
  point curr = {0, 0};
  int r;
  srand(time(NULL));
  
  // initialize maze and visited
  for (i = 0; i < MAZE_HEIGHT; i++) {
    for (j = 0; j < MAZE_WIDTH; j++) {
      maze[i][j] = 1;
      visited[i][j] = 0;
    }
  }
  
  // initialize starting cell
  maze[0][0] = 0;
  visited[0][0] = 1;
  
  // generate maze
  while (curr.x != MAZE_WIDTH - 1 || curr.y != MAZE_HEIGHT - 1) {
    // choose random unvisited neighbor
    r = rand() % 4;
    while (1) {
      point neighbor = {curr.x + directions[r].x, curr.y + directions[r].y};
      if (neighbor.x >= 0 && neighbor.x < MAZE_WIDTH && neighbor.y >= 0 && neighbor.y < MAZE_HEIGHT && !visited[neighbor.y][neighbor.x]) {
        // remove wall between current cell and neighbor
        maze[(curr.y + neighbor.y) / 2][(curr.x + neighbor.x) / 2] = 0;
        // update current cell and mark neighbor as visited
        curr = neighbor;
        visited[curr.y][curr.x] = 1;
        break;
      }
      r = (r + 1) % 4;
    }
  }
  
  // print maze
  print_maze(maze, curr);
  
  return 0;
}