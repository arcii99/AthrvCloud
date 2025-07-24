//FormAI DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLUMNS 8

// Function to print the current board state
void printBoard(char board[ROWS][COLUMNS])
{
    printf("  A B C D E F G H\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i + 1);
    }
    printf("  A B C D E F G H\n");
}

// Function to check if the move is valid
int isValidMove(char board[ROWS][COLUMNS], int startRow, int startCol, int endRow, int endCol, char player)
{
    // Check if the end position is within the bounds of the board
    if (endRow < 0 || endRow >= ROWS || endCol < 0 || endCol >= COLUMNS)
    {
        return 0;
    }

    // Check if the end position is empty
    if (board[endRow][endCol] != '-')
    {
        return 0;
    }

    // Check if the move is diagonal
    if (abs(endRow - startRow) != abs(endCol - startCol))
    {
        return 0;
    }

    int jumpRow = -1;
    int jumpCol = -1;

    // Check if the move is a jump
    if (abs(endRow - startRow) == 2 && abs(endCol - startCol) == 2)
    {
        jumpRow = (startRow + endRow) / 2;
        jumpCol = (startCol + endCol) / 2;

        // Check if the piece being jumped over belongs to the other player
        if (toupper(board[jumpRow][jumpCol]) != toupper(player))
        {
            return 0;
        }
    }

    // Check if the move is legal for the given player's piece
    if (player == 'r')
    {
        if (endRow > startRow)
        {
            return 0;
        }

        if (abs(endRow - startRow) == 1 && abs(endCol - startCol) == 1)
        {
            return 1;
        }

        if (abs(endRow - startRow) == 2 && abs(endCol - startCol) == 2)
        {
            return 1;
        }
    }
    else if (player == 'b')
    {
        if (endRow < startRow)
        {
            return 0;
        }

        if (abs(endRow - startRow) == 1 && abs(endCol - startCol) == 1)
        {
            return 1;
        }

        if (abs(endRow - startRow) == 2 && abs(endCol - startCol) == 2)
        {
            return 1;
        }
    }

    return 0;
}

// Function to perform a move
void makeMove(char board[ROWS][COLUMNS], int startRow, int startCol, int endRow, int endCol, char player)
{
    board[endRow][endCol] = player;
    board[startRow][startCol] = '-';

    // Check if the move is a jump and remove the piece that was jumped over
    if (abs(endRow - startRow) == 2 && abs(endCol - startCol) == 2)
    {
        int jumpRow = (startRow + endRow) / 2;
        int jumpCol = (startCol + endCol) / 2;

        board[jumpRow][jumpCol] = '-';
    }

    // Promote the piece to king if it reaches the opposite end of the board
    if (player == 'r' && endRow == 0)
    {
        board[endRow][endCol] = 'R';
    }
    else if (player == 'b' && endRow == ROWS - 1)
    {
        board[endRow][endCol] = 'B';
    }
}

// Function to check if the game has ended
int hasGameEnded(char board[ROWS][COLUMNS])
{
    int redPieces = 0;
    int blackPieces = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (board[i][j] == 'r' || board[i][j] == 'R')
            {
                redPieces++;
            }
            else if (board[i][j] == 'b' || board[i][j] == 'B')
            {
                blackPieces++;
            }
        }
    }

    if (redPieces == 0)
    {
        printf("Black wins!\n");
        return 1;
    }
    else if (blackPieces == 0)
    {
        printf("Red wins!\n");
        return 1;
    }

    return 0;
}

int main()
{
    char board[ROWS][COLUMNS] =
    {
        {'-', 'r', '-', 'r', '-', 'r', '-', 'r'},
        {'r', '-', 'r', '-', 'r', '-', 'r', '-'},
        {'-', 'r', '-', 'r', '-', 'r', '-', 'r'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'b', '-', 'b', '-', 'b', '-', 'b', '-'},
        {'-', 'b', '-', 'b', '-', 'b', '-', 'b'},
        {'b', '-', 'b', '-', 'b', '-', 'b', '-'}
    };

    printf("Welcome to Checkers!\n");
    printf("Red pieces: r\n");
    printf("Black pieces: b\n");
    printf("Red kings: R\n");
    printf("Black kings: B\n");
    printf("Moves should be entered as space separated coordinate pairs, e.g. A3 to B4\n");
    printf("Enter q to quit the game\n\n");

    printBoard(board);

    char player = 'r';

    while (1)
    {
        printf("%c's turn: ", player);

        char input[5];
        scanf("%s", input);

        if (input[0] == 'q')
        {
            break;
        }

        int startCol = input[0] - 'A';
        int startRow = input[1] - '1';
        int endCol = input[3] - 'A';
        int endRow = input[4] - '1';

        if (!isValidMove(board, startRow, startCol, endRow, endCol, player))
        {
            printf("Invalid move!\n");
            continue;
        }

        makeMove(board, startRow, startCol, endRow, endCol, player);

        if (hasGameEnded(board))
        {
            break;
        }

        printBoard(board);

        // Switch to the other player's turn
        if (player == 'r')
        {
            player = 'b';
        }
        else
        {
            player = 'r';
        }
    }

    return 0;
}