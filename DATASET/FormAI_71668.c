//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ada Lovelace
#include <stdio.h>

#define BOARD_SIZE 8 // Here we define the board size using preprocessor directives
#define EMPTY 0
#define WHITE 1
#define BLACK 2

// Function to initialize the board with the initial checker positions
void initialize_board(int board[][BOARD_SIZE])
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if ((i + j) % 2 == 0 && i < 3)
            {
                board[i][j] = WHITE;
            }
            else if ((i + j) % 2 == 0 && i > 4)
            {
                board[i][j] = BLACK;
            }
            else
            {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Function to print the current state of the board
void print_board(int board[][BOARD_SIZE])
{
    int i, j;
    printf("  A B C D E F G H\n");
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                printf("- ");
            }
            else if (board[i][j] == WHITE)
            {
                printf("W ");
            }
            else if (board[i][j] == BLACK)
            {
                printf("B ");
            }
        }
        printf("%d\n", i + 1);
    }
    printf("  A B C D E F G H\n");
}

// Function to check if a given move is valid or not
int is_move_valid(int board[][BOARD_SIZE], int player, int row1, int col1, int row2, int col2)
{
    // Check if the destination is within the board
    if (row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE)
    {
        return 0;
    }

    // Check if the destination is empty
    if (board[row2][col2] != EMPTY)
    {
        return 0;
    }

    // Check if the player is moving their own piece
    if (board[row1][col1] != player && board[row1][col1] != player + 2)
    {
        return 0;
    }

    // If the piece is a regular piece
    if (board[row1][col1] == player)
    {
        // Check if the move is diagonal
        if (abs(row2 - row1) != 1 || abs(col2 - col1) != 1)
        {
            return 0;
        }

        // Check if the move is forward (for white) or backward (for black)
        if ((row2 - row1) * player < 0)
        {
            return 0;
        }
    }

    // If the piece is a king
    if (board[row1][col1] == player + 2)
    {
        // Check if the move is diagonal
        if (abs(row2 - row1) != abs(col2 - col1))
        {
            return 0;
        }

        // Check if the destination is reachable
        int i, j;
        for (i = row1 + (row2 - row1) / abs(row2 - row1), j = col1 + (col2 - col1) / abs(col2 - col1); i != row2; i += (row2 - row1) / abs(row2 - row1), j += (col2 - col1) / abs(col2 - col1))
        {
            if (board[i][j] != EMPTY)
            {
                return 0;
            }
        }
    }

    return 1;
}

// Function to make a move
void make_move(int board[][BOARD_SIZE], int player, int row1, int col1, int row2, int col2)
{
    // Make the move
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = EMPTY;

    // Check if the piece has become a king
    if (row2 == 0 && board[row2][col2] == WHITE)
    {
        board[row2][col2] = WHITE + 2;
    }
    if (row2 == BOARD_SIZE - 1 && board[row2][col2] == BLACK)
    {
        board[row2][col2] = BLACK + 2;
    }
}

// Function to check if a player has won
int has_won(int board[][BOARD_SIZE], int player)
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {

            if (board[i][j] == 3 - player || board[i][j] == 3 - player + 2)
            {
                // Check if this piece has any legal moves left
                if (is_move_valid(board, player, i, j, i + 1, j + 1) || is_move_valid(board, player, i, j, i + 1, j - 1) || is_move_valid(board, player, i, j, i - 1, j + 1) || is_move_valid(board, player, i, j, i - 1, j - 1) || is_move_valid(board, player, i, j, i + 2, j + 2) || is_move_valid(board, player, i, j, i + 2, j - 2) || is_move_valid(board, player, i, j, i - 2, j + 2) || is_move_valid(board, player, i, j, i - 2, j - 2))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int player = WHITE;
    int row1, col1, row2, col2;

    initialize_board(board);

    while (!has_won(board, player))
    {
        printf("\n---------\n");
        print_board(board);
        printf("Player %d's turn\n", player);
        printf("Enter the coordinates of the checker you want to move (row column): ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the destination (row column): ");
        scanf("%d %d", &row2, &col2);

        if (is_move_valid(board, player, row1 - 1, col1 - 1, row2 - 1, col2 - 1))
        {
            make_move(board, player, row1 - 1, col1 - 1, row2 - 1, col2 - 1);
            player = 3 - player;
        }
        else
        {
            printf("Error: Invalid move\n");
        }
    }

    printf("\n---------\n");
    print_board(board);
    printf("Player %d wins!\n", player);

    return 0;
}