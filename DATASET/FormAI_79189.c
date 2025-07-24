//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(int maze[][COLS], int row, int col);

int main(){
    int maze[ROWS][COLS];
    int i, j;
    srand(time(NULL));
    
    //fill maze with walls
    for(i = 0; i < ROWS; i++) {
          for(j = 0; j < COLS; j++) {
              maze[i][j] = 1;
          }
    }

    generateMaze(maze, 0, 0); //generate maze starting from (0,0)

    //print maze
    for(i = 0; i < ROWS; i++) {
          for(j = 0; j < COLS; j++) {
              if(maze[i][j] == 1) {
                  printf("#");
              } else {
                  printf(" ");
              }
          }
          printf("\n");
    }

    return 0;
}

void generateMaze(int maze[][COLS], int row, int col) {
    //direction vectors: Movement on the grid
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int random, nextRow, nextCol, temp;

    //shuffle direction array
    for (int i = 0; i < 4; i++) {
        random = rand() % 4;
        temp = directions[random][0];
        directions[random][0] = directions[i][0];
        directions[i][0] = temp;
        temp = directions[random][1];
        directions[random][1] = directions[i][1];
        directions[i][1] = temp;
    }

    //for each direction, check if it leads to a valid cell
    for (int i = 0; i < 4; i++) {
        nextRow = row + directions[i][0] * 2;
        nextCol = col + directions[i][1] * 2;
        if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS) {
            if (maze[nextRow][nextCol] == 1) {
                maze[row + directions[i][0]][col + directions[i][1]] = 0;
                maze[nextRow][nextCol] = 0;
                generateMaze(maze, nextRow, nextCol);
            }
        }
    }
}