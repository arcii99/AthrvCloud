//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 10

// This function initializes the grid with the numbers 1 to GRID_SIZE
void initializeGrid(int grid[GRID_SIZE][GRID_SIZE])
{
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = (i * GRID_SIZE) + j + 1;
        }
    }
}

// This function displays the grid
void displayGrid(int grid[GRID_SIZE][GRID_SIZE], bool hideNumbers)
{
    printf("\n");
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            if(hideNumbers) 
            {
                printf(" * ");
            } 
            else 
            {
                printf("%2d ", grid[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// This function returns true if the game is won (i.e., all numbers are hidden)
bool isGameWon(int grid[GRID_SIZE][GRID_SIZE])
{
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            if(grid[i][j] != 0) return false;
        }
    }
    return true;
}

// This function takes input from the player and hides the corresponding number in the grid
bool hideNumber(int grid[GRID_SIZE][GRID_SIZE])
{
    int input;
    printf("Enter a number to hide: ");
    scanf("%d", &input);

    if(input < 1 || input > GRID_SIZE * GRID_SIZE) 
    {
        printf("Invalid input. Please enter a number between 1 and %d.\n", GRID_SIZE * GRID_SIZE);
        return false;
    }

    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            if(grid[i][j] == input) 
            {
                grid[i][j] = 0;
                return true;
            }
        }
    }

    printf("Number not found. Please try again.\n");
    return false;
}

int main()
{
    int grid[GRID_SIZE][GRID_SIZE];
    bool hideNumbers = true;
    srand(time(NULL));

    initializeGrid(grid);
    displayGrid(grid, hideNumbers);

    // Game loop
    while(!isGameWon(grid))
    {
        hideNumbers = !hideNumbers;
        displayGrid(grid, hideNumbers);

        if(hideNumbers)
        {
            if(!hideNumber(grid))
            {
                hideNumbers = !hideNumbers;
            }
        }
        else
        {
            printf("Press any key to reveal the numbers.\n");
            getchar();
            displayGrid(grid, hideNumbers);
            printf("\n");
        }
    }

    printf("Congratulations! You have won the game.\n");

    return 0;
}