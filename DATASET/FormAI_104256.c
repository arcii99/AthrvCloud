//FormAI DATASET v1.0 Category: Checkers Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Constants to represent the players and the pieces
#define PLAYER_1 1
#define PLAYER_2 2
#define PLAYER_1_PIECE 'x'
#define PLAYER_2_PIECE 'o'
#define PLAYER_1_KING 'X'
#define PLAYER_2_KING 'O'

// Struct to represent a single piece on the board
typedef struct Piece {
    int player;
    int king;
} Piece;

// Method to initialize the board with starting positions
void initialize_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i+j)%2 == 0) {
                if (i < 3) {
                    board[i][j].player = PLAYER_2;
                    board[i][j].king = 0;
                } else if (i > 4) {
                    board[i][j].player = PLAYER_1;
                    board[i][j].king = 0;
                } else {
                    board[i][j].player = 0;
                    board[i][j].king = 0;
                }
            } else {
                board[i][j].player = 0;
                board[i][j].king = 0;
            }
        }
    }
}

// Method to print the current state of the board
void print_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("  %d ", i);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (j == 0) {
                printf("%d ", i);
            }
            if (board[i][j].player == PLAYER_1 && board[i][j].king == 0) {
                printf("%c ", PLAYER_1_PIECE);
            } else if (board[i][j].player == PLAYER_2 && board[i][j].king == 0) {
                printf("%c ", PLAYER_2_PIECE);
            } else if (board[i][j].player == PLAYER_1 && board[i][j].king == 1) {
                printf("%c ", PLAYER_1_KING);
            } else if (board[i][j].player == PLAYER_2 && board[i][j].king == 1) {
                printf("%c ", PLAYER_2_KING);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// Method to check if a position is valid
int is_valid_position(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

// Method to check if a move is valid for a piece
int is_valid_move(Piece board[BOARD_SIZE][BOARD_SIZE], int player, int row, int col, int dst_row, int dst_col) {
    // Check if the destination position is a valid position on the board
    if (!is_valid_position(dst_row, dst_col)) {
        return 0;
    }
    // Check if the destination position is empty
    if (board[dst_row][dst_col].player != 0) {
        return 0;
    }
    // Check if the move is diagonal
    if (abs(dst_row - row) != abs(dst_col - col)) {
        return 0;
    }
    // Check if the move is in the correct direction for the player
    if ((player == PLAYER_1 && dst_row > row) || (player == PLAYER_2 && dst_row < row)) {
        return 0;
    }
    // Check if the move is a capture move
    if (abs(dst_row - row) == 2 && abs(dst_col - col) == 2) {
        int mid_row = (row + dst_row) / 2;
        int mid_col = (col + dst_col) / 2;
        if (board[mid_row][mid_col].player == player || board[mid_row][mid_col].player == 0) {
            return 0;
        }
    }
    // If none of the checks failed, the move is valid
    return 1;
}

// Method to check if a piece can capture and return the number of possible capture moves
int can_capture(Piece board[BOARD_SIZE][BOARD_SIZE], int player, int row, int col) {
    int count = 0;
    int i, j;
    for (i = -2; i <= 2; i++) {
        for (j = -2; j <= 2; j++) {
            int dst_row = row + i;
            int dst_col = col + j;
            if (is_valid_move(board, player, row, col, dst_row, dst_col) && abs(i) == 2 && abs(j) == 2) {
                int mid_row = (row + dst_row) / 2;
                int mid_col = (col + dst_col) / 2;
                if (board[mid_row][mid_col].player != player && board[mid_row][mid_col].player != 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

// Method to handle a move of a piece
int move_piece(Piece board[BOARD_SIZE][BOARD_SIZE], int player, int row, int col, int dst_row, int dst_col) {
    int is_capture = abs(dst_row - row) == 2 && abs(dst_col - col) == 2;
    // Move the piece to the destination position
    board[dst_row][dst_col].player = board[row][col].player;
    board[dst_row][dst_col].king = board[row][col].king;
    // Clear the initial position
    board[row][col].player = 0;
    board[row][col].king = 0;
    // If the piece reached the opposite end of the board, make it a king
    if (player == PLAYER_1 && dst_row == BOARD_SIZE - 1) {
        board[dst_row][dst_col].king = 1;
    } else if (player == PLAYER_2 && dst_row == 0) {
        board[dst_row][dst_col].king = 1;
    }
    // If the move was a capture move, remove the captured piece
    if (is_capture) {
        int mid_row = (row + dst_row) / 2;
        int mid_col = (col + dst_col) / 2;
        board[mid_row][mid_col].player = 0;
        board[mid_row][mid_col].king = 0;
    }
    // Return 1 if the move was a capture move, 0 otherwise
    return is_capture;
}

// Main method
int main() {
    // Initialize the board and the player turn
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int turn = PLAYER_1;
    initialize_board(board);

    while (1) {
        int i, j;
        // Print the current state of the board
        printf("\nPlayer %d's turn:\n", turn);
        print_board(board);
        // Check if the game is over
        int player_1_pieces = 0, player_2_pieces = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j].player == PLAYER_1) {
                    player_1_pieces++;
                } else if (board[i][j].player == PLAYER_2) {
                    player_2_pieces++;
                }
            }
        }
        if (player_1_pieces == 0) {
            printf("\nPlayer 2 wins!\n");
            break;
        } else if (player_2_pieces == 0) {
            printf("\nPlayer 1 wins!\n");
            break;
        }
        // Ask the player to choose a piece to move
        int sel_row, sel_col;
        do {
            printf("Select a piece (row and column): ");
            scanf("%d %d", &sel_row, &sel_col);
        } while (!is_valid_position(sel_row, sel_col) || board[sel_row][sel_col].player != turn);
        // Check if the piece can capture
        int num_captures = can_capture(board, turn, sel_row, sel_col);
        if (num_captures > 0) {
            // If the piece can capture, ask the player to choose which move to make
            int dst_row, dst_col;
            do {
                printf("Possible capture moves: %d\n", num_captures);
                printf("Select a capture move (row and column): ");
                scanf("%d %d", &dst_row, &dst_col);
            } while (!is_valid_move(board, turn, sel_row, sel_col, dst_row, dst_col) || abs(dst_row - sel_row) != 2 || abs(dst_col - sel_col) != 2);
            // Handle the move and check for multiple captures
            int is_multiple = 0;
            while (move_piece(board, turn, sel_row, sel_col, dst_row, dst_col)) {
                if (can_capture(board, turn, dst_row, dst_col) > 0) {
                    is_multiple = 1;
                    sel_row = dst_row;
                    sel_col = dst_col;
                    do {
                        printf("Possible capture moves: %d\n", num_captures);
                        printf("Select a capture move (row and column): ");
                        scanf("%d %d", &dst_row, &dst_col);
                    } while (!is_valid_move(board, turn, sel_row, sel_col, dst_row, dst_col) || abs(dst_row - sel_row) != 2 || abs(dst_col - sel_col) != 2);
                } else {
                    is_multiple = 0;
                }
            }
            // If the move was not a multiple capture move, switch to the next player turn
            if (!is_multiple) {
                turn = turn == PLAYER_1 ? PLAYER_2 : PLAYER_1;
            }
        } else {
            // If the piece can't capture, ask the player to choose a regular move
            int dst_row, dst_col;
            do {
                printf("Select a destination position (row and column): ");
                scanf("%d %d", &dst_row, &dst_col);
            } while (!is_valid_move(board, turn, sel_row, sel_col, dst_row, dst_col) || abs(dst_row - sel_row) != 1 || abs(dst_col - sel_col) != 1);
            // Handle the move and switch to the next player turn
            move_piece(board, turn, sel_row, sel_col, dst_row, dst_col);
            turn = turn == PLAYER_1 ? PLAYER_2 : PLAYER_1;
        }
    }

    return 0;
}