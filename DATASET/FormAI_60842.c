//FormAI DATASET v1.0 Category: Checkers Game ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Board size
#define SIZE 8

// Player pieces
#define EMPTY 0
#define BLACK 1
#define WHITE 2

// Recursive function to find available moves for current player
void find_moves(int board[SIZE][SIZE], int player, int row, int col, int dir_row, int dir_col, int *moves)
{
    int new_row = row + dir_row;
    int new_col = col + dir_col;

    // Check if the new position is out of bounds
    if (new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE) {
        return;
    }

    // Check if the new position is occupied by an opponent's piece
    if (board[new_row][new_col] == EMPTY) {
        // Check if there is a jump available after this move
        if (*moves == 0) {
            find_moves(board, player, new_row, new_col, dir_row, dir_col, moves);
        }
        return;
    }

    // Check if the new position is occupied by the current player's piece or if the next position is out of bounds
    if (board[new_row][new_col] == player || new_row + dir_row < 0 || new_row + dir_row >= SIZE || new_col + dir_col < 0 || new_col + dir_col >= SIZE) {
        return;
    }

    // Check if the next position in the same direction is empty
    if (board[new_row + dir_row][new_col + dir_col] == EMPTY) {
        // Add the move to available moves list
        *(moves++) = new_row * 10 + new_col;
        // Recursively check for more jumps
        find_moves(board, player, new_row + dir_row, new_col + dir_col, dir_row, dir_col, moves);
    }
}

// Function to check available moves for current player
void available_moves(int board[SIZE][SIZE], int player, int moves[SIZE*SIZE][2])
{
    int i, j, count = 0;

    // Loop through each position on the board
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            // Check if the current position is occupied by the current player's piece
            if (board[i][j] == player) {
                // Check for available moves in all directions
                int temp_moves[SIZE * SIZE][2];
                int *m = temp_moves;
                find_moves(board, player, i, j, 1, 1, m);
                find_moves(board, player, i, j, 1, -1, m);
                find_moves(board, player, i, j, -1, 1, m);
                find_moves(board, player, i, j, -1, -1, m);

                // Add the available moves to the list
                while (m != temp_moves) {
                    m--;
                    moves[count][0] = *m / 10;
                    moves[count][1] = *m % 10;
                    count++;
                }
            }
        }
    }

    // If there are no available moves, add a dummy move
    if (count == 0) {
        moves[count][0] = -1;
        moves[count][1] = -1;
        count++;
    }

    // Add a terminating move
    moves[count][0] = -2;
    moves[count][1] = -2;
}

// Function to apply move to board
void apply_move(int board[SIZE][SIZE], int move[2])
{
    int row = move[0];
    int col = move[1];
    board[row][col] = board[row][col] == WHITE ? BLACK : WHITE;
}

// Recursive function to check if a player has won
int check_win(int board[SIZE][SIZE], int row, int col, int dir_row, int dir_col, int count, int player)
{
    if (count == 4) {
        return 1;
    }

    int new_row = row + dir_row;
    int new_col = col + dir_col;

    if (new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE) {
        return 0;
    }

    if (board[new_row][new_col] != player) {
        return 0;
    }

    return check_win(board, new_row, new_col, dir_row, dir_col, count + 1, player);
}

// Function to check for a win
int check_board(int board[SIZE][SIZE], int player)
{
    int i, j;

    // Loop through each position on the board
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            // Check if the current position is occupied by the current player's piece
            if (board[i][j] == player) {
                // Check for a win in all directions
                if (check_win(board, i, j, 1, 1, 1, player) || check_win(board, i, j, 1, -1, 1, player) ||
                    check_win(board, i, j, -1, 1, 1, player) || check_win(board, i, j, -1, -1, 1, player)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// Function to print the board
void print_board(int board[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            switch (board[i][j]) {
            case BLACK:
                printf(" B ");
                break;
            case WHITE:
                printf(" W ");
                break;
            default:
                printf(" . ");
                break;
            }
        }
        printf("\n");
    }
}

int main()
{
    // Initialize board
    int board[SIZE][SIZE] = {
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0}
    };

    int player = WHITE;
    int moves[SIZE*SIZE][2];

    while (1) {
        printf("\nCurrent board:\n");
        print_board(board);

        // Check for a win
        if (check_board(board, player)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        // Check for available moves
        available_moves(board, player, moves);
        printf("\nAvailable moves for player %d:\n", player);
        int i = 0;
        while (moves[i][0] >= 0) {
            printf("%d. (%d,%d)\n", i+1, moves[i][0], moves[i][1]);
            i++;
        }

        // Get move from user
        int choice;
        do {
            printf("Enter your choice: ");
            scanf("%d", &choice);
        } while (moves[choice-1][0] < 0);

        // Apply move to board
        apply_move(board, moves[choice-1]);

        // Switch player
        player = player == WHITE ? BLACK : WHITE;
    }

    return 0;
}