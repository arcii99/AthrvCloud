//FormAI DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10 //Size of the maze. Increase this for larger mazes.
#define WALL 'X'
#define PATH ' '

char maze[MAZE_SIZE][MAZE_SIZE];

void printMaze() {
  int i, j;
  for (i = 0; i < MAZE_SIZE; i++) {
    for (j = 0; j < MAZE_SIZE; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int i, j;
  srand(time(NULL));

  //Initialize the maze to all walls
  for (i = 0; i < MAZE_SIZE; i++) {
    for (j = 0; j < MAZE_SIZE; j++) {
      maze[i][j] = WALL;
    }
  }

  //Generate a random starting point
  int startX = rand() % MAZE_SIZE;
  int startY = rand() % MAZE_SIZE;

  //Fill in a starting path
  maze[startX][startY] = PATH;

  //Make a path through the maze
  int curX = startX;
  int curY = startY;
  while (1) {
    //Stop the loop when we reach the edge of the maze
    if (curX == 0 || curX == MAZE_SIZE - 1 || curY == 0 || curY == MAZE_SIZE - 1)
      break;

    //Randomly choose a new direction
    int dir = rand() % 4;
    if (dir == 0 && maze[curX - 1][curY] == WALL) { //Left
      maze[curX - 1][curY] = PATH;
      curX--;
    } else if (dir == 1 && maze[curX + 1][curY] == WALL) { //Right
      maze[curX + 1][curY] = PATH;
      curX++;
    } else if (dir == 2 && maze[curX][curY - 1] == WALL) { //Up
      maze[curX][curY - 1] = PATH;
      curY--;
    } else if (dir == 3 && maze[curX][curY + 1] == WALL) { //Down
      maze[curX][curY + 1] = PATH;
      curY++;
    }
  }

  //Print the maze
  printMaze();

  return 0;
}