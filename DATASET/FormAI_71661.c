//FormAI DATASET v1.0 Category: Game of Life ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50
#define GENERATIONS 500

int current_generation[ROWS][COLS];
int next_generation[ROWS][COLS];

/*
 * Function to print the current generation
 */
void print_generation(int generation[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (generation[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * Function to count the number of neighbors that are alive
 */
int count_alive_neighbors(int row, int col, int generation[ROWS][COLS])
{
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int r = (row + i + ROWS) % ROWS;
            int c = (col + j + COLS) % COLS;
            count += generation[r][c];
        }
    }

    count -= generation[row][col];

    return count;
}

/*
 * Function to update the next generation using the rules of the Game of Life
 */
void update_next_generation(int generation[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_alive_neighbors(i, j, generation);

            if (generation[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                next_generation[i][j] = 0;
            } else if (generation[i][j] == 0 && neighbors == 3) {
                next_generation[i][j] = 1;
            } else {
                next_generation[i][j] = generation[i][j];
            }
        }
    }

    // Copy the next generation to the current generation
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            generation[i][j] = next_generation[i][j];
        }
    }
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the current generation with random values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            current_generation[i][j] = rand() % 2;
        }
    }

    // Run the generations
    for (int i = 0; i < GENERATIONS; i++) {
        printf("Generation %d:\n", i);
        print_generation(current_generation);
        update_next_generation(current_generation);
    }

    return 0;
}