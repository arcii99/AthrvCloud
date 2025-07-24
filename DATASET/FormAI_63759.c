//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUMBER 75

// Function prototypes
bool isUnique(int n, int arr[]);
void generateRandomNumbers(int arr[]);
void printGrid(int grid[][COLS]);
bool isBingo(int grid[][COLS]);

int main()
{
  // Seed random number generator
  srand(time(NULL));

  // Initialize grid
  int grid[ROWS][COLS];

  // Generate random numbers for grid
  int randomNumbers[MAX_NUMBER];
  generateRandomNumbers(randomNumbers);

  // Initialize grid with random numbers
  int i, j;
  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      // Pick a unique random number and add it to the grid
      int number;
      do
      {
        number = randomNumbers[rand() % MAX_NUMBER];
      } while (!isUnique(number, randomNumbers));

      grid[i][j] = number;
    }
  }

  printf("*** BINGO SIMULATOR ***\n\n");

  // Print empty grid
  printGrid(grid);

  // Play game until there's a bingo
  bool bingo = false;
  while (!bingo)
  {
    // Ask user to input number
    printf("Enter a number (1 to 75): ");
    int number;
    scanf("%d", &number);

    // Check if number exists in grid
    bool found = false;
    for (i = 0; i < ROWS; i++)
    {
      for (j = 0; j < COLS; j++)
      {
        if (grid[i][j] == number)
        {
          grid[i][j] = -1;
          found = true;
          break;
        }
      }
      if (found)
      {
        break;
      }
    }

    // Print updated grid
    printGrid(grid);

    // Check for bingo
    bingo = isBingo(grid);
    if (bingo)
    {
      printf("*** BINGO! ***\n");
    }
  }

  return 0;
}

// Check if a number is unique in an array
bool isUnique(int n, int arr[])
{
  int i;
  for (i = 0; i < MAX_NUMBER; i++)
  {
    if (arr[i] == n)
    {
      return false;
    }
  }
  return true;
}

// Generate an array of random numbers
void generateRandomNumbers(int arr[])
{
  int i;
  for (i = 0; i < MAX_NUMBER; i++)
  {
    arr[i] = i + 1;
  }

  // Shuffle array
  for (i = MAX_NUMBER - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

// Print the grid
void printGrid(int grid[][COLS])
{
  printf("\n");
  printf("B   I   N   G   O\n");

  int i, j;
  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      if (grid[i][j] == -1)
      {
        printf("X   ");
      }
      else
      {
        printf("%-3d ", grid[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

// Check if there's a bingo
bool isBingo(int grid[][COLS])
{
  int i, j, count;

  // Check rows
  for (i = 0; i < ROWS; i++)
  {
    count = 0;
    for (j = 0; j < COLS; j++)
    {
      if (grid[i][j] == -1)
      {
        count++;
      }
    }
    if (count == COLS)
    {
      return true;
    }
  }

  // Check columns
  for (i = 0; i < COLS; i++)
  {
    count = 0;
    for (j = 0; j < ROWS; j++)
    {
      if (grid[j][i] == -1)
      {
        count++;
      }
    }
    if (count == ROWS)
    {
      return true;
    }
  }

  // Check diagonals
  count = 0;
  for (i = 0, j = 0; i < ROWS && j < COLS; i++, j++)
  {
    if (grid[i][j] == -1)
    {
      count++;
    }
  }
  if (count == ROWS)
  {
    return true;
  }

  count = 0;
  for (i = 0, j = COLS - 1; i < ROWS && j >= 0; i++, j--)
  {
    if (grid[i][j] == -1)
    {
      count++;
    }
  }
  if (count == ROWS)
  {
    return true;
  }

  return false;
}