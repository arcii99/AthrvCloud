//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

void print_maze(int maze[ROWS][COLS]) {
  int i, j;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%c", maze[i][j] == 1 ? '#' : ' ');
    }

    printf("\n");
  }
}

void generate_maze(int maze[ROWS][COLS], int row, int col) {
  int i, rand_dir;
  int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  maze[row][col] = 1;

  for (i = 0; i < 4; i++) {
    rand_dir = rand() % 4;

    int next_row = row + directions[rand_dir][0];
    int next_col = col + directions[rand_dir][1];

    if (next_row >= 0 && next_row < ROWS && next_col >= 0 && next_col < COLS && maze[next_row][next_col] == 0) {
      maze[row + directions[rand_dir][0] / 2][col + directions[rand_dir][1] / 2] = 1;
      generate_maze(maze, next_row, next_col);
    }
  }
}

int main() {
  srand(time(NULL));

  int maze[ROWS][COLS] = {0};

  generate_maze(maze, 0, 0);

  print_maze(maze);

  return 0;
}