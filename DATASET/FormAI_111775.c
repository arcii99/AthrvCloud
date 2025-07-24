//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 5
#define MAX_COLS 5

typedef struct {
  int x;
  int y;
} Point;

int main() {
  int maze[MAX_ROWS][MAX_COLS] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
  };

  Point start = {0, 0};
  Point end = {4, 4};
  Point path[MAX_ROWS * MAX_COLS];
  int path_len = 0;

  path[path_len++] = start;

  while (path_len > 0) {
    Point curr = path[path_len - 1];

    if (curr.x == end.x && curr.y == end.y) {
      // We have found the end!
      printf("Found it!");
      return EXIT_SUCCESS;
    }

    if (maze[curr.x][curr.y] != 0) {
      // Can't move here
      path_len--;
      continue;
    }

    Point next_steps[4] = {
      // Check all 4 possible moves
      {curr.x - 1, curr.y},
      {curr.x + 1, curr.y},
      {curr.x, curr.y - 1},
      {curr.x, curr.y + 1}
    };

    int valid_moves = 0;
    for (int i = 0; i < 4; i++) {
      Point next = next_steps[i];
      if (next.x >= 0 && next.x < MAX_ROWS &&
          next.y >= 0 && next.y < MAX_COLS &&
          maze[next.x][next.y] == 0) {
            valid_moves++;
          }
    }

    if (valid_moves == 0) {
      // We're stuck, backtrack
      path_len--;
      continue;
    }

    // Choose the next step randomly
    int random_index = rand() % valid_moves;

    int i = 0;
    Point next;
    for (; i < 4; i++) {
      next = next_steps[i];
      if (next.x >= 0 && next.x < MAX_ROWS &&
          next.y >= 0 && next.y < MAX_COLS &&
          maze[next.x][next.y] == 0) {
            if (random_index == 0) {
              // Take this path
              break;
            }
            random_index--;
          }
    }

    path[path_len++] = next;
    maze[next.x][next.y] = path_len; // mark path
  }

  // We couldn't find a path!
  printf("No path found.");
  return EXIT_FAILURE;
}