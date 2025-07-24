//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Size of the grid
#define N 10

// Probability of site being open
#define P 0.5

// Function to perform the union of two sites
void unionSites(int current[N][N], int a[], int b[]) {
    // Determine the parent of each site
    int rootA = a[0] * N + a[1];
    while (current[a[0]][a[1]] != rootA) {
        rootA = current[a[0]][a[1]];
        a[0] = rootA / N;
        a[1] = rootA % N;
    }
    int rootB = b[0] * N + b[1];
    while (current[b[0]][b[1]] != rootB) {
        rootB = current[b[0]][b[1]];
        b[0] = rootB / N;
        b[1] = rootB % N;
    }

    // If the roots are not the same, combine the trees
    if (rootA != rootB) {
        current[rootA/N][rootA%N] = rootB;
    }
}

int main() {
    int current[N][N];
    // Initialize the grid as closed and default root to itself
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            current[i][j] = i*N + j;
        }
    }

    // Randomly open sites
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if ((double)rand() / (double)RAND_MAX < P) {
                current[i][j] = -1;
            }
        }
    }

    // Union neighboring open sites
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (current[i][j] == -1) {
                if (i > 0 && current[i-1][j] == -1) {
                    unionSites(current, (int[]){i, j}, (int[]){i-1, j});
                }
                if (i < N-1 && current[i+1][j] == -1) {
                    unionSites(current, (int[]){i, j}, (int[]){i+1, j});
                }
                if (j > 0 && current[i][j-1] == -1) {
                    unionSites(current, (int[]){i, j}, (int[]){i, j-1});
                }
                if (j < N-1 && current[i][j+1] == -1) {
                    unionSites(current, (int[]){i, j}, (int[]){i, j+1});
                }
            }
        }
    }

    // Determine if the top and bottom are connected
    int topRoot = current[0][0];
    while (current[0][0] != -1) {
        topRoot = current[topRoot/N][topRoot%N];
    }
    int bottomRoot = current[N-1][N-1];
    while (current[N-1][N-1] != -1) {
        bottomRoot = current[bottomRoot/N][bottomRoot%N];
    }
    if (topRoot == bottomRoot) {
        printf("Percolation occured!\n");
    } else {
        printf("Percolation did not occur.\n");
    }

    return 0;
}