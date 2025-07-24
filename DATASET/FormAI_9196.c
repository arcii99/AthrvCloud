//FormAI DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // size of the game board

// function to print the game board
void print_board(int board[][GRID_SIZE]) {
  printf("\n");
  int i,j;
  for(i=0;i<GRID_SIZE;i++) {
    for(j=0;j<GRID_SIZE;j++) {
      if(board[i][j]==1) printf("*");
      else printf(".");
    }
    printf("\n");
  }
}

// function to generate the initial board with random alive cells
void generate_initial_board(int board[][GRID_SIZE]) {
  int i,j;
  srand(time(NULL));
  for(i=0;i<GRID_SIZE;i++) {
    for(j=0;j<GRID_SIZE;j++) {
      board[i][j] = rand() % 2;
    }
  }
}

// function to calculate the next state of the game board
void next_state(int board[][GRID_SIZE], int new_board[][GRID_SIZE]) {
  int i,j;
  for(i=0;i<GRID_SIZE;i++) {
    for(j=0;j<GRID_SIZE;j++) {
      int neighbors = 0;
      if(i>0 && board[i-1][j]==1) neighbors++; // check top neighbor
      if(i<GRID_SIZE-1 && board[i+1][j]==1) neighbors++; // check bottom neighbor
      if(j>0 && board[i][j-1]==1) neighbors++; // check left neighbor
      if(j<GRID_SIZE-1 && board[i][j+1]==1) neighbors++; // check right neighbor
      if(i>0 && j>0 && board[i-1][j-1]==1) neighbors++; // check top left neighbor
      if(i>0 && j<GRID_SIZE-1 && board[i-1][j+1]==1) neighbors++; // check top right neighbor
      if(i<GRID_SIZE-1 && j>0 && board[i+1][j-1]==1) neighbors++; // check bottom left neighbor
      if(i<GRID_SIZE-1 && j<GRID_SIZE-1 && board[i+1][j+1]==1) neighbors++; // check bottom right neighbor
      if(board[i][j]==0 && neighbors==3) new_board[i][j] = 1; // cell becomes alive
      else if(board[i][j]==1 && (neighbors==2 || neighbors==3)) new_board[i][j] = 1; // cell stays alive
      else new_board[i][j] = 0; // cell dies
    }
  }
}

int main() {
  int board[GRID_SIZE][GRID_SIZE], new_board[GRID_SIZE][GRID_SIZE], i, j;
  
  generate_initial_board(board);
  print_board(board);

  for(i=0;i<100;i++) {
    next_state(board, new_board);
    print_board(new_board);
    for(j=0;j<GRID_SIZE;j++) {
      for(int k=0;k<GRID_SIZE;k++) {
        board[j][k] = new_board[j][k];
      }
    }
  }

  return 0;
}