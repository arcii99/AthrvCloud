//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function to print the maze.
void print_maze(char maze[ROWS][COLS]) {
  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      printf("%c ",maze[i][j]);
    }
    printf("\n");
  }
}

// Function to find the route through the maze.
int find_route(int x, int y, char maze[ROWS][COLS]) {
  // Check if the current position is the end of the maze.
  if(maze[x][y] == 'E') {
    return 1;
  }
  // Check if the current position is a wall or has already been visited.
  if(maze[x][y] == '#' || maze[x][y] == '*') {
    return 0;
  }
  // Mark the current position as visited.
  maze[x][y] = '*';
  // Check for possible directions to move.
  if(find_route(x+1,y,maze) == 1) { // Move down.
    return 1;
  }
  if(find_route(x-1,y,maze) == 1) { // Move up.
    return 1;
  }
  if(find_route(x,y+1,maze) == 1) { // Move right.
    return 1;
  }
  if(find_route(x,y-1,maze) == 1) { // Move left.
    return 1;
  }
  // If no successful paths were found, unmark the current position as visited.
  maze[x][y] = ' ';
  return 0;
}

int main() {
  char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ','#',' ',' ',' ','#',' ','#'},
    {'#',' ',' ','#',' ','#',' ','#',' ','#'},
    {'#',' ',' ',' ',' ','#',' ','#',' ','#'},
    {'#','#','#','#',' ','#','#','#',' ','#'},
    {'#',' ',' ',' ',' ','#',' ',' ',' ','#'},
    {'#',' ','#','#',' ','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#',' ',' ','#'},
    {'#',' ',' ',' ','#',' ',' ','#','E','#'}
  };
  
  // Print the initial maze.
  printf("Initial Maze:\n");
  print_maze(maze);
  
  // Find the route through the maze.
  int start_x = 1;
  int start_y = 1;
  if(find_route(start_x,start_y,maze) == 1) {
    printf("\nRoute Found!\n");
  } else {
    printf("\nRoute Not Found.\n");
  }
  
  // Print the final maze with the route marked.
  printf("Final Maze:\n");
  print_maze(maze);
  
  return 0;
}