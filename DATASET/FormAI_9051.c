//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

int maze[MAZE_WIDTH][MAZE_HEIGHT];

// Function to initialize maze array
void initialize_maze() {
  for(int i = 0; i < MAZE_HEIGHT; i++) {
    for(int j = 0; j < MAZE_WIDTH; j++) {
      if(i == 0 || i == MAZE_HEIGHT-1 || j == 0 || j == MAZE_WIDTH-1) {
        maze[i][j] = 1;
      } else {
        maze[i][j] = 0;
      }
    }
  }
}

int get_random_direction() {
  int direction = rand() % 4;
  return direction;
}

// Function to generate random maze using DFS algorithm
void generate_maze(int row, int col) {
  maze[row][col] = 1;

  int directions[4] = {0,1,2,3};
  int temp_directions[4];
  int temp_index = 0;
  int temp_horizontal = 0;
  int temp_vertical = 0;

  for(int i = 0; i < 4; i++) {
    int temp = directions[i];
    int swap_index = rand() % 4;
    directions[i] = directions[swap_index];
    directions[swap_index] = temp;
  }

  for(int i = 0; i < 4; i++) {
    int temp_direction = directions[i];

    if(temp_direction == 0) {
      temp_horizontal = row-2;
      temp_vertical = col;
    } else if(temp_direction == 1) {
      temp_horizontal = row+2;
      temp_vertical = col;
    } else if(temp_direction == 2) {
      temp_horizontal = row;
      temp_vertical = col-2;
    } else {
      temp_horizontal = row;
      temp_vertical = col+2;
    }

    if(temp_horizontal <= 0 || temp_horizontal >= MAZE_HEIGHT-1 || temp_vertical <= 0 || temp_vertical >= MAZE_WIDTH-1) {
      continue;
    }

    if(maze[temp_horizontal][temp_vertical] == 0) {
      maze[(row+temp_horizontal)/2][(col+temp_vertical)/2] = 1;
      generate_maze(temp_horizontal,temp_vertical);
    }
  }
}

// Function to print maze to console
void print_maze() {
  for(int i = 0; i < MAZE_HEIGHT; i++) {
    for(int j = 0; j < MAZE_WIDTH; j++) {
      if(maze[i][j] == 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  initialize_maze();
  generate_maze(1,1);
  print_maze();
  return 0;
}