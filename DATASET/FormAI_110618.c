//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7

int placeToken(int playerNum, int col, char board[][COLS]);
void printBoard(char board[][COLS]);
int checkWinner(char board[][COLS], int playerNum);
void clearBoard(char board[][COLS]);

int main()
{
    char board[ROWS][COLS];
    int playerNum = 1;
    int col, row;
    int winner = 0;
    clearBoard(board);
    printf("Welcome to Connect Four!\n");
    printf("Player 1 (X) - Player 2 (O)\n");
    printf("-----------------------------\n");
    do
    {
        printBoard(board);
        printf("Player %d, enter a column number: ", playerNum);
        scanf("%d", &col);
        while (placeToken(playerNum, col, board) == 0)
        {
            printf("Column is full. Please choose another column.\n");
            scanf("%d", &col);
        }
        winner = checkWinner(board, playerNum);
        playerNum = (playerNum == 1) ? 2 : 1;
    } while (winner == 0);
    printBoard(board);

    if (winner == 1)
        printf("Player 1 (X) wins!\n");
    else
        printf("Player 2 (O) wins!\n");

    return 0;
}

void clearBoard(char board[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = '-';
        }
    }
}

int placeToken(int playerNum, int col, char board[][COLS])
{
    int i;
    for (i = ROWS - 1; i >= 0; i--)
    {
        if (board[i][col] == '-')
        {
            board[i][col] = (playerNum == 1) ? 'X' : 'O';
            return 1;
        }
    }
    return 0;
}

void printBoard(char board[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    for (i = 0; i < COLS; i++)
    {
        printf("  %d ", i);
    }
    printf("\n");
}

int checkWinner(char board[][COLS], int playerNum)
{
    int i, j;
    // Horizontal check
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == (playerNum == 1 ? 'X' : 'O') && board[i][j + 1] == (playerNum == 1 ? 'X' : 'O') && board[i][j + 2] == (playerNum == 1 ? 'X' : 'O') && board[i][j + 3] == (playerNum == 1 ? 'X' : 'O'))
                return playerNum;
        }
    }
    // Vertical check
    for (i = 0; i < ROWS - 3; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == (playerNum == 1 ? 'X' : 'O') && board[i + 1][j] == (playerNum == 1 ? 'X' : 'O') && board[i + 2][j] == (playerNum == 1 ? 'X' : 'O') && board[i + 3][j] == (playerNum == 1 ? 'X' : 'O'))
                return playerNum;
        }
    }
    // Diagonal check
    for (i = 0; i < ROWS - 3; i++)
    {
        for (j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == (playerNum == 1 ? 'X' : 'O') && board[i + 1][j + 1] == (playerNum == 1 ? 'X' : 'O') && board[i + 2][j + 2] == (playerNum == 1 ? 'X' : 'O') && board[i + 3][j + 3] == (playerNum == 1 ? 'X' : 'O'))
                return playerNum;
            if (board[i + 3][j] == (playerNum == 1 ? 'X' : 'O') && board[i + 2][j + 1] == (playerNum == 1 ? 'X' : 'O') && board[i + 1][j + 2] == (playerNum == 1 ? 'X' : 'O') && board[i][j + 3] == (playerNum == 1 ? 'X' : 'O'))
                return playerNum;
        }
    }
    return 0;
}