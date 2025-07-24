//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define p 0.5

void initialize(int arr[N][N], int size);
int check_percolation(int arr[N][N], int size);

int main(void) {
    int grid[N][N];
    int percolation = 0;
    
    initialize(grid, N);
    percolation = check_percolation(grid, N);

    if (percolation) {
        printf("Percolation achieved!\n");
    } else {
        printf("No percolation.\n");
    }
    
    return 0;
}

void initialize(int arr[N][N], int size) {
    srand(time(NULL));
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((double) rand() / RAND_MAX < p) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }
}

int check_percolation(int arr[N][N], int size) {
    int top[N][N];
    int bottom[N][N];
    int visited[N][N];
    int top_count = 0;
    int bottom_count = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            visited[i][j] = 0;
            
            if (i == 0) {
                top[i][j] = 1;
            } else {
                top[i][j] = 0;
            }
            
            if (i == size - 1) {
                bottom[i][j] = 1;
            } else {
                bottom[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < size; i++) {
        if (arr[0][i]) {
            top[0][i] = 1;
            top_count++;
        }
        
        if (arr[size - 1][i]) {
            bottom[size - 1][i] = 1;
            bottom_count++;
        }
    }
    
    while (top_count > 0 && bottom_count > 0) {
        int i, j;
        
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (visited[i][j] == 0 && top[i][j] == 1) {
                    visited[i][j] = 1;
                    
                    if (i > 0 && arr[i - 1][j]) {
                        top[i - 1][j] = 1;
                        top_count++;
                    }
                    
                    if (j > 0 && arr[i][j - 1]) {
                        top[i][j - 1] = 1;
                        top_count++;
                    }
                    
                    if (i < size - 1 && arr[i + 1][j]) {
                        top[i + 1][j] = 1;
                        top_count++;
                    }
                    
                    if (j < size - 1 && arr[i][j + 1]) {
                        top[i][j + 1] = 1;
                        top_count++;
                    }
                }
                
                if (visited[i][j] == 0 && bottom[i][j] == 1) {
                    visited[i][j] = 1;
                    
                    if (i > 0 && arr[i - 1][j]) {
                        bottom[i - 1][j] = 1;
                        bottom_count++;
                    }
                    
                    if (j > 0 && arr[i][j - 1]) {
                        bottom[i][j - 1] = 1;
                        bottom_count++;
                    }
                    
                    if (i < size - 1 && arr[i + 1][j]) {
                        bottom[i + 1][j] = 1;
                        bottom_count++;
                    }
                    
                    if (j < size - 1 && arr[i][j + 1]) {
                        bottom[i][j + 1] = 1;
                        bottom_count++;
                    }
                }
            }
        }
    }
    
    if (bottom_count > 0) {
        return 1;
    } else {
        return 0;
    }
}