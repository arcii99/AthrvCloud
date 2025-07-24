//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void printGrid(int grid[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", grid[i][j] == 1 ? '#' : '.');
        }
        printf("\n");
    }
}

int percolates(int grid[][N]) {
    for (int i = 0; i < N; i++) {
        if (grid[0][i] == 1) {
            int visited[N] = { 0 };
            visited[i] = 1;
            for (int j = 1; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if ((grid[j][k] == 1) && (visited[k] || ((k > 0) && (visited[k-1])) || ((k < N-1) && (visited[k+1])))) {
                        visited[k] = 1;
                    }
                }
            }
            for (int j = 0; j < N; j++) {
                if ((grid[N-1][j] == 1) && visited[j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void simulate() {
    int grid[N][N] = { 0 };
    srand(time(NULL));
    int count = 0;
    while(!percolates(grid)) {
        int i = rand() % N;
        int j = rand() % N;
        if (grid[i][j] == 0) {
            grid[i][j] = 1;
            count++;
        }
    }
    printf("Percolated after %d attempts\n", count);
    printGrid(grid);
}

int main() {
    simulate();
    return 0;
}