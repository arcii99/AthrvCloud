//FormAI DATASET v1.0 Category: Checkers Game ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Set up the initial state of the board
void setup_board() {
    // Set all squares to empty
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Set up the red pieces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = 'r';
            }
        }
    }

    // Set up the black pieces
    for (int i = 5; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = 'b';
            }
        }
    }
}

// Print the current state of the board
void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("%d\n", i);
        printf(" +----------------+\n");
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

// Check whether a move is valid
bool is_move_valid(int start_row, int start_col, int end_row, int end_col, char player) {
    // Check that start and end squares are within the bounds of the board
    if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE ||
        end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return false;
    }

    // Check that end square is empty
    if (board[end_row][end_col] != ' ') {
        return false;
    }

    // Check that player is moving their own piece
    if (board[start_row][start_col] != player) {
        return false;
    }

    // Check that player is moving diagonally
    if (start_row == end_row || start_col == end_col) {
        return false;
    }

    // Check that player is moving only one space forwards or backwards
    if ((player == 'r' && end_row > start_row) || (player == 'b' && end_row < start_row)) {
        return false;
    }

    // Check that player is moving only one space diagonally (or two if taking a piece)
    if (end_row - start_row != 1 && end_row - start_row != -1) {
        return false;
    }
    if (end_col - start_col != 1 && end_col - start_col != -1) {
        return false;
    }

    // Check that player is not moving to a non-diagonal square
    if (end_row - start_row == end_col - start_col) {
        return false;
    }

    // Check that player is not moving more than two spaces diagonally when taking a piece
    if (board[(start_row + end_row) / 2][(start_col + end_col) / 2] != ' ' &&
        (end_row - start_row != 2 && end_row - start_row != -2) &&
        (end_col - start_col != 2 && end_col - start_col != -2)) {
        return false;
    }

    return true;
}

// Make a move
void make_move(int start_row, int start_col, int end_row, int end_col, char player) {
    // Move the piece
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = ' ';

    // If taking a piece, remove it from the board
    if (end_row - start_row == 2) {
        board[(start_row + end_row) / 2][(start_col + end_col) / 2] = ' ';
    }
}

int main() {
    // Set up the board and print the initial state
    setup_board();
    print_board();

    // Main game loop
    char current_player = 'r';
    while (true) {
        // Get the player's move
        int start_row, start_col, end_row, end_col;
        printf("%c's turn. Enter your move (start row, start col, end row, end col): ", current_player);
        scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);

        // Check if the move is valid
        if (is_move_valid(start_row, start_col, end_row, end_col, current_player)) {
            // Make the move and print the updated board
            make_move(start_row, start_col, end_row, end_col, current_player);
            print_board();

            // Check for a win
            bool red_wins = true;
            bool black_wins = true;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == 'b' || board[i][j] == 'B') {
                        red_wins = false;
                    }
                    if (board[i][j] == 'r' || board[i][j] == 'R') {
                        black_wins = false;
                    }
                }
            }
            if (red_wins) {
                printf("Red wins!\n");
                break;
            }
            if (black_wins) {
                printf("Black wins!\n");
                break;
            }

            // Switch to the other player's turn
            if (current_player == 'r') {
                current_player = 'b';
            } else {
                current_player = 'r';
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}