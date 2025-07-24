//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

bool grid[N][N];

void initialize_grid() {
    srand(time(NULL));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int r = rand() % 10;
            if(r < 4) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }
}

bool is_percolating() {
    bool visited[N][N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            visited[i][j] = false;
        }
    }

    for(int i=0; i<N; i++) {
        if(grid[0][i]) {
            visited[0][i] = true;
            for(int j=1; j<N; j++) {
                if(grid[j][i] && !visited[j][i]) {
                    visited[j][i] = true;
                }
            }
        }
    }

    for(int i=1; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] && visited[i-1][j] && !visited[i][j]) {
                visited[i][j] = true;
                for(int k=0; k<N; k++) {
                    if(grid[i-1][k] && visited[i-1][k] && !visited[i][k]) {
                        visited[i][k] = true;
                    }
                }
            }
        }
    }

    for(int i=0; i<N; i++) {
        if(visited[N-1][i]) {
            return true;
        }
    }

    return false;
}

int main() {
    printf("Initializing grid...\n");
    initialize_grid();

    printf("Grid:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    if(is_percolating()) {
        printf("The grid is percolating!\n");
    } else {
        printf("The grid is not percolating.\n");
    }

    return 0;
}