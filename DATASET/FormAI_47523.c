//FormAI DATASET v1.0 Category: Checkers Game ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define SIZE 8

int board[SIZE][SIZE];

void initialize_board()
{
    int i, j;

    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if((i + j) % 2 == 0)
            {
                if(i < 3)
                {
                    board[i][j] = WHITE;
                }
                else if(i > 4)
                {
                    board[i][j] = BLACK;
                }
                else
                {
                    board[i][j] = EMPTY;
                }
            }
            else
            {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board()
{
    int i, j;

    for(i = 0; i < SIZE; i++)
    {
        printf(" %d", i);
    }
    printf("\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", i);
        for(j = 0; j < SIZE; j++)
        {
            switch(board[i][j])
            {
                case EMPTY:
                    printf(" ");
                    break;
                case BLACK:
                    printf("B");
                    break;
                case WHITE:
                    printf("W");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int player = BLACK;

    initialize_board();
    print_board();

    return 0;
}