//FormAI DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Function prototypes
void init_board(char board[][BOARD_SIZE]);
void print_board(const char board[][BOARD_SIZE]);
bool is_valid_move(const char board[][BOARD_SIZE], char player, int start_row, int start_col, int end_row, int end_col);
void make_move(char board[][BOARD_SIZE], char player, int start_row, int start_col, int end_row, int end_col);
bool has_valid_moves(const char board[][BOARD_SIZE], char player);

// Main function
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];

    // Initialize board
    init_board(board);

    // Game loop
    char current_player = 'X';
    while (true) {
        // Print board
        printf("Board:\n");
        print_board(board);

        // Check if current player has valid moves
        if (!has_valid_moves(board, current_player)) {
            printf("%c has no valid moves. Game over!\n", current_player);
            break;
        }

        // Prompt player for move
        int start_row, start_col, end_row, end_col;
        while (true) {
            printf("%c's turn. Enter start row, start col, end row, end col: ", current_player);
            scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);

            if (is_valid_move(board, current_player, start_row, start_col, end_row, end_col)) {
                break;
            }

            printf("Invalid move! Try again.\n");
        }

        // Make move
        make_move(board, current_player, start_row, start_col, end_row, end_col);

        // Switch player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Function implementations

void init_board(char board[][BOARD_SIZE]) {
    // Initialize all squares to empty
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = ' ';
        }
    }

    // Set starting positions for X
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1) {
                board[row][col] = 'X';
            }
        }
    }

    // Set starting positions for O
    for (int row = BOARD_SIZE - 3; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1) {
                board[row][col] = 'O';
            }
        }
    }
}

void print_board(const char board[][BOARD_SIZE]) {
    // Print column labels
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");

    // Print row labels and board contents
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

bool is_valid_move(const char board[][BOARD_SIZE], char player, int start_row, int start_col, int end_row, int end_col) {
    // Check if end position is empty
    if (board[end_row][end_col] != ' ') {
        return false;
    }

    // Check if start position contains a piece belonging to player
    if (board[start_row][start_col] != player) {
        return false;
    }

    // Check if move is diagonal
    int row_diff = abs(end_row - start_row);
    int col_diff = abs(end_col - start_col);
    if (row_diff != col_diff) {
        return false;
    }

    // Check if move is valid for assigned player
    int row_increment = (end_row > start_row) ? 1 : -1;
    int col_increment = (end_col > start_col) ? 1 : -1;

    if (row_diff == 1) { // Single move
        if (player == 'X' && end_row < start_row) { // X can only move forward
            return false;
        }
        if (player == 'O' && end_row > start_row) { // O can only move backward
            return false;
        }
    } else { // Capture move (jump over opponent's piece)
        if (board[(start_row+end_row)/2][(start_col+end_col)/2] == ' ') { // No opponent's piece to capture
            return false;
        }
        if (board[(start_row+end_row)/2][(start_col+end_col)/2] == player) { // Cannot capture own piece
            return false;
        }
    }

    return true;
}

void make_move(char board[][BOARD_SIZE], char player, int start_row, int start_col, int end_row, int end_col) {
    // Remove piece from starting position
    board[start_row][start_col] = ' ';

    // Place piece at end position
    board[end_row][end_col] = player;

    // Capture opponent's piece (if applicable)
    if (abs(end_row - start_row) == 2) {
        board[(start_row+end_row)/2][(start_col+end_col)/2] = ' ';
    }
}

bool has_valid_moves(const char board[][BOARD_SIZE], char player) {
    // Check each square for player's pieces
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == player) {

                // Check each possible move for player's piece
                for (int row_offset = -2; row_offset <= 2; row_offset++) {
                    for (int col_offset = -2; col_offset <= 2; col_offset++) {
                        int end_row = row + row_offset;
                        int end_col = col + col_offset;

                        if (is_valid_move(board, player, row, col, end_row, end_col)) {
                            return true;
                        }

                    }
                }

            }
        }
    }

    return false;
}