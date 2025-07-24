//FormAI DATASET v1.0 Category: Game of Life ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 15
#define GENERATIONS 10

int grid[GRID_SIZE][GRID_SIZE];
int tempGrid[GRID_SIZE][GRID_SIZE];

void printGrid(){
  for(int i=0;i<GRID_SIZE;i++){
    for(int j=0;j<GRID_SIZE;j++){
      if(grid[i][j]) printf("* ");
      else printf(". ");
    }
    printf("\n");
  }
}

int checkNeighbours(int row, int col){
  int count = 0;
  int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
  for(int i=0;i<8;i++){
    int r = row + directions[i][0];
    int c = col + directions[i][1];
    if(r>=0 && r<GRID_SIZE && c>=0 && c<GRID_SIZE && grid[r][c]){
      count++;
    }
  }
  return count;
}

void generateNextGen(){
  for(int i=0;i<GRID_SIZE;i++){
    for(int j=0;j<GRID_SIZE;j++){
      int count = checkNeighbours(i, j);
      if(grid[i][j]){ // cell is alive
        if(count < 2 || count > 3) tempGrid[i][j] = 0; // death
        else tempGrid[i][j] = 1; // survived
      }
      else{ // cell is dead
        if(count == 3) tempGrid[i][j] = 1; // birth
        else tempGrid[i][j] = 0; // still dead
      }
    }
  }
  for(int i=0;i<GRID_SIZE;i++){
    for(int j=0;j<GRID_SIZE;j++){
      grid[i][j] = tempGrid[i][j];
    }
  }
}

int main(){
  srand(time(0));
  for(int i=0;i<GRID_SIZE;i++){
    for(int j=0;j<GRID_SIZE;j++){
      grid[i][j] = rand() % 2;
    }
  }
  printf("Starting state:\n");
  printGrid();
  printf("\n");

  for(int i=0;i<GENERATIONS;i++){
    generateNextGen();
    printf("Generation %d:\n", i+1);
    printGrid();
    printf("\n");
  }
  return 0;
}