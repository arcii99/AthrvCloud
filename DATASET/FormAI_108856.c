//FormAI DATASET v1.0 Category: Checkers Game ; Style: future-proof
#include <stdio.h>

#define EMPTY 0
#define RED 1
#define BLACK 2

#define SIZE 8

int board[SIZE][SIZE] = {
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};

void display_board() {
    printf("\n    0 1 2 3 4 5 6 7\n");
    printf("    ----------------\n");
    for (int row = 0; row < SIZE; row++) {
        printf("%d | ", row);
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == EMPTY) {
                printf("  ");
            } else if (board[row][col] == RED) {
                printf("r ");
            } else if (board[row][col] == BLACK) {
                printf("b ");
            }
        }
        printf("|\n");
    }
    printf("    ----------------\n");
}

int get_piece_at(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return -1;
    }
    return board[row][col];
}

int is_valid_move(int row, int col, int new_row, int new_col) {
    if (new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE) {
        return 0;
    }
    int piece = board[row][col];
    int new_piece = board[new_row][new_col];
    if (new_piece != EMPTY) {
        return 0;
    }
    if (piece == BLACK) {
        if (new_row > row) {
            return 0;
        }
        if (col != new_col && row - new_row != 1) {
            return 0;
        }
        if (row - new_row == 2) {
            int middle_piece = get_piece_at(row-1, (col+new_col)/2);
            if (middle_piece == EMPTY || middle_piece == BLACK) {
                return 0;
            }
        }
    } else if (piece == RED) {
        if (new_row < row) {
            return 0;
        }
        if (col != new_col && new_row - row != 1) {
            return 0;
        }
        if (new_row - row == 2) {
            int middle_piece = get_piece_at(row+1, (col+new_col)/2);
            if (middle_piece == EMPTY || middle_piece == RED) {
                return 0;
            }
        }
    } else {
        return 0;
    }
    return 1;
}

int move_piece(int row, int col, int new_row, int new_col) {
    if (!is_valid_move(row, col, new_row, new_col)) {
        return 0;
    }
    int piece = board[row][col];
    board[row][col] = EMPTY;
    board[new_row][new_col] = piece;
    if (piece == RED && new_row == SIZE-1) {
        board[new_row][new_col] = piece+2;
    } else if (piece == BLACK && new_row == 0) {
        board[new_row][new_col] = piece+2;
    }
    if (new_row - row == 2 || row - new_row == 2) {
        board[(row+new_row)/2][(col+new_col)/2] = EMPTY;
    }
    return 1;
}

int has_legal_moves(int player) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == player || board[row][col] == player+2) {
                for (int new_row = row-2; new_row <= row+2; new_row++) {
                    for (int new_col = col-2; new_col <= col+2; new_col++) {
                        if (is_valid_move(row, col, new_row, new_col)) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    int player = RED;
    while (1) {
        display_board();
        printf("\nPlayer %d's turn.\n", player);
        if (!has_legal_moves(player)) {
            printf("Player %d has no legal moves and loses.\n", player);
            break;
        }
        int row, col, new_row, new_col;
        printf("Enter row and column of piece to move: ");
        scanf("%d %d", &row, &col);
        printf("Enter row and column of new location: ");
        scanf("%d %d", &new_row, &new_col);
        if (move_piece(row, col, new_row, new_col)) {
            if (player == RED) {
                player = BLACK;
            } else {
                player = RED;
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    return 0;
}