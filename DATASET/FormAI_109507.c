//FormAI DATASET v1.0 Category: Game of Life ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLS 40

int grid1[ROWS][COLS], grid2[ROWS][COLS];
/* grid1 and grid2 are used to store the states of a cell */
/* grid1 holds the current state while grid2 holds the future state*/
int cell_count(){
  int count = 0, row, col;
  for(row = 0; row < ROWS; row++){
    for(col = 0; col < COLS; col++){
      if(grid1[row][col] == 1){
        count++;
      }
    }
  }
 return count;
}

void initialize_grid(){
  int row, col;
  srand(time(NULL));
  for(row = 0; row < ROWS; row++){
    for(col = 0; col < COLS; col++){
      grid1[row][col] = rand() % 2;
    }
 }
}

void print_grid(){
 int row, col;
 for(row = 0; row < ROWS; row++){
   for(col = 0; col < COLS; col++){
     if(grid1[row][col] == 1){
      printf("X");
     }
     else{
       printf(".");
     }
  }
  printf("\n");
 }
}

void update(){
  int row, col, n, m;
  for(row = 0; row < ROWS; row++){
    for(col = 0; col < COLS; col++){
      n = row == 0 ? ROWS - 1 : row - 1;
      m = col == 0 ? COLS - 1 : col - 1;
      int neighbors = grid1[n][m] + grid1[n][col] + grid1[n][(col + 1) % COLS] + grid1[row][m] + grid1[row][(col+1)%COLS]+ grid1[(row + 1) % ROWS][m] + grid1[(row + 1) % ROWS][col] + grid1[(row + 1) % ROWS][(col + 1) % COLS];
      if(grid1[row][col] == 1){
        if(neighbors < 2 || neighbors > 3){
          grid2[row][col] = 0;
        }
        else{
          grid2[row][col] = 1;
        }
      }
      else{ 
        if(neighbors == 3){  
          grid2[row][col] = 1;
        }
        else{
          grid2[row][col] = 0;
        }
      }
    }
  }
}

int main(){
  int iterations = 0, total_cells = 0;
  initialize_grid(); // initialize the grid with random values
  while(cell_count() != 0){ // repeat until all cells have died
    iterations++;
    printf("# Iteration %d:\n", iterations);
    print_grid();
    update();
    total_cells = cell_count();
    printf("Total number of cells: %d\n", total_cells);
    printf("\n");
    // update the current grid with the future grid
    int row, col;
    for(row = 0; row < ROWS; row++){
      for(col = 0; col < COLS; col++){
        grid1[row][col] = grid2[row][col];
      }
    }
  }
  printf("# Iteration %d:\n", iterations+1);
  print_grid(); // print the final state of the grid
  return 0;
}