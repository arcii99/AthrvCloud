//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1000

bool isPercolate(int n, float p, int grid[n+2][n+2]) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(grid[i][j] == 0 && ((float)rand()/(float)RAND_MAX) < p) {
                grid[i][j] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(grid[n][i] == 1) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, numTrials;
    float p;
    printf("Enter the grid size (n): ");
    scanf("%d", &n);

    printf("Enter the probability of open site (p): ");
    scanf("%f", &p);

    printf("Enter the number of trials: ");
    scanf("%d", &numTrials);

    int count = 0;
    int grid[MAX_SIZE+2][MAX_SIZE+2] = {0};

    for(int i=1; i<=numTrials; i++) {
        if(isPercolate(n, p, grid)) {
            count++;
        }
    }

    float probability = (float)count/(float)numTrials;
    printf("Percolation threshold: %f\n", probability);

    return 0;
}