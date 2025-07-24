//FormAI DATASET v1.0 Category: Chess engine ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define MAX_MOVE_SIZE 50

typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } piece_t;
typedef enum { WHITE, BLACK } color_t;

typedef struct {
    piece_t piece;
    color_t color;
} square_t;

typedef struct {
    square_t board[BOARD_SIZE][BOARD_SIZE];
    color_t turn;
    int halfmove_clock;
    int fullmove_number;
    char *history[MAX_MOVE_SIZE];
    int history_size;
} chess_t;

/* Initializes a chess board to the starting position */
void init_board(chess_t *c) {
    c->turn = WHITE;
    c->halfmove_clock = 0;
    c->fullmove_number = 1;
    c->history_size = 0;

    /* Initialize pieces */
    c->board[0][0] = (square_t){ROOK, WHITE};
    c->board[0][1] = (square_t){KNIGHT, WHITE};
    c->board[0][2] = (square_t){BISHOP, WHITE};
    c->board[0][3] = (square_t){QUEEN, WHITE};
    c->board[0][4] = (square_t){KING, WHITE};
    c->board[0][5] = (square_t){BISHOP, WHITE};
    c->board[0][6] = (square_t){KNIGHT, WHITE};
    c->board[0][7] = (square_t){ROOK, WHITE};

    for (int i = 0; i < BOARD_SIZE; i++) {
        c->board[1][i] = (square_t){PAWN, WHITE};
        c->board[6][i] = (square_t){PAWN, BLACK};
    }

    c->board[7][0] = (square_t){ROOK, BLACK};
    c->board[7][1] = (square_t){KNIGHT, BLACK};
    c->board[7][2] = (square_t){BISHOP, BLACK};
    c->board[7][3] = (square_t){QUEEN, BLACK};
    c->board[7][4] = (square_t){KING, BLACK};
    c->board[7][5] = (square_t){BISHOP, BLACK};
    c->board[7][6] = (square_t){KNIGHT, BLACK};
    c->board[7][7] = (square_t){ROOK, BLACK};
}

/* Prints out the current state of the chess board */
void print_board(chess_t *c) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (c->board[i][j].piece) {
                case PAWN:
                    printf("%c ", c->board[i][j].color == WHITE ? 'P' : 'p');
                    break;
                case KNIGHT:
                    printf("%c ", c->board[i][j].color == WHITE ? 'N' : 'n');
                    break;
                case BISHOP:
                    printf("%c ", c->board[i][j].color == WHITE ? 'B' : 'b');
                    break;
                case ROOK:
                    printf("%c ", c->board[i][j].color == WHITE ? 'R' : 'r');
                    break;
                case QUEEN:
                    printf("%c ", c->board[i][j].color == WHITE ? 'Q' : 'q');
                    break;
                case KING:
                    printf("%c ", c->board[i][j].color == WHITE ? 'K' : 'k');
                    break;
                default:
                    printf("  ");
                    break;
            }
        }
        printf(" %d\n", i+1);
    }
    printf("  A B C D E F G H\n");
}

/* Returns true if the given position is empty */
int is_empty(chess_t *c, int row, int col) {
    return c->board[row][col].piece == 0;
}

/* Returns true if the given position is occupied by a piece of the opposite color */
int is_opposite_color(chess_t *c, int row, int col, color_t color) {
    return !is_empty(c, row, col) && c->board[row][col].color != color;
}

/* Returns true if the given position is occupied by a piece of the same color */
int is_same_color(chess_t *c, int row, int col, color_t color) {
    return !is_empty(c, row, col) && c->board[row][col].color == color;
}

/* Returns true if the given position is inside the board */
int is_inside_board(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

/* Returns true if the given piece can move from its current position to the given position */
int can_move_to(chess_t *c, int from_row, int from_col, int to_row, int to_col) {
    if (!is_inside_board(from_row, from_col) || !is_inside_board(to_row, to_col)) {
        return 0;
    }

    if (!is_empty(c, to_row, to_col) && c->board[from_row][from_col].color == c->board[to_row][to_col].color) {
        return 0;
    }

    switch (c->board[from_row][from_col].piece) {
        case PAWN:
            return from_col == to_col && is_empty(c, to_row, to_col)
                && ((c->board[from_row][from_col].color == WHITE && to_row == from_row+1)
                    || (c->board[from_row][from_col].color == BLACK && to_row == from_row-1));
        case KNIGHT:
            return (abs(to_row - from_row) == 2 && abs(to_col - from_col) == 1)
                || (abs(to_row - from_row) == 1 && abs(to_col - from_col) == 2);
        case BISHOP:
            /* Moving diagonally */
            if (abs(to_row - from_row) != abs(to_col - from_col)) {
                return 0;
            }

            /* Check the diagonals */
            int row_dir = to_row > from_row ? 1 : -1;
            int col_dir = to_col > from_col ? 1 : -1;
            for (int i = 1; i < abs(to_row - from_row); i++) {
                int row = from_row + i * row_dir;
                int col = from_col + i * col_dir;
                if (!is_empty(c, row, col)) {
                    return 0;
                }
            }
            return 1;
        case ROOK:
            /* Moving vertically or horizontally */
            if (to_row != from_row && to_col != from_col) {
                return 0;
            }

            /* Check the row or column */
            if (to_row == from_row) {
                int dir = to_col > from_col ? 1 : -1;
                for (int col = from_col + dir; col != to_col; col += dir) {
                    if (!is_empty(c, from_row, col)) {
                        return 0;
                    }
                }
            } else {
                int dir = to_row > from_row ? 1 : -1;
                for (int row = from_row + dir; row != to_row; row += dir) {
                    if (!is_empty(c, row, from_col)) {
                        return 0;
                    }
                }
            }
            return 1;
        case QUEEN:
            /* Moving diagonally or vertically or horizontally */
            if (abs(to_row - from_row) == abs(to_col - from_col)) {
                return can_move_to(c, from_row, from_col, to_row, to_col);
            }

            if (to_row != from_row && to_col != from_col) {
                return 0;
            }

            /* Check the row or column */
            if (to_row == from_row) {
                int dir = to_col > from_col ? 1 : -1;
                for (int col = from_col + dir; col != to_col; col += dir) {
                    if (!is_empty(c, from_row, col)) {
                        return 0;
                    }
                }
            } else {
                int dir = to_row > from_row ? 1 : -1;
                for (int row = from_row + dir; row != to_row; row += dir) {
                    if (!is_empty(c, row, from_col)) {
                        return 0;
                    }
                }
            }
            return 1;
        case KING:
            return abs(to_row - from_row) <= 1 && abs(to_col - from_col) <= 1;
        default:
            return 0;
    }
}

int main() {
    chess_t c;
    init_board(&c);
    print_board(&c);

    return 0;
}