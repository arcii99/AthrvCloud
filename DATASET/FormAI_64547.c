//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

int maze[WIDTH][HEIGHT];

void print_maze() {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (maze[j][i] == 1) {
        printf("█"); //print wall
      } else {
        printf(" "); //print open space
      }
    }
    printf("\n");
  }
}

void generate_maze(int x, int y) {
  int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}}; //up, down, right, left
  int i, r;
  int new_x, new_y;
  
  for (i = 0; i < 4; i++) {
    r = rand() % 4;
    new_x = x + directions[r][0];
    new_y = y + directions[r][1];
    
    if (new_x < 0 || new_x >= WIDTH || new_y < 0 || new_y >= HEIGHT) {
      continue; //out of bounds
    }
    
    if (maze[new_x][new_y] == 0) { //if the new space is open
      if (r == 0) {
        maze[x][y] |= 1;      //set current wall as north
        maze[new_x][new_y] |= 2; //set new wall as south
      } else if (r == 1) {
        maze[x][y] |= 2;      //south
        maze[new_x][new_y] |= 1; //north
      } else if (r == 2) {
        maze[x][y] |= 4;      //east
        maze[new_x][new_y] |= 8; //west
      } else {
        maze[x][y] |= 8;      //west
        maze[new_x][new_y] |= 4; //east
      }
      generate_maze(new_x, new_y);
    }
  }
}

int main() {
  srand(time(NULL));
  int x, y;
  x = rand() % WIDTH;
  y = rand() % HEIGHT;
  generate_maze(x, y);
  print_maze();
  return 0;
}