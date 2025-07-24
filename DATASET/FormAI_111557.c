//FormAI DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8
#define RED 'R'
#define BLACK 'B'
#define EMPTY '-'

char board[ROWS][COLS];

void initialize_board() {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = BLACK;
                } else if (i > 4) {
                    board[i][j] = RED;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_move_valid(int from_row, int from_col, int to_row, int to_col, char player) {
    if (to_row < 0 || to_row >= ROWS || to_col < 0 || to_col >= COLS ||
        board[to_row][to_col] != EMPTY ||
        player == BLACK && to_row > from_row ||
        player == RED && to_row < from_row) {
        return 0;
    }
    int row_diff = abs(from_row - to_row);
    int col_diff = abs(from_col - to_col);
    if (row_diff == 1 && col_diff == 1) {
        return 1;
    } else if (row_diff == 2 && col_diff == 2) {
        int jump_row = from_row + (to_row - from_row) / 2;
        int jump_col = from_col + (to_col - from_col) / 2;
        if (board[jump_row][jump_col] == EMPTY) {
            return 0;
        }
        return 1;
    } else {
        return 0;
    }
}

void apply_move(int from_row, int from_col, int to_row, int to_col, char player) {
    board[to_row][to_col] = player;
    board[from_row][from_col] = EMPTY;
    if (abs(from_row - to_row) == 2) {
        int jump_row = from_row + (to_row - from_row) / 2;
        int jump_col = from_col + (to_col - from_col) / 2;
        board[jump_row][jump_col] = EMPTY;
    }
}

int is_game_over() {
    int num_red = 0;
    int num_black = 0;
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            if (board[i][j] == RED) {
                num_red++;
            } else if (board[i][j] == BLACK) {
                num_black++;
            }
        }
    }
    if (num_red == 0) {
        printf("Congratulations! Black has won.\n");
        return 1;
    } else if (num_black == 0) {
        printf("Congratulations! Red has won.\n");
        return 1;
    } else {
        return 0;
    }
}

int main() {
    initialize_board();
    char player = BLACK;
    while (!is_game_over()) {
        printf("It is %c's turn.\n", player);
        print_board();
        int from_row, from_col, to_row, to_col;
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &from_row, &from_col);
        printf("Enter the row and column you want to move to: ");
        scanf("%d %d", &to_row, &to_col);
        if (is_move_valid(from_row, from_col, to_row, to_col, player)) {
            apply_move(from_row, from_col, to_row, to_col, player);
            if (player == BLACK) {
                player = RED;
            } else {
                player = BLACK;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}