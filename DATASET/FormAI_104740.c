//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 21 // maze rows (must be odd)
#define COL 41 // maze columns (must be odd)

typedef struct cell {
  int row, col; // row and column of the cell
  int visited; // has the cell been visited or not?
  int wall_left, wall_right, wall_top, wall_bottom; // does the cell have a wall on its left/right/top/bottom?
} cell;

cell maze[ROW][COL]; // 2D array representing the maze

void init_maze() {
  // initialize the maze
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      maze[i][j].row = i;
      maze[i][j].col = j;
      maze[i][j].visited = 0;
      maze[i][j].wall_left = 1;
      maze[i][j].wall_right = 1;
      maze[i][j].wall_top = 1;
      maze[i][j].wall_bottom = 1;
    }
  }
}

void print_maze() {
  // print the maze
  for (int i = 0; i < ROW; i++) {
    // top wall
    for (int j = 0; j < COL; j++) {
      if (maze[i][j].wall_top)
        printf("+-");
      else
        printf("+ ");
    }
    printf("+\n");

    // left wall, cell value or space
    for (int j = 0; j < COL; j++) {
      if (maze[i][j].wall_left)
        printf("| ");
      else
        printf("  ");
    }
    printf("|\n");
  }

  // bottom wall
  for (int j = 0; j < COL; j++) {
    printf("+-");
  }
  printf("+\n");
}

void remove_wall(int r1, int c1, int r2, int c2) {
  // remove a wall between two adjacent cells
  if (r1 == r2 && c1 < c2) {
    maze[r1][c1].wall_right = 0;
    maze[r2][c2].wall_left = 0;
  } else if (r1 == r2 && c1 > c2) {
    maze[r1][c1].wall_left = 0;
    maze[r2][c2].wall_right = 0;
  } else if (r1 < r2 && c1 == c2) {
    maze[r1][c1].wall_bottom = 0;
    maze[r2][c2].wall_top = 0;
  } else if (r1 > r2 && c1 == c2) {
    maze[r1][c1].wall_top = 0;
    maze[r2][c2].wall_bottom = 0;
  }
}

void generate_maze(int row, int col) {
  int current_row = row, current_col = col;
  int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up, right, down, left
  int visited_cells = 1; // number of visited cells
  int total_cells = (ROW - 2) * (COL - 2); // total number of cells
  
  maze[current_row][current_col].visited = 1;

  while (visited_cells < total_cells) {
    // randomly choose a direction
    int direction = rand() % 4;

    // calculate the next row and column
    int next_row = current_row + directions[direction][0];
    int next_col = current_col + directions[direction][1];

    // check if the next cell is within the maze and has not been visited
    if (next_row >= 0 && next_row < ROW && next_col >= 0 && next_col < COL && !maze[next_row][next_col].visited) {
      // remove the wall between the current cell and the next cell
      remove_wall(current_row, current_col, next_row, next_col);

      // set the visited flag for the next cell
      maze[next_row][next_col].visited = 1;

      // update the current cell
      current_row = next_row;
      current_col = next_col;

      // increment the visited cells counter
      visited_cells++;
    }
  }
}

int main() {
  srand(time(NULL)); // seed the random number generator

  init_maze(); // initialize the maze

  generate_maze(1, 1); // generate the maze starting from the top-left cell

  print_maze(); // print the maze

  return 0;
}