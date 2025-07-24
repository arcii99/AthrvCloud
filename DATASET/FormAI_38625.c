//FormAI DATASET v1.0 Category: Checkers Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define BOARD_SIZE 8

enum piece_type {
    EMPTY,
    BLACK,
    WHITE,
    BLACK_KING,
    WHITE_KING
};

typedef struct piece_t {
    enum piece_type type;
} piece_t;

typedef struct square_t {
    piece_t piece;
} square_t;

void initialize_board(square_t board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board[i][j].piece.type = BLACK;
                } else if (i > BOARD_SIZE - 4) {
                    board[i][j].piece.type = WHITE;
                } else {
                    board[i][j].piece.type = EMPTY;
                }
            } else {
                board[i][j].piece.type = EMPTY;
            }
        }
    }
}

void display_board(square_t board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece;
            switch (board[i][j].piece.type) {
                case BLACK:
                    piece = 'b';
                    break;
                case WHITE:
                    piece = 'w';
                    break;
                case BLACK_KING:
                    piece = 'B';
                    break;
                case WHITE_KING:
                    piece = 'W';
                    break;
                default: 
                    piece = ' ';
            }
            printf("|%c", piece);
        }
        printf("| %d\n", BOARD_SIZE - i);
    }
    printf("  a b c d e f g h\n");
}

bool is_move_valid(square_t board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col, enum piece_type player) {
    if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE || end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return false;
    }
    
    if (board[start_row][start_col].piece.type != player && board[start_row][start_col].piece.type != WHITE_KING && board[start_row][start_col].piece.type != BLACK_KING) {
        return false;
    }
    
    if (board[end_row][end_col].piece.type != EMPTY) {
        return false;
    }
    
    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;
    
    if (player == BLACK || board[start_row][start_col].piece.type == BLACK_KING) {
        if (row_diff != -1 && row_diff != -2) {
            return false;
        }
        if (col_diff != -1 && col_diff != 1) {
            return false;
        }
        if (row_diff == -2) {
            if (col_diff < 0) {
                if (board[start_row - 1][start_col - 1].piece.type != WHITE && board[start_row - 1][start_col - 1].piece.type != WHITE_KING) {
                    return false;
                }
            } else {
                if (board[start_row - 1][start_col + 1].piece.type != WHITE && board[start_row - 1][start_col + 1].piece.type != WHITE_KING) {
                    return false;
                }
            }
        }
    } else {
        if (row_diff != 1 && row_diff != 2) {
            return false;
        }
        if (col_diff != -1 && col_diff != 1) {
            return false;
        }
        if (row_diff == 2) {
            if (col_diff < 0) {
                if (board[start_row + 1][start_col - 1].piece.type != BLACK && board[start_row + 1][start_col - 1].piece.type != BLACK_KING) {
                    return false;
                }
            } else {
                if (board[start_row + 1][start_col + 1].piece.type != BLACK && board[start_row + 1][start_col + 1].piece.type != BLACK_KING) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

void make_move(square_t board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    board[end_row][end_col].piece = board[start_row][start_col].piece;
    board[start_row][start_col].piece.type = EMPTY;
    if (end_row == 0 && board[end_row][end_col].piece.type == BLACK) {
        board[end_row][end_col].piece.type = BLACK_KING;
    }
    if (end_row == BOARD_SIZE - 1 && board[end_row][end_col].piece.type == WHITE) {
        board[end_row][end_col].piece.type = WHITE_KING;
    }
    if (abs(end_row - start_row) == 2) {
        int jumped_row = (start_row + end_row) / 2;
        int jumped_col = (start_col + end_col) / 2;
        board[jumped_row][jumped_col].piece.type = EMPTY;
    }
}

bool check_for_winner(square_t board[BOARD_SIZE][BOARD_SIZE]) {
    bool found_black = false;
    bool found_white = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j].piece.type) {
                case BLACK:
                case BLACK_KING:
                    found_black = true;
                    break;
                case WHITE:
                case WHITE_KING:
                    found_white = true;
                    break;
                default:
                    break;
            }
        }
        if (found_black && found_white) {
            return false;
        } else if (found_black) {
            printf("Black wins!\n");
            return true;
        } else if (found_white) {
            printf("White wins!\n");
            return true;
        }
    }
    return true;
}

int main() {
    square_t board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    display_board(board);
    
    enum piece_type player = BLACK;
    while (!check_for_winner(board)) {
        int start_row, start_col, end_row, end_col;
        printf("Player %s, enter your move (e.g. 'a3 b4'): ", player == BLACK ? "black" : "white");
        char start_col_char, end_col_char;
        scanf(" %c%d %c%d", &start_col_char, &start_row, &end_col_char, &end_row);
        start_col = tolower(start_col_char) - 'a';
        end_col = tolower(end_col_char) - 'a';
        
        if (!is_move_valid(board, start_row, start_col, end_row, end_col, player)) {
            printf("Invalid move, please try again.\n");
            continue;
        }
        
        make_move(board, start_row, start_col, end_row, end_col);
        display_board(board);
        
        player = player == BLACK ? WHITE : BLACK;
    }
    
    return 0;
}