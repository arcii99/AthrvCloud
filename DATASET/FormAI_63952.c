//FormAI DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 30
#define MAX_GENERATIONS 100

/*
 * Returns the number of living neighbors for a given cell
 */
int count_neighbors(int arr[][COLS], int row_index, int col_index) {
    int count = 0;
    for(int row = row_index - 1; row <= row_index + 1; row++) {
        for(int col = col_index - 1; col <= col_index + 1; col++) {
            if(row == row_index && col == col_index) continue;
            if(row < 0 || row >= ROWS || col < 0 || col >= COLS) continue;
            if(arr[row][col] == 1) count++;
        }
    }
    return count;
}

/*
 * Updates the array with the next generation of cells
 */
void update_generation(int arr[][COLS], int buffer[][COLS]) {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            int neighbors = count_neighbors(arr, row, col);
            if(neighbors == 2) {
                buffer[row][col] = arr[row][col]; // cell stays the same
            } else if(neighbors == 3) {
                buffer[row][col] = 1; // cell becomes alive
            } else {
                buffer[row][col] = 0; // cell becomes dead
            }
        }
    }
    // Copy the buffer array into the original array
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            arr[row][col] = buffer[row][col];
        }
    }
}

int main() {
    int cells[ROWS][COLS] = {0}; // initialize all cells as dead
    int buffer[ROWS][COLS] = {0}; // buffer for new generation
    srand(time(NULL)); // seed the random number generator
    
    // Randomly set some cells to be alive
    for(int i = 0; i < ROWS * COLS / 4; i++) {
        int rand_row = rand() % ROWS;
        int rand_col = rand() % COLS;
        cells[rand_row][rand_col] = 1;
    }

    // Run the simulation for the specified number of generations
    for(int gen = 0; gen < MAX_GENERATIONS; gen++) {
        system("clear"); // clear the screen
        printf("\nGeneration %d:\n", gen);
        for(int row = 0; row < ROWS; row++) {
            for(int col = 0; col < COLS; col++) {
                if(cells[row][col] == 1) {
                    printf("O"); // alive cell
                } else {
                    printf("."); // dead cell
                }
            }
            printf("\n");
        }
        update_generation(cells, buffer);
    }
    
    return 0;
}