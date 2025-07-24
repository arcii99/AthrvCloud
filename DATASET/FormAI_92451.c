//FormAI DATASET v1.0 Category: Checkers Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

// Function prototype
void display_board(int board[ROWS][COLS]);
int is_valid_move(int board[ROWS][COLS], int player, int row1, int col1, int row2, int col2);
void make_move(int board[ROWS][COLS], int player, int row1, int col1, int row2, int col2);
int is_gameover(int board[ROWS][COLS], int player);

int main()
{
    int board[ROWS][COLS] = {
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0}
    };
    int player = 1;
    int row1, col1, row2, col2;
    
    // Game loop
    while (!is_gameover(board, player))
    {
        display_board(board);
        printf("Player %d's turn.\n", player);
        printf("Enter the coordinates of the piece you want to move: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the destination: ");
        scanf("%d %d", &row2, &col2);

        if (is_valid_move(board, player, row1, col1, row2, col2))
        {
            make_move(board, player, row1, col1, row2, col2);
            player = (player == 1) ? 2 : 1; // switch player
        }
        else
        {
            printf("Invalid move. Please try again.\n");
        }
    }
    display_board(board);
    printf("Game over. Player %d wins!\n", player);
    return 0;
}

// Function to display the checkers board
void display_board(int board[ROWS][COLS])
{
    printf("   _______________________________\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("  |   |   |   |   |   |   |   |   |\n");
        printf("%d |", i);
        for (int j = 0; j < COLS; j++)
        {
            printf(" %d |", board[i][j]);
        }
        printf(" %d\n", i);
        printf("  |___|___|___|___|___|___|___|___|\n");
    }
    printf("    0   1   2   3   4   5   6   7  \n");
}

// Function to check if a move is valid
int is_valid_move(int board[ROWS][COLS], int player, int row1, int col1, int row2, int col2)
{
    if (board[row2][col2] != 0) return 0; // destination must be empty
    if (row1 < 0 || row1 >= ROWS) return 0;
    if (col1 < 0 || col1 >= COLS) return 0;
    if (row2 < 0 || row2 >= ROWS) return 0;
    if (col2 < 0 || col2 >= COLS) return 0;
    if (board[row1][col1] != player && board[row1][col1] != player + 2) return 0; // player can only move its own pieces
    if (player == 1 && row2 > row1) return 0; // regular pieces of player 1 can only move up
    if (player == 2 && row2 < row1) return 0; // regular pieces of player 2 can only move down
    if (abs(row2 - row1) == 1 && abs(col2 - col1) == 1)
    {
        if (board[row1][col1] == 1 && board[row2][col2] == 2) return 1; // Player 1 can capture player 2's pieces
        if (board[row1][col1] == 2 && board[row2][col2] == 1) return 1; // Player 2 can capture player 1's pieces
        return 0; // if not capturing, move must be one space diagonal
    }

    // Check for possible jump moves
    int drow = (row2 - row1) / abs(row2 - row1);
    int dcol = (col2 - col1) / abs(col2 - col1);
    if (abs(row2 - row1) == 2 && abs(col2 - col1) == 2 && board[row1 + drow][col1 + dcol] != player && board[row1 + drow][col1 + dcol] != player + 2)
    {
        if (board[row1][col1] == 1 && board[row1 + drow][col1 + dcol] == 2) return 1; // Player 1 can jump over and capture player 2's pieces
        if (board[row1][col1] == 2 && board[row1 + drow][col1 + dcol] == 1) return 1; // Player 2 can jump over and capture player 1's pieces
    }
    return 0;
}

// Function to make a move on the checkers board
void make_move(int board[ROWS][COLS], int player, int row1, int col1, int row2, int col2)
{
    int drow = (row2 - row1) / abs(row2 - row1);
    int dcol = (col2 - col1) / abs(col2 - col1);
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = 0; // empty the starting position
    if (abs(row2 - row1) == 2 && abs(col2 - col1) == 2)
    {
        board[row1 + drow][col1 + dcol] = 0; // capture opponent's piece
    }
    if (player == 1 && row2 == ROWS - 1)
    {
        board[row2][col2] = 3; // player 1's piece becomes a king
    }
    if (player == 2 && row2 == 0)
    {
        board[row2][col2] = 4; // player 2's piece becomes a king
    }
}

// Function to check if the game is over
int is_gameover(int board[ROWS][COLS], int player)
{
    int pieces_left[5] = {0, 0, 0, 0, 0}; // index 0 unused, index 1-2 for player 1's pieces, index 3-4 for player 2's pieces
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == 1 || board[i][j] == 3) pieces_left[1]++;
            if (board[i][j] == 2 || board[i][j] == 4) pieces_left[2]++;
        }
    }
    if (pieces_left[1] == 0)
    {
        printf("Player 2 wins!\n");
        return 1;
    }
    else if (pieces_left[2] == 0)
    {
        printf("Player 1 wins!\n");
        return 1;
    }
    else
    {
        return 0;
    }
}