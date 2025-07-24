//FormAI DATASET v1.0 Category: Checkers Game ; Style: innovative
#include <stdio.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define BLACK 'B'
#define WHITE 'W'

char board[BOARD_SIZE][BOARD_SIZE];
char current_player = BLACK;

void initialize_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                if (row < 3) {
                    board[row][col] = WHITE;
                } else if (row > 4) {
                    board[row][col] = BLACK;
                } else {
                    board[row][col] = EMPTY;
                }
            } else {
                board[row][col] = EMPTY;
            }
        }
    }
}

void print_board() {
    printf("\n    0   1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d |", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf(" %c |", board[row][col]);
        }
        printf("\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
}

void move_piece(int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;
}

int is_valid_move(int from_row, int from_col, int to_row, int to_col) {
    // check if move is within board bounds
    if (to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) {
        return 0;
    }
    // check if move is to an empty square
    if (board[to_row][to_col] != EMPTY) {
        return 0;
    }
    // check if move is diagonal
    if (from_row == to_row || from_col == to_col) {
        return 0;
    }
    // check if move is only one square
    if (abs(from_row - to_row) != 1 || abs(from_col - to_col) != 1) {
        return 0;
    }
    // check if player is moving their own piece
    if (board[from_row][from_col] != current_player) {
        return 0;
    }
    // check if player is moving forward unless capturing
    if ((current_player == BLACK && to_row > from_row) || (current_player == WHITE && to_row < from_row)) {
        return 0;
    }
    // check if capturing move
    if (abs(from_row - to_row) == 2 && abs(from_col - to_col) == 2) {
        int capture_row = (from_row + to_row) / 2;
        int capture_col = (from_col + to_col) / 2;
        // check if capturing opponent's piece
        if (board[capture_row][capture_col] == (current_player == BLACK ? WHITE : BLACK)) {
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}

int is_endgame() {
    int black_pieces = 0;
    int white_pieces = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == BLACK) {
                black_pieces++;
            } else if (board[row][col] == WHITE) {
                white_pieces++;
            }
        }
    }
    if (black_pieces == 0 || white_pieces == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int game_over = 0;
    initialize_board();
    print_board();
    while (!game_over) {
        int from_row, from_col, to_row, to_col;
        printf("Enter move for %c: ", current_player);
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
        if (is_valid_move(from_row, from_col, to_row, to_col)) {
            move_piece(from_row, from_col, to_row, to_col);
            if (abs(from_row - to_row) == 2 && abs(from_col - to_col) == 2) {
                int capture_row = (from_row + to_row) / 2;
                int capture_col = (from_col + to_col) / 2;
                board[capture_row][capture_col] = EMPTY;
            }
            print_board();
            if (is_endgame()) {
                game_over = 1;
                printf("%c wins!\n", current_player);
            } else {
                current_player = (current_player == BLACK ? WHITE : BLACK);
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    return 0;
}