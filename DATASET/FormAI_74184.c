//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

bool percolates(int arr[][N], int row) {
    for(int j = 0; j < N; j++) {
        if(arr[row][j] == 2) {
            return true;
        }
    }
    return false;
}

void print_grid(int arr[][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 0) {
                printf("⬜");
            } else if(arr[i][j] == 1) {
                printf("⬛");
            } else {
                printf("🔵");
            }
        }
        printf("\n");
    }
}

int main() {
    int grid[N][N];
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(rand() % 100 < 40) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    int row = 0;
    while(row < N) {
        int col = 0;
        while(col < N) {
            if(grid[row][col] == 1 && !percolates(grid, row)) {
                grid[row][col] = 2;
            }
            col++;
        }
        row++;
    }
    print_grid(grid);
    if(percolates(grid, 0)) {
        printf("\nThe grid percolates!\n");
    } else {
        printf("\nThe grid does not percolate :(\n");
    }
    return 0;
}