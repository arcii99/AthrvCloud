//FormAI DATASET v1.0 Category: Checkers Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Defining the pieces
#define EMPTY 0
#define RED 1
#define WHITE 2
#define KING_RED 3
#define KING_WHITE 4

// Board representation
int board[SIZE][SIZE];

// Function to initialize the board
void init_board() {
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if ((row + col) % 2 == 0) {
                if (row < 3)
                    board[row][col] = WHITE;
                else if (row > 4)
                    board[row][col] = RED;
                else
                    board[row][col] = EMPTY;
            } else {
                board[row][col] = EMPTY;
            }
        }
    }
}

// Function to print the board
void print_board() {
    int row, col;
    printf("   ");
    for (col = 0; col < SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for (row = 0; row < SIZE; row++) {
        printf("%d: ", row);
        for (col = 0; col < SIZE; col++) {
            switch (board[row][col]) {
                case EMPTY:
                    printf(". ");
                    break;
                case RED:
                    printf("r ");
                    break;
                case WHITE:
                    printf("w ");
                    break;
                case KING_RED:
                    printf("R ");
                    break;
                case KING_WHITE:
                    printf("W ");
                    break;
            }
        }
        printf("\n");
    }
}

// Function to move a piece
void move_piece(int start_row, int start_col, int end_row, int end_col) {
    int piece = board[start_row][start_col];
    board[start_row][start_col] = EMPTY;
    board[end_row][end_col] = piece;
}

// Function to check if a move is valid
int is_valid_move(int start_row, int start_col, int end_row, int end_col, int player) {
    // Make sure the end position is empty
    if (board[end_row][end_col] != EMPTY)
        return 0;

    // Check if the piece exists and is owned by the player
    int piece = board[start_row][start_col];
    if (piece == EMPTY || (player == RED && (piece == WHITE || piece == KING_WHITE)) || (player == WHITE && (piece == RED || piece == KING_RED)))
        return 0;

    // Check if a non-king piece moves backwards (unless it's a capture move)
    if (piece == RED && end_row > start_row && !is_capture_move(start_row, start_col, end_row, end_col))
        return 0;
    if (piece == WHITE && end_row < start_row && !is_capture_move(start_row, start_col, end_row, end_col))
        return 0;

    // Check if the move is a diagonal move
    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;
    if (abs(row_diff) != abs(col_diff))
        return 0;

    // Check if the move is a single or double diagonal move
    if (abs(row_diff) > 2)
        return 0;
    if (abs(row_diff) == 2 && !is_capture_move(start_row, start_col, end_row, end_col))
        return 0;

    // Check if the move is a valid capture move
    if (is_capture_move(start_row, start_col, end_row, end_col))
        return 1;

    // Check if the move is a valid non-capture move
    if (abs(row_diff) == 1 && abs(col_diff) == 1)
        return 1;

    // If none of the above conditions are met, the move is not valid
    return 0;
}

// Function to check if a move is a capture move
int is_capture_move(int start_row, int start_col, int end_row, int end_col) {
    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;
    int capture_row = start_row + row_diff / 2;
    int capture_col = start_col + col_diff / 2;
    if (abs(row_diff) == 2 && abs(col_diff) == 2 && board[capture_row][capture_col] != EMPTY && board[capture_row][capture_col] != board[start_row][start_col])
        return 1;
    return 0;
}

// Function to execute a move
int execute_move(int start_row, int start_col, int end_row, int end_col, int player) {
    if (!is_valid_move(start_row, start_col, end_row, end_col, player))
        return 0;
    move_piece(start_row, start_col, end_row, end_col);
    int piece = board[end_row][end_col];
    if (piece == RED && end_row == 0)
        board[end_row][end_col] = KING_RED;
    if (piece == WHITE && end_row == 7)
        board[end_row][end_col] = KING_WHITE;
    if (is_capture_move(start_row, start_col, end_row, end_col)) {
        int capture_row = start_row + (end_row - start_row) / 2;
        int capture_col = start_col + (end_col - start_col) / 2;
        board[capture_row][capture_col] = EMPTY;
        if (!has_capture_move(end_row, end_col))
            return 2;
    }
    return 1;
}

// Function to check if a player has a valid capture move
int has_capture_move(int row, int col) {
    int piece = board[row][col];
    if (piece == RED || piece == KING_RED) {
        if (row >= 2 && col >= 2 && is_valid_move(row, col, row - 2, col - 2, RED))
            return 1;
        if (row >= 2 && col <= 5 && is_valid_move(row, col, row - 2, col + 2, RED))
            return 1;
        if (piece == KING_RED) {
            if (row <= 5 && col >= 2 && is_valid_move(row, col, row + 2, col - 2, RED))
                return 1;
            if (row <= 5 && col <= 5 && is_valid_move(row, col, row + 2, col + 2, RED))
                return 1;
        }
    }
    if (piece == WHITE || piece == KING_WHITE) {
        if (row <= 5 && col >= 2 && is_valid_move(row, col, row + 2, col - 2, WHITE))
            return 1;
        if (row <= 5 && col <= 5 && is_valid_move(row, col, row + 2, col + 2, WHITE))
            return 1;
        if (piece == KING_WHITE) {
            if (row >= 2 && col >= 2 && is_valid_move(row, col, row - 2, col - 2, WHITE))
                return 1;
            if (row >= 2 && col <= 5 && is_valid_move(row, col, row - 2, col + 2, WHITE))
                return 1;
        }
    }
    return 0;
}

// Function to get the player's move
void get_move(int *start_row, int *start_col, int *end_row, int *end_col, int player) {
    printf("Player %d's turn\n", player);
    printf("Enter the starting row: ");
    scanf("%d", start_row);
    printf("Enter the starting column: ");
    scanf("%d", start_col);
    printf("Enter the ending row: ");
    scanf("%d", end_row);
    printf("Enter the ending column: ");
    scanf("%d", end_col);
}

int main() {
    // Initialize the board
    init_board();

    // Play the game
    int player = RED;
    int start_row, start_col, end_row, end_col;
    while (1) {
        // Print the board
        print_board();

        // Get the player's move
        get_move(&start_row, &start_col, &end_row, &end_col, player);

        // Execute the move
        int result = execute_move(start_row, start_col, end_row, end_col, player);

        // Check the result
        if (result == 0) {
            printf("Invalid move, try again.\n");
        } else if (result == 1) {
            // Switch turns
            player = (player == RED) ? WHITE : RED;
        } else if (result == 2) {
            // Check if the game is over
            int row, col;
            int red_pieces = 0, white_pieces = 0;
            for (row = 0; row < SIZE; row++) {
                for (col = 0; col < SIZE; col++) {
                    if (board[row][col] == RED || board[row][col] == KING_RED)
                        red_pieces++;
                    if (board[row][col] == WHITE || board[row][col] == KING_WHITE)
                        white_pieces++;
                }
            }
            if (red_pieces == 0 || white_pieces == 0) {
                printf("Game over! ");
                if (red_pieces == 0)
                    printf("White wins!\n");
                else
                    printf("Red wins!\n");
                break;
            }

            // Continue the current player's turn
            start_row = end_row;
            start_col = end_col;
        }
    }

    return 0;
}