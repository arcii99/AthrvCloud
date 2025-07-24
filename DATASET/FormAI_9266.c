//FormAI DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_GENERATIONS 50
#define MAX_ROWS 40
#define MAX_COLS 60

void initialize_board(int board[MAX_ROWS][MAX_COLS]) {
    // fill board with random 0's and 1's
    srand(time(NULL));
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[MAX_ROWS][MAX_COLS]) {
    // print the board
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == 1)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

void update_board(int board[MAX_ROWS][MAX_COLS]) {
    int temp_board[MAX_ROWS][MAX_COLS] = {0};

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            int live_neighbors = 0;

            // count live neighbors
            for (int row = i-1; row <= i+1; row++) {
                for (int col = j-1; col <= j+1; col++) {
                    // check for boundaries
                    if (row < 0 || col < 0 || row >= MAX_ROWS || col >= MAX_COLS || (row == i && col == j))
                        continue;

                    if (board[row][col] == 1)
                        live_neighbors++;
                }
            }

            // update cell based on rules of Game of Life
            if (board[i][j] == 1 && live_neighbors < 2)
                temp_board[i][j] = 0;

            else if (board[i][j] == 1 && (live_neighbors == 2 || live_neighbors == 3))
                temp_board[i][j] = 1;

            else if (board[i][j] == 1 && live_neighbors > 3)
                temp_board[i][j] = 0;

            else if (board[i][j] == 0 && live_neighbors == 3)
                temp_board[i][j] = 1;

            else
                temp_board[i][j] = board[i][j];
        }
    }

    // copy temp_board to board
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}

int main() {
    int board[MAX_ROWS][MAX_COLS] = {0};
    int generation = 0;

    initialize_board(board);
    printf("Initial board:\n");
    print_board(board);

    while (generation < MAX_GENERATIONS) {
        update_board(board);
        printf("\nGeneration %d:\n", generation+1);
        print_board(board);
        generation++;
    }

    return 0;
}