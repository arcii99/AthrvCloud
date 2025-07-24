//FormAI DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void print_generation(int generation[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (generation[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int generation[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS) {
                if (i != row || j != col) {
                    count += generation[i][j];
                }
            }
        }
    }
    return count;
}

void update_generation(int generation[ROWS][COLS]) {
    int new_generation[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(generation, i, j);
            if (generation[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_generation[i][j] = 0;
                } else {
                    new_generation[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    new_generation[i][j] = 1;
                } else {
                    new_generation[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            generation[i][j] = new_generation[i][j];
        }
    }
}

int main() {
    int generation[ROWS][COLS] = {0};
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rand() % 3 == 0) {
                generation[i][j] = 1;
            }
        }
    }
    int generation_count = 1;
    while (1) {
        printf("Generation %d:\n", generation_count);
        print_generation(generation);
        update_generation(generation);
        generation_count++;
        printf("\n");
        // Wait for a moment to create a mind-bending effect
        for (int i = 0; i < 50000000; i++) {}
    }
    return 0;
}