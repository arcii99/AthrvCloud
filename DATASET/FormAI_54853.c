//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLUMNS 10
#define OBSTACLES 10

int maze[ROWS][COLUMNS];
int visited[ROWS][COLUMNS];
int startX, startY, endX, endY, currentX, currentY, foundEnd;
int possibleNextMoves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void printMaze(){
  int i, j;
  printf("Maze:\n");
  for(i=0; i<ROWS; i++){
    for(j=0; j<COLUMNS; j++){
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

void initializeMaze(){
  int i, j, k;
  srand(time(0));
  //set all cells to 1 (open)
  for(i=0; i<ROWS; i++){
    for(j=0; j<COLUMNS; j++){
      maze[i][j]=1;
    }
  }
  //set obstacle cells to 0 (closed)
  for(i=0; i<OBSTACLES; i++){
    do{
      k = rand()%100;
    }while(maze[k/10-1][k%10-1] == 0);
    maze[k/10-1][k%10-1] = 0;
  }
  //set start and end cells
  do{
    startX = rand()%10;
    startY = rand()%10;
    endX = rand()%10;
    endY = rand()%10;
  }while(maze[startX][startY] == 0 || maze[endX][endY] == 0);
  maze[startX][startY] = 2;
  maze[endX][endY] = 3;
}

void printVisited(){
  int i, j;
  printf("Visited:\n");
  for(i=0; i<ROWS; i++){
    for(j=0; j<COLUMNS; j++){
      printf("%d ", visited[i][j]);
    }
    printf("\n");
  }
}

void findRoute(int x, int y){
  visited[x][y] = 1;
  int i;
  for(i=0; i<4; i++){
    int nextX = x + possibleNextMoves[i][0];
    int nextY = y + possibleNextMoves[i][1];
    if(nextX >= 0 && nextX < ROWS && nextY >= 0 && nextY < COLUMNS && maze[nextX][nextY] != 0){
      if(visited[nextX][nextY] == 0){
        findRoute(nextX, nextY);
        if(foundEnd == 1){
          return;
        }
      }
    }
  }
  if(maze[x][y] == 3){
    foundEnd = 1;
  }
}

int main(){
  initializeMaze();
  printMaze();
  findRoute(startX, startY);
  if(foundEnd == 1){
    printf("\nPath found!\n");
    visited[startX][startY] = 5; //change start and end cells to special values
    visited[endX][endY] = 6;
    printVisited();
  }
  else{
    printf("\nNo path found.\n");
  }
  return 0;
}