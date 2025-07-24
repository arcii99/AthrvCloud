//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 31
#define COLS 61

int maze[ROWS][COLS];

void initMaze();
void printMaze();
void generateMaze(int row, int col);

int main(){
  initMaze();
  generateMaze(1,1);
  printMaze();
  return 0;
}

void initMaze(){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      maze[i][j] = 1;
    }
  }
  srand(time(NULL));
}

void printMaze(){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      printf("%c", maze[i][j] == 1 ? '#' : ' ');
    }
    printf("\n");
  }
}

void generateMaze(int row, int col){
  int dirs[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
  int r, c, count, tmp;

  for(int i = 0; i < 4; i++){
    r = row + dirs[i][0];
    c = col + dirs[i][1];

    if(r > 0 && r < ROWS && c > 0 && c < COLS && maze[r][c] == 1){
      count++;
      if(rand() % count == 0){
        tmp = i;
      }
    }
  }

  maze[row][col] = 0;

  if(count == 0){
    return;
  }

  generateMaze(row + dirs[tmp][0], col + dirs[tmp][1]);

  for(int i = 0; i < 4; i++){
    r = row + dirs[i][0];
    c = col + dirs[i][1];

    if(r > 0 && r < ROWS && c > 0 && c < COLS && maze[r][c] == 1 && i != tmp){
      count++;
      if(rand() % count == 0){
        tmp = i;
      }
    }
  }

  generateMaze(row + dirs[tmp][0], col + dirs[tmp][1]);
}