//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 30
#define COLS 30

// Function to generate random number between given limits
int generate_random_number(int lower, int upper){
  return(rand() % (upper - lower + 1)) + lower;
}

// Function to print the maze
void print_maze(int maze_map[][COLS]){
  for(int i=0; i<ROWS; i++){
    for(int j=0; j<COLS; j++){
      if(maze_map[i][j] == 0){
        printf("# ");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}

int main(){
  int maze_map[ROWS][COLS];
  int start_x = generate_random_number(1, ROWS-2);
  int start_y = generate_random_number(1, COLS-2);
  
  // Fill the maze with walls
  for(int i=0; i<ROWS; i++){
    for(int j=0; j<COLS; j++){
      maze_map[i][j] = 0;
    }
  }
  
  // Add the starting point in the maze
  maze_map[start_x][start_y] = 1;
  
  // Generate the maze using Depth First Search Algorithm
  int x = start_x;
  int y = start_y;
  int moves_x[4] = {-1, 0, 1, 0};
  int moves_y[4] = {0, 1, 0, -1};
  int stack_x[ROWS*COLS];
  int stack_y[ROWS*COLS];
  int top = 0;
  do{
    int moves[4];
    int possible_moves = 0;
    for(int i=0; i<4; i++){
      int new_x = x + moves_x[i];
      int new_y = y + moves_y[i];
      if(new_x >=1 && new_x < ROWS-1 && new_y >=1 && new_y < COLS-1 && maze_map[new_x][new_y] == 0){ // Check if the next move is not crossing the boundaries of the maze and the cell is not visited already
        moves[possible_moves] = i;
        possible_moves++;
      }
    }
    if(possible_moves > 0){ // If there are moves available
      int move_index = moves[generate_random_number(0, possible_moves-1)]; // Choose a random move
      x += moves_x[move_index];
      y += moves_y[move_index];
      maze_map[x][y] = 1;
      stack_x[top] = x;
      stack_y[top] = y;
      top++;
    }
    else{ // Backtrack to the last cell
      top--;
      x = stack_x[top];
      y = stack_y[top];
    }
  }while(top > 0);
  
  // Display the maze
  printf("Generated Maze:\n");
  print_maze(maze_map);
  
  return 0;
}