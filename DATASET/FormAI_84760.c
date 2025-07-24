//FormAI DATASET v1.0 Category: Checkers Game ; Style: systematic
#include <stdio.h>

#define BOARD_SIZE 8

// Board piece representation
enum Piece {
    EMPTY,
    BLACK_PIECE,
    WHITE_PIECE
};

// Game board
struct Board {
    enum Piece board[BOARD_SIZE][BOARD_SIZE];
};

// Initialize the game board
void init_board(struct Board *b) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Set the initial configuration of the board
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    b->board[i][j] = BLACK_PIECE;
                } else if (i > 4) {
                    b->board[i][j] = WHITE_PIECE;
                } else {
                    b->board[i][j] = EMPTY;
                }
            } else {
                b->board[i][j] = EMPTY;
            }
        }
    }
}

// Print the game board
void print_board(struct Board b) {
    printf("  ");  // Add column indices
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", i + 'a');  // Add row indices
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (b.board[i][j]) {
                case BLACK_PIECE:
                    printf("B ");
                    break;
                case WHITE_PIECE:
                    printf("W ");
                    break;
                default:
                    printf("- ");
                    break;
            }
        }
        printf("\n");
    }
}

// Check if a given move is valid
int is_valid_move(struct Board b, int start_row, int start_col, int end_row, int end_col) {
    // Make sure the end position is inside the board
    if (end_row < 0 || end_col < 0 || end_row >= BOARD_SIZE || end_col >= BOARD_SIZE) {
        return 0;
    }
    // Make sure the start and end positions are different
    if (start_row == end_row && start_col == end_col) {
        return 0;
    }
    // Make sure the end position is empty
    if (b.board[end_row][end_col] != EMPTY) {
        return 0;
    }
    // Black can only move diagonal down, white diagonal up
    int delta_row = end_row - start_row;
    if (b.board[start_row][start_col] == BLACK_PIECE && delta_row <= 0) {
        return 0;
    }
    if (b.board[start_row][start_col] == WHITE_PIECE && delta_row >= 0) {
        return 0;
    }
    // Regular moves can only move one diagonal, jumps can only move two diagonals
    int delta_col = end_col - start_col;
    int delta_col_abs = delta_col < 0 ? -delta_col : delta_col;
    if (delta_col_abs != delta_row && delta_col_abs != 2 * delta_row) {
        return 0;
    }
    // Check for jumps
    if (delta_col_abs == 2 * delta_row) {
        int jump_row = start_row + delta_row / 2;
        int jump_col = start_col + delta_col / 2;
        if (b.board[jump_row][jump_col] == EMPTY) {
            return 0;
        }
        if (b.board[start_row][start_col] == BLACK_PIECE && b.board[jump_row][jump_col] != WHITE_PIECE) {
            return 0;
        }
        if (b.board[start_row][start_col] == WHITE_PIECE && b.board[jump_row][jump_col] != BLACK_PIECE) {
            return 0;
        }
    }
    return 1;
}

// Apply a move to the board
void apply_move(struct Board *b, int start_row, int start_col, int end_row, int end_col) {
    // Move piece to end position
    b->board[end_row][end_col] = b->board[start_row][start_col];
    b->board[start_row][start_col] = EMPTY;
    // Remove captured piece if a jump was made
    if (end_row - start_row == 2) {
        b->board[start_row + 1][start_col + (end_col - start_col) / 2] = EMPTY;
    }
    if (end_row - start_row == -2) {
        b->board[start_row - 1][start_col + (end_col - start_col) / 2] = EMPTY;
    }
    // Promote to king if piece has reached the opposite end of the board
    if (b->board[end_row][end_col] == BLACK_PIECE && end_row == BOARD_SIZE - 1) {
        b->board[end_row][end_col] = WHITE_PIECE;
    }
    if (b->board[end_row][end_col] == WHITE_PIECE && end_row == 0) {
        b->board[end_row][end_col] = BLACK_PIECE;
    }
}

int main() {
    struct Board board;
    init_board(&board);
    print_board(board);
    int game_over = 0;
    int player = BLACK_PIECE;  // Player who has the current turn
    while (!game_over) {
        printf("Player %s's move\n", player == BLACK_PIECE ? "black" : "white");
        int start_row, start_col, end_row, end_col, valid;
        do {  // Repeatedly ask for input until a valid move is entered
            valid = 0;
            printf("Enter starting position: ");
            scanf("%d %d", &start_row, &start_col);
            printf("Enter ending position: ");
            scanf("%d %d", &end_row, &end_col);
            if (is_valid_move(board, start_row - 1, start_col - 1, end_row - 1, end_col - 1)) {
                apply_move(&board, start_row - 1, start_col - 1, end_row - 1, end_col - 1);
                valid = 1;
            } else {
                printf("Invalid move, please try again\n");
            }
        } while (!valid);
        print_board(board);
        // Check if game is over
        int black_pieces_remaining = 0;
        int white_pieces_remaining = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board.board[i][j] == BLACK_PIECE) {
                    black_pieces_remaining++;
                }
                if (board.board[i][j] == WHITE_PIECE) {
                    white_pieces_remaining++;
                }
            }
        }
        if (black_pieces_remaining == 0) {
            printf("Game over, white wins!\n");
            game_over = 1;
        }
        if (white_pieces_remaining == 0) {
            printf("Game over, black wins!\n");
            game_over = 1;
        }
        int no_moves_possible = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board.board[i][j] == player) {
                    // Check if any moves are possible from current position
                    if (is_valid_move(board, i, j, i + 1, j + 1)
                        || is_valid_move(board, i, j, i + 1, j - 1)
                        || is_valid_move(board, i, j, i - 1, j + 1)
                        || is_valid_move(board, i, j, i - 1, j - 1)
                        || is_valid_move(board, i, j, i + 2, j + 2)
                        || is_valid_move(board, i, j, i + 2, j - 2)
                        || is_valid_move(board, i, j, i - 2, j + 2)
                        || is_valid_move(board, i, j, i - 2, j - 2)) {
                        no_moves_possible = 0;
                    }
                }
            }
        }
        if (no_moves_possible) {
            printf("No moves possible, game over!\n");
            game_over = 1;
            if (player == BLACK_PIECE) {
                printf("White wins!\n");
            } else {
                printf("Black wins!\n");
            }
        }
        // Switch player
        player = player == BLACK_PIECE ? WHITE_PIECE : BLACK_PIECE;
    }
    return 0;
}