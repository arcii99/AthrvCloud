//FormAI DATASET v1.0 Category: Checkers Game ; Style: portable
#include <stdio.h>

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'

#define BOARD_ROWS 8
#define BOARD_COLS 8

char board[BOARD_ROWS][BOARD_COLS];
char current_player = BLACK;

void init_board() {
    // Initializes the board with starting positions
    int i, j;

    for (i = 0; i < BOARD_ROWS; i++) {
        for (j = 0; j < BOARD_COLS; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Set black pieces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < BOARD_COLS; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = BLACK;
            }
        }
    }

    // Set white pieces
    for (i = BOARD_ROWS-1; i > BOARD_ROWS-4; i--) {
        for (j = 0; j < BOARD_COLS; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = WHITE;
            }
        }
    }
}

int get_piece_color(int row, int col) {
    // Returns the integer value for the color of the piece at the specified position
    switch(board[row][col]) {
        case BLACK:
            return 0;
        case WHITE:
            return 1;
        default:
            return -1;
    }
}

int is_valid_move(int row, int col, int new_row, int new_col) {
    // Returns 1 if the move is valid or 0 if it is not valid
    int color = get_piece_color(row, col);

    if (color == -1 || (new_row < 0 || new_row > BOARD_ROWS-1) || (new_col < 0 || new_col > BOARD_COLS-1)) {
        return 0;
    }

    if (board[new_row][new_col] != EMPTY) {
        return 0;
    }

    if (color == 0 && new_row > row) {
        return 0;
    }

    if (color == 1 && new_row < row) {
        return 0;
    }

    if (abs(new_row - row) == 1 && abs(new_col - col) == 1) {
        return 1;
    }

    if (abs(new_row - row) == 2 && abs(new_col - col) == 2) {
        int enemy_row = (new_row + row) / 2;
        int enemy_col = (new_col + col) / 2;

        if (get_piece_color(enemy_row, enemy_col) != (color ^ 1)) {
            return 0;
        }

        board[enemy_row][enemy_col] = EMPTY;
        return 1;
    }

    return 0;
}

void print_board() {
    // Prints the board to the console
    int i, j;

    printf("  ");
    for (i = 0; i < BOARD_COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < BOARD_ROWS; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int move_row, move_col, move_new_row, move_new_col;

    init_board();
    print_board();

    while (1) {
        printf("Player %c, enter move (row col new_row new_col): ", current_player);
        scanf("%d %d %d %d", &move_row, &move_col, &move_new_row, &move_new_col);

        if (is_valid_move(move_row, move_col, move_new_row, move_new_col)) {
            board[move_new_row][move_new_col] = current_player;
            board[move_row][move_col] = EMPTY;

            if (current_player == BLACK) {
                current_player = WHITE;
            } else {
                current_player = BLACK;
            }

            print_board();
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    return 0;
}