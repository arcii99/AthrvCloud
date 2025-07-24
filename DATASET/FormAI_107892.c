//FormAI DATASET v1.0 Category: Checkers Game ; Style: intelligent
#include <stdio.h>

#define ROWS 8
#define COLS 8

void init_board(char board[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (i < 3 && (i+j)%2 == 0)
            {
                board[i][j] = 'B';
            }
            else if (i > 4 && (i+j)%2 == 0)
            {
                board[i][j] = 'W';
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board(char board[ROWS][COLS])
{
    int i, j;
    
    printf(" ");

    for(i = 0; i < ROWS; i++)
    {
        printf(" %d ", i+1);
    }

    printf("\n");

    for(i=0; i<COLS*2+1; i++)
    {
        printf("-");
    }

    printf("\n");

    for (i = 0; i < ROWS; i++)
    {
        printf("%c|", i+65);

        for (j = 0; j < COLS; j++)
        {
            printf("%c|", board[i][j]);
        }

        printf("\n");

        for(j=0; j<COLS*2+1; j++)
        {
            printf("-");
        }

        printf("\n");
    }
}

int main()
{
    char board[ROWS][COLS];
    init_board(board);
    print_board(board);
    return 0;
}