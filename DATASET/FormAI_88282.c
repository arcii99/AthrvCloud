//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void initializeGrid(int grid[ROWS][COLS]);
void callNumber(int *calledNumbers, int *numCalled);
void markCard(int grid[ROWS][COLS], int num);
int checkBingo(int grid[ROWS][COLS]);

int main()
{
    int grid[ROWS][COLS];
    int calledNumbers[75] = {0};
    int numCalled = 0;

    initializeGrid(grid);

    while (1)
    {
        callNumber(calledNumbers, &numCalled);
        markCard(grid, calledNumbers[numCalled-1]);

        if (checkBingo(grid))
        {
            printf("\nBingo!");
            break;
        }
    }

    return 0;
}

//Initializes the bingo grid 
void initializeGrid(int grid[ROWS][COLS])
{
    int num = 1;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = num++;
        }
    }
}

//Calls a random number and keeps track of numbers that have been called 
void callNumber(int *calledNumbers, int *numCalled)
{
    int num;

    do
    {
        num = rand() % 75 + 1;
    } while (calledNumbers[num-1]);

    calledNumbers[num-1] = 1;
    (*numCalled)++;
}

//Marks the bingo grid if the number was called 
void markCard(int grid[ROWS][COLS], int num)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == num)
            {
                grid[i][j] = -1;
            }
        }
    }
}

//Checks the bingo grid for a bingo 
int checkBingo(int grid[ROWS][COLS])
{
    int bingoCounter = 0;

    //Rows
    for (int i = 0; i < ROWS; i++)
    {
        int rowCounter = 0;

        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == -1)
            {
                rowCounter++;
            }
        }

        if (rowCounter == 5)
        {
            bingoCounter++;
        }
    }

    //Columns
    for (int i = 0; i < COLS; i++)
    {
        int colCounter = 0;

        for (int j = 0; j < ROWS; j++)
        {
            if (grid[j][i] == -1)
            {
                colCounter++;
            }
        }

        if (colCounter == 5)
        {
            bingoCounter++;
        }
    }

    //Diagonal 1 (top-left to bottom-right)
    int dia1Counter = 0;

    for (int i = 0; i < ROWS; i++)
    {
        if (grid[i][i] == -1)
        {
            dia1Counter++;
        }
    }

    if (dia1Counter == 5)
    {
        bingoCounter++;
    }

    //Diagonal 2 (bottom-left to top-right)
    int dia2Counter = 0;

    for (int i = 0, j = COLS-1; i < ROWS && j >= 0; i++, j--)
    {
        if (grid[i][j] == -1)
        {
            dia2Counter++;
        }
    }

    if (dia2Counter == 5)
    {
        bingoCounter++;
    }

    return bingoCounter;
}