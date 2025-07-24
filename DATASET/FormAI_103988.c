//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function to print the grid
void printGrid(int grid[][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (grid[i][j] == 0)
				printf(". ");
			else
				printf("O ");
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int grid[ROWS][COLS] = {0};
	int percolated = 0;

	// seeding the random number generator
	srand(time(NULL));

	// randomly filling the top row of the grid
	for (int i = 0; i < COLS; i++)
	{
		if (rand() % 2 == 1)
			grid[0][i] = 1;
	}

	// looping through the grid and propagating the water downwards
	for (int i = 1; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (grid[i-1][j] == 1)
			{
				if (j > 0 && grid[i][j-1] == 1)
					grid[i][j] = 1;
				if (j < COLS-1 && grid[i][j+1] == 1)
					grid[i][j] = 1;
			}
		}
	}

	// checking if the bottom row is percolated
	for (int i = 0; i < COLS; i++)
	{
		if (grid[ROWS-1][i] == 1)
			percolated = 1;
	}

	// printing the grid and percolation status
	printGrid(grid);
	if (percolated)
		printf("The system percolates!\n");
	else
		printf("The system does not percolate.\n");

	return 0;
}