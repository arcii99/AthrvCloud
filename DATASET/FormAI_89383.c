//FormAI DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define BLACK 'B'
#define RED 'R'

int current_player = 1;
char board[BOARD_SIZE][BOARD_SIZE] = {
    {EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK},
    {BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY},
    {EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {RED, EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY},
    {EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY, RED},
    {RED, EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY}
};

int is_valid_move(int row, int col, int new_row, int new_col) {
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        // Moving outside the board
        return 0;
    }

    if (board[new_row][new_col] != EMPTY) {
        // Trying to move onto an occupied cell
        return 0;
    }

    int player = current_player;

    if (board[row][col] == BLACK) {
        if (player == 1 && new_row > row) {
            // Black pieces can only move up the board
            return 0;
        } else if (player == 2 && new_row < row) {
            // Red pieces can only move down the board
            return 0;
        }

        int diff_row = new_row - row;
        int diff_col = new_col - col;

        if (diff_row == 1 && (diff_col == -1 || diff_col == 1)) {
            // Normal move for black pieces
            return 1;
        }

        if (diff_row == 2 && (diff_col == -2 || diff_col == 2)) {
            // Jumping move for black pieces
            int jumped_row = (row + new_row) / 2;
            int jumped_col = (col + new_col) / 2;

            if (board[jumped_row][jumped_col] == RED) {
                board[jumped_row][jumped_col] = EMPTY;
                return 1;
            }
        }
    } else if (board[row][col] == RED) {
        if (player == 1 && new_row > row) {
            // Black pieces can only move up the board
            return 0;
        } else if (player == 2 && new_row < row) {
            // Red pieces can only move down the board
            return 0;
        }

        int diff_row = new_row - row;
        int diff_col = new_col - col;

        if (diff_row == -1 && (diff_col == -1 || diff_col == 1)) {
            // Normal move for red pieces
            return 1;
        }

        if (diff_row == -2 && (diff_col == -2 || diff_col == 2)) {
            // Jumping move for red pieces
            int jumped_row = (row + new_row) / 2;
            int jumped_col = (col + new_col) / 2;

            if (board[jumped_row][jumped_col] == BLACK) {
                board[jumped_row][jumped_col] = EMPTY;
                return 1;
            }
        }
    }

    return 0;
}

void print_board() {
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i);
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

void make_move(int row, int col, int new_row, int new_col) {
    board[new_row][new_col] = board[row][col];
    board[row][col] = EMPTY;

    if (new_row == 0 && board[new_row][new_col] == BLACK) {
        board[new_row][new_col] = 'K';
    }

    if (new_row == BOARD_SIZE - 1 && board[new_row][new_col] == RED) {
        board[new_row][new_col] = 'K';
    }

    current_player = 3 - current_player;
}

int main() {
    printf("Welcome to Checkers!\n");
    printf("Player 1: Black\n");
    printf("Player 2: Red\n");
    printf("To move, enter the coordinates of the piece you want to move and the coordinates of the cell you want to move it to.\n");
    printf("Coordinates are in the format 'row column', with a space between them.\n");

    while (1) {
        print_board();

        int row, col, new_row, new_col;
        printf("Player %d's turn\n", current_player);
        printf("Enter the coordinates of the piece you want to move: ");
        scanf("%d %d", &row, &col);
        printf("Enter the coordinates of the cell you want to move it to: ");
        scanf("%d %d", &new_row, &new_col);

        if (is_valid_move(row, col, new_row, new_col)) {
            make_move(row, col, new_row, new_col);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}