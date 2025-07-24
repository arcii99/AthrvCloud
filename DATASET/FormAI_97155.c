//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int size;
  printf("Enter the size of your game board:");
  scanf("%d", &size);

  int game_board[size][size], i, j;
  srand(time(NULL));
  int rand_num;

  // Initializing game board with random numbers
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      rand_num = rand() % 10;
      game_board[i][j] = rand_num;
    }
  }

  // Printing the game board
  printf("\nHere is your game board:\n");
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      printf("%d ", game_board[i][j]);
    }
    printf("\n");
  }

  // Game logic
  int row, col, sum, count = 0;
  printf("\nFind the sum of each row and column.\n");
  while (count < (2 * size))
  {
    printf("Enter the row and column numbers (separated by a space):");
    scanf("%d %d", &row, &col);
    if (row >= size || col >= size)
    {
      printf("Invalid row or column number. Try again.\n");
    }
    else
    {
      sum = 0;
      for (i = 0; i < size; i++)
      {
        sum += game_board[row][i];
      }
      printf("The sum of row %d is: %d\n", row, sum);

      sum = 0;
      for (i = 0; i < size; i++)
      {
        sum += game_board[i][col];
      }
      printf("The sum of column %d is: %d\n", col, sum);

      count++;
    }
  }

  printf("\nCongratulations, you won the game!\n");
  return 0;
}