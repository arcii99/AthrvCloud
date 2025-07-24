//FormAI DATASET v1.0 Category: Checkers Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

char board[ROWS][COLS];
char player1 = 'X';
char player2 = 'O';

void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = '-';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    board[3][0] = player1;
    board[3][2] = player1;
    board[3][4] = player1;
    board[3][6] = player1;
    board[4][1] = player1;
    board[4][3] = player1;
    board[4][5] = player1;
    board[4][7] = player1;

    board[0][1] = player2;
    board[0][3] = player2;
    board[0][5] = player2;
    board[0][7] = player2;
    board[1][0] = player2;
    board[1][2] = player2;
    board[1][4] = player2;
    board[1][6] = player2;
}

void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d", i);
        printf("\n");
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

void make_move(char player) {
    int row, col;
    int row2, col2;
    printf("%c's turn\n", player);
    printf("Enter row and column of piece to move (separated by space): ");
    scanf("%d %d", &row, &col);
    printf("Enter row and column of destination (separated by space): ");
    scanf("%d %d", &row2, &col2);

    if (abs(row-row2) == 2 && abs(col-col2) == 2) {
        // Jump move, remove jumped piece
        int jumped_row = (row+row2)/2;
        int jumped_col = (col+col2)/2;
        if (board[jumped_row][jumped_col] == player1 || board[jumped_row][jumped_col] == player2) {
            board[jumped_row][jumped_col] = ' ';
        } else {
            printf("Invalid move\n");
            make_move(player);
            return;
        }
    }

    if (row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS) {
        printf("Invalid move\n");
        make_move(player);
        return;
    }

    if (board[row][col] != player) {
        printf("Invalid move\n");
        make_move(player);
        return;
    }

    if (board[row2][col2] != ' ') {
        printf("Invalid move\n");
        make_move(player);
        return;
    }

    if ((player == player1 && row2 < row) || (player == player2 && row2 > row)) {
        printf("Invalid move\n");
        make_move(player);
        return;
    }

    if (abs(row-row2) == 1 && abs(col-col2) == 1) {
        board[row][col] = ' ';
        board[row2][col2] = player;
    } else if (abs(row-row2) == 2 && abs(col-col2) == 2) {
        board[row][col] = ' ';
        board[row2][col2] = player;
    } else {
        printf("Invalid move\n");
        make_move(player);
        return;
    }
}

int check_win(char player) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
    }
    if (count == 0) {
        return 1; // Player has no more pieces
    } else {
        return 0;
    }
}

int main() {
    init_board();
    print_board();
    while (1) {
        make_move(player1);
        print_board();
        if (check_win(player1)) {
            printf("%c wins!\n", player2);
            break;
        }
        make_move(player2);
        print_board();
        if (check_win(player2)) {
            printf("%c wins!\n", player1);
            break;
        }
    }
    return 0;
}