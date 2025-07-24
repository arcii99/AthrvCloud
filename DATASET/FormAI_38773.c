//FormAI DATASET v1.0 Category: Checkers Game ; Style: careful
#include<stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i+j) % 2 == 0) {
                board[i][j] = ' ';
            } else {
                if (i < 3) {
                    board[i][j] = 'w';
                } else if (i > 4) {
                    board[i][j] = 'r';
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    } 
}

void print_board() {
    int i, j;
    printf("\n   |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("\n");
        printf(" %d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("|  %c  ", board[i][j]);
        }
        printf("| %d", i);
    }
    printf("\n   |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |\n");
}

int is_valid_move(int player, int start_row, int start_col, int end_row, int end_col) {
    // check if the move is within the board bounds
    if (end_row < 0 || end_col < 0 || end_row >= BOARD_SIZE || end_col >= BOARD_SIZE) {
        return 0;
    }
    // check if the end position is empty
    if (board[end_row][end_col] != ' ') {
        return 0;
    }
    // check if the correct player is moving
    if (player == 1 && board[start_row][start_col] != 'r') {
        return 0;
    }
    if (player == 2 && board[start_row][start_col] != 'w') {
        return 0;
    }
    // check if the move is diagonal
    if (abs(start_row - end_row) != abs(start_col - end_col)) {
        return 0;
    }
    // check if the move is only one space
    if (abs(start_row - end_row) != 1) {
        return 0;
    }
    // check if the move is in the correct direction for a normal piece
    if (player == 1 && end_row > start_row) {
        return 0;
    }
    if (player == 2 && end_row < start_row) {
        return 0;
    }
    return 1;
}

void make_move(int start_row, int start_col, int end_row, int end_col) {
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = ' ';
}

int is_valid_jump(int player, int start_row, int start_col, int end_row, int end_col) {
    // check if the move is within the board bounds
    if (end_row < 0 || end_col < 0 || end_row >= BOARD_SIZE || end_col >= BOARD_SIZE) {
        return 0;
    }
    // check if the end position is empty
    if (board[end_row][end_col] != ' ') {
        return 0;
    }
    // check if the correct player is moving
    if (player == 1 && board[start_row][start_col] != 'r') {
        return 0;
    }
    if (player == 2 && board[start_row][start_col] != 'w') {
        return 0;
    }
    // check if the move is diagonal
    if (abs(start_row - end_row) != abs(start_col - end_col)) {
        return 0;
    }
    // check if the move is two spaces
    if (abs(start_row - end_row) != 2) {
        return 0;
    }
    // check if the move is in the correct direction for a normal piece
    if (player == 1 && end_row > start_row) {
        return 0;
    }
    if (player == 2 && end_row < start_row) {
        return 0;
    }
    // check if there is an enemy piece to jump over
    int jumped_row = (start_row + end_row) / 2;
    int jumped_col = (start_col + end_col) / 2;
    if (board[jumped_row][jumped_col] == ' ') {
        return 0;
    }
    // check if the piece being jumped is an enemy piece
    if (player == 1 && board[jumped_row][jumped_col] != 'w' && board[jumped_row][jumped_col] != 'W') {
        return 0;
    }
    if (player == 2 && board[jumped_row][jumped_col] != 'r' && board[jumped_row][jumped_col] != 'R') {
        return 0;
    }
    return 1;
}

void do_jump(int start_row, int start_col, int end_row, int end_col) {
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = ' ';
    int jumped_row = (start_row + end_row) / 2;
    int jumped_col = (start_col + end_col) / 2;
    board[jumped_row][jumped_col] = ' ';
}

int has_valid_jump(int player) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (player == 1 && board[i][j] == 'r') {
                if (is_valid_jump(player, i, j, i+2, j+2) || is_valid_jump(player, i, j, i+2, j-2)) {
                    return 1;
                }
                if (board[i][j] == 'R') {
                    if (is_valid_jump(player, i, j, i-2, j+2) || is_valid_jump(player, i, j, i-2, j-2)) {
                        return 1;
                    }
                }
            } else if (player == 2 && board[i][j] == 'w') {
                if (is_valid_jump(player, i, j, i-2, j+2) || is_valid_jump(player, i, j, i-2, j-2)) {
                    return 1;
                }
                if (board[i][j] == 'W') {
                    if (is_valid_jump(player, i, j, i+2, j+2) || is_valid_jump(player, i, j, i+2, j-2)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void play_game() {
    int turn = 1, player = 1;
    int start_row, start_col, end_row, end_col;
    while (1) {
        printf("\n");
        print_board();
        printf("\nPlayer %d's turn.", player);
        printf("\nEnter starting row, column: ");
        scanf("%d,%d", &start_row, &start_col);
        printf("Enter ending row, column: ");
        scanf("%d,%d", &end_row, &end_col);
        if (is_valid_jump(player, start_row, start_col, end_row, end_col)) {
            do_jump(start_row, start_col, end_row, end_col);
            if (!has_valid_jump(player)) {
                turn++;
                player = (player == 1) ? 2 : 1;
            }
        } else if (is_valid_move(player, start_row, start_col, end_row, end_col)) {
            make_move(start_row, start_col, end_row, end_col);
            turn++;
            player = (player == 1) ? 2 : 1;
        } else {
            printf("Invalid move.\n");
        }
        int i, j;
        int red_pieces = 0, white_pieces = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 'r' || board[i][j] == 'R') {
                    red_pieces++;
                } else if (board[i][j] == 'w' || board[i][j] == 'W') {
                    white_pieces++;
                }
            }
        }
        if (red_pieces == 0) {
            printf("\nPlayer 2 wins!");
            break;
        } else if (white_pieces == 0) {
            printf("\nPlayer 1 wins!");
            break;
        }
    }
}

int main() {
    initialize_board();
    play_game();
    return 0;
}