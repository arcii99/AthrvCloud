//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// function to print the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("\n\n   1 2 3 4\n");
    printf("  +-------+\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j])
                printf("%d ", board[i][j]);
            else
                printf("  ");
        }
        printf("|\n");
    }
    printf("  +-------+\n");
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0}, revealed[BOARD_SIZE][BOARD_SIZE] = {0};
    int i, j, row1, col1, row2, col2, val1, val2, moves = 0;
    srand(time(NULL));

    // populate the board
    for (i = 1; i <= BOARD_SIZE * BOARD_SIZE / 2; i++) {
        do {
            row1 = rand() % BOARD_SIZE;
            col1 = rand() % BOARD_SIZE;
        } while (board[row1][col1] != 0);
        do {
            row2 = rand() % BOARD_SIZE;
            col2 = rand() % BOARD_SIZE;
        } while (board[row2][col2] != 0);
        board[row1][col1] = board[row2][col2] = i;
    }

    // game loop
    while (1) {
        print_board(board, revealed);
        printf("\nMoves so far: %d\n", moves);
        printf("Enter the first card (row col): ");
        scanf("%d %d", &row1, &col1);
        if (row1 < 1 || row1 > BOARD_SIZE || col1 < 1 || col1 > BOARD_SIZE) {
            printf("\nInvalid input. Please try again.\n");
            continue;
        } else if (revealed[row1 - 1][col1 - 1]) {
            printf("\nThis card has already been revealed. Please try again.\n");
            continue;
        }
        revealed[row1 - 1][col1 - 1] = 1;
        val1 = board[row1 - 1][col1 - 1];
        print_board(board, revealed);
        printf("\nEnter the second card (row col): ");
        scanf("%d %d", &row2, &col2);
        if (row2 < 1 || row2 > BOARD_SIZE || col2 < 1 || col2 > BOARD_SIZE) {
            printf("\nInvalid input. Please try again.\n");
            revealed[row1 - 1][col1 - 1] = 0;
            continue;
        } else if (revealed[row2 - 1][col2 - 1]) {
            printf("\nThis card has already been revealed. Please try again.\n");
            revealed[row1 - 1][col1 - 1] = 0;
            continue;
        }
        revealed[row2 - 1][col2 - 1] = 1;
        val2 = board[row2 - 1][col2 - 1];
        print_board(board, revealed);
        if (val1 == val2) {
            printf("\nMatch!\n");
            moves++;
            if (moves == BOARD_SIZE * BOARD_SIZE / 2) {
                printf("\nCongratulations! You won in %d moves!\n", moves);
                break;
            }
        } else {
            printf("\nNot a match.\n");
            revealed[row1 - 1][col1 - 1] = revealed[row2 - 1][col2 - 1] = 0;
            moves++;
        }
    }

    return 0;
}