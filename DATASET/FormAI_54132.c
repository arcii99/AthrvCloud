//FormAI DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>

// Defining constants for the board size and the pieces
#define BOARD_SIZE 8
#define EMPTY 0
#define WHITE 1
#define BLACK 2
#define WHITE_KING 3
#define BLACK_KING 4

// Defining the board
int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {3, 0, 3, 0, 3, 0, 3, 0},
    {0, 3, 0, 3, 0, 3, 0, 3},
    {3, 0, 3, 0, 3, 0, 3, 0}
};

// Defining function to print the board
void print_board() {
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case WHITE:
                    printf("W ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case WHITE_KING:
                    printf("KW");
                    break;
                case BLACK_KING:
                    printf("KB");
                    break;
            }
        }
        printf("\n");
    }
}

// Defining function to check if the move is valid
int is_valid_move(int player, int start_row, int start_col, int end_row, int end_col) {
    // Checking if the start position is empty or out of bounds
    if (board[start_row][start_col] == EMPTY || start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE) {
        return 0;
    }
    // Checking if the end position is empty or out of bounds
    if (board[end_row][end_col] != EMPTY || end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return 0;
    }
    // Checking if the move is diagonal and of length 1 or 2
    if (abs(end_row - start_row) == 1 && abs(end_col - start_col) == 1 && board[start_row][start_col] != player && board[start_row][start_col] != player + 2) {
        return 0;
    }
    if (abs(end_row - start_row) == 2 && abs(end_col - start_col) == 2) {
        int jumped_row = (start_row + end_row) / 2;
        int jumped_col = (start_col + end_col) / 2;
        if (board[jumped_row][jumped_col] != player && board[jumped_row][jumped_col] != player + 2) {
            return 0;
        }
    }
    // Checking if the current player is moving their own piece
    if (board[start_row][start_col] != player && board[start_row][start_col] != player + 2) {
        return 0;
    }
    // Checking if the move is a capture move
    if (abs(end_row - start_row) == 2 && abs(end_col - start_col) == 2) {
        int jumped_row = (start_row + end_row) / 2;
        int jumped_col = (start_col + end_col) / 2;
        // Removing the captured piece from the board
        board[jumped_row][jumped_col] = EMPTY;
    }
    // Checking if the move is a promotion move
    if (player == WHITE && end_row == 0 && board[start_row][start_col] == WHITE) {
        board[end_row][end_col] = WHITE_KING;
    } else if (player == BLACK && end_row == 7 && board[start_row][start_col] == BLACK) {
        board[end_row][end_col] = BLACK_KING;
    } else {
        board[end_row][end_col] = board[start_row][start_col];
    }
    board[start_row][start_col] = EMPTY;
    return 1;
}

// Defining the main function
int main() {
    int player = WHITE;
    while (1) {
        // Printing the board and prompting for input
        print_board();
        printf("Player %d, enter your move (start row, start col, end row, end col): ", player);
        int start_row, start_col, end_row, end_col;
        scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);
        // Making the move if valid
        if (is_valid_move(player, start_row, start_col, end_row, end_col)) {
            // Print a message if the current player has won
            int has_won = 1;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == BLACK || board[i][j] == BLACK_KING) {
                        has_won = 0;
                    }
                }
            }
            if (has_won) {
                printf("Player %d has won!", player);
                break;
            }
            // Switching to the other player
            player = (player == WHITE) ? BLACK : WHITE;
        } else {
            printf("Invalid move!\n");
        }
    }
    return 0;
}