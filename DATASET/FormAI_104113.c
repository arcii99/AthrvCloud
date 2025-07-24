//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define BLACK 1
#define WHITE 2

typedef struct {
    int row;
    int col;
} Position;

int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0}
};

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|");
            switch (board[i][j]) {
                case EMPTY:
                    printf("   ");
                    break;
                case BLACK:
                    printf(" B ");
                    break;
                case WHITE:
                    printf(" W ");
                    break;
            }
        }
        printf("|\n");
    }
}

int in_bounds(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

int can_capture(int piece_type, int row, int col, int jump_row, int jump_col) {
    if (!in_bounds(jump_row, jump_col) || board[jump_row][jump_col] != EMPTY) {
        return 0;
    }
    int opp_piece = piece_type == BLACK ? WHITE : BLACK;
    int capture_row = (row + jump_row) / 2;
    int capture_col = (col + jump_col) / 2;
    return in_bounds(capture_row, capture_col) && board[capture_row][capture_col] == opp_piece;
}

Position get_move() {
    int row, col, jump_row, jump_col;
    printf("Enter move (e.g. 3,2 to 4,3): ");
    scanf("%d,%d to %d,%d", &row, &col, &jump_row, &jump_col);
    Position move = {row - 1, col - 1};
    Position jump = {jump_row - 1, jump_col - 1};
    if (!in_bounds(move.row, move.col) || !in_bounds(jump.row, jump.col)) {
        printf("Invalid move, out of bounds.\n");
        return get_move();
    }
    int piece_type = board[move.row][move.col];
    if (piece_type == EMPTY) {
        printf("Invalid move, no piece at source position.\n");
        return get_move();
    }
    int dist_row = jump.row - move.row;
    int dist_col = jump.col - move.col;
    if (dist_row == 0 || dist_col == 0 || dist_row != dist_col) {
        printf("Invalid move, invalid direction.\n");
        return get_move();
    }
    int capture = can_capture(piece_type, move.row, move.col, jump.row, jump.col);
    if (dist_row == 2 && capture) {
        int capture_row = (move.row + jump.row) / 2;
        int capture_col = (move.col + jump.col) / 2;
        board[capture_row][capture_col] = EMPTY;
        return jump;
    } else if (dist_row == 1 && !capture) {
        return jump;
    } else {
        printf("Invalid move, cannot capture.\n");
        return get_move();
    }
}

int main() {
    int turn = BLACK;
    while (1) {
        printf("\nTurn: %s\n", turn == BLACK ? "Black" : "White");
        print_board();
        Position move = get_move();
        board[move.row][move.col] = EMPTY;
        board[move.row + (turn == BLACK ? 1 : -1)][move.col + (move.col < 4 ? 1 : -1)] = turn;
        if (move.row + (turn == BLACK ? 1 : -1) == (turn == BLACK ? BOARD_SIZE - 1 : 0)) {
            printf("\nGame over, %s wins!\n", turn == BLACK ? "Black" : "White");
            break;
        }
        turn = turn == BLACK ? WHITE : BLACK;
    }
    return 0;
}