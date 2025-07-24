//FormAI DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>
#include <stdlib.h>

// define size of board
#define SIZE 8

// define player pieces
#define BLACK 'B'
#define WHITE 'W'

// define player directions
#define TOPLEFT -9
#define TOPRIGHT -7
#define BOTLEFT 7
#define BOTRIGHT 9

// define empty space and null character
#define EMPTY '_'
#define NULLCHAR '\0'

// define row labels
#define ROWLABELS "ABCDEFGH"

// declare board and function to initialize
char board[SIZE][SIZE];
void initBoard();

// declare function to print board
void printBoard();

// declare function to check if piece can move to specified square
int canMove(int currentPlayer, int origin, int destination);

// declare function to make move
void makeMove(int currentPlayer, int origin, int destination);

// declare function to check if current player has any legal moves
int hasMoves(int currentPlayer);

// main function
int main()
{
    // initialize board
    initBoard();

    // initialize player and game status
    int currentPlayer = WHITE;
    int gameStatus = 1;

    // print initial board
    printBoard();

    // game loop
    while (gameStatus)
    {
        // check if current player has moves
        if (!hasMoves(currentPlayer))
        {
            printf("Player %c has no moves! Game over.\n", currentPlayer);
            gameStatus = 0;
            continue;
        }

        // get move input from player
        int origin, destination;
        printf("Player %c, enter move in format 'A1->B2': ", currentPlayer);
        scanf("%d->%d", &origin, &destination);

        // check if move is valid
        if (!canMove(currentPlayer, origin, destination))
        {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // make move and print board
        makeMove(currentPlayer, origin, destination);
        printBoard();

        // switch players
        currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE;
    }

    return 0;
}

// function to initialize board
void initBoard()
{
    // loop through board and set initial pieces
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i + j) % 2 == 0)
            {
                board[i][j] = EMPTY;
            }
            else if (i < 3)
            {
                board[i][j] = BLACK;
            }
            else if (i > 4)
            {
                board[i][j] = WHITE;
            }
            else
            {
                board[i][j] = EMPTY;
            }
        }
    }
}

// function to print board
void printBoard()
{
    // print column labels
    printf("\n  ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", i+1);
    }
    printf("\n");

    // print row labels and board squares
    for (int i = 0; i < SIZE; i++)
    {
        printf("%c ", ROWLABELS[i]);
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("%c\n", ROWLABELS[i]);
    }

    // print column labels
    printf("  ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", i+1);
    }
    printf("\n");
}

// function to check if piece can move to specified square
int canMove(int currentPlayer, int origin, int destination)
{
    // check if origin and destination are valid squares
    if (origin < 0 || origin >= SIZE*SIZE || board[origin/SIZE][origin%SIZE] != currentPlayer || destination < 0 || destination >= SIZE*SIZE || board[destination/SIZE][destination%SIZE] != EMPTY)
    {
        return 0;
    }

    // check if move is diagonal
    int diagonal = destination - origin;
    if (diagonal != TOPLEFT && diagonal != TOPRIGHT && diagonal != BOTLEFT && diagonal != BOTRIGHT)
    {
        return 0;
    }

    // check if move is legal for regular piece or king
    if (currentPlayer == WHITE && (diagonal == TOPLEFT || diagonal == TOPRIGHT) && board[destination/SIZE][destination%SIZE] == EMPTY)
    {
        return 1;
    }
    else if (currentPlayer == BLACK && (diagonal == BOTLEFT || diagonal == BOTRIGHT) && board[destination/SIZE][destination%SIZE] == EMPTY)
    {
        return 1;
    }
    else if (board[origin/SIZE][origin%SIZE] == currentPlayer+32 && abs(diagonal) == 18 && board[(origin+destination)/2/SIZE][(origin+destination)/2%SIZE] == (currentPlayer == WHITE ? BLACK : WHITE))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to make move
void makeMove(int currentPlayer, int origin, int destination)
{
    // move piece to destination square
    board[destination/SIZE][destination%SIZE] = board[origin/SIZE][origin%SIZE];
    board[origin/SIZE][origin%SIZE] = EMPTY;

    // check if piece becomes king
    if (currentPlayer == WHITE && destination/SIZE == 0)
    {
        board[destination/SIZE][destination%SIZE] = 'W';
    }
    else if (currentPlayer == BLACK && destination/SIZE == SIZE-1)
    {
        board[destination/SIZE][destination%SIZE] = 'B';
    }

    // check if capturing move
    if (abs(destination - origin) == 18)
    {
        board[(origin+destination)/2/SIZE][(origin+destination)/2%SIZE] = EMPTY;
    }
}

// function to check if current player has any legal moves
int hasMoves(int currentPlayer)
{
    // loop through board and check each piece
    for (int i = 0; i < SIZE*SIZE; i++)
    {
        if (board[i/SIZE][i%SIZE] == currentPlayer || board[i/SIZE][i%SIZE] == currentPlayer+32)
        {
            // check if piece can move in any direction
            if (canMove(currentPlayer, i, i+TOPLEFT) || canMove(currentPlayer, i, i+TOPRIGHT) || canMove(currentPlayer, i, i+BOTLEFT) || canMove(currentPlayer, i, i+BOTRIGHT))
            {
                return 1;
            }
        }
    }

    return 0;
}