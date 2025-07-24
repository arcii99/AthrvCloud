//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define EMPTY 0
#define BLOCKED 1
#define OPEN 2

void initialize_grid(int grid[N][N]) {
    int random_num;
    srand(time(NULL));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            random_num = rand()%101;
            if(random_num < 35) {
                grid[i][j] = BLOCKED;
            }
            else {
                grid[i][j] = EMPTY;
            }
        }
    }
}

void print_grid(int grid[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == BLOCKED) {
                printf(" X ");
            }
            else if(grid[i][j] == OPEN) {
                printf(" O ");
            }
            else {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

int percolation_check(int grid[N][N]) {
    int top_row_open = 0;
    for(int i=0; i<N; i++) {
        if(grid[0][i] == OPEN) {
            top_row_open++;
        }
    }
    if(top_row_open > 0) {
        for(int j=1; j<N; j++) {
            for(int i=0; i<N; i++) {
                if(grid[j][i] == OPEN && (grid[j-1][i] == OPEN || grid[j][i-1] == OPEN || grid[j][i+1] == OPEN)) {
                    continue;
                }
                if(i > 0 && grid[j][i-1] == OPEN && grid[j-1][i-1] == OPEN) {
                    continue;
                }
                if(i < N-1 && grid[j][i+1] == OPEN && grid[j-1][i+1] == OPEN) {
                    continue;
                }
                return 0;
            }
        }
        return 1;
    }
    else {
        return 0;
    }
}

void percolation_simulate(int grid[N][N]) {
    int i=1;
    while(!percolation_check(grid)) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == OPEN) {
                if(i > 0 && grid[i-1][j] == EMPTY) {
                    grid[i-1][j] = OPEN;
                }
                if(j > 0 && grid[i][j-1] == EMPTY) {
                    grid[i][j-1] = OPEN;
                }
                if(j < N-1 && grid[i][j+1] == EMPTY) {
                    grid[i][j+1] = OPEN;
                }
                if(i < N-1 && grid[i+1][j] == EMPTY) {
                    grid[i+1][j] = OPEN;
                }
            }
        }
        i++;
        if(i == N) {
            break;
        }
    }
    if(percolation_check(grid)) {
        printf("Percolates!\n");
    }
    else {
        printf("Does not percolate!\n");
    }
}

int main() {
    int grid[N][N];
    initialize_grid(grid);
    printf("Initial Grid\n");
    print_grid(grid);
    printf("\n");
    percolation_simulate(grid);
    printf("\nFinal Grid\n");
    print_grid(grid);
    return 0;
}