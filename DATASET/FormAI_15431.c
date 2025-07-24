//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int score = 0;

void initializeGrid()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

void displayGrid()
{
    printf("Score: %d\n", score);
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            if(grid[i][j] == 1)
            {
                printf("# ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int calculateScore()
{
    int count = 0;
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            if(grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

void playGame()
{
    char choice;
    do
    {
        displayGrid();
        printf("Do you want to flip a tile? (y/n): ");
        scanf("%c", &choice);
        getchar();
        if(choice == 'y')
        {
            int row, col;
            printf("Enter row number (0 - 9): ");
            scanf("%d", &row);
            printf("Enter col number (0 - 9): ");
            scanf("%d", &col);
            getchar();
            if(row >= ROWS || col >= COLS)
            {
                printf("Invalid Input!\n");
            }
            else
            {
                grid[row][col] = !grid[row][col];
                score = calculateScore();
            }
        }
    }while(choice != 'n');
}

int main()
{
    srand(time(NULL));
    initializeGrid();
    playGame();
    return 0;
}