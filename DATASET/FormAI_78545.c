//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 35
#define COLS 60

char maze[ROWS][COLS];

void generateMaze() {
  int i, j;
  // initialize the maze with walls
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      if(i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
        maze[i][j] = '#';
      } else {
        maze[i][j] = ' ';
      }
    }
  }
  // randomly generate paths
  int x, y;
  srand(time(NULL));
  x = rand() % (COLS-2) + 1;
  y = rand() % (ROWS-2) + 1;
  maze[y][x] = ' ';
  while(1) {
    if(maze[y-1][x] == '#' && maze[y+1][x] == '#' && maze[y][x-1] == '#' && maze[y][x+1] == '#') {
      return;
    }
    int r = rand() % 4;
    switch(r) {
      case 0:
        if(maze[y-1][x] == '#') {
          maze[y-1][x] = ' ';
          y--;
        }
        break;
      case 1:
        if(maze[y+1][x] == '#') {
          maze[y+1][x] = ' ';
          y++;
        }
        break;
      case 2:
        if(maze[y][x-1] == '#') {
          maze[y][x-1] = ' ';
          x--;
        }
        break;
      case 3:
        if(maze[y][x+1] == '#') {
          maze[y][x+1] = ' ';
          x++;
        }
        break;
    }
  }
}

void displayMaze() {
  int i, j;
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  generateMaze();
  displayMaze();
  return 0;
}