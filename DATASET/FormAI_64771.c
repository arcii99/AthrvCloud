//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void percolate(int size, float p) {
    // create a 2D array to represent the grid
    int grid[size][size];
    // initialize the random seed
    srand(time(NULL));
    // fill the grid with blocked cells with probability (1 - p)
    // or open cells with probability p
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((float) rand() / RAND_MAX < p) {
                grid[i][j] = 1; // open cell
            } else {
                grid[i][j] = 0; // blocked cell
            }
        }
    }

    // mark the cells in the top and bottom rows that are open
    int top[size], bottom[size];
    for (int j = 0; j < size; j++) {
        if (grid[0][j] == 1) top[j] = 1;
        else top[j] = 0;
        if (grid[size - 1][j] == 1) bottom[j] = 1;
        else bottom[j] = 0;
    }

    // merge the open clusters
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 1 && grid[i+1][j] == 1) {
                int k = j;
                while (k < size && grid[i][k] == 1 && grid[i+1][k] == 1) {
                    grid[i][k] = 2;
                    grid[i+1][k] = 2;
                    k++;
                }
            }
        }
    }

    // determine if the grid percolates
    int percolates = 0;
    for (int j = 0; j < size; j++) {
        if (top[j] == 1 && bottom[j] == 1) {
            int i = 1;
            while (i < size && grid[i][j] != 2) {
                i++;
            }
            if (i < size) {
                percolates = 1;
                break;
            }
        }
    }

    // print the final grid
    printf("Final grid:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 0) printf("* ");
            else if (grid[i][j] == 1) printf("  ");
            else printf("# ");
        }
        printf("\n");
    }

    // print whether or not the grid percolates
    if (percolates) printf("The grid percolates.\n");
    else printf("The grid does not percolate.\n");
}

int main() {
    int size;
    float p;
    printf("Enter the size of the grid: ");
    scanf("%d", &size);
    printf("Enter the probability of an open cell (0 to 1): ");
    scanf("%f", &p);
    percolate(size, p);
    return 0;
}