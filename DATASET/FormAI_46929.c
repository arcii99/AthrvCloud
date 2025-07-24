//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int grid[N][N];
    srand(time(NULL));  // Seed the random number generator with current time

    // Fill the grid randomly with 0's and 1's
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Print the initial grid
    printf("Initial grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Perform the percolation simulation
    for (int i = 0; i < N; i++) {
        if (grid[0][i] == 1) {
            grid[0][i] = 2;  // Mark the top row as "occupied"
            printf("(%d, %d) is occupied!\n", 0, i);
        }
    }
    // Iterate over each row, marking cells as "occupied" if they are connected to an already occupied cell
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                if ((j > 0 && grid[i][j-1] == 2) || (j < N-1 && grid[i][j+1] == 2) || (i < N-1 && grid[i+1][j] == 2)) {
                    grid[i][j] = 2;  // Mark the cell as "occupied"
                    printf("(%d, %d) is occupied!\n", i, j);
                }
            }
        }
    }

    // Print the final grid
    printf("Final grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}