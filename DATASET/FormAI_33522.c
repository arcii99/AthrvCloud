//FormAI DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>
#define BOARD_SIZE 8

enum Piece { EMPTY, RED, BLACK };
int board[BOARD_SIZE][BOARD_SIZE];

// initializes the board with the starting positions for a game of checkers
void init_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row % 2 == col % 2) {
                if (row < 3)
                    board[row][col] = BLACK;
                else if (row > 4)
                    board[row][col] = RED;
                else
                    board[row][col] = EMPTY;
            }
            else {
                board[row][col] = EMPTY;
            }
        }
    }
}

// prints the board to the console
void print_board() {
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY) {
                printf("_ ");
            }
            else if (board[row][col] == BLACK) {
                printf("B ");
            }
            else {
                printf("R ");
            }
        }
        printf("\n");
    }
}

// returns true if a move from (row1, col1) to (row2, col2) is valid; false otherwise
int is_valid_move(int player, int row1, int col1, int row2, int col2) {
    // check destination is an empty tile
    if (board[row2][col2] != EMPTY) {
        return 0;
    }

    // check piece is being moved in the right direction
    if (player == RED) {
        if (row2 <= row1) {
            return 0;
        }
    }
    else { // player == BLACK
        if (row2 >= row1) {
            return 0;
        }
    }

    // check move is a jump
    int row_diff = row2 - row1;
    int col_diff = col2 - col1;
    if (row_diff == 2 || row_diff == -2) {
        if (col_diff == 2 || col_diff == -2) {
            int jumped_row = (row1 + row2) / 2;
            int jumped_col = (col1 + col2) / 2;
            if (board[jumped_row][jumped_col] != player % 2 + 1) { // player can only jump over an opponent's piece
                return 0;
            }
            return 1;
        }
    }

    // check move is a regular move
    if (row_diff != 1 && row_diff != -1) {
        return 0;
    }
    if (col_diff != 1 && col_diff != -1) {
        return 0;
    }

    return 1;
}

// returns true if the current player (RED or BLACK) can make a move; false otherwise
int can_make_move(int player) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == player) {
                if (row < BOARD_SIZE-1 && col < BOARD_SIZE-1 && is_valid_move(player, row, col, row+1, col+1)) {
                    return 1;
                }
                if (row > 0 && col < BOARD_SIZE-1 && is_valid_move(player, row, col, row-1, col+1)) {
                    return 1;
                }
                if (row < BOARD_SIZE-1 && col > 0 && is_valid_move(player, row, col, row+1, col-1)) {
                    return 1;
                }
                if (row > 0 && col > 0 && is_valid_move(player, row, col, row-1, col-1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// applies a move from (row1, col1) to (row2, col2) on the board
void apply_move(int player, int row1, int col1, int row2, int col2) {
    board[row2][col2] = player;
    board[row1][col1] = EMPTY;
    if (row2 - row1 == 2 || row2 - row1 == -2) {
        int jumped_row = (row1 + row2) / 2;
        int jumped_col = (col1 + col2) / 2;
        board[jumped_row][jumped_col] = EMPTY;
    }
}

// returns the winner of the game; 0 if the game is still ongoing
int get_winner() {
    int black_count = 0;
    int red_count = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == BLACK) {
                black_count++;
            }
            else if (board[row][col] == RED) {
                red_count++;
            }
        }
    }
    if (red_count == 0) {
        return BLACK;
    }
    if (black_count == 0) {
        return RED;
    }
    return 0;
}

int main()
{
    init_board();
    int player = RED;
    print_board();

    while (!get_winner()) {
        if (!can_make_move(player)) {
            printf("No available moves for player %d. Skipping turn.\n", player);
        }
        else {
            printf("Player %d's turn. Enter move as: 'row1 col1 row2 col2'\n", player);
            int row1, col1, row2, col2;
            scanf("%d,%d,%d,%d", &row1, &col1, &row2, &col2);
            if (is_valid_move(player, row1, col1, row2, col2)) {
                apply_move(player, row1, col1, row2, col2);
                printf("Move applied. Board is now:\n");
                print_board();
                player = player % 2 + 1; // switch player
            }
            else {
                printf("Invalid move. Try again.\n");
            }
        }
    }

    int winner = get_winner();
    if (winner) {
        printf("Player %d wins!\n", winner);
    }
    else {
        printf("It's a tie.\n");
    }

    return 0;
}