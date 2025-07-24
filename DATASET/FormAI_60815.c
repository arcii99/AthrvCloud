//FormAI DATASET v1.0 Category: Checkers Game ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Game board represented by a 2D array
char board[BOARD_SIZE][BOARD_SIZE] = {
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'},
    {'_', 'w', '_', 'w', '_', 'w', '_', 'w'},
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'}
};

// Check if a move from (r1, c1) to (r2, c2) is valid
bool is_valid_move(int r1, int c1, int r2, int c2, char player) {
    // Check if move is within board bounds
    if (r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE) {
        return false;
    }

    // Check if destination square is empty
    if (board[r2][c2] != '_') {
        return false;
    }

    // Check if move is diagonal
    int row_diff = r2 - r1;
    int col_diff = c2 - c1;
    if (row_diff != col_diff && row_diff != -col_diff) {
        return false;
    }

    // Check if move direction is correct based on player's turn
    if ((player == 'b' && row_diff > 0) || (player == 'w' && row_diff < 0)) {
        return false;
    }

    // Check if move is a capture move
    if (row_diff == 2 || row_diff == -2) {
        int capture_row = r1 + (row_diff / 2);
        int capture_col = c1 + (col_diff / 2);
        if (board[capture_row][capture_col] != (player == 'b' ? 'w' : 'b')) {
            return false;
        }
    }

    return true;
}

// Print the current state of the game board
void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to Checkers!\n");
    printf("Player 1 (Black) goes first\n");
    char player1 = 'b';
    char player2 = 'w';
    char current_player = player1;

    bool game_over = false;
    while (!game_over) {
        // Print current state of board
        print_board();

        // Get move from current player
        int from_r, from_c, to_r, to_c;
        printf("%c's turn\n", current_player);
        printf("Enter move (from_row from_col to_row to_col): ");
        scanf("%d %d %d %d", &from_r, &from_c, &to_r, &to_c);

        // Check if move is valid and make the move if so
        if (is_valid_move(from_r, from_c, to_r, to_c, current_player)) {
            board[to_r][to_c] = current_player;
            board[from_r][from_c] = '_';

            // Check if move was a capture move
            int capture_row = from_r + ((to_r - from_r) / 2);
            int capture_col = from_c + ((to_c - from_c) / 2);
            if (to_r - from_r == 2 || to_r - from_r == -2) {
                board[capture_row][capture_col] = '_';
            }

            // Switch player turn
            current_player = (current_player == player1 ? player2 : player1);

            // Check if current player has won
            bool has_won = true;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == current_player || board[i][j] == (current_player == player1 ? 'W' : 'B')) {
                        if (j < BOARD_SIZE - 1 && i < BOARD_SIZE - 1) {
                            if (board[i+1][j+1] == '_') {
                                has_won = false;
                            } else if (board[i+1][j+1] == (current_player == player1 ? 'w' : 'b') || board[i+1][j+1] == (current_player == player1 ? 'W' : 'B')) {
                                if (board[i+2][j+2] == '_') {
                                    has_won = false;
                                }
                            }
                        }
                        if (j > 0 && i < BOARD_SIZE - 1) {
                            if (board[i+1][j-1] == '_') {
                                has_won = false;
                            } else if (board[i+1][j-1] == (current_player == player1 ? 'w' : 'b') || board[i+1][j-1] == (current_player == player1 ? 'W' : 'B')) {
                                if (board[i+2][j-2] == '_') {
                                    has_won = false;
                                }
                            }
                        }
                        if (j < BOARD_SIZE - 1 && i > 0) {
                            if (board[i-1][j+1] == '_') {
                                has_won = false;
                            } else if (board[i-1][j+1] == (current_player == player1 ? 'w' : 'b') || board[i-1][j+1] == (current_player == player1 ? 'W' : 'B')) {
                                if (board[i-2][j+2] == '_') {
                                    has_won = false;
                                }
                            }
                        }
                        if (j > 0 && i > 0) {
                            if (board[i-1][j-1] == '_') {
                                has_won = false;
                            } else if (board[i-1][j-1] == (current_player == player1 ? 'w' : 'b') || board[i-1][j-1] == (current_player == player1 ? 'W' : 'B')) {
                                if (board[i-2][j-2] == '_') {
                                    has_won = false;
                                }
                            }
                        }
                    }
                }
            }
            if (has_won) {
                printf("%c has won the game!\n", current_player);
                game_over = true;
            }
        } else {
            printf("Invalid move, please try again.\n");
        }
    }

    return 0;
}