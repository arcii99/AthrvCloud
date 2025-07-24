//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

char maze[WIDTH][HEIGHT];

void printMaze() {
  for(int i=0; i<HEIGHT; i++) {
    for(int j=0; j<WIDTH; j++) {
      printf("%c ", maze[j][i]);
    }
    printf("\n");
  }
}

void generateMaze(int x, int y) {
  int i, j;
  int nextX, nextY;
  int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
  int order[4] = {0,1,2,3};
  int temp, move;

  maze[x][y] = ' ';

  for(i=0; i<4; i++) {
    j = rand() % 4;
    temp = order[i];
    order[i] = order[j];
    order[j] = temp;
  }

  for(i=0; i<4; i++) {
    move = order[i];
    nextX = x + directions[move][0]*2;
    nextY = y + directions[move][1]*2;

    if(nextX > 0 && nextX < WIDTH && nextY > 0 && nextY < HEIGHT) {
      if(maze[nextX][nextY] == '#') {
        maze[x + directions[move][0]][y + directions[move][1]] = ' ';
        generateMaze(nextX, nextY);
      }
    }
  }
}

int main() {
  int i, j;

  srand(time(NULL));

  for(i=0; i<WIDTH; i++) {
    for(j=0; j<HEIGHT; j++) {
      maze[i][j] = '#';
    }
  }

  generateMaze(1,1);
  printMaze();

  return 0;
}