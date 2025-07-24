//FormAI DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

int checkWin(char board[][BOARD_SIZE], char symbol);
void printBoard(char board[][BOARD_SIZE]);
int checkBounds(int x, int y);
int checkOccupied(char board[][BOARD_SIZE], int x, int y);
void clearScreen();

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn = 0;
    srand(time(NULL));

    //initialize board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '-';
        }
    }

    //randomly select starting player
    if (rand() % 2 == 0)
    {
        turn = 1;
        printf("Player 2 goes first!\n");
    }
    else
    {
        turn = 0;
        printf("Player 1 goes first!\n");
    }

    //game loop
    int x, y, validMove;
    char symbol;
    while (!checkWin(board, 'X') && !checkWin(board, 'O'))
    {   
        symbol = turn == 0 ? 'X' : 'O';
        validMove = 0;

        //get move from player
        while (!validMove)
        {
            printf("Player %d: Enter your move (row,col): ", turn + 1);
            scanf("%d,%d", &x, &y);

            if (!checkBounds(x, y))
            {
                printf("Invalid move! Out of bounds.\n");
            }
            else if (checkOccupied(board, x, y))
            {
                printf("Invalid move! Tile already occupied.\n");
            }
            else
            {
                validMove = 1;
            }
        }

        //place symbol on board
        board[x][y] = symbol;

        //clear screen and print board
        clearScreen();
        printBoard(board);

        //switch turn
        turn = turn == 0 ? 1 : 0;
    }

    //game over
    if (checkWin(board, 'X'))
    {
        printf("Player 1 wins!\n");
    }
    else if (checkWin(board, 'O'))
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}

//check if there is a winning player
int checkWin(char board[][BOARD_SIZE], char symbol)
{
    //check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == symbol)
            {
                count++;
            }
        }
        if (count == BOARD_SIZE)
        {
            return 1;
        }
    }

    //check columns
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[j][i] == symbol)
            {
                count++;
            }
        }
        if (count == BOARD_SIZE)
        {
            return 1;
        }
    }

    //check diagonals
    int count = 0;
    for (int i = 0, j = 0; i < BOARD_SIZE; i++, j++)
    {
        if (board[i][j] == symbol)
        {
            count++;
        }
    }
    if (count == BOARD_SIZE)
    {
        return 1;
    }

    count = 0;
    for (int i = 0, j = BOARD_SIZE - 1; i < BOARD_SIZE; i++, j--)
    {
        if (board[i][j] == symbol)
        {
            count++;
        }
    }
    if (count == BOARD_SIZE)
    {
        return 1;
    }

    return 0;
}

//print the current state of the board
void printBoard(char board[][BOARD_SIZE])
{
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

//check if a move is within the board
int checkBounds(int x, int y)
{
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE)
    {
        return 1;
    }
    return 0;
}

//check if a tile is already occupied
int checkOccupied(char board[][BOARD_SIZE], int x, int y)
{
    if (board[x][y] == '-')
    {
        return 0;
    }
    return 1;
}

//clear the screen
void clearScreen()
{
    system("clear||cls");
}