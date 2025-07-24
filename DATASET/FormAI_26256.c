//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

void createMaze(char maze[][COL]);
void printMaze(char maze[][COL]);
void findRoute(char maze[][COL], int i, int j);

int main() {
  char maze[ROW][COL];
  srand(time(NULL));
  createMaze(maze);
  printf("Welcome to Romeo and Juliet Maze Route Finder!\n");
  printf("In this maze, Romeo must find his way to Juliet through a series of obstacles.\n");
  printf("The maze is represented by the following characters:\n");
  printf("'X' - Represents a wall, which Romeo cannot pass through.\n");
  printf("'O' - Represents an open space, which Romeo can pass through.\n");
  printf("'R' - Represents Romeo's starting position.\n");
  printf("'J' - Represents Juliet's location, which Romeo must reach.\n");
  printf("Good luck Romeo, your Juliet awaits you!\n\n");
  printMaze(maze);
  findRoute(maze, 1, 1);

  return 0;
}

void createMaze(char maze[][COL]) {
  int i, j;

  for(i = 0; i < ROW; i++) {
    for(j = 0; j < COL; j++) {
      if(i == 0 || j == 0 || i == ROW-1 || j == COL-1 || rand()%100 < 30) {
        maze[i][j] = 'X'; // Add walls (30% chance)
      } else {
        maze[i][j] = 'O'; // Add open spaces
      }
    }
  }

  maze[1][1] = 'R'; // Add Romeo's starting position
  maze[ROW-2][COL-2] = 'J'; // Add Juliet's position
}

void printMaze(char maze[][COL]) {
  int i, j;

  for(i = 0; i < ROW; i++) {
    for(j = 0; j < COL; j++) {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void findRoute(char maze[][COL], int i, int j) {
  if(maze[i][j] == 'J') { // Romeo has reached Juliet's position
    maze[i][j] = 'R'; // Replace Juliet's position with Romeo's position
    printMaze(maze);
    printf("Romeo has found his way to Juliet, and they lived happily ever after!\n");
    return;
  } else if(maze[i][j] == 'X' || maze[i][j] == '.') { // Romeo has hit a dead end
    return;
  } else { // Romeo is on the right path
    maze[i][j] = '.'; // Mark this path as already visited
    printMaze(maze); // Print the current state of the maze
    printf("Romeo is at position (%d,%d)\n", i, j);
    findRoute(maze, i+1, j); // Check the cell north of Romeo
    findRoute(maze, i-1, j); // Check the cell south of Romeo
    findRoute(maze, i, j+1); // Check the cell east of Romeo
    findRoute(maze, i, j-1); // Check the cell west of Romeo
    maze[i][j] = 'O'; // Mark this path as unvisited
    return;
  }
}