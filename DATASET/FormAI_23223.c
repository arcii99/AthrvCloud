//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

// function declaration
void setBoard(char board[][SIZE]);
void printBoard(char board[][SIZE]);
int makeMove(char board[][SIZE], int col, int row, char player);

int main()
{
    char board[SIZE][SIZE];
    int col;
    int row;
    char player = 'X';

    setBoard(board);

    while(1)
    {
        printf("\nPlayer %c's turn:\n", player);
        printf("Enter the column (1-8) and row (1-8) to move: ");
        scanf("%d %d", &col, &row);

        if(makeMove(board, col-1, row-1, player))
        {
            printBoard(board);
            if(player == 'X')
                player = 'O';
            else
                player = 'X';
        }
        else
        {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}

// function to initialize the board with pieces
void setBoard(char board[][SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if((i+j)%2 == 0)
            {
                if(i < 3)
                    board[i][j] = 'O';
                else if(i > 4)
                    board[i][j] = 'X';
                else
                    board[i][j] = '-';
            }
            else
                board[i][j] = ' ';
        }
    }
}

// function to display the board state
void printBoard(char board[][SIZE])
{
    printf("  1 2 3 4 5 6 7 8\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ", i+1);
        for(int j=0;j<SIZE;j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check and make a move
int makeMove(char board[][SIZE], int col, int row, char player)
{
    if(board[row][col] != '-')
        return 0;

    if(player == 'X')
    {
        if(row > 0 && col > 0 && board[row-1][col-1] == 'O')
        {
            if(row > 1 && col > 1 && board[row-2][col-2] == '-')
            {
                board[row][col] = '-';
                board[row-1][col-1] = '-';
                board[row-2][col-2] = 'X';
                return 1;
            }
        }
        if(row > 0 && col < 7 && board[row-1][col+1] == 'O')
        {
            if(row > 1 && col < 6 && board[row-2][col+2] == '-')
            {
                board[row][col] = '-';
                board[row-1][col+1] = '-';
                board[row-2][col+2] = 'X';
                return 1;
            }
        }
        if(row < 7 && col < 7 && board[row+1][col+1] == '-')
        {
            board[row][col] = '-';
            board[row+1][col+1] = 'X';
            return 1;
        }
        if(row < 7 && col > 0 && board[row+1][col-1] == '-')
        {
            board[row][col] = '-';
            board[row+1][col-1] = 'X';
            return 1;
        }
    }
    else
    {
        if(row < 7 && col > 0 && board[row+1][col-1] == 'X')
        {
            if(row < 6 && col > 1 && board[row+2][col-2] == '-')
            {
                board[row][col] = '-';
                board[row+1][col-1] = '-';
                board[row+2][col-2] = 'O';
                return 1;
            }
        }
        if(row < 7 && col < 7 && board[row+1][col+1] == 'X')
        {
            if(row < 6 && col < 6 && board[row+2][col+2] == '-')
            {
                board[row][col] = '-';
                board[row+1][col+1] = '-';
                board[row+2][col+2] = 'O';
                return 1;
            }
        }
        if(row > 0 && col < 7 && board[row-1][col+1] == '-')
        {
            board[row][col] = '-';
            board[row-1][col+1] = 'O';
            return 1;
        }
        if(row > 0 && col > 0 && board[row-1][col-1] == '-')
        {
            board[row][col] = '-';
            board[row-1][col-1] = 'O';
            return 1;
        }
    }
    return 0;
}