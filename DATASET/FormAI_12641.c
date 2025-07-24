//FormAI DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

void printBoard(int board[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j])
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int board[][COLS], int row, int col)
{
    int count = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }
            int r = row + i;
            int c = col + j;
            if(r < 0 || r >= ROWS || c < 0 || c >= COLS)
            {
                continue;
            }
            if(board[r][c])
            {
                count++;
            }
        }
    }
    return count;
}

void simulate(int board[][COLS])
{
    int newBoard[ROWS][COLS];
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            int neighbors = countNeighbors(board, i, j);
            if(board[i][j])
            {
                if(neighbors < 2 || neighbors > 3)
                {
                    newBoard[i][j] = 0;
                }
                else
                {
                    newBoard[i][j] = 1;
                }
            }
            else
            {
                if(neighbors == 3)
                {
                    newBoard[i][j] = 1;
                }
                else
                {
                    newBoard[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main()
{
    int board[ROWS][COLS];
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            board[i][j] = rand() % 2;
        }
    }
    while(1)
    {
        printBoard(board);
        simulate(board);
        printf("\033[2J"); 
        printf("\033[%d;%dH", 0, 0); 
    }
    return 0;
}