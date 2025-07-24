//FormAI DATASET v1.0 Category: Checkers Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Macros for checker pieces and colors
#define EMPTY 0
#define RED 1
#define BLACK 2
#define RED_KING 3
#define BLACK_KING 4

// Function prototypes
void initBoard(int board[][BOARD_SIZE]);
void displayBoard(int board[][BOARD_SIZE]);
bool movePiece(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int turn);
bool validMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int turn);
bool checkKing(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int turn);
bool canCapture(int board[][BOARD_SIZE], int row, int col, bool isKing, int turn);
bool gameOver(int board[][BOARD_SIZE], int turn);

int main(void)
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn = RED; // Red always goes first
    int fromRow, fromCol, toRow, toCol;

    initBoard(board);

    while (!gameOver(board, turn))
    {
        // Display the board
        displayBoard(board);

        // Prompt user for piece to move and where to move it
        printf("Player %d's turn.\n", turn);
        printf("Enter the row and column of the piece to move: ");
        scanf("%d %d", &fromRow, &fromCol);
        printf("Enter the row and column to move the piece to: ");
        scanf("%d %d", &toRow, &toCol);

        // Move the piece and check if it's valid
        if (movePiece(board, fromRow, fromCol, toRow, toCol, turn))
        {
            // Switch turns
            turn = (turn == RED) ? BLACK : RED;
        }
        else
        {
            printf("Invalid move. Try again.\n");
        }
    }

    // Game over, display the final board
    displayBoard(board);

    // Declare winner
    printf("Player %d wins!\n", (turn == RED) ? BLACK : RED);

    return 0;
}

// Initialize the board with pieces in their starting positions
void initBoard(int board[][BOARD_SIZE])
{
    int row, col;

    // Fill top three rows with black pieces
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < BOARD_SIZE; col++)
        {
            if ((row + col) % 2 == 0)
            {
                board[row][col] = BLACK;
            }
            else
            {
                board[row][col] = EMPTY;
            }
        }
    }

    // Fill bottom three rows with red pieces
    for (row = BOARD_SIZE - 3; row < BOARD_SIZE; row++)
    {
        for (col = 0; col < BOARD_SIZE; col++)
        {
            if ((row + col) % 2 == 0)
            {
                board[row][col] = RED;
            }
            else
            {
                board[row][col] = EMPTY;
            }
        }
    }
}

// Display the board with its current pieces
void displayBoard(int board[][BOARD_SIZE])
{
    int row, col;

    // Print column numbers
    printf("  ");
    for (col = 0; col < BOARD_SIZE; col++)
    {
        printf("%d ", col);
    }
    printf("\n");

    // Print board and row numbers
    for (row = 0; row < BOARD_SIZE; row++)
    {
        printf("%d ", row);
        for (col = 0; col < BOARD_SIZE; col++)
        {
            switch (board[row][col])
            {
                case RED:
                    printf("R ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case RED_KING:
                    printf("RK");
                    break;
                case BLACK_KING:
                    printf("BK");
                    break;
                default:
                    printf(". ");
                    break;
            }
        }
        printf("\n");
    }
}

// Move a piece on the board, if it's valid
bool movePiece(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int turn)
{
    // Check if move is valid
    if (!validMove(board, fromRow, fromCol, toRow, toCol, turn))
    {
        return false;
    }

    // Move the piece
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = EMPTY;

    // Check if piece becomes a king
    if (checkKing(board, fromRow, fromCol, toRow, toCol, turn))
    {
        if (turn == RED)
        {
            board[toRow][toCol] = RED_KING;
        }
        else if (turn == BLACK)
        {
            board[toRow][toCol] = BLACK_KING;
        }
    }

    // Capture a piece if possible
    if (abs(fromRow - toRow) == 2 && abs(fromCol - toCol) == 2)
    {
        int captureRow = (fromRow + toRow) / 2;
        int captureCol = (fromCol + toCol) / 2;
        board[captureRow][captureCol] = EMPTY;
    }

    return true;
}

// Check if a move is valid based on the current state of the board and player's turn
bool validMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int turn)
{
    // Check if moving to a valid square
    if (toRow < 0 || toRow >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE)
    {
        return false;
    }

    // Check if the piece is moving diagonally
    if (abs(fromRow - toRow) != abs(fromCol - toCol))
    {
        return false;
    }

    // Check if the piece is not moving anywhere
    if (fromRow == toRow || fromCol == toCol)
    {
        return false;
    }

    // Check if the player is moving their own piece
    if (board[fromRow][fromCol] != turn && board[fromRow][fromCol] != turn + 2)
    {
        return false;
    }

    // Check if destination square is empty
    if (board[toRow][toCol] != EMPTY)
    {
        return false;
    }

    // Check if piece is being captured
    if (abs(fromRow - toRow) == 2 && abs(fromCol - toCol) == 2)
    {
        int captureRow = (fromRow + toRow) / 2;
        int captureCol = (fromCol + toCol) / 2;
        if (board[captureRow][captureCol] == EMPTY || board[captureRow][captureCol] == turn ||
            board[captureRow][captureCol] == turn + 2)
        {
            return false;
        }
    }

    // Check if the piece is a king
    if (board[fromRow][fromCol] == RED_KING || board[fromRow][fromCol] == BLACK_KING)
    {
        // Kings can move in any direction as long as it's diagonally
        return true;
    }

    // Check if the player is moving the piece forward (based on their turn)
    if (turn == RED)
    {
        return toRow < fromRow;
    }
    else if (turn == BLACK)
    {
        return toRow > fromRow;
    }

    // Failed all checks, move is not valid
    return false;
}

// Check if the piece becomes a king
bool checkKing(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int turn)
{
    if (turn == RED && toRow == 0 && board[fromRow][fromCol] == RED)
    {
        return true;
    }
    else if (turn == BLACK && toRow == BOARD_SIZE - 1 && board[fromRow][fromCol] == BLACK)
    {
        return true;
    }

    return false;
}

// Check if a piece can capture another piece
bool canCapture(int board[][BOARD_SIZE], int row, int col, bool isKing, int turn)
{
    // Check if the piece can capture diagonally
    int captureLeft = (col - 2 >= 0 && row - 2 >= 0) ? board[row - 1][col - 1] == turn + 2 &&
                                                      board[row - 2][col - 2] == EMPTY : false;
    int captureRight = (col + 2 < BOARD_SIZE && row - 2 >= 0) ? board[row - 1][col + 1] == turn + 2 &&
                                                               board[row - 2][col + 2] == EMPTY : false;
    if (isKing)
    {
        captureLeft |= (col - 2 >= 0 && row + 2 < BOARD_SIZE) ? board[row + 1][col - 1] == turn + 2 &&
                                                               board[row + 2][col - 2] == EMPTY : false;
        captureRight |= (col + 2 < BOARD_SIZE && row + 2 < BOARD_SIZE) ? board[row + 1][col + 1] == turn + 2 &&
                                                                         board[row + 2][col + 2] == EMPTY : false;
    }

    return captureLeft || captureRight;
}

// Check if game is over by seeing if player has any moves left
bool gameOver(int board[][BOARD_SIZE], int turn)
{
    int row, col;
    bool isKing = false;

    for (row = 0; row < BOARD_SIZE; row++)
    {
        for (col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == turn || board[row][col] == turn + 2)
            {
                isKing = (board[row][col] == turn + 2) ? true : false;
                if (canCapture(board, row, col, isKing, turn))
                {
                    return false;
                }
            }
        }
    }

    // No moves left, game over
    return true;
}