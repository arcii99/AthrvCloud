//FormAI DATASET v1.0 Category: Chess engine ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define MAX_MOVES 50

int board[BOARD_SIZE][BOARD_SIZE];

typedef struct {
    int row;
    int col;
} move_t;

move_t moves[MAX_MOVES];
int num_moves;

void add_move(int row, int col) {
    moves[num_moves].row = row;
    moves[num_moves].col = col;
    num_moves++;
}

int is_valid_move(int row, int col, int color, int dir) {
    // check if piece can move in direction
    if (dir == 1 && row - 1 >= 0 && board[row - 1][col] == 0) return 1;
    if (dir == -1 && row + 1 < BOARD_SIZE && board[row + 1][col] == 0) return 1;

    // check if piece can capture
    if (col - 1 >= 0 && board[row + dir][col - 1] == -color) return 1;
    if (col + 1 < BOARD_SIZE && board[row + dir][col + 1] == -color) return 1;

    return 0;
}

void generate_moves(int row, int col, int color) {
    if (is_valid_move(row, col, color, 1)) {
        add_move(row - 1, col);
    }
    if (is_valid_move(row, col, color, -1)) {
        add_move(row + 1, col);
    }
    if (is_valid_move(row, col, color, -color)) {
        if (col - 1 >= 0 && board[row + (-color)][col - 1] == -color) {
            add_move(row + (-color), col - 1);
        }
        if (col + 1 < BOARD_SIZE && board[row + (-color)][col + 1] == -color) {
            add_move(row + (-color), col + 1);
        }
    }
}

void print_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int main() {
    memset(board, 0, sizeof(board));

    // set up initial board
    board[0][1] = board[0][3] = board[0][5] = -1;
    board[1][0] = board[1][2] = board[1][4] = board[1][6] = -1;
    board[2][1] = board[2][3] = board[2][5] = -1;
    board[5][0] = board[5][2] = board[5][4] = board[5][6] = 1;
    board[6][1] = board[6][3] = board[6][5] = 1;
    board[7][0] = board[7][2] = board[7][4] = -1;

    print_board();

    // find all moves for black pieces
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == -1) {
                generate_moves(row, col, -1);
            }
        }
    }

    printf("Black moves:\n");
    for (int i = 0; i < num_moves; i++) {
        printf("(%d,%d) ", moves[i].row, moves[i].col);
    }
    printf("\n");

    num_moves = 0;

    // find all moves for red pieces
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 1) {
                generate_moves(row, col, 1);
            }
        }
    }

    printf("Red moves:\n");
    for (int i = 0; i < num_moves; i++) {
        printf("(%d,%d) ", moves[i].row, moves[i].col);
    }
    printf("\n");

    return 0;
}