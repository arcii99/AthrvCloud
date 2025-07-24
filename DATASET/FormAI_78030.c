//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

void print_maze(char maze[ROWS][COLS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char maze[ROWS][COLS];
  
  // Initialize random seed
  srand(time(NULL));
  
  // Fill maze with walls
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      maze[i][j] = '#';
    }
  }
  
  // Generate random entrance and exit
  int entrance_col = rand() % COLS;
  maze[0][entrance_col] = ' ';
  
  int exit_col = rand() % COLS;
  maze[ROWS-1][exit_col] = ' ';
  
  // Generate path from entrance to exit
  int current_row = 0;
  int current_col = entrance_col;
  
  while(current_row < ROWS-1) {
    // Move in horizontal direction
    int choice = rand() % 3; // 0 = left, 1 = stay, 2 = right
    
    if(choice == 0 && current_col > 0) {
      current_col--;
    } else if(choice == 2 && current_col < COLS-1) {
      current_col++;
    }
    
    // Move in vertical direction
    current_row++;
    
    // Carve path
    if(maze[current_row][current_col] != ' ') {
      maze[current_row][current_col] = ' ';
    }
  }
  
  // Print maze
  print_maze(maze);
  
  return 0;
}