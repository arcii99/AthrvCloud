//FormAI DATASET v1.0 Category: Table Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 10

void display_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void win_message(int player) {
    printf("\n#####################\n");
    printf("#     Player %d won!     #\n", player);
    printf("#####################\n\n");
}

int check_rows(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        int row_sum = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            row_sum += board[i][j];
        }
        if (row_sum == BOARD_SIZE) {
            return 1;
        } else if (row_sum == -BOARD_SIZE) {
            return -1;
        }
    }
    return 0;
}

int check_columns(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        int column_sum = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            column_sum += board[j][i];
        }
        if (column_sum == BOARD_SIZE) {
            return 1;
        } else if (column_sum == -BOARD_SIZE) {
            return -1;
        }
    }
    return 0;
}

int check_diagonals(int board[BOARD_SIZE][BOARD_SIZE]) {
    int left_sum = 0;
    int right_sum = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        left_sum += board[i][i];
        right_sum += board[i][BOARD_SIZE-i-1];
    }
    if (left_sum == BOARD_SIZE || right_sum == BOARD_SIZE) {
        return 1;
    } else if (left_sum == -BOARD_SIZE || right_sum == -BOARD_SIZE) {
        return -1;
    }
    return 0;
}

int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
    int row_win = check_rows(board);
    if (row_win) {
        return row_win;
    }
    int column_win = check_columns(board);
    if (column_win) {
        return column_win;
    }
    int diagonal_win = check_diagonals(board);
    if (diagonal_win) {
        return diagonal_win;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE];
    // Initialize board to 0
    memset(board, 0, sizeof(board));
    int player = 1;
    int moves_left = BOARD_SIZE*BOARD_SIZE;
    while (moves_left > 0) {
        display_board(board);
        int row, column;
        printf("Player %d's turn:\n", player);
        printf("Enter row (0-%d): ", BOARD_SIZE-1);
        scanf("%d", &row);
        printf("Enter column (0-%d): ", BOARD_SIZE-1);
        scanf("%d", &column);
        if (row >= BOARD_SIZE || row < 0 || column >= BOARD_SIZE || column < 0) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (board[row][column] != 0) {
            printf("That spot is already taken. Try again.\n");
            continue;
        }
        board[row][column] = player;
        int win = check_win(board);
        if (win) {
            display_board(board);
            win_message(player);
            return 0;
        }
        player *= -1;
        moves_left -= 1;
    }
    printf("It's a tie!\n");
    return 0;
}