//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

void display_board(int board[ROWS][COLS]) {
    printf(" B | I | N | G | O\n");
    printf("---+---+---+---+---\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("   |");
            } else {
                printf("%2d |", board[i][j]);
            }
        }
        printf("\n");
        printf("---+---+---+---+---\n");
    }
}

void generate_bingo_board(int board[ROWS][COLS]) {
    // Initialize the board with -1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }

    // Generate random unique numbers within each column range
    for (int i = 0; i < ROWS; i++) {
        int col_idx = i;
        for (int j = 0; j < COLS; j++) {
            int min = j * 15 + 1;
            int max = min + 14;
            if (j == 2 && i == 2) {
                board[i][j] = -1;
            } else {
                int num;
                do {
                    num = rand() % (max - min + 1) + min;
                } while (board[0][col_idx] == num || board[1][col_idx] == num || board[2][col_idx] == num || board[3][col_idx] == num || board[4][col_idx] == num);
                board[i][j] = num;
            }
        }
    }
}

int is_bingo(int board[ROWS][COLS]) {
    int count = 0;

    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int row_sum = 0;
        for (int j = 0; j < COLS; j++) {
            row_sum += board[i][j];
        }
        if (row_sum == -5) {
            count++;
        }
    }

    // Check columns
    for (int i = 0; i < ROWS; i++) {
        int col_sum = 0;
        for (int j = 0; j < COLS; j++) {
            col_sum += board[j][i];
        }
        if (col_sum == -5) {
            count++;
        }
    }

    // Check diagonals (left to right)
    int diagonal_sum = 0;
    for (int i = 0; i < ROWS; i++) {
        diagonal_sum += board[i][i];
    }
    if (diagonal_sum == -5) {
        count++;
    }

    // Check diagonals (right to left)
    diagonal_sum = 0;
    for (int i = 0; i < ROWS; i++) {
        diagonal_sum += board[i][ROWS - 1 - i];
    }
    if (diagonal_sum == -5) {
        count++;
    }

    return count;
}

int main() {
    int board[ROWS][COLS];
    srand(time(NULL));
    generate_bingo_board(board);
    int count = 0;
    while (1) {
        printf("Bingo board:\n");
        display_board(board);
        printf("Enter the next number (0 to exit):\n");
        int num;
        scanf("%d", &num);
        if (num == 0) {
            printf("Exiting...\n");
            break;
        }
        // Check if number is within 1-75 and not already marked
        if (num >= 1 && num <= 75) {
            int row_idx = -1;
            int col_idx = -1;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (board[i][j] == num) {
                        row_idx = i;
                        col_idx = j;
                        break;
                    }
                }
                if (row_idx != -1) {
                    break;
                }
            }
            if (row_idx != -1 && col_idx != -1) {
                board[row_idx][col_idx] = -1;
            }
            count = is_bingo(board);
            printf("Bingo count: %d\n", count);
            if (count >= 5) {
                printf("Congratulations! You won!\n");
                break;
            }
        }
    }
    return 0;
}