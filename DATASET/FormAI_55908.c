//FormAI DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define ROWS 25
#define COLS 50

void initialize_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
void update_board(int board[ROWS][COLS]);

int main(void)
{
    int board[ROWS][COLS];
    int generations = 0;

    initialize_board(board);
    printf("Game of Life\n");

    do {
        printf("Generation: %d\n", generations);
        print_board(board);
        update_board(board);
        generations++;
    } while (getchar() != 'q');

    return 0;
}

void initialize_board(int board[ROWS][COLS])
{
    int i, j, r;

    /* Initialize random seed */
    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            r = rand() % 2;
            board[i][j] = r;
        }
    }
}

void print_board(int board[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void update_board(int board[ROWS][COLS])
{
    int new_board[ROWS][COLS];
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int alive_neighbors = 0;

            /* Check the eight neighbors */
            if (i > 0 && j > 0 && board[i-1][j-1] == 1) {
                alive_neighbors++;
            }
            if (i > 0 && board[i-1][j] == 1) {
                alive_neighbors++;
            }
            if (i > 0 && j < COLS-1 && board[i-1][j+1] == 1) {
                alive_neighbors++;
            }
            if (j > 0 && board[i][j-1] == 1) {
                alive_neighbors++;
            }
            if (j < COLS-1 && board[i][j+1] == 1) {
                alive_neighbors++;
            }
            if (i < ROWS-1 && j > 0 && board[i+1][j-1] == 1) {
                alive_neighbors++;
            }
            if (i < ROWS-1 && board[i+1][j] == 1) {
                alive_neighbors++;
            }
            if (i < ROWS-1 && j < COLS-1 && board[i+1][j+1] == 1) {
                alive_neighbors++;
            }

            if (board[i][j] == 1 && (alive_neighbors == 2 || alive_neighbors == 3)) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 0 && alive_neighbors == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = 0;
            }
        }
    }

    /* Copy the new board to the old board */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}