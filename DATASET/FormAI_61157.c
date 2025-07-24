//FormAI DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50
#define GENERATIONS 1000

void initialize_board(int board[][COLS]) {
    // srand the random number generator
    srand(time(NULL));

    // generate random starting state for the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[][COLS]) {
    // print the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void update_board(int board[][COLS]) {
    // create a copy of the board to make updates to without affecting the current state of the board
    int copy[ROWS][COLS];

    // copy the current state of the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            copy[i][j] = board[i][j];
        }
    }

    // update each cell in the copy
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // count the number of neighbors
            int neighbors = 0;

            if (i > 0) {
                if (copy[i - 1][j] == 1) {
                    neighbors++;
                }

                if (j > 0 && copy[i - 1][j - 1] == 1) {
                    neighbors++;
                }

                if (j < COLS - 1 && copy[i - 1][j + 1] == 1) {
                    neighbors++;
                }
            }

            if (i < ROWS - 1) {
                if (copy[i + 1][j] == 1) {
                    neighbors++;
                }

                if (j > 0 && copy[i + 1][j - 1] == 1) {
                    neighbors++;
                }

                if (j < COLS - 1 && copy[i + 1][j + 1] == 1) {
                    neighbors++;
                }
            }

            if (j > 0 && copy[i][j - 1] == 1) {
                neighbors++;
            }

            if (j < COLS - 1 && copy[i][j + 1] == 1) {
                neighbors++;
            }

            // update the cell based on the number of neighbors
            if (copy[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                board[i][j] = 0;
            } else if (copy[i][j] == 0 && neighbors == 3) {
                board[i][j] = 1;
            }
        }
    }
}

int main() {
    // initialize the board
    int board[ROWS][COLS];
    initialize_board(board);

    // print the initial state of the board
    printf("Initial state:\n");
    print_board(board);

    // iterate through each generation
    for (int g = 0; g < GENERATIONS; g++) {
        // wait for a brief moment
        usleep(5000);

        // clear the console
        system("clear");

        // update and print the board
        update_board(board);
        printf("Generation %d:\n", g + 1);
        print_board(board);
    }

    return 0;
}