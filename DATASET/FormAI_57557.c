//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define BLOCKED 0
#define OPEN 1
#define FULL 2

int grid[N][N];
int open_sites = 0;

void initialize_grid(){
    int i, j;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            grid[i][j] = BLOCKED;
        }
    }
}

int is_full(int row, int col){
    if (row < 0 || row >= N || col < 0 || col >= N) return 0;
    if (grid[row][col] == FULL || grid[row][col] == BLOCKED) return 0;
    if (grid[row][col] == OPEN) return 1;
    grid[row][col] = FULL;
    int full_top = is_full(row-1, col);
    int full_bottom = is_full(row+1, col);
    int full_left = is_full(row, col-1);
    int full_right = is_full(row, col+1);
    return full_top && full_bottom && full_left && full_right;
}

void open_site(int row, int col){
    if (grid[row][col] == BLOCKED){
        grid[row][col] = OPEN;
        open_sites++;
        if (is_full(row-1, col) || is_full(row+1, col) || is_full(row, col-1) || is_full(row, col+1)){
            is_full(row, col);
        }
    }
}

void print_grid(){
    int i, j;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void percolate(){
    while (1){
        int row = rand() % N;
        int col = rand() % N;
        open_site(row, col);
        if (open_sites >= N){
            int i;
            for (i=0; i<N; i++){
                if (is_full(N-1, i)){
                    printf("Percolates!\n");
                    return;
                }
            }
        }
    }
}

int main(){
    srand(time(NULL));
    initialize_grid();
    percolate();
    return 0;
}