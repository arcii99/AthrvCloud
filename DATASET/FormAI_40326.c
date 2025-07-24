//FormAI DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 40
#define COLS 80

int generation = 0;

void print_board(int board[][COLS])
{
     printf("Generation: %d\n", generation++);
     for(int i=0; i<ROWS; i++)
     {
          for(int j=0; j<COLS; j++)
          {
               printf("%c", board[i][j] ? '#' : '.');
          }
          printf("\n");
     }
}

int count_neighbors(int row, int col, int board[][COLS])
{
     int neighbors = 0;

     // Check North cell
     if((row-1)>=0 && board[row-1][col]) 
          neighbors++;

     // Check South cell
     if((row+1)<ROWS && board[row+1][col]) 
          neighbors++;

     // Check West cell
     if((col-1)>=0 && board[row][col-1]) 
          neighbors++;

     // Check East cell
     if((col+1)<COLS && board[row][col+1]) 
          neighbors++;

     // Check North West cell
     if((row-1)>=0 && (col-1)>=0 && board[row-1][col-1]) 
          neighbors++;

     // Check North East cell
     if((row-1)>=0 && (col+1)<COLS && board[row-1][col+1]) 
          neighbors++;

     // Check South West cell
     if((row+1)<ROWS && (col-1)>=0 && board[row+1][col-1]) 
          neighbors++;

     // Check South East cell
     if((row+1)<ROWS && (col+1)<COLS && board[row+1][col+1]) 
          neighbors++;

     return neighbors;
}

void generate_board(int board[][COLS])
{
     for(int i=0;i<ROWS;i++)
     {
          for(int j=0;j<COLS;j++)
          {
               board[i][j] = rand() % 2;
          }
     }
}

void copy_board(int src_board[][COLS], int dst_board[][COLS])
{
     for(int i=0;i<ROWS;i++)
     {
          for(int j=0;j<COLS;j++)
          {
               dst_board[i][j] = src_board[i][j];
          }
     }
}

void simulate(int board[][COLS], int generation_limit)
{
     int current_board[ROWS][COLS];
     copy_board(board, current_board);
     print_board(current_board);

     if(generation<generation_limit)
     {
          for(int i=0;i<ROWS;i++)
          {
               for(int j=0;j<COLS;j++)
               {
                    // For each cell, count its neighbors
                    int neighbors = count_neighbors(i, j, current_board);
                    int state = current_board[i][j];

                    // If cell is dead and has exactly 3 neighbors, it comes alive
                    // Else if cell is alive and has less than 2 or more than 3 neighbors, it dies
                    board[i][j] = (state && (neighbors==2 || neighbors==3)) || (!state && neighbors==3);
               }
          }
          simulate(board, generation_limit);
     }
}

int main()
{
     int board[ROWS][COLS];
     
     srand(time(0));
     generate_board(board);
     simulate(board, 50);
     
     return 0;
}