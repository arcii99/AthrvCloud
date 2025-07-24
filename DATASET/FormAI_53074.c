//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50 // grid size
#define PROB 0.6 // probability of site being open

int grid[SIZE][SIZE]; // grid to hold site statuses
int uf[SIZE*SIZE]; // union-find array
int sz[SIZE*SIZE]; // size of each union-find root

// Initialize union-find arrays
void UF_init() {
    for(int i = 0; i < SIZE*SIZE; i++) {
        uf[i] = i;
        sz[i] = 1;
    }
}

// Find root of union-find tree for given site
int UF_find(int x) {
    while(x != uf[x]) {
        uf[x] = uf[uf[x]];
        x = uf[x];
    }
    return x;
}

// Merge union-find trees for two sites
void UF_merge(int x, int y) {
    int rx = UF_find(x);
    int ry = UF_find(y);

    if(rx == ry) {
        return;
    }

    if(sz[rx] < sz[ry]) {
        int temp = rx;
        rx = ry;
        ry = temp;
    }

    uf[ry] = rx;
    sz[rx] += sz[ry];
}

// Generate random boolean value based on given probability
int rand_bool(double prob) {
    return (rand() < prob*RAND_MAX);
}

// Generate random grid
void grid_init() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            grid[i][j] = rand_bool(PROB);
        }
    }
}

// Check if site is open
int is_open(int row, int col) {
    return grid[row][col];
}

// Check if site is connected to top row
int is_full(int row, int col) {
    if(row == 0) {
        return 1;
    }
    for(int i = 0; i < SIZE; i++) {
        if(UF_find(SIZE*row + col) == UF_find(i)) {
            return 1;
        }
    }
    return 0;
}

// Check if system percolates
int percolates() {
    for(int i = 0; i < SIZE; i++) {
        if(is_open(SIZE-1,i) && is_full(SIZE-1,i)) {
            return 1;
        }
    }
    return 0;
}

// Print current grid
void print_grid() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    grid_init();
    UF_init();

    // Open random sites and merge connected components
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(is_open(i,j)) {
                if(i > 0 && is_open(i-1,j)) {
                    UF_merge(SIZE*i+j, SIZE*(i-1)+j);
                }
                if(j > 0 && is_open(i,j-1)) {
                    UF_merge(SIZE*i+j, SIZE*i+j-1);
                }
                if(i < SIZE-1 && is_open(i+1,j)) {
                    UF_merge(SIZE*i+j, SIZE*(i+1)+j);
                }
                if(j < SIZE-1 && is_open(i,j+1)) {
                    UF_merge(SIZE*i+j, SIZE*i+j+1);
                }
            }
        }
    }

    // Print results
    printf("Randomly generated grid:\n");
    print_grid();
    printf("System percolates: %s\n", percolates() ? "true" : "false");

    return 0;
}