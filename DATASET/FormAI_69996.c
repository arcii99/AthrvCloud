//FormAI DATASET v1.0 Category: Chess AI ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

// board declaration
char board[8][8];

// function to print the board
void print_board()
{
  printf("\n\n\t  0  1  2  3  4  5  6  7 \n\n");
  for (int i = 0; i < 8; i++)
  {
    printf("\t%d ", i);
    for (int j = 0; j < 8; j++)
    {
      printf("|%c", board[i][j]);
    }
    printf("|\n");
  }
}

// function to initialize the board
void init_board()
{
  // white pieces
  board[0][0] = 'R'; board[0][1] = 'N'; board[0][2] = 'B'; board[0][3] = 'Q';
  board[0][4] = 'K'; board[0][5] = 'B'; board[0][6] = 'N'; board[0][7] = 'R';
  for (int i = 0; i < 8; i++)
  {
    board[1][i] = 'P';
  }

  // black pieces
  board[7][0] = 'r'; board[7][1] = 'n'; board[7][2] = 'b'; board[7][3] = 'q';
  board[7][4] = 'k'; board[7][5] = 'b'; board[7][6] = 'n'; board[7][7] = 'r';
  for (int i = 0; i < 8; i++)
  {
    board[6][i] = 'p';
  }

  // empty spaces
  for (int i = 2; i <= 5; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      board[i][j] = ' ';
    }
  }
}

// main function
int main()
{
  init_board();
  print_board();
  return 0;
}