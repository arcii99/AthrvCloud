//FormAI DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void populate_board(int board[][COLS]);
void print_board(int board[][COLS]);
int get_user_input();

int main() {
    int board[ROWS][COLS];
    int row, col, dummy;

    srand(time(NULL)); // initialize random number generator

    populate_board(board);
    print_board(board);

    printf("Choose a row and column (separated by a space) to reveal the number at that location:");
    row = get_user_input();
    col = get_user_input();

    if (board[row][col] == 0) {
        printf("Game over! You hit a mine.\n");
    } else {
        printf("You revealed a %d!\n", board[row][col]);
    }

    return 0;
}

void populate_board(int board[][COLS]) {
    int i, j;

    // Initialize all cells to 0 (no mine)
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Randomly place 10 mines
    for (i = 0; i < 10; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;

        board[row][col] = -1;
    }

    // Fill in remaining cells with number of neighboring mines
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] != -1) {
                int count = 0;

                if (i - 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] == -1) count++; // top-left
                if (i - 1 >= 0 && board[i-1][j] == -1) count++; // top
                if (i - 1 >= 0 && j + 1 < COLS && board[i-1][j+1] == -1) count++; // top-right
                if (j - 1 >= 0 && board[i][j-1] == -1) count++; // left
                if (j + 1 < COLS && board[i][j+1] == -1) count++; // right
                if (i + 1 < ROWS && j - 1 >= 0 && board[i+1][j-1] == -1) count++; // bottom-left
                if (i + 1 < ROWS && board[i+1][j] == -1) count++; // bottom
                if (i + 1 < ROWS && j + 1 < COLS && board[i+1][j+1] == -1) count++; // bottom-right

                board[i][j] = count;
            }
        }
    }
}

void print_board(int board[][COLS]) {
    int i, j;

    printf("   ");
    for (i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("%d: ", i);

        for (j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", board[i][j]);
            }
        }

        printf("\n");
    }
}

int get_user_input() {
    int input, dummy;

    do {
        printf("\nEnter a number between 0 and 9 (inclusive):");
        scanf("%d", &input);

        if (input < 0 || input > 9) {
            printf("Invalid input. ");
            scanf("%*s");
        }

    } while (input < 0 || input > 9);

    return input;
}