//FormAI DATASET v1.0 Category: Checkers Game ; Style: beginner-friendly
#include <stdio.h>

#define BOARD_SIZE 8

typedef enum {
    BLANK,
    RED,
    BLACK
} piece_t;

typedef struct {
    piece_t piece;
    int row;
    int col;
} square_t;

square_t board[BOARD_SIZE][BOARD_SIZE];

void print_board() {
    printf("  1 2 3 4 5 6 7 8\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row+1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch(board[row][col].piece) {
                case BLANK:
                    printf("- ");
                    break;
                case RED:
                    printf("R ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
            }
        }
        printf("\n");
    }
}

void set_starting_positions() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row < 3) && ((row + col) % 2 == 1)) {
                board[row][col].piece = BLACK;
            } else if ((row >= BOARD_SIZE - 3) && ((row + col) % 2 == 1)) {
                board[row][col].piece = RED;
            } else {
                board[row][col].piece = BLANK;
            }
            board[row][col].row = row;
            board[row][col].col = col;
        }
    }
}

void move_piece(square_t *from, square_t *to) {
    to->piece = from->piece;
    from->piece = BLANK;
}

int is_valid_move(square_t *from, square_t *to) {
    if (to->piece != BLANK) {
        return 0;
    }
    int row_diff = to->row - from->row;
    int col_diff = to->col - from->col;
    if (from->piece == BLACK) {
        if (!(row_diff == 1 &&
            (col_diff == 1 || col_diff == -1))) {
            return 0;
        }
    }
    if (from->piece == RED) {
        if (!(row_diff == -1 &&
            (col_diff == 1 || col_diff == -1))) {
            return 0;
        }
    }
    return 1;
}

int main() {
    set_starting_positions();
    print_board();
    int done = 0;
    int red_turn = 1;
    while (!done) {
        printf("\n");
        if (red_turn) {
            printf("Red's turn\n");
        } else {
            printf("Black's turn\n");
        }
        int from_row, from_col, to_row, to_col;
        printf("Enter the row of the piece you want to move: ");
        scanf("%d", &from_row);
        printf("Enter the column of the piece you want to move: ");
        scanf("%d", &from_col);
        printf("Enter the row of the square you want to move to: ");
        scanf("%d", &to_row);
        printf("Enter the column of the square you want to move to: ");
        scanf("%d", &to_col);
        square_t *from = &board[from_row-1][from_col-1];
        square_t *to = &board[to_row-1][to_col-1];
        if (!is_valid_move(from, to)) {
            printf("Invalid move\n");
            continue;
        }
        move_piece(from, to);
        print_board();
        red_turn = !red_turn;
    }
    return 0;
}