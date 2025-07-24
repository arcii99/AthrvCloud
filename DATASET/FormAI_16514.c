//FormAI DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY ' '
#define WALL '#'

// Function prototypes
void initialize_board(char board[][SIZE]);
void print_board(char board[][SIZE]);
bool valid_move(char board[][SIZE], int player, int r1, int c1, int r2, int c2);
void make_move(char board[][SIZE], int r1, int c1, int r2, int c2);
bool jump_available(char board[][SIZE], int player);
bool can_jump(char board[][SIZE], int player, int r, int c, int dr, int dc);
void get_best_move(char board[][SIZE], int player, int *r1, int *c1, int *r2, int *c2);
bool game_over(char board[][SIZE]);
int count_pieces(char board[][SIZE], char piece);

// Main function
int main(void)
{
    // Declare and initialize the board
    char board[SIZE][SIZE] = {0};
    initialize_board(board);

    // Keep track of whose turn it is (BLACK goes first)
    int player = BLACK;

    // Main game loop
    while (!game_over(board))
    {
        // Print the board
        print_board(board);

        // Get the best move for the current player
        int r1, c1, r2, c2;
        get_best_move(board, player, &r1, &c1, &r2, &c2);

        // Make the move
        make_move(board, r1, c1, r2, c2);

        // Switch players
        player = (player == BLACK) ? WHITE : BLACK;
    }

    // Print the final board
    print_board(board);

    // Print the winner
    int black_pieces = count_pieces(board, BLACK);
    int white_pieces = count_pieces(board, WHITE);
    if (black_pieces > white_pieces)
    {
        printf("BLACK wins!\n");
    }
    else if (white_pieces > black_pieces)
    {
        printf("WHITE wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}

// Initialize the board with the starting position
// BLACK pieces go at the top, WHITE pieces go at the bottom
void initialize_board(char board[][SIZE])
{
    // Fill the board with EMPTY spaces
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            board[r][c] = EMPTY;
        }
    }

    // Add the WALL around the edges
    for (int r = 0; r < SIZE; r++)
    {
        board[0][r] = WALL;
        board[SIZE-1][r] = WALL;
        board[r][0] = WALL;
        board[r][SIZE-1] = WALL;
    }

    // Add the BLACK pieces
    for (int r = 1; r <= 3; r++)
    {
        for (int c = 1; c <= SIZE-2; c++)
        {
            if ((r+c) % 2 == 1)
            {
                board[r][c] = BLACK;
            }
        }
    }

    // Add the WHITE pieces
    for (int r = SIZE-4; r <= SIZE-2; r++)
    {
        for (int c = 1; c <= SIZE-2; c++)
        {
            if ((r+c) % 2 == 1)
            {
                board[r][c] = WHITE;
            }
        }
    }
}

// Print the board
void print_board(char board[][SIZE])
{
    printf("  ");
    for (int c = 1; c <= SIZE-2; c++)
    {
        printf("%d ", c);
    }
    printf("\n");

    for (int r = 1; r <= SIZE-2; r++)
    {
        printf("%d ", r);
        for (int c = 1; c <= SIZE-2; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("%d\n", r);
    }

    printf("  ");
    for (int c = 1; c <= SIZE-2; c++)
    {
        printf("%d ", c);
    }
    printf("\n");
}

// Check if a move is valid
bool valid_move(char board[][SIZE], int player, int r1, int c1, int r2, int c2)
{
    // Check that the destination is empty
    if (board[r2][c2] != EMPTY)
    {
        return false;
    }

    // Check that the source contains a piece of the correct color
    if (board[r1][c1] != player && board[r1][c1] != player+'K' )
    {
        return false;
    }

    // Check that the destination is a valid diagonal
    int dr = r2 - r1;
    int dc = c2 - c1;
    if (dr*dr != dc*dc || dr*dr != 1)
    {
        return false;
    }

    // Check for a jump
    if (abs(dr) == 2)
    {
        int jr = (r1 + r2) / 2;
        int jc = (c1 + c2) / 2;
        if (board[jr][jc] != (player == BLACK ? WHITE : BLACK) && board[jr][jc] != (player == BLACK ? WHITE+'K' : BLACK+'K'))
        {
            return false;
        }
    }

    return true;
}

// Make a move (and capture any pieces if necessary)
void make_move(char board[][SIZE], int r1, int c1, int r2, int c2)
{
    // Make the move
    board[r2][c2] = board[r1][c1];
    board[r1][c1] = EMPTY;

    // Check for a jump
    int dr = r2 - r1;
    int dc = c2 - c1;
    if (abs(dr) == 2)
    {
        int jr = (r1 + r2) / 2;
        int jc = (c1 + c2) / 2;
        board[jr][jc] = EMPTY;
    }

    // Check for a king
    if (board[r2][c2] == BLACK && r2 == 1)
    {
        board[r2][c2] = BLACK+'K';
    }
    else if (board[r2][c2] == WHITE && r2 == SIZE-2)
    {
        board[r2][c2] = WHITE+'K';
    }
}

// Check if a jump is available for the given player
bool jump_available(char board[][SIZE], int player)
{
    for (int r = 1; r <= SIZE-2; r++)
    {
        for (int c = 1; c <= SIZE-2; c++)
        {
            if (board[r][c] == player || board[r][c] == player+'K')
            {
                if (can_jump(board, player, r, c, 1, 1) || can_jump(board, player, r, c, 1, -1) ||
                    can_jump(board, player, r, c, -1, 1) || can_jump(board, player, r, c, -1, -1))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// Check if there is a jump available from the given square
bool can_jump(char board[][SIZE], int player, int r, int c, int dr, int dc)
{
    // Determine the coordinates of the square to potentially jump over
    int jr = r + dr;
    int jc = c + dc;

    // Check if the jump would be out of bounds
    if (jr < 1 || jr > SIZE-2 || jc < 1 || jc > SIZE-2)
    {
        return false;
    }

    // Check if the square to potentially jump over contains an opponent's piece
    if (board[jr][jc] != (player == BLACK ? WHITE : BLACK) && board[jr][jc] != (player == BLACK ? WHITE+'K' : BLACK+'K'))
    {
        return false;
    }

    // Determine the coordinates of the landing square
    int lr = r + 2*dr;
    int lc = c + 2*dc;

    // Check if the landing square is out of bounds
    if (lr < 1 || lr > SIZE-2 || lc < 1 || lc > SIZE-2)
    {
        return false;
    }

    // Check if the landing square is empty
    if (board[lr][lc] != EMPTY)
    {
        return false;
    }

    return true;
}

// Get the best move for the given player
void get_best_move(char board[][SIZE], int player, int *r1, int *c1, int *r2, int *c2)
{
    // If a jump is available, make that move
    if (jump_available(board, player))
    {
        for (int r = 1; r <= SIZE-2; r++)
        {
            for (int c = 1; c <= SIZE-2; c++)
            {
                if (board[r][c] == player || board[r][c] == player+'K')
                {
                    if (can_jump(board, player, r, c, 1, 1))
                    {
                        *r1 = r;
                        *c1 = c;
                        *r2 = r+2;
                        *c2 = c+2;
                        return;
                    }
                    else if (can_jump(board, player, r, c, 1, -1))
                    {
                        *r1 = r;
                        *c1 = c;
                        *r2 = r+2;
                        *c2 = c-2;
                        return;
                    }
                    else if (can_jump(board, player, r, c, -1, 1))
                    {
                        *r1 = r;
                        *c1 = c;
                        *r2 = r-2;
                        *c2 = c+2;
                        return;
                    }
                    else if (can_jump(board, player, r, c, -1, -1))
                    {
                        *r1 = r;
                        *c1 = c;
                        *r2 = r-2;
                        *c2 = c-2;
                        return;
                    }
                }
            }
        }
    }

    // Otherwise, make a random move
    while (true)
    {
        *r1 = rand() % (SIZE-2) + 1;
        *c1 = rand() % (SIZE-2) + 1;
        *r2 = rand() % (SIZE-2) + 1;
        *c2 = rand() % (SIZE-2) + 1;
        if (valid_move(board, player, *r1, *c1, *r2, *c2))
        {
            return;
        }
    }
}

// Check if the game is over
bool game_over(char board[][SIZE])
{
    // Check if either player has no pieces left
    if (count_pieces(board, BLACK) == 0 || count_pieces(board, WHITE) == 0)
    {
        return true;
    }

    // Check if either player can make a move
    if (!jump_available(board, BLACK) && !jump_available(board, WHITE))
    {
        return true;
    }

    return false;
}

// Count the number of pieces of the given type
int count_pieces(char board[][SIZE], char piece)
{
    int count = 0;
    for (int r = 1; r <= SIZE-2; r++)
    {
        for (int c = 1; c <= SIZE-2; c++)
        {
            if (board[r][c] == piece)
            {
                count++;
            }
        }
    }
    return count;
}