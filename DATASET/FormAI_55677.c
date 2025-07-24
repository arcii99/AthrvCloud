//FormAI DATASET v1.0 Category: Checkers Game ; Style: future-proof
#include <stdio.h>

#define BOARD_ROWS 8
#define BOARD_COLS 8

char board[BOARD_ROWS][BOARD_COLS]; // stores the current state of the board

int current_player; // 1 for player 1, 2 for player 2

void init_board(); // initializes the board to its starting state
void print_board(); // prints the current state of the board
int move_piece(int start_row, int start_col, int end_row, int end_col); // moves a piece from start position to end position
int is_valid_move(int start_row, int start_col, int end_row, int end_col); // checks if a move is valid
int get_piece_color(int row, int col); // returns the color of the piece at a given position
int is_jump(int start_row, int start_col, int end_row, int end_col); // checks if a move is a jump move
int remove_piece(int start_row, int start_col, int end_row, int end_col); // removes the piece that was jumped over during a jump move

int main() {
    init_board();
    print_board();
    current_player = 1;
    while (1) {
        int start_row, start_col, end_row, end_col;
        printf("Player %d's turn: ", current_player);
        scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);
        if (move_piece(start_row, start_col, end_row, end_col)) {
            print_board();
            if (current_player == 1) {
                current_player = 2;
            } else {
                current_player = 1;
            }
        } else {
            printf("Invalid move!\n");
        }
    }
    return 0;
}

void init_board() {
    int i, j;
    for (i = 0; i < BOARD_ROWS; i++) {
        for (j = 0; j < BOARD_COLS; j++) {
            if ((i + j) % 2 != 0) { // add pieces to black squares only
                if (i < 3) { // player 1's pieces
                    board[i][j] = '1';
                } else if (i > 4) { // player 2's pieces
                    board[i][j] = '2';
                } else { // empty squares
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < BOARD_ROWS; i++) {
        printf("   -----------------\n");
        printf("%d |", i);
        for (j = 0; j < BOARD_COLS; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
    printf("   -----------------\n");
    printf("    0  1  2  3  4  5  6  7\n");
}

int move_piece(int start_row, int start_col, int end_row, int end_col) {
    if (!is_valid_move(start_row, start_col, end_row, end_col)) {
        return 0;
    }
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = ' ';
    if (is_jump(start_row, start_col, end_row, end_col)) {
        remove_piece(start_row, start_col, end_row, end_col);
    }
    return 1;
}

int is_valid_move(int start_row, int start_col, int end_row, int end_col) {
    // check if end position is outside the board
    if (end_row < 0 || end_row >= BOARD_ROWS || end_col < 0 || end_col >= BOARD_COLS) {
        return 0;
    }
    // check if end position is occupied
    if (board[end_row][end_col] != ' ') {
        return 0;
    }
    // check if piece at start position is the current player's piece
    if (get_piece_color(start_row, start_col) != current_player) {
        return 0;
    }
    int delta_row = end_row - start_row;
    int delta_col = end_col - start_col;
    // check if move is diagonal
    if (delta_row == delta_col || delta_row == -delta_col) {
        // check if move is one square
        if (delta_row == 1 || delta_row == -1) {
            return 1;
        }
        // check if move is a jump move
        if (delta_row == 2 || delta_row == -2) {
            if (is_jump(start_row, start_col, end_row, end_col)) {
                return 1;
            }
        }
    }
    return 0;
}

int get_piece_color(int row, int col) {
    if (board[row][col] == '1' || board[row][col] == '3') {
        return 1;
    } else if (board[row][col] == '2' || board[row][col] == '4') {
        return 2;
    } else {
        return 0;
    }
}

int is_jump(int start_row, int start_col, int end_row, int end_col) {
    int delta_row = end_row - start_row;
    int delta_col = end_col - start_col;
    // check if move is a jump move
    if (delta_row == 2 || delta_row == -2) {
        // check if jump is over an opponent's piece
        int jumped_row = (start_row + end_row) / 2; // calculate the row of the jumped piece
        int jumped_col = (start_col + end_col) / 2; // calculate the column of the jumped piece
        if (get_piece_color(jumped_row, jumped_col) == 3 - current_player) {
            return 1;
        }
    }
    return 0;
}

int remove_piece(int start_row, int start_col, int end_row, int end_col) {
    int delta_row = end_row - start_row;
    int delta_col = end_col - start_col;
    int jumped_row = (start_row + end_row) / 2; // calculate the row of the jumped piece
    int jumped_col = (start_col + end_col) / 2; // calculate the column of the jumped piece
    board[jumped_row][jumped_col] = ' '; // remove the jumped piece
    return 1;
}