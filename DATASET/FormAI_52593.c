//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10
#define p .5

int grid[N][N];
bool visited[N][N];

void dfs(int row, int col) {
    visited[row][col] = true;
    if(row -1 >= 0 && grid[row-1][col] == 1 && !visited[row-1][col]) {
        dfs(row-1, col);
    }

    if(col -1 >= 0 && grid[row][col-1] == 1 && !visited[row][col-1]) {
        dfs(row, col-1);
    }

    if(row + 1 < N && grid[row+1][col] == 1 && !visited[row+1][col]) {
        dfs(row+1, col);
    }

    if(col + 1 < N && grid[row][col+1] == 1 && !visited[row][col+1]) {
        dfs(row, col+1);
    }
}

int find_largest_cluster() {
    int largest_cluster = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                largest_cluster++;
            }
        }
    }
    return largest_cluster;
}

int main() {
    srand(time(NULL));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(((float) rand() / RAND_MAX) < p) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
            visited[i][j] = false;
        }
    }

    printf("Initial grid:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    int largest_cluster = find_largest_cluster();
    
    printf("Number of clusters: %d\n", largest_cluster);
    return 0;
}