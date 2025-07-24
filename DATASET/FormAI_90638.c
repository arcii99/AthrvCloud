//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define PERCOLATED 1

int grid[N][N];
int visited[N][N];

void initialize_grid() {
    // Set all values to 0
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            grid[i][j] = 0;
        }
    }
}

void create_percolation_path() {
    // Set top row as open
    for(int i=0; i<N; i++) {
        grid[0][i] = 1;
    }

    // Create percolation path
    for(int i=1; i<N; i++) {
        for(int j=0; j<N; j++) {
            if((rand()%2 == 1 || j == 0) && grid[i-1][j] == 1) {
                grid[i][j] = 1;
            }
        }
    }
}

void print_grid() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void check_percolation() {
    // Check if bottom row is open
    for(int j=0; j<N; j++) {
        if(grid[N-1][j] == 1) {
            visited[N-1][j] = PERCOLATED;
        }
    }

    // Check percolation
    while(visited[0][0] != PERCOLATED && visited[N-1][N-1] != PERCOLATED) {
        for(int i=1; i<N-1; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j] == 1) {
                    // Check above
                    if(visited[i-1][j] == PERCOLATED) {
                        visited[i][j] = PERCOLATED;
                        continue;
                    }

                    // Check left
                    if(j > 0 && visited[i][j-1] == PERCOLATED) {
                        visited[i][j] = PERCOLATED;
                        continue;
                    }

                    // Check right
                    if(j < N-1 && visited[i][j+1] == PERCOLATED) {
                        visited[i][j] = PERCOLATED;
                        continue;
                    }

                    // Check below
                    if(i < N-1 && visited[i+1][j] == PERCOLATED) {
                        visited[i][j] = PERCOLATED;
                        continue;
                    }
                }
            }
        }
    }

    // Print results
    if(visited[0][0] == PERCOLATED || visited[N-1][N-1] == PERCOLATED) {
        printf("Percolation detected!\n");
    } else {
        printf("No percolation detected!\n");
    }
}

int main() {
    srand(time(NULL));

    initialize_grid();
    create_percolation_path();

    printf("Initial Grid: \n");
    print_grid();

    check_percolation();

    return 0;
}