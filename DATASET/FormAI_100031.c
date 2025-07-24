//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILL_PROB 0.6 // Probability of filling a site
#define SIZE 20 // Grid size

// Struct for a site
typedef struct {
    int x;
    int y;
    int filled;
} Site;

// Prints the grid
void print_grid(Site grid[SIZE][SIZE]) {
    int i, j;
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j].filled) {
                printf("█ ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Site grid[SIZE][SIZE];
    int i, j, k;

    // Initialize grid
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].filled = 0;
        }
    }

    // Fill random sites
    srand(time(NULL));
    for (k = 1; k <= 10; k++) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if ((double) rand() / RAND_MAX < FILL_PROB) {
                    grid[i][j].filled = 1;
                }
            }
        }
        print_grid(grid);
    }

    return 0;
}