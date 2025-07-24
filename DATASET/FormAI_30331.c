//FormAI DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void init_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize the board with empty cells    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    
    // Place the pieces on the board according to the rules of Checkers
    for (int i = 0; i < BOARD_SIZE / 2 - 1; i++) {
        for (int j = (i % 2 == 0) ? 1 : 0; j < BOARD_SIZE; j += 2) {
            board[i][j] = 1; // Player 1's pieces
            board[BOARD_SIZE - i - 1][j - 1] = 2; // Player 2's pieces
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Print the board to the console
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf(" -");
            } else if (board[i][j] == 1) {
                printf(" O");
            } else if (board[i][j] == 2) {
                printf(" X");
            } else if (board[i][j] == 3) {
                printf(" K");
            }
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
}

int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int row, int col, int new_row, int new_col) {
    // Check if the move is valid according to the rules of Checkers
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        return 0; // The move is out of bounds
    }
    if (board[new_row][new_col] != 0) {
        return 0; // The destination cell is already occupied
    }
    if (player == 1) {
        if (board[row][col] == 1 && new_row > row) {
            return 0; // Regular pieces can only move forward
        }
        if (board[row][col] == 2) {
            if (new_row < row) {
                return 0; // Kings can move backwards, but cannot do regular moves
            }
            if (abs(new_row - row) == 1 && abs(new_col - col) == 1) {
                return 0; // Kings cannot do regular moves, only jumps
            }
        }
    }
    if (player == 2) {
        if (board[row][col] == 2 && new_row < row) {
            return 0; // Regular pieces can only move forward
        }
        if (board[row][col] == 1) {
            if (new_row > row) {
                return 0; // Kings can move backwards, but cannot do regular moves
            }
            if (abs(new_row - row) == 1 && abs(new_col - col) == 1) {
                return 0; // Kings cannot do regular moves, only jumps
            }
        }
    }
    if (abs(new_row - row) == 1 && abs(new_col - col) == 1) {
        return 1; // Regular move
    }
    if (abs(new_row - row) == 2 && abs(new_col - col) == 2) {
        if (board[(new_row + row) / 2][(new_col + col) / 2] == 0) {
            return 0; // There must be an opponent's piece in between to do a jump
        }
        if ((player == 1 && board[(new_row + row) / 2][(new_col + col) / 2] == 2) ||
            (player == 2 && board[(new_row + row) / 2][(new_col + col) / 2] == 1)) {
            return 1; // The jump is valid
        }
    }
    return 0; // The move is not valid
}

int has_valid_moves(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    // Check if the player has any valid moves left
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (player == 1 && (board[i][j] == 1 || board[i][j] == 3)) {
                if (is_valid_move(board, player, i, j, i + 1, j - 1) ||
                    is_valid_move(board, player, i, j, i + 1, j + 1) ||
                    is_valid_move(board, player, i, j, i + 2, j - 2) ||
                    is_valid_move(board, player, i, j, i + 2, j + 2)) {
                    return 1;
                }
            }
            if (player == 2 && (board[i][j] == 2 || board[i][j] == 3)) {
                if (is_valid_move(board, player, i, j, i - 1, j - 1) ||
                    is_valid_move(board, player, i, j, i - 1, j + 1) ||
                    is_valid_move(board, player, i, j, i - 2, j - 2) ||
                    is_valid_move(board, player, i, j, i - 2, j + 2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int do_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int row, int col, int new_row, int new_col) {
    // Execute the move and return the result
    if (!is_valid_move(board, player, row, col, new_row, new_col)) {
        return -1; // Invalid move
    }
    board[new_row][new_col] = board[row][col];
    board[row][col] = 0;
    if (abs(new_row - row) == 2 && abs(new_col - col) == 2) {
        // The move is a jump, remove the opponent's piece
        board[(new_row + row) / 2][(new_col + col) / 2] = 0;
    }
    if (player == 1 && new_row == BOARD_SIZE - 1) {
        // The piece has reached the opposite end, promote to king
        board[new_row][new_col] = 3;
    }
    if (player == 2 && new_row == 0) {
        // The piece has reached the opposite end, promote to king
        board[new_row][new_col] = 3;
    }
    return 0; // Success
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    int player = 1;
    int game_over = 0;
    printf("Welcome to the Checkers game! Player 1 uses O and player 2 uses X.\n");
    print_board(board);
    while (!game_over) {
        int row, col, new_row, new_col;
        printf("Player %d's turn. Please enter your move: ", player);
        scanf("%c%d %c%d", &col, &row, &new_col, &new_row);
        row = BOARD_SIZE - row; // Adjust to zero-based index
        new_row = BOARD_SIZE - new_row; // Adjust to zero-based index
        col -= 'A'; // Adjust to zero-based index
        new_col -= 'A'; // Adjust to zero-based index
        if (do_move(board, player, row, col, new_row, new_col) == -1) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (has_valid_moves(board, player == 1 ? 2 : 1)) {
            player = player == 1 ? 2 : 1; // Switch to the other player
        } else {
            printf("Player %d has no valid moves left. Player %d wins!\n", player, player == 1 ? 2 : 1);
            game_over = 1;
        }
        print_board(board);
    }
    return 0;
}