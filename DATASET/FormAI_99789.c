//FormAI DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void drawBoard(char board[ROWS][COLS]);
int checkWin(char board[ROWS][COLS]);
void playerTurn(char board[ROWS][COLS], char player);
void computerTurn(char board[ROWS][COLS], char computer, char player);

int main()
{
    char board[ROWS][COLS] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char player = 'X';
    char computer = 'O';

    int turn = 1;
    int win = 0;
    srand(time(NULL)); // initialize random seed

    printf("Welcome to the Tic Tac Toe game!\n");
    printf("Player (%c) starts first.\n", player);

    while (turn <= ROWS * COLS && win == 0)
    {
        drawBoard(board);

        if (turn % 2 == 1)
        {
            playerTurn(board, player);
            win = checkWin(board);
        }
        else
        {
            computerTurn(board, computer, player);
            win = checkWin(board);
        }
        
        turn++;     
    }

    drawBoard(board);

    if (win == 1)
    {
        printf("Congrats! Player (%c) has won!\n", player);
    }
    else if (win == -1)
    {
        printf("Oh no! Computer (%c) has won!\n", computer);
    }
    else
    {
        printf("It's a draw.\n");
    }

    return 0;
}

void drawBoard(char board[ROWS][COLS])
{
    printf("\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf(" %c ", board[i][j]);

            if (j != COLS - 1)
            {
                printf("|");
            }
        }

        printf("\n");

        if (i != ROWS - 1)
        {
            printf("---+---+---\n");
        }
    }

    printf("\n");
}

int checkWin(char board[ROWS][COLS])
{
    // Check rows
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            if (board[i][0] == 'X')
            {
                return 1;
            }
            else if (board[i][0] == 'O')
            {
                return -1;
            }
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j])
        {
            if (board[0][j] == 'X')
            {
                return 1;
            }
            else if (board[0][j] == 'O')
            {
                return -1;
            }
        }
    }

    // Check diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        if (board[0][0] == 'X')
        {
            return 1;
        }
        else if (board[0][0] == 'O')
        {
            return -1;
        }
    }

    // Check anti-diagonal
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        if (board[0][2] == 'X')
        {
            return 1;
        }
        else if (board[0][2] == 'O')
        {
            return -1;
        }
    }

    // Check for draw
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return 0;
            }
        }
    }

    return 2; // draw
}

void playerTurn(char board[ROWS][COLS], char player)
{
    int choice = 0;

    do
    {
        printf("Player (%c), enter a number (1-9): ", player);
        scanf("%d", &choice);
        getchar(); // remove newline character from input buffer
        printf("\n");
    } while (choice < 1 || choice > 9 || board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O');

    board[(choice - 1) / 3][(choice - 1) % 3] = player;
}

void computerTurn(char board[ROWS][COLS], char computer, char player)
{
    printf("It's the computer's turn.\n");

    // Check if computer can win
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                board[i][j] = computer;

                if (checkWin(board) == -1)
                {
                    return;
                }
                
                board[i][j] = ' ';
            }
        }
    }

    // Check if player can win
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                board[i][j] = player;

                if (checkWin(board) == 1)
                {
                    board[i][j] = computer;
                    return;
                }

                board[i][j] = ' ';
            }
        }
    }

    // Otherwise, pick a random available spot
    int choice = 0;

    do
    {
        choice = rand() % (ROWS * COLS) + 1;
    } while (board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O');

    board[(choice - 1) / 3][(choice - 1) % 3] = computer;
}