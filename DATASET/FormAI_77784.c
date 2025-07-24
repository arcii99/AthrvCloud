//FormAI DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int board[ROWS][COLS];
int flipped[ROWS][COLS];

void initialize_board() {
    int i, j, value;
    int nums[ROWS * COLS / 2];

    for (i = 0; i < ROWS * COLS / 2; i++) {
        nums[i] = i + 1;
    }

    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 && j == 0) {
                value = 1;
            } else if (i == ROWS - 1 && j == COLS - 1) {
                value = ROWS * COLS / 2;
            } else {
                int index = rand() % (ROWS * COLS / 2);
                value = nums[index];
                nums[index] = nums[ROWS * COLS / 2 - 1];
            }

            board[i][j] = flipped[i][j] = value;
        }
    }
}

void print_board() {
    int i, j;

    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (flipped[i][j]) {
                printf("%2d", board[i][j]);
            } else {
                printf("  ");
            }

            printf(" | ");
        }

        printf("\n");
    }
}

void flip_tile(int row, int col) {
    flipped[row][col] = 1;
}

int is_match(int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}

int game_over() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (!flipped[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    initialize_board();
    print_board();

    int row1, col1, row2, col2;
    while (!game_over()) {
        printf("Enter the row and column of the first tile: ");
        scanf("%d %d", &row1, &col1);
        flip_tile(row1, col1);
        print_board();

        printf("Enter the row and column of the second tile: ");
        scanf("%d %d", &row2, &col2);
        flip_tile(row2, col2);
        print_board();

        if (is_match(row1, col1, row2, col2)) {
            printf("Match found!\n");
        } else {
            printf("No match found.\n");
            flipped[row1][col1] = 0;
            flipped[row2][col2] = 0;
        }
    }

    printf("Congratulations, you won the game!\n");

    return 0;
}