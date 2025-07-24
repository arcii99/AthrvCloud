//FormAI DATASET v1.0 Category: Checkers Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Checker color codes
#define EMPTY 0
#define WHITE 1
#define BLACK 2

// Define the board and initialize it
int board[BOARD_SIZE][BOARD_SIZE] = {
    { 0, 2, 0, 2, 0, 2, 0, 2 },
    { 2, 0, 2, 0, 2, 0, 2, 0 },
    { 0, 2, 0, 2, 0, 2, 0, 2 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 1, 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 0, 1, 0 },
};

// Function to print the board
void print_board() {
    printf("\n   0  1  2  3  4  5  6  7");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(" - ");
            }
            else if (board[i][j] == WHITE) {
                printf(" W ");
            }
            else if (board[i][j] == BLACK) {
                printf(" B ");
            }
        }
    }
    printf("\n");
}

// Function to get the input from the user
void get_input(int* row, int* col) {
    printf("\nEnter the location of the piece to move (row, col): ");
    scanf("%d %d", row, col);
}

// Function to check if the move is valid
int is_valid_move(int row, int col, int color, int direction) {
    // Check if the piece exists and belongs to the player
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE 
        || board[row][col] != color) {
        return 0;
    }

    // Check if the move is diagonal and one or two steps
    int row_diff = direction * (row - (row - direction));
    int col_diff = col - (col - direction);
    if (row_diff != 1 && row_diff != 2) {
        return 0;
    }
    if (col_diff != 1 && col_diff != 2) {
        return 0;
    }

    // Check if the target location is empty
    int target_row = row + row_diff;
    int target_col = col + col_diff;
    if (target_row < 0 || target_row >= BOARD_SIZE || target_col < 0 
        || target_col >= BOARD_SIZE || board[target_row][target_col] != EMPTY) {
        return 0;
    }

    // Check if a jump is being made
    if (row_diff == 2 || col_diff == 2) {
        int captured_row = row + (row_diff / 2);
        int captured_col = col + (col_diff / 2);
        if (board[captured_row][captured_col] == EMPTY 
            || board[captured_row][captured_col] == color) {
            return 0;
        }
    }

    return 1;
}

// Function to make the move
void make_move(int row, int col, int color, int direction) {
    int row_diff = direction * (row - (row - direction));
    int col_diff = col - (col - direction);
    int target_row = row + row_diff;
    int target_col = col + col_diff;

    // Move the piece to the target location
    board[target_row][target_col] = color;
    board[row][col] = EMPTY;

    // Remove the captured piece if a jump was made
    if (row_diff == 2 || col_diff == 2) {
        int captured_row = row + (row_diff / 2);
        int captured_col = col + (col_diff / 2);
        board[captured_row][captured_col] = EMPTY;
    }
}

// Function to check if a player has won
int has_won(int color) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == color) {
                int row_diff = color == WHITE ? 1 : -1;
                if (is_valid_move(i, j, color, row_diff)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Main function
int main() {
    int current_player = WHITE;
    int game_over = 0;
    
    while (!game_over) {
        // Print the board and get input from the user
        print_board();
        int row, col;
        get_input(&row, &col);
        
        // Check if the move is valid and make the move
        int direction = current_player == WHITE ? 1 : -1;
        if (is_valid_move(row, col, current_player, direction)) {
            make_move(row, col, current_player, direction);
            // Check if the player has won
            if (has_won(current_player)) {
                print_board();
                printf("\nCongratulations! Player %d won!\n", current_player);
                game_over = 1;
            }
            // Switch to the other player
            current_player = current_player == WHITE ? BLACK : WHITE;
        }
        else {
            printf("\nInvalid move. Please try again.\n");
        }
    }
    return 0;
}