//FormAI DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i, j, n = 10, generation = 20;

  srand(time(NULL));

  int board[n][n], newBoard[n][n];

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      board[i][j] = rand() % 2;
      newBoard[i][j] = 0;
    }
  }

  printf("Initial Configuration:\n\n");

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (board[i][j] == 1)
        printf("* ");
      else
        printf(". ");
    }
    printf("\n");
  }

  for (int gen = 1; gen <= generation; gen++)
  {
    printf("\nGeneration %d:\n\n", gen);

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        int neighbors = 0;
        if (i > 0 && board[i - 1][j] == 1)
          neighbors++;
        if (i < n - 1 && board[i + 1][j] == 1)
          neighbors++;
        if (j > 0 && board[i][j - 1] == 1)
          neighbors++;
        if (j < n - 1 && board[i][j + 1] == 1)
          neighbors++;
        if (i > 0 && j > 0 && board[i - 1][j - 1] == 1)
          neighbors++;
        if (i < n - 1 && j > 0 && board[i + 1][j - 1] == 1)
          neighbors++;
        if (i > 0 && j < n - 1 && board[i - 1][j + 1] == 1)
          neighbors++;
        if (i < n - 1 && j < n - 1 && board[i + 1][j + 1] == 1)
          neighbors++;

        if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3))
          newBoard[i][j] = 1;
        else if (board[i][j] == 0 && neighbors == 3)
          newBoard[i][j] = 1;
        else
          newBoard[i][j] = 0;

        if (newBoard[i][j] == 1)
          printf("* ");
        else
          printf(". ");
      }
      printf("\n");
    }

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        board[i][j] = newBoard[i][j];
      }
    }
  }

  return 0;
}