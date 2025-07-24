//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

char maze[ROWS][COLS];

void print_maze() {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      printf("%c", maze[row][col]);
    }
    printf("\n");
  }
}

void initialize_maze() {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (row == 0 || col == 0 || row == ROWS-1 || col == COLS-1) {
        maze[row][col] = '#';
      } else {
        maze[row][col] = ' ';
      }
    }
  }
}

int is_wall(int row, int col) {
  if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
    return 1;
  }
  return maze[row][col] == '#';
}

int count_neighbours(int row, int col) {
  int count = 0;
  if (is_wall(row-1, col)) count++;
  if (is_wall(row+1, col)) count++;
  if (is_wall(row, col-1)) count++;
  if (is_wall(row, col+1)) count++;
  return count;
}

void shuffle_directions(int *directions) {
  for (int i = 0; i < 4; i++) {
    int j = rand() % 4;
    int temp = directions[i];
    directions[i] = directions[j];
    directions[j] = temp;
  }
}

void generate_maze(int row, int col) {
  int directions[4] = {0, 1, 2, 3};
  shuffle_directions(directions);
  for (int i = 0; i < 4; i++) {
    int dr = 0, dc = 0;
    switch (directions[i]) {
      case 0: dr = -1; break;
      case 1: dr = 1; break;
      case 2: dc = -1; break;
      case 3: dc = 1; break;
    }
    if (count_neighbours(row+dr, col+dc) == 1) {
      maze[row+dr][col+dc] = '#';
      generate_maze(row+2*dr, col+2*dc);
    }
  }
}

int main() {
  srand(time(NULL));
  initialize_maze();
  generate_maze(2, 2);
  print_maze();
  return 0;
}