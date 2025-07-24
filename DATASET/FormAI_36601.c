//FormAI DATASET v1.0 Category: Checkers Game ; Style: single-threaded
#include <stdio.h>

// The dimensions of the game board
#define ROWS 8
#define COLS 8

// Piece values (positive is white, negative is black)
#define EMPTY 0
#define WHITE 1
#define BLACK -1

// Piece characters
#define EMPTY_CHAR ' '
#define WHITE_CHAR 'W'
#define BLACK_CHAR 'B'

// Function prototypes
void init_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
int move_piece(int board[ROWS][COLS], int from_row, int from_col, int to_row, int to_col);

// Entry point of the program
int main(void)
{
    // Initialize the board
    int board[ROWS][COLS];
    init_board(board);

    // Print the initial state of the board
    print_board(board);

    // Main game loop
    while (1)
    {
        // Read the move from the user
        int from_row, from_col, to_row, to_col;
        printf("Enter move (from_row from_col to_row to_col): ");
        if (scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col) != 4)
        {
            printf("Invalid move!\n");
            continue;
        }

        // Perform the move
        if (move_piece(board, from_row, from_col, to_row, to_col))
        {
            // Print the board after the move
            print_board(board);
        }
        else
        {
            printf("Invalid move!\n");
        }
    }

    return 0;
}

// Initializes the board with pieces in their starting positions
void init_board(int board[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (row < 3)
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
            else if (row > 4)
            {
                if ((row + col) % 2 == 0)
                {
                    board[row][col] = WHITE;
                }
                else
                {
                    board[row][col] = EMPTY;
                }
            }
            else
            {
                board[row][col] = EMPTY;
            }
        }
    }
}

// Prints the current state of the board to the console
void print_board(int board[ROWS][COLS])
{
    printf("\n  ");
    for (int col = 0; col < COLS; col++)
    {
        printf(" %d ", col);
    }
    printf("\n");

    for (int row = 0; row < ROWS; row++)
    {
        printf("%d|", row);
        for (int col = 0; col < COLS; col++)
        {
            switch (board[row][col])
            {
                case EMPTY:
                    printf(" %c ", EMPTY_CHAR);
                    break;
                case WHITE:
                    printf(" %c ", WHITE_CHAR);
                    break;
                case BLACK:
                    printf(" %c ", BLACK_CHAR);
                    break;
            }
        }
        printf("|\n");
    }

    printf("  ");
    for (int col = 0; col < COLS; col++)
    {
        printf(" %d ", col);
    }
    printf("\n");
}

// Tries to move a piece from the given position to the given destination, returns 1 if successful, 0 otherwise
int move_piece(int board[ROWS][COLS], int from_row, int from_col, int to_row, int to_col)
{
    // Check if the from position is valid
    if (from_row < 0 || from_row >= ROWS || from_col < 0 || from_col >= COLS)
    {
        return 0;
    }

    // Check if the to position is valid
    if (to_row < 0 || to_row >= ROWS || to_col < 0 || to_col >= COLS)
    {
        return 0;
    }

    // Check if there is a piece at the from position
    int piece = board[from_row][from_col];
    if (piece == EMPTY)
    {
        return 0;
    }

    // Check if the destination is empty
    if (board[to_row][to_col] != EMPTY)
    {
        return 0;
    }

    // Check if the move is diagonal
    if (from_row == to_row || from_col == to_col || abs(from_row - to_row) != abs(from_col - to_col))
    {
        return 0;
    }

    // Check if the move is valid for the piece
    int dy = piece > 0 ? -1 : 1;
    if (to_row != from_row + dy || abs(to_col - from_col) != 1)
    {
        // Check if this is a capture move (pawn only)
        if (abs(to_col - from_col) != 2 || abs(to_row - from_row) != 2)
        {
            return 0;
        }

        int capture_row = (from_row + to_row) / 2;
        int capture_col = (from_col + to_col) / 2;
        if (board[capture_row][capture_col] == EMPTY || board[capture_row][capture_col] * piece >= 0)
        {
            return 0;
        }
    }

    // Apply the move
    board[from_row][from_col] = EMPTY;
    board[to_row][to_col] = piece;

    return 1;
}