//FormAI DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES 16

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int count = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = count;
            count++;
        }
    }
    board[BOARD_SIZE-1][BOARD_SIZE-1] = 0;
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(0));
    for (int i = 0; i < MAX_MOVES; i++) {
        int rand_row = rand() % BOARD_SIZE;
        int rand_col = rand() % BOARD_SIZE;
        int zero_row, zero_col;
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = 0; k < BOARD_SIZE; k++) {
                if (board[j][k] == 0) {
                    zero_row = j;
                    zero_col = k;
                    break;
                }
            }
        }
        if (rand_row == zero_row) {
            if (rand_col == zero_col + 1 || rand_col == zero_col - 1) {
                int temp = board[rand_row][rand_col];
                board[rand_row][rand_col] = board[zero_row][zero_col];
                board[zero_row][zero_col] = temp;
            }
        }
        else if (rand_col == zero_col) {
            if (rand_row == zero_row + 1 || rand_row == zero_row - 1) {
                int temp = board[rand_row][rand_col];
                board[rand_row][rand_col] = board[zero_row][zero_col];
                board[zero_row][zero_col] = temp;
            }
        }
    }
}

int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
    int count = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == BOARD_SIZE - 1 && j == BOARD_SIZE - 1) {
                if (board[i][j] != 0) {
                    return 0;
                }
            }
            else {
                if (board[i][j] != count) {
                    return 0;
                }
                count++;
            }
        }
    }
    return 1;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int moves = 0;
    initialize_board(board);
    shuffle_board(board);
    printf("Welcome to the Memory Game!\n");
    while (1) {
        printf("Moves: %d\n", moves);
        print_board(board);
        if (check_win(board)) {
            printf("Congratulations! You won in %d moves!\n", moves);
            break;
        }
        printf("Enter row and column of tile to move (separated by space): ");
        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        int zero_row, zero_col;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 0) {
                    zero_row = i;
                    zero_col = j;
                    break;
                }
            }
        }
        if (row == zero_row) {
            if (col == zero_col + 1 || col == zero_col - 1) {
                int temp = board[row][col];
                board[row][col] = board[zero_row][zero_col];
                board[zero_row][zero_col] = temp;
                moves++;
            }
            else {
                printf("Invalid move. Please try again.\n");
            }
        }
        else if (col == zero_col) {
            if (row == zero_row + 1 || row == zero_row - 1) {
                int temp = board[row][col];
                board[row][col] = board[zero_row][zero_col];
                board[zero_row][zero_col] = temp;
                moves++;
            }
            else {
                printf("Invalid move. Please try again.\n");
            }
        }
        else {
            printf("Invalid move. Please try again.\n");
        }
    }
    return 0;
}