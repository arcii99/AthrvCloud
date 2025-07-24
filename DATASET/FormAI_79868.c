//FormAI DATASET v1.0 Category: Chess AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the chess board.
char board[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

// Define the color of current turn.
char turn = 'w';

// Define a function to display the current state of the game board.
void displayBoard()
{
    printf("\n    A   B   C   D   E   F   G   H \n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d |", i + 1);
        for (int j = 0; j < 8; j++)
        {
            printf(" %c |", board[i][j]);
        }
        printf(" %d\n", i + 1);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    A   B   C   D   E   F   G   H \n");
}

// Define a function to check if the given position is on the board.
int isOnBoard(int row, int col)
{
    return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

// Define a function to check if the given position is empty.
int isEmpty(int row, int col)
{
    return (board[row][col] == ' ');
}

// Define a function to check if the piece at the given position is of the opposite color.
int isOpponent(int row, int col)
{
    if (isOnBoard(row, col))
    {
        if (turn == 'w' && islower(board[row][col]))
            return 1;
        if (turn == 'b' && isupper(board[row][col]))
            return 1;
    }
    return 0;
}

// Define a function to move a piece to the given position.
void movePiece(int fromRow, int fromCol, int toRow, int toCol)
{
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';
}

// Define a function to check if the given position is in check.
int isInCheck(int row, int col)
{
    int i, j;

    // Check if the king is under attack from a knight.
    int knightMoves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for (int k = 0; k < 8; k++)
    {
        i = row + knightMoves[k][0];
        j = col + knightMoves[k][1];
        if (isOnBoard(i, j) && board[i][j] == 'n' && isOpponent(i, j))
            return 1;
    }

    // Check if the king is under attack from a pawn.
    if (turn == 'w')
    {
        if (isOnBoard(row - 1, col - 1) && board[row - 1][col - 1] == 'p' && isOpponent(row - 1, col - 1))
            return 1;
        if (isOnBoard(row - 1, col + 1) && board[row - 1][col + 1] == 'p' && isOpponent(row - 1, col + 1))
            return 1;
    }
    else
    {
        if (isOnBoard(row + 1, col - 1) && board[row + 1][col - 1] == 'P' && isOpponent(row + 1, col - 1))
            return 1;
        if (isOnBoard(row + 1, col + 1) && board[row + 1][col + 1] == 'P' && isOpponent(row + 1, col + 1))
            return 1;
    }

    // Check if the king is under attack from a rook or queen in the same row or column.
    for (i = row - 1; i >= 0; i--)
    {
        if (board[i][col] != ' ')
        {
            if (board[i][col] == 'r' || board[i][col] == 'q')
                return 1;
            else
                break;
        }
    }
    for (i = row + 1; i < 8; i++)
    {
        if (board[i][col] != ' ')
        {
            if (board[i][col] == 'r' || board[i][col] == 'q')
                return 1;
            else
                break;
        }
    }
    for (j = col - 1; j >= 0; j--)
    {
        if (board[row][j] != ' ')
        {
            if (board[row][j] == 'r' || board[row][j] == 'q')
                return 1;
            else
                break;
        }
    }
    for (j = col + 1; j < 8; j++)
    {
        if (board[row][j] != ' ')
        {
            if (board[row][j] == 'r' || board[row][j] == 'q')
                return 1;
            else
                break;
        }
    }

    // Check if the king is under attack from a bishop or queen in the same diagonal.
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] != ' ')
        {
            if (board[i][j] == 'b' || board[i][j] == 'q')
                return 1;
            else
                break;
        }
    }
    for (i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++)
    {
        if (board[i][j] != ' ')
        {
            if (board[i][j] == 'b' || board[i][j] == 'q')
                return 1;
            else
                break;
        }
    }
    for (i = row + 1, j = col - 1; i < 8 && j >= 0; i++, j--)
    {
        if (board[i][j] != ' ')
        {
            if (board[i][j] == 'b' || board[i][j] == 'q')
                return 1;
            else
                break;
        }
    }
    for (i = row + 1, j = col + 1; i < 8 && j < 8; i++, j++)
    {
        if (board[i][j] != ' ')
        {
            if (board[i][j] == 'b' || board[i][j] == 'q')
                return 1;
            else
                break;
        }
    }

    // Check if the king is under attack from the opposing king.
    int kingMoves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int k = 0; k < 8; k++)
    {
        i = row + kingMoves[k][0];
        j = col + kingMoves[k][1];
        if (isOnBoard(i, j) && board[i][j] == 'k' && isOpponent(i, j))
            return 1;
    }

    return 0;
}

// Define a function to get a move from the user.
void getMove(int *fromRow, int *fromCol, int *toRow, int *toCol)
{
    char moveNotation[5];
    char piece = ' ';

    do
    {
        printf("\nEnter your move (example: e2e4): ");
        scanf("%s", moveNotation);

        *fromCol = moveNotation[0] - 'a';
        *toCol = moveNotation[2] - 'a';
        *fromRow = moveNotation[1] - '1';
        *toRow = moveNotation[3] - '1';
    } while (!isOnBoard(*fromRow, *fromCol) || !isOnBoard(*toRow, *toCol) || isEmpty(*fromRow, *fromCol));

    piece = board[*fromRow][*fromCol];
    if (turn == 'w' && !isupper(piece))
        piece = ' ';
    if (turn == 'b' && !islower(piece))
        piece = ' ';

    if (piece == ' ')
    {
        printf("\nThere is no piece at %s.\n", moveNotation);
        getMove(fromRow, fromCol, toRow, toCol);
    }
    else if (isOpponent(*toRow, *toCol) || isEmpty(*toRow, *toCol))
    {
        if (isLegalMove(*fromRow, *fromCol, *toRow, *toCol))
        {
            movePiece(*fromRow, *fromCol, *toRow, *toCol);
        }
        else
        {
            printf("\nThat is not a legal move.\n");
            getMove(fromRow, fromCol, toRow, toCol);
        }
    }
    else
    {
        printf("\nYou cannot capture your own piece.\n");
        getMove(fromRow, fromCol, toRow, toCol);
    }
}

// Define a function to check if the given move is legal.
int isLegalMove(int fromRow, int fromCol, int toRow, int toCol)
{
    char piece = board[fromRow][fromCol];
    char capturedPiece = board[toRow][toCol];

    // Check if the move is valid for the given piece.
    switch (toupper(piece))
    {
    case 'P':
        if (fromCol == toCol && isEmpty(toRow, toCol))
        {
            if (turn == 'w')
            {
                if (toRow == fromRow - 1)
                    return 1;
                else if (fromRow == 6 && toRow == 4 && isEmpty(5, toCol))
                    return 1;
            }
            else
            {
                if (toRow == fromRow + 1)
                    return 1;
                else if (fromRow == 1 && toRow == 3 && isEmpty(2, toCol))
                    return 1;
            }
        }
        else if (abs(fromCol - toCol) == 1 && isOpponent(toRow, toCol))
        {
            if (turn == 'w' && toRow == fromRow - 1)
                return 1;
            else if (turn == 'b' && toRow == fromRow + 1)
                return 1;
        }
        break;
    case 'R':
        if (fromRow == toRow)
        {
            if (fromCol < toCol)
            {
                for (int i = fromCol + 1; i < toCol; i++)
                {
                    if (!isEmpty(fromRow, i))
                        return 0;
                }
                return 1;
            }
            else if (fromCol > toCol)
            {
                for (int i = fromCol - 1; i > toCol; i--)
                {
                    if (!isEmpty(fromRow, i))
                        return 0;
                }
                return 1;
            }
        }
        else if (fromCol == toCol)
        {
            if (fromRow < toRow)
            {
                for (int i = fromRow + 1; i < toRow; i++)
                {
                    if (!isEmpty(i, fromCol))
                        return 0;
                }
                return 1;
            }
            else if (fromRow > toRow)
            {
                for (int i = fromRow - 1; i > toRow; i--)
                {
                    if (!isEmpty(i, fromCol))
                        return 0;
                }
                return 1;
            }
        }
        break;
    case 'N':
        if ((abs(fromRow - toRow) == 2 && abs(fromCol - toCol) == 1) || (abs(fromRow - toRow) == 1 && abs(fromCol - toCol) == 2))
            return 1;
        break;
    case 'B':
        if (abs(fromRow - toRow) == abs(fromCol - toCol))
        {
            if (fromRow < toRow && fromCol < toCol)
            {
                for (int i = fromRow + 1, j = fromCol + 1; i < toRow && j < toCol; i++, j++)
                {
                    if (!isEmpty(i, j))
                        return 0;
                }
                return 1;
            }
            else if (fromRow < toRow && fromCol > toCol)
            {
                for (int i = fromRow + 1, j = fromCol - 1; i < toRow && j > toCol; i++, j--)
                {
                    if (!isEmpty(i, j))
                        return 0;
                }
                return 1;
            }
            else if (fromRow > toRow && fromCol < toCol)
            {
                for (int i = fromRow - 1, j = fromCol + 1; i > toRow && j < toCol; i--, j++)
                {
                    if (!isEmpty(i, j))
                        return 0;
                }
                return 1;
            }
            else if (fromRow > toRow && fromCol > toCol)
            {
                for (int i = fromRow - 1, j = fromCol - 1; i > toRow && j > toCol; i--, j--)
                {
                    if (!isEmpty(i, j))
                        return 0;
                }
                return 1;
            }
        }
        break;
    case 'Q':
        if (fromRow == toRow)
        {
            if (fromCol < toCol)
            {
                for (int i = fromCol + 1; i < toCol; i++)
                {
                    if (!isEmpty(fromRow, i))
                        return 0;
                }
                return 1;
            }
            else if (fromCol > toCol)
            {
                for (int i = fromCol - 1; i > toCol; i--)
                {
                    if (!isEmpty(fromRow, i))
                        return 0;
                }
                return 1;
            }
        }
        else if (fromCol == toCol)
        {
            if (fromRow < toRow)
            {
                for (int i = fromRow + 1; i < toRow; i++)
                {
                    if (!isEmpty(i, fromCol))
                        return 0;
                }
                return 1;
            }
            else if (fromRow > toRow)
            {
                for (int i = fromRow - 1; i > toRow; i--)
                {
                    if (!isEmpty(i, fromCol))
                        return 0;
                }
                return 1;
            }
        }
        else if (abs(fromRow - toRow) == abs(fromCol - toCol))
        {
            if (fromRow < toRow && fromCol < toCol)
            {
                for (int i = fromRow + 1, j = fromCol + 1; i < toRow && j < toCol; i++, j++)
                {
                    if (!isEmpty(i, j))
                        return 0;
                }
                return 1;
            }
            else if (fromRow < toRow && fromCol > toCol)
            {
                for (int i = fromRow + 1, j = fromCol - 1; i < toRow && j > toCol; i++, j--)
                {
                    if (!isEmpty(i, j))
                        return 0;
                }
                return 1;
            }
            else if (fromRow > toRow && fromCol < toCol)
            {
                for (int i = fromRow - 1, j = fromCol + 1; i > toRow && j < toCol; i--, j++)
                {
                    if (!isEmpty(i, j))
                        return 0;
                }
                return 1;
            }
            else if (fromRow > toRow && fromCol > toCol)
            {
                for (int i = fromRow - 1, j = fromCol - 1; i > toRow && j > toCol; i--, j--)
                {
                    if (!isEmpty(i, j))
                        return 0;
                }
                return 1;
            }
        }
        break;
    case 'K':
        if (abs(fromRow - toRow) <= 1 && abs(fromCol - toCol) <= 1)
            return 1;
        break;
    }
    return 0;
}

// Define the main function to play the game.
int main()
{
    int fromRow, fromCol, toRow, toCol;

    printf("Welcome to C Chess!\n\n");
    displayBoard();

    while (1)
    {
        if (turn == 'w')
            printf("\nWhite's turn.\n");
        else
            printf("\nBlack's turn.\n");

        getMove(&fromRow, &fromCol, &toRow, &toCol);
        movePiece(fromRow, fromCol, toRow, toCol);

        if (isInCheck(toRow, toCol))
        {
            printf("\nCheck!\n");
        }

        turn = (turn == 'w' ? 'b' : 'w');
        displayBoard();
    }

    return 0;
}