//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Bingo board dimensions */
#define ROWS 5
#define COLS 5

/* Function declarations */
void display_board(int board[ROWS][COLS], int uncovered[ROWS][COLS]);
int check_for_bingo(int board[ROWS][COLS], int uncovered[ROWS][COLS]);
void generate_random_num(int board[ROWS][COLS], int num_to_generate);

/* Main function */
int main() {
    srand(time(NULL));
    int bingo_board[ROWS][COLS] = { 0 };
    int board_uncovered[ROWS][COLS] = { 0 };
    int current_num = 1;
    generate_random_num(bingo_board, current_num++);
    display_board(bingo_board, board_uncovered);

    /* Main loop for playing the game */
    while (1) {
        /* Print current board state */
        printf("Current Board State:\n");
        display_board(bingo_board, board_uncovered);

        /* Check if there is bingo */
        if (check_for_bingo(bingo_board, board_uncovered)) {
            printf("Congratulations! You have bingo!\n");
            break;
        }

        /* Get user input for next number or quitting */
        printf("Enter next number or type 'quit' to exit: ");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        /* Check if input matches any number on the board */
        int input_num = atoi(input);
        int num_found = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo_board[i][j] == input_num) {
                    board_uncovered[i][j] = 1;
                    num_found = 1;
                }
            }
        }
        if (!num_found) {
            printf("Sorry, that number is not on the board.\n");
        }

        /* Generate next random number */
        generate_random_num(bingo_board, current_num++);
    }
    return 0;
}

/* Function definitions */

/* Displays the current state of the board */
void display_board(int board[ROWS][COLS], int uncovered[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (uncovered[i][j]) {
                printf("[%d]\t", board[i][j]);
            } else {
                printf("[ ]\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* Checks for bingo by checking rows, columns, and diagonals */
int check_for_bingo(int board[ROWS][COLS], int uncovered[ROWS][COLS]) {
    /* Check rows */
    for (int i = 0; i < ROWS; i++) {
        int row_bingo = 1;
        for (int j = 0; j < COLS; j++) {
            if (!uncovered[i][j]) {
                row_bingo = 0;
                break;
            }
        }
        if (row_bingo) {
            return 1;
        }
    }

    /* Check columns */
    for (int j = 0; j < COLS; j++) {
        int col_bingo = 1;
        for (int i = 0; i < ROWS; i++) {
            if (!uncovered[i][j]) {
                col_bingo = 0;
                break;
            }
        }
        if (col_bingo) {
            return 1;
        }
    }

    /* Check diagonal from top left to bottom right */
    int diagonal_bingo = 1;
    for (int i = 0; i < ROWS; i++) {
        if (!uncovered[i][i]) {
            diagonal_bingo = 0;
            break;
        }
    }
    if (diagonal_bingo) {
        return 1;
    }

    /* Check diagonal from top right to bottom left */
    diagonal_bingo = 1;
    for (int i = 0; i < ROWS; i++) {
        if (!uncovered[i][COLS-1-i]) {
            diagonal_bingo = 0;
            break;
        }
    }
    if (diagonal_bingo) {
        return 1;
    }

    /* No bingo found */
    return 0;
}

/* Generates a random number and places it on the board */
void generate_random_num(int board[ROWS][COLS], int num_to_generate) {
    int row = rand() % ROWS;
    int col = rand() % COLS;
    while (board[row][col] != 0) {
        row = rand() % ROWS;
        col = rand() % COLS;
    }
    board[row][col] = num_to_generate;
}