//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define EMPTY 0
#define BLOCKED 1
#define OPEN 2

int cells[N][N]; // the grid
int size; // number of open cells
int connected[N][N]; // will store the connected components of open cells
int labels[N][N]; // will store the label of each connected component

int count_components() {
    int max_label = 0;
    int i, j, k;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            connected[i][j] = 0;
        }
    }
    
    // Find connected components (in a dirty way, but it works for this small grid)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (cells[i][j] == OPEN && connected[i][j] == 0) {
                max_label++;
                labels[i][j] = max_label;
                connected[i][j] = max_label;
                
                // check neighbors
                for (k = 0; k < 4; k++) {
                    int ni = i + (k == 0) - (k == 1);
                    int nj = j + (k == 2) - (k == 3);
                    
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N && cells[ni][nj] == OPEN) {
                        if (connected[ni][nj] == 0) {
                            labels[ni][nj] = max_label;
                            connected[ni][nj] = max_label;
                        } else if (connected[ni][nj] != max_label) {
                            // merge the components
                            int old_label = connected[ni][nj];
                            for (int x = 0; x < N; x++) {
                                for (int y = 0; y < N; y++) {
                                    if (cells[x][y] == OPEN && connected[x][y] == old_label) {
                                        connected[x][y] = max_label;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return max_label;
}

void print_grid() {
    printf("  ");
    for (int i = 0; i < N; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < N; i++) {
        printf("%d ", i);
        for (int j = 0; j < N; j++) {
            if (cells[i][j] == EMPTY) {
                printf("  ");
            } else if (cells[i][j] == BLOCKED) {
                printf("X ");
            } else {
                printf("%d ", labels[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    // Initialize grid with blocked cells
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cells[i][j] = BLOCKED;
        }
    }
    
    // Open a random cell on each row
    for (int i = 0; i < N; i++) {
        int j = rand() % N;
        cells[i][j] = OPEN;
        size++;
    }
    
    printf("Initial grid:\n");
    print_grid();
    
    // Open cells until the grid percolates
    while (count_components() > 1) {
        int i = rand() % N;
        int j = rand() % N;
        
        if (cells[i][j] == BLOCKED) {
            cells[i][j] = OPEN;
            size++;
        }
    }
    
    printf("\nFinal grid after percolation:\n");
    print_grid();
    printf("%d open cells out of %d total cells (%.2f%%)\n", size, N*N, 100.0 * size / (N*N));
    
    return 0;
}