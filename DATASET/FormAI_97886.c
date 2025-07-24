//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main()
{
  int bingo[ROWS][COLS] = { 0 };
  int numbers[76] = { 0 };
  int row, col, num, count, result;
  srand(time(NULL));
  
  // Generate numbers from 1 to 75
  for(int i=1; i<76; i++)
  {
    numbers[i] = i;
  }

  // Shuffle the numbers
  for(int i=1; i<76; i++)
  {
    int j = rand() % 75 + 1;
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
  }
  
  printf("*** Welcome to Bingo Simulator ***\n\n");

  // Game Loop
  do
  {
    printf("Press Enter to draw a number...\n");
    getchar();
    
    // Check if there are numbers left to draw
    count = 0;
    for(int i=1; i<76; i++)
    {
      if(numbers[i] != 0)
      {
        count++;
      }
    }
    
    // Draw a number randomly
    if(count > 0)
    {
      int index = rand() % count + 1;
      num = numbers[index];
      numbers[index] = 0;
      printf("The number is %d.\n", num);
      
      // Check if the number is in the bingo grid
      result = 0;
      for(int i=0; i<ROWS; i++)
      {
        for(int j=0; j<COLS; j++)
        {
          if(bingo[i][j] == num)
          {
            bingo[i][j] = 0;
            result = 1;
          }
        }
      }
      
      if(result == 1)
      {
        printf("Bingo!\n");
      }
      else
      {
        printf("No match.\n");
      }
    }
    else
    {
      printf("The game is over.\n");
    }
    
    // Print the bingo grid
    printf("\n");
    for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
      {
        printf("%3d ", bingo[i][j]);
      }
      printf("\n");
    }
    
    // Check the rows
    for(int i=0; i<ROWS; i++)
    {
      result = 1;
      for(int j=0; j<COLS; j++)
      {
        if(bingo[i][j] != 0)
        {
          result = 0;
        }
      }
      if(result == 1)
      {
        printf("Row %d is complete!\n", i+1);
      }
    }
    
    // Check the columns
    for(int j=0; j<COLS; j++)
    {
      result = 1;
      for(int i=0; i<ROWS; i++)
      {
        if(bingo[i][j] != 0)
        {
          result = 0;
        }
      }
      if(result == 1)
      {
        printf("Column %d is complete!\n", j+1);
      }
    }
    
    // Check the diagonals
    result = 1;
    for(int i=0; i<ROWS; i++)
    {
      if(bingo[i][i] != 0)
      {
        result = 0;
      }
    }
    if(result == 1)
    {
      printf("Diagonal is complete!\n");
    }
    
    result = 1;
    for(int i=0; i<ROWS; i++)
    {
      if(bingo[i][COLS-i-1] != 0)
      {
        result = 0;
      }
    }
    if(result == 1)
    {
      printf("Diagonal is complete!\n");
    }
    
  } while(count > 0);
  
  return 0;
}