//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 75
#define ROWS 5
#define COLS 5

int bingo_board[ROWS][COLS];

void init_board() {
    int i, j, num, idx;
    int numbers[MAX_NUMBERS];

    // Initialize numbers array
    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = i + 1;
    }

    // Shuffle numbers array
    srand(time(NULL));
    for (i = 0; i < MAX_NUMBERS; i++) {
        idx = rand() % MAX_NUMBERS;
        num = numbers[i];
        numbers[i] = numbers[idx];
        numbers[idx] = num;
    }

    // Populate bingo board
    idx = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            bingo_board[i][j] = numbers[idx++];
        }
    }
}

void print_board() {
    int i, j;
    printf("\nBINGO BOARD\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%-3d", bingo_board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_bingo() {
    int i, j, count;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        count = 0;
        for (j = 0; j < COLS; j++) {
            if (bingo_board[i][j] == -1) {
                count++;
            }
        }
        if (count == COLS) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < COLS; j++) {
        count = 0;
        for (i = 0; i < ROWS; i++) {
            if (bingo_board[i][j] == -1) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }

    // Check diagonal
    count = 0;
    for (i = 0, j = 0; i < ROWS && j < COLS; i++, j++) {
        if (bingo_board[i][j] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    // Check reverse diagonal
    count = 0;
    for (i = 0, j = COLS - 1; i < ROWS && j >= 0; i++, j--) {
        if (bingo_board[i][j] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    return 0;
}

int main() {
    int num, i, j, found;

    init_board();
    print_board();

    while (!is_bingo()) {
        printf("Enter a number (0 to quit): ");
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        found = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (bingo_board[i][j] == num) {
                    bingo_board[i][j] = -1;
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            print_board();
        } else {
            printf("Number %d not found.\n", num);
        }
    }

    printf("Bingo!\n");
    return 0;
}