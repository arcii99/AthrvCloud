//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

enum player {
    WHITE = 1,
    BLACK = 2,
    NONE = 0
};

enum piece_type {
    SINGLE = 1,
    KING = 2
};

typedef struct piece {
    enum player color;
    enum piece_type type;
} Piece;

Piece board[ROWS][COLS];
enum player whose_turn = WHITE;
int turn_number = 0;

void init_board();
void display_board();
void move_piece(int row, int col, int new_row, int new_col);
void remove_piece(int row, int col);
int can_jump(int row, int col, int row_offset, int col_offset);
int move_is_valid(int row, int col, int new_row, int new_col);
int game_is_over();
int count_pieces(enum player color);

int main() {
    init_board();
    while (!game_is_over()) {
        display_board();
        int row, col, new_row, new_col;
        printf("%s's turn. Enter move: ", whose_turn == WHITE ? "White" : "Black");
        scanf("%d %d %d %d", &row, &col, &new_row, &new_col);
        if (move_is_valid(row, col, new_row, new_col)) {
            move_piece(row, col, new_row, new_col);
            turn_number++;
            whose_turn = whose_turn == WHITE ? BLACK : WHITE;
        }
        else {
            printf("Invalid move. Try again.\n");
        }
    }
    printf("Game over. %s wins!\n", count_pieces(WHITE) > count_pieces(BLACK) ? "White" : "Black");
    return 0;
}

void init_board() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if ((row + col) % 2 == 0 && row <= 2) {
                board[row][col].color = WHITE;
                board[row][col].type = SINGLE;
            }
            else if ((row + col) % 2 == 0 && row >= 5) {
                board[row][col].color = BLACK;
                board[row][col].type = SINGLE;
            }
            else {
                board[row][col].color = NONE;
                board[row][col].type = SINGLE;
            }
        }
    }
}

void display_board() {
    printf("   ");
    for (int col = 0; col < COLS; col++) {
        printf("%d  ", col);
    }
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        printf("%d  ", row);
        for (int col = 0; col < COLS; col++) {
            printf(board[row][col].color == WHITE ? "w" : board[row][col].color == BLACK ? "b" : "-");
            printf(board[row][col].type == KING ? "K " : "  ");
        }
        printf("\n");
    }
}

void move_piece(int row, int col, int new_row, int new_col) {
    int row_offset = new_row - row;
    int col_offset = new_col - col;
    if (can_jump(row, col, row_offset, col_offset)) {
        remove_piece(row + row_offset / 2, col + col_offset / 2);
    }
    Piece temp = board[row][col];
    board[row][col] = board[new_row][new_col];
    board[new_row][new_col] = temp;
    if (new_row == 0 && board[new_row][new_col].color == WHITE) {
        board[new_row][new_col].type = KING;
    }
    else if (new_row == 7 && board[new_row][new_col].color == BLACK) {
        board[new_row][new_col].type = KING;
    }
}

void remove_piece(int row, int col) {
    board[row][col].color = NONE;
    board[row][col].type = SINGLE;
}

int can_jump(int row, int col, int row_offset, int col_offset) {
    if (board[row][col].type == SINGLE) {
        if (board[row + row_offset / 2][col + col_offset / 2].color != whose_turn && board[row + row_offset][col + col_offset].color == NONE) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        int jumped = -1;
        for (int i = 1; row + i * row_offset < ROWS && row + i * row_offset >= 0 && col + i * col_offset < COLS && col + i * col_offset >= 0; i++) {
            if (board[row + i * row_offset][col + i * col_offset].color != NONE) {
                if (jumped == -1 && board[row + i * row_offset][col + i * col_offset].color != whose_turn) {
                    jumped = i;
                }
                else {
                    return 0;
                }
            }
            else {
                if (jumped > 0 && board[row + i * row_offset][col + i * col_offset].color == NONE) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
    }
    return 0;
}

int move_is_valid(int row, int col, int new_row, int new_col) {
    if (row < 0 || row > 7 || col < 0 || col > 7 || new_row < 0 || new_row > 7 || new_col < 0 || new_col > 7) {
        return 0;
    }
    if (board[row][col].color != whose_turn) {
        return 0;
    }
    int row_offset = new_row - row;
    int col_offset = new_col - col;
    if (board[new_row][new_col].color != NONE) {
        return 0;
    }
    if (board[row][col].type == SINGLE) {
        if (abs(row_offset) != 1 || abs(col_offset) != 1) {
            return 0;
        }
        if ((board[row][col].color == WHITE && row_offset == -1) || (board[row][col].color == BLACK && row_offset == 1)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (abs(row_offset) != abs(col_offset)) {
            return 0;
        }
        for (int i = 1; i < abs(row_offset); i++) {
            if (board[row + i * (row_offset / abs(row_offset))][col + i * (col_offset / abs(col_offset))].color != NONE) {
                return 0;
            }
        }
        if (can_jump(row, col, row_offset, col_offset)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    return 0;
}

int game_is_over() {
    if (count_pieces(WHITE) == 0 || count_pieces(BLACK) == 0) {
        return 1;
    }
    int white_moves = 0, black_moves = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col].color == whose_turn) {
                if (board[row][col].type == SINGLE) {
                    if ((board[row][col].color == WHITE && row > 0 && col > 0 && move_is_valid(row, col, row - 1, col - 1)) ||
                        (board[row][col].color == WHITE && row > 0 && col < 7 && move_is_valid(row, col, row - 1, col + 1)) ||
                        (board[row][col].color == BLACK && row < 7 && col > 0 && move_is_valid(row, col, row + 1, col - 1)) ||
                        (board[row][col].color == BLACK && row < 7 && col < 7 && move_is_valid(row, col, row + 1, col + 1))) {
                        if (whose_turn == WHITE) {
                            white_moves = 1;
                        }
                        else {
                            black_moves = 1;
                        }
                    }
                    if ((board[row][col].color == WHITE && row > 1 && col > 1 && can_jump(row, col, -2, -2)) ||
                        (board[row][col].color == WHITE && row > 1 && col < 6 && can_jump(row, col, -2, 2)) ||
                        (board[row][col].color == BLACK && row < 6 && col > 1 && can_jump(row, col, 2, -2)) ||
                        (board[row][col].color == BLACK && row < 6 && col < 6 && can_jump(row, col, 2, 2))) {
                        if (whose_turn == WHITE) {
                            white_moves = 1;
                        }
                        else {
                            black_moves = 1;
                        }
                    }
                }
                else {
                    for (int i = 1; row - i >= 0 && col - i >= 0; i++) {
                        if ((board[row][col].color == WHITE && move_is_valid(row, col, row - i, col - i)) ||
                            (board[row][col].color == BLACK && move_is_valid(row, col, row + i, col - i))) {
                            if (whose_turn == WHITE) {
                                white_moves = 1;
                            }
                            else {
                                black_moves = 1;
                            }
                            break;
                        }
                        if (board[row - i][col - i].color != NONE) {
                            break;
                        }
                    }
                    for (int i = 1; row - i >= 0 && col + i < COLS; i++) {
                        if ((board[row][col].color == WHITE && move_is_valid(row, col, row - i, col + i)) ||
                            (board[row][col].color == BLACK && move_is_valid(row, col, row + i, col + i))) {
                            if (whose_turn == WHITE) {
                                white_moves = 1;
                            }
                            else {
                                black_moves = 1;
                            }
                            break;
                        }
                        if (board[row - i][col + i].color != NONE) {
                            break;
                        }
                    }
                    for (int i = 1; row + i < ROWS && col - i >= 0; i++) {
                        if ((board[row][col].color == WHITE && move_is_valid(row, col, row + i, col - i)) ||
                            (board[row][col].color == BLACK && move_is_valid(row, col, row - i, col - i))) {
                            if (whose_turn == WHITE) {
                                white_moves = 1;
                            }
                            else {
                                black_moves = 1;
                            }
                            break;
                        }
                        if (board[row + i][col - i].color != NONE) {
                            break;
                        }
                    }
                    for (int i = 1; row + i < ROWS && col + i < COLS; i++) {
                        if ((board[row][col].color == WHITE && move_is_valid(row, col, row + i, col + i)) ||
                            (board[row][col].color == BLACK && move_is_valid(row, col, row - i, col + i))) {
                            if (whose_turn == WHITE) {
                                white_moves = 1;
                            }
                            else {
                                black_moves = 1;
                            }
                            break;
                        }
                        if (board[row + i][col + i].color != NONE) {
                            break;
                        }
                    }
                }
            }
        }
    }
    if (white_moves == 0 || black_moves == 0) {
        return 1;
    }
    return 0;
}

int count_pieces(enum player color) {
    int count = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col].color == color) {
                count++;
            }
        }
    }
    return count;
}