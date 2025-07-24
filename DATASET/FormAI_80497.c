//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

int maze[MAZE_SIZE][MAZE_SIZE];

void print_maze() {
  for(int row = 0; row < MAZE_SIZE; row++) {
    for(int col = 0; col < MAZE_SIZE; col++) {
      if(maze[row][col]) {
        printf(" ");
      } else {
        printf("█");
      }
    }
    printf("\n");
  }
}

void generate_maze() {
  srand(time(NULL));

  // Initialize maze to all walls
  for(int row = 0; row < MAZE_SIZE; row++) {
    for(int col = 0; col < MAZE_SIZE; col++) {
      maze[row][col] = 0;
    }
  }

  // Generate random starting point
  int cur_row = rand() % MAZE_SIZE;
  int cur_col = rand() % MAZE_SIZE;
  maze[cur_row][cur_col] = 1;

  // Loop until all spaces are filled
  while(1) {
    // Check for filled maze
    int filled = 1;
    for(int row = 0; row < MAZE_SIZE; row++) {
      for(int col = 0; col < MAZE_SIZE; col++) {
        if(maze[row][col] == 0) {
          filled = 0;
          break;
        }
      }
      if(!filled) break;
    }
    if(filled) break;

    // Find valid neighbors
    int neighbors[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int valid_neighbors[4][2];
    int num_valid_neighbors = 0;
    for(int i = 0; i < 4; i++) {
      int new_row = cur_row + neighbors[i][0];
      int new_col = cur_col + neighbors[i][1];
      if(new_row >= 0 && new_row < MAZE_SIZE && new_col >= 0 && new_col < MAZE_SIZE) {
        if(maze[new_row][new_col] == 0) {
          valid_neighbors[num_valid_neighbors][0] = new_row;
          valid_neighbors[num_valid_neighbors][1] = new_col;
          num_valid_neighbors++;
        }
      }
    }

    // Choose random neighbor and connect to current cell
    if(num_valid_neighbors > 0) {
      int rand_neighbor = rand() % num_valid_neighbors;
      int new_row = valid_neighbors[rand_neighbor][0];
      int new_col = valid_neighbors[rand_neighbor][1];
      if(new_row < cur_row) {
        maze[cur_row-1][cur_col] = 1;
      } else if(new_row > cur_row) {
        maze[cur_row+1][cur_col] = 1;
      } else if(new_col < cur_col) {
        maze[cur_row][cur_col-1] = 1;
      } else if(new_col > cur_col) {
        maze[cur_row][cur_col+1] = 1;
      }
      cur_row = new_row;
      cur_col = new_col;
    } else {
      // Backtrack if no valid neighbors
      for(int row = 0; row < MAZE_SIZE; row++) {
        for(int col = 0; col < MAZE_SIZE; col++) {
          if(maze[row][col] == 1) {
            int num_neighbors = 0;
            for(int i = 0; i < 4; i++) {
              int neighbor_row = row + neighbors[i][0];
              int neighbor_col = col + neighbors[i][1];
              if(neighbor_row >= 0 && neighbor_row < MAZE_SIZE && neighbor_col >= 0 && neighbor_col < MAZE_SIZE) {
                if(maze[neighbor_row][neighbor_col] == 1) {
                  num_neighbors++;
                }
              }
            }
            if(num_neighbors == 1) {
              maze[row][col] = 0;
              cur_row = row;
              cur_col = col;
              break;
            }
          }
        }
      }
    }
  }
}

int main() {
  generate_maze();
  print_maze();
  return 0;
}