//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main()
{
  // Set up the bingo grid
  int grid[ROWS][COLS];
  int numbers[75];

  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the bingo grid
  for(int i = 0; i < ROWS; i++)
  {
    for(int j = 0; j < COLS; j++)
    {
      // Add a random number between 1 and 75 to the grid
      grid[i][j] = rand() % 75 + 1;
      // Check the previous numbers
      for (int k = 0; k < j; k++)
      {
        if (grid[i][j] == grid[i][k])
        {
          j--;
          break;
        }
      }
    }
  }

  // Print out the grid
  printf("B   I   N   G   O\n");
  for(int i = 0; i < ROWS; i++)
  {
    for(int j = 0; j < COLS; j++)
    {
      if (grid[i][j] < 10)
      {
        printf("%d   ", grid[i][j]);
      }
      else
      {
        printf("%d  ", grid[i][j]);
      }
    }
    printf("\n");
  }

  // Generate the bingo numbers
  for(int i = 0; i < 75; i++)
  {
    numbers[i] = i + 1;
  }

  // Shuffle the numbers
  for(int i = 0; i < 75 - 1; i++)
  {
    int j = rand() % (75 - i) + i;
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
  }

  // Print out the numbers as they are called
  printf("\n");
  printf("Press enter to call a number\n");
  for(int i = 0; i < 75; i++)
  {
    getchar();
    printf("%d\n", numbers[i]);
  }

  return 0;
}