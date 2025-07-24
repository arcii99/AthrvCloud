//FormAI DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 40

// function to print the current generation of cells
void print_generation(int generation[ROWS][COLUMNS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", generation[i][j] ? 'O' : '.');
        }
        printf("\n");
    }
}

// function to count the neighbors of a particular cell
int count_neighbors(int generation[ROWS][COLUMNS], int row, int column) {
    int count = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = column-1; j <= column+1; j++) {
            int r = (i + ROWS) % ROWS;
            int c = (j + COLUMNS) % COLUMNS;
            if (r == row && c == column) continue;
            if (generation[r][c]) count++;
        }
    }
    return count;
}

// function to update the generation of cells based on the rules of the Game of Life
void update_generation(int generation[ROWS][COLUMNS], int next_generation[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int neighbors = count_neighbors(generation, i, j);
            if (generation[i][j]) {
                if (neighbors < 2 || neighbors > 3) next_generation[i][j] = 0;
                else next_generation[i][j] = 1;
            }
            else {
                if (neighbors == 3) next_generation[i][j] = 1;
                else next_generation[i][j] = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int generation[ROWS][COLUMNS] = {0}; // initialize the current generation of cells to all 0's
    int next_generation[ROWS][COLUMNS]; // initialize the next generation of cells
    printf("Press any key to start the simulation...\n");
    getchar();
    while (1) {
        print_generation(generation);
        update_generation(generation, next_generation);
        int temp[ROWS][COLUMNS];
        memcpy(temp, generation, ROWS*COLUMNS*sizeof(int));
        memcpy(generation, next_generation, ROWS*COLUMNS*sizeof(int));
        memcpy(next_generation, temp, ROWS*COLUMNS*sizeof(int));
        usleep(100000); // pause for 100 milliseconds
    }
    return 0;
}