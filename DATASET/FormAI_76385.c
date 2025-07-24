//FormAI DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

bool find_unassigned(int grid[N][N], int *r, int *c);
bool used_in_row(int grid[N][N], int row, int num);
bool used_in_col(int grid[N][N], int col, int num);
bool used_in_box(int grid[N][N], int box_start_row, int box_start_col, int num);
bool is_safe(int grid[N][N], int row, int col, int num);
bool solve_sudoku(int grid[N][N]);
void print_board(int grid[N][N]);

int main(void)
{
  int grid[N][N] = 
  {
    {2, 0, 0, 0, 0, 0, 8, 4, 0},
    {0, 0, 4, 2, 0, 8, 0, 7, 0},
    {0, 0, 0, 0, 0, 5, 0, 0, 0},
    {0, 0, 0, 4, 5, 0, 3, 0, 0},
    {0, 6, 0, 0, 0, 0, 0, 2, 0},
    {0, 0, 0, 0, 7, 3, 0, 1, 9},
    {0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 7, 0, 1, 5, 0, 0},
    {0, 7, 5, 0, 0, 0, 0, 0, 6}
  };

  printf("\nSudoku Puzzle:\n");
  print_board(grid);

  if(solve_sudoku(grid))
  {
    printf("\nSolution:\n");
    print_board(grid);
  }
  else
  {
    printf("\nUnable to solve puzzle.\n");
  }

  return 0;
}

// Function to find an unassigned location in the grid
bool find_unassigned(int grid[N][N], int *r, int *c)
{
  for(*r = 0; *r < N; (*r)++)
  {
    for(*c = 0; *c < N; (*c)++)
    {
      if(grid[*r][*c] == 0)
      {
        return true;
      }
    }
  }
  return false;
}

// Function to check if the provided number is used in the row
bool used_in_row(int grid[N][N], int row, int num)
{
  for(int col = 0; col < N; col++)
  {
    if(grid[row][col] == num)
    {
      return true;
    }
  }
  return false;
}

// Function to check if the provided number is used in the column
bool used_in_col(int grid[N][N], int col, int num)
{
  for(int row = 0; row < N; row++)
  {
    if(grid[row][col] == num)
    {
      return true;
    }
  }
  return false;
}

// Function to check if the provided number is used in the corresponding 3x3 box
bool used_in_box(int grid[N][N], int box_start_row, int box_start_col, int num)
{
  for(int row = 0; row < 3; row++)
  {
    for(int col = 0; col < 3; col++)
    {
      if(grid[row + box_start_row][col + box_start_col] == num)
      {
        return true;
      }
    }
  }
  return false;
}

// Function to check if it is safe to place a number at a specific location
bool is_safe(int grid[N][N], int row, int col, int num)
{
  return !used_in_row(grid, row, num) &&
         !used_in_col(grid, col, num) &&
         !used_in_box(grid, row - row % 3 , col - col % 3, num);
}

// Recursive function to solve the sudoku puzzle
bool solve_sudoku(int grid[N][N])
{
  int row, col;

  if(!find_unassigned(grid, &row, &col))
  {
    return true;
  }

  for(int num = 1; num <= 9; num++)
  {
    if(is_safe(grid, row, col, num))
    {
      grid[row][col] = num;

      if(solve_sudoku(grid))
      {
        return true;
      }

      grid[row][col] = 0;
    }
  }
  return false;
}

// Function to display the solved sudoku puzzle
void print_board(int grid[N][N])
{
  printf("-----------------\n");
  for(int row = 0; row < N; row++)
  {
    printf("| ");
    for(int col = 0; col < N; col++)
    {
      printf("%d ", grid[row][col]);
      if((col + 1) % 3 == 0)
      {
        printf("| ");
      }
    }
    printf("\n");
    if((row + 1) % 3 == 0)
    {
      printf("-----------------\n");
    }
  }
}