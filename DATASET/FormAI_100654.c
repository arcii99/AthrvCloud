//FormAI DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Game of Life implementation */
void generate_next_generation(int rows, int cols, int current[rows][cols], int next[rows][cols]) {
    // iterate through all cells
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int count = 0;
            // count live neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (i+x >= 0 && i+x < rows && j+y >= 0 && j+y < cols && (x != 0 || y != 0)) {
                        if (current[i+x][j+y]) count++;
                    }
                }
            }

            // apply rules to determine next state of cell
            if (current[i][j]) {
                if (count == 2 || count == 3) next[i][j] = 1;
                else next[i][j] = 0;
            } else {
                if (count == 3) next[i][j] = 1;
                else next[i][j] = 0;
            }
        }
    }
}

void print_board(int rows, int cols, int board[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j]) printf("*");
            else printf("-");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed random number generator

    int rows = 10;
    int cols = 10;
    int board[rows][cols];
    int next[rows][cols];

    // initialize board randomly
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // print initial board state
    printf("Initial state:\n");
    print_board(rows, cols, board);

    // simulate 10 generations
    for (int generation = 1; generation <= 10; generation++) {
        generate_next_generation(rows, cols, board, next);
        // copy next state to current state
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = next[i][j];
            }
        }
        // print current board state
        printf("\nGeneration %d:\n", generation);
        print_board(rows, cols, board);
    }

    return 0;
}