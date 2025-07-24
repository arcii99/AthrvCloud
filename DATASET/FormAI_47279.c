//FormAI DATASET v1.0 Category: Checkers Game ; Style: light-weight
#include <stdio.h>

// Constants
#define BOARD_SIZE 8
#define PLAYER_1 1
#define PLAYER_2 2
#define EMPTY 0
#define PLAYER_1_TOKEN 'O'
#define PLAYER_1_KING 'K'
#define PLAYER_2_TOKEN 'X'
#define PLAYER_2_KING 'Q'

// Function prototypes
void init_board(int board[][BOARD_SIZE]);
void display_board(int board[][BOARD_SIZE]);
void move_piece(int board[][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col);
int is_valid_move(int board[][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col);
int player_has_valid_move(int board[][BOARD_SIZE], int player);
int is_capture_move(int board[][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col);
int can_capture(int board[][BOARD_SIZE], int player, int row, int col);
void capture_piece(int board[][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col);
int check_win(int board[][BOARD_SIZE]);
int count_pieces(int board[][BOARD_SIZE], int player);

// Function to initialize the board
void init_board(int board[][BOARD_SIZE]) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = PLAYER_2_TOKEN;
                } else if (i > 4) {
                    board[i][j] = PLAYER_1_TOKEN;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Function to display the board
void display_board(int board[][BOARD_SIZE]) {
    int i, j;

    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %d  ", i + 1);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("  +");
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("---+");
        }
        printf("\n");

        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }

    printf("  +");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("---+");
    }
    printf("\n");
}

// Function to move a piece
void move_piece(int board[][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;

    // Check if the piece has become a king
    if (player == PLAYER_1 && to_row == 0) {
        board[to_row][to_col] = PLAYER_1_KING;
    } else if (player == PLAYER_2 && to_row == BOARD_SIZE - 1) {
        board[to_row][to_col] = PLAYER_2_KING;
    }
}

// Function to check if a move is valid
int is_valid_move(int board[][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col) {
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;

    // Check if destination is within the board
    if (to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) {
        return 0;
    }

    // Check if the destination is empty
    if (board[to_row][to_col] != EMPTY) {
        return 0;
    }

    // If the piece is not a king
    if (board[from_row][from_col] == PLAYER_1_TOKEN) {
        // Check if move is in the correct direction
        if (row_diff != -1 || (col_diff != -1 && col_diff != 1)) {
            return 0;
        }
    } else if (board[from_row][from_col] == PLAYER_2_TOKEN) {
        // Check if move is in the correct direction
        if (row_diff != 1 || (col_diff != -1 && col_diff != 1)) {
            return 0;
        }
    } else if (board[from_row][from_col] == PLAYER_1_KING || board[from_row][from_col] == PLAYER_2_KING) {
        // If the piece is a king, then it can move in any direction
        if (row_diff == 0 || col_diff == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to check if a player has any valid move
int player_has_valid_move(int board[][BOARD_SIZE], int player) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == PLAYER_1_TOKEN || board[i][j] == PLAYER_1_KING) {
                if (player == PLAYER_1 && can_capture(board, PLAYER_1, i, j)) {
                    return 1;
                } else if (player == PLAYER_2 && is_valid_move(board, PLAYER_2, i, j, i - 1, j - 1)
                            || is_valid_move(board, PLAYER_2, i, j, i - 1, j + 1)) {
                    return 1;
                }
            } else if (board[i][j] == PLAYER_2_TOKEN || board[i][j] == PLAYER_2_KING) {
                if (player == PLAYER_2 && can_capture(board, PLAYER_2, i, j)) {
                    return 1;
                } else if (player == PLAYER_1 && is_valid_move(board, PLAYER_1, i, j, i + 1, j - 1)
                            || is_valid_move(board, PLAYER_1, i, j, i + 1, j + 1)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// Function to check if a move is a capture move
int is_capture_move(int board[][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col) {
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;

    // Check if destination is within the board
    if (to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) {
        return 0;
    }

    // Check if the destination is empty or not opposite player's piece
    if (board[to_row][to_col] != EMPTY && ((player == PLAYER_1 && board[to_row][to_col] != PLAYER_2_TOKEN
                                             && board[to_row][to_col] != PLAYER_2_KING)
                                           || (player == PLAYER_2 && board[to_row][to_col] != PLAYER_1_TOKEN
                                               && board[to_row][to_col] != PLAYER_1_KING))) {
        return 0;
    }

    // Check if the piece being captured is adjacent to the current position
    if (player == PLAYER_1) {
        if (row_diff != 2 || (col_diff != -2 && col_diff != 2)) {
            return 0;
        }
    } else if (player == PLAYER_2) {
        if (row_diff != -2 || (col_diff != -2 && col_diff != 2)) {
            return 0;
        }
    }

    // Check if there is a piece to capture
    if (player == PLAYER_1) {
        if (board[from_row - 1][from_col - 1] == PLAYER_2_TOKEN || board[from_row - 1][from_col - 1] == PLAYER_2_KING) {
            return 1;
        } else if (board[from_row - 1][from_col + 1] == PLAYER_2_TOKEN || board[from_row - 1][from_col + 1] == PLAYER_2_KING) {
            return 1;
        }
    } else if (player == PLAYER_2) {
        if (board[from_row + 1][from_col - 1] == PLAYER_1_TOKEN || board[from_row + 1][from_col - 1] == PLAYER_1_KING) {
            return 1;
        } else if (board[from_row + 1][from_col + 1] == PLAYER_1_TOKEN || board[from_row + 1][from_col + 1] == PLAYER_1_KING) {
            return 1;
        }
    }

    return 0;
}

// Function to check if a piece can make a capture move
int can_capture(int board[][BOARD_SIZE], int player, int row, int col) {
    if (player == PLAYER_1) {
        if (is_capture_move(board, PLAYER_1, row, col, row - 2, col - 2)
            || is_capture_move(board, PLAYER_1, row, col, row - 2, col + 2)) {
            return 1;
        }
    } else if (player == PLAYER_2) {
        if (is_capture_move(board, PLAYER_2, row, col, row + 2, col - 2)
            || is_capture_move(board, PLAYER_2, row, col, row + 2, col + 2)) {
            return 1;
        }
    }

    return 0;
}

// Function to capture a piece
void capture_piece(int board[][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col) {
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;

    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;

    // If the piece is a king, then move to the end of the capture chain
    if (board[to_row][to_col] == PLAYER_1_KING || board[to_row][to_col] == PLAYER_2_KING) {
        if (row_diff == 2 && col_diff == -2 && board[to_row - 1][to_col + 1] != EMPTY) {
            capture_piece(board, player, to_row, to_col, to_row - 2, to_col + 2);
        } else if (row_diff == 2 && col_diff == 2 && board[to_row - 1][to_col - 1] != EMPTY) {
            capture_piece(board, player, to_row, to_col, to_row - 2, to_col - 2);
        } else if (row_diff == -2 && col_diff == -2 && board[to_row + 1][to_col + 1] != EMPTY) {
            capture_piece(board, player, to_row, to_col, to_row + 2, to_col + 2);
        } else if (row_diff == -2 && col_diff == 2 && board[to_row + 1][to_col - 1] != EMPTY) {
            capture_piece(board, player, to_row, to_col, to_row + 2, to_col - 2);
        }
    }
}

// Function to check if the game has been won
int check_win(int board[][BOARD_SIZE]) {
    if (count_pieces(board, PLAYER_1) == 0) {
        return PLAYER_2;
    } else if (count_pieces(board, PLAYER_2) == 0) {
        return PLAYER_1;
    }

    return 0;
}

// Function to count the number of pieces a player has
int count_pieces(int board[][BOARD_SIZE], int player) {
    int i, j;
    int count = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (player == PLAYER_1 && (board[i][j] == PLAYER_1_TOKEN || board[i][j] == PLAYER_1_KING)) {
                count++;
            } else if (player == PLAYER_2 && (board[i][j] == PLAYER_2_TOKEN || board[i][j] == PLAYER_2_KING)) {
                count++;
            }
        }
    }

    return count;
}

// Main function
int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int player = PLAYER_1;
    int from_row, from_col, to_row, to_col;
    int game_over = 0;

    init_board(board);

    // Game loop
    while (!game_over) {
        display_board(board);

        // Get input from player
        printf("Player %d, enter your move (from_row from_col to_row to_col): ", player);
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

        // Check if the move is valid
        if (!is_valid_move(board, player, from_row - 1, from_col - 1, to_row - 1, to_col - 1)) {
            printf("Invalid move!\n");
            continue;
        }

        // Check if the move is a capture move
        if (is_capture_move(board, player, from_row - 1, from_col - 1, to_row - 1, to_col - 1)) {
            capture_piece(board, player, from_row - 1, from_col - 1, to_row - 1, to_col - 1);

            // Check if the player can continue capturing pieces
            if (can_capture(board, player, to_row - 1, to_col - 1)) {
                printf("Capture move! You can capture another piece.\n");
                continue;
            }
        }

        // Move the piece
        move_piece(board, player, from_row - 1, from_col - 1, to_row - 1, to_col - 1);

        // Check if the game has been won
        if (check_win(board) != 0) {
            printf("Player %d wins!\n", check_win(board));
            game_over = 1;
        } else if (!player_has_valid_move(board, player)) {
            printf("Player %d has no valid moves and loses.\n", player);
            game_over = 1;
        }

        // Switch players
        player = (player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
    }

    return 0;
}