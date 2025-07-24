//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size
#define P 0.6 // probability of site being open

int main() {
    srand(time(NULL)); // seed random number generator
    
    // initialize grid with all sites closed
    int grid[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }
    
    // randomly open sites with probability P
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double) rand() / RAND_MAX < P) {
                grid[i][j] = 1;
            }
        }
    }
    
    // connect open sites to top using percolation algorithm
    int top[N];
    for (int i = 0; i < N; i++) {
        top[i] = 0;
    }
    for (int j = 0; j < N; j++) {
        if (grid[0][j] == 1) {
            top[j] = 1;
            for (int i = 1; i < N; i++) {
                if (grid[i][j] == 1) {
                    if (top[j-1] == 1 || top[j] == 1 || top[j+1] == 1) {
                        top[j] = 1;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    
    // determine if percolation occurred
    int percolation = 0;
    for (int j = 0; j < N; j++) {
        if (top[j] == 1 && grid[N-1][j] == 1) {
            percolation = 1;
            break;
        }
    }
    
    // print grid and percolation result
    printf("     ");
    for (int j = 0; j < N; j++) {
        printf("%d ", j);
    }
    printf("\n");
    printf("     ");
    for (int j = 0; j < N; j++) {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d | ", i);
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
    if (percolation == 1) {
        printf("Percolation occurred!\n");
    } else {
        printf("Percolation did not occur.\n");
    }
    
    return 0;
}