//FormAI DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 30
#define COLS 60

void printBoard(char board[][COLS])
{
    system("clear");
    printf("\n");
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void updateBoard(char board[][COLS])
{
    char newBoard[ROWS][COLS];

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            int neighbors = 0;

            if(i > 0)
            {
                neighbors += board[i-1][j] == '*' ? 1 : 0;
                if(j > 0)
                    neighbors += board[i-1][j-1] == '*' ? 1 : 0;
                if(j < COLS-1)
                    neighbors += board[i-1][j+1] == '*' ? 1 : 0;
            }

            if(i < ROWS-1)
            {
                neighbors += board[i+1][j] == '*' ? 1 : 0;
                if(j > 0)
                    neighbors += board[i+1][j-1] == '*' ? 1 : 0;
                if(j < COLS-1)
                    neighbors += board[i+1][j+1] == '*' ? 1 : 0;
            }

            if(j > 0)
                neighbors += board[i][j-1] == '*' ? 1 : 0;
            if(j < COLS-1)
                neighbors += board[i][j+1] == '*' ? 1 : 0;

            if(board[i][j] == '*')
            {
                if(neighbors < 2 || neighbors > 3)
                    newBoard[i][j] = ' ';
                else
                    newBoard[i][j] = '*';
            }
            else
            {
                if(neighbors == 3)
                    newBoard[i][j] = '*';
                else
                    newBoard[i][j] = ' ';
            }
        }
    }

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            board[i][j] = newBoard[i][j];
        }
    }
}

void initializeBoard(char board[][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            board[i][j] = rand() % 2 == 0 ? ' ' : '*';
        }
    }
}

int main()
{
    srand(time(NULL));
    char board[ROWS][COLS];

    initializeBoard(board);
    while(1)
    {
        printBoard(board);
        updateBoard(board);
        usleep(100000);     // sleep for 100ms
    }

    return 0;
}