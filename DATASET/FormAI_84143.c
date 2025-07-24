//FormAI DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10
#define MAX_GENERATIONS 100

void initialize_board(int board[ROWS][COLUMNS]);
void print_board(int board[ROWS][COLUMNS]);
void generate_next_generation(int board[ROWS][COLUMNS]);

int main() {
    int board[ROWS][COLUMNS];
    int generation = 0;

    srand(time(NULL));
    initialize_board(board);

    while (generation < MAX_GENERATIONS) {
        printf("Generation %d\n", generation);
        print_board(board);
        generate_next_generation(board);
        generation++;
    }

    return 0;
}

void initialize_board(int board[ROWS][COLUMNS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[ROWS][COLUMNS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void generate_next_generation(int board[ROWS][COLUMNS]) {
    int next_generation[ROWS][COLUMNS];
    int i, j, num_neighbors;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            num_neighbors = 0;

            // Check neighbors
            if (i > 0 && board[i-1][j] == 1) {
                num_neighbors++;
            }
            if (j > 0 && board[i][j-1] == 1) {
                num_neighbors++;
            }
            if (i > 0 && j > 0 && board[i-1][j-1] == 1) {
                num_neighbors++;
            }
            if (i < ROWS-1 && board[i+1][j] == 1) {
                num_neighbors++;
            }
            if (j < COLUMNS-1 && board[i][j+1] == 1) {
                num_neighbors++;
            }
            if (i < ROWS-1 && j < COLUMNS-1 && board[i+1][j+1] == 1) {
                num_neighbors++;
            }
            if (i < ROWS-1 && j > 0 && board[i+1][j-1] == 1) {
                num_neighbors++;
            }
            if (i > 0 && j < COLUMNS-1 && board[i-1][j+1] == 1) {
                num_neighbors++;
            }

            // Update next_generation based on rules
            if (board[i][j] == 1 && (num_neighbors < 2 || num_neighbors > 3)) {
                next_generation[i][j] = 0;
            }
            else if (board[i][j] == 0 && num_neighbors == 3) {
                next_generation[i][j] = 1;
            }
            else {
                next_generation[i][j] = board[i][j];
            }
        }
    }

    // Copy next_generation back to board
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = next_generation[i][j];
        }
    }
}