//FormAI DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printBoard(int board[][COLS], int rows);
void createRandomBoard(int board[][COLS], int rows);
void updateBoard(int board[][COLS], int rows, int cols);
int countNeighbors(int board[][COLS], int row, int col);

int main(void)
{
  // initializing the board
  int board[ROWS][COLS];
  createRandomBoard(board, ROWS);

  // printing the starting board
  printf("Starting Board:\n");
  printBoard(board, ROWS);

  // updating the board for multiple generations
  int generation = 1;
  while (generation <= 10)
  {
    // updating the board
    updateBoard(board, ROWS, COLS);

    // printing the updated board
    printf("Generation %d:\n", generation);
    printBoard(board, ROWS);

    generation++;
  }

  return 0;
}

// function to print the board
void printBoard(int board[][COLS], int rows)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      printf("%c", board[i][j] ? '*' : '.');
    }
    printf("\n");
  }
}

// function to create a random board
void createRandomBoard(int board[][COLS], int rows)
{
  srand(time(NULL));
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      board[i][j] = rand() % 2;
    }
  }
}

// function to update the board
void updateBoard(int board[][COLS], int rows, int cols)
{
  int newBoard[ROWS][COLS] = {0};

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      int numberOfNeighbors = countNeighbors(board, i, j);
      if (board[i][j])
      {
        if (numberOfNeighbors < 2 || numberOfNeighbors > 3)
        {
          newBoard[i][j] = 0;
        }
        else
        {
          newBoard[i][j] = 1;
        }
      }
      else
      {
        if (numberOfNeighbors == 3)
        {
          newBoard[i][j] = 1;
        }
      }
    }
  }

  // copying the new values to the original board
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      board[i][j] = newBoard[i][j];
    }
  }
}

// function to count the number of neighbors of a cell
int countNeighbors(int board[][COLS], int row, int col)
{
  int count = 0;

  for (int i = row - 1; i <= row + 1; i++)
  {
    for (int j = col - 1; j <= col + 1; j++)
    {
      if (i == row && j == col)
      {
        continue;
      }

      if (i < 0 || i >= ROWS || j < 0 || j >= COLS)
      {
        continue;
      }

      if (board[i][j])
      {
        count++;
      }
    }
  }

  return count;
}