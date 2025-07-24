//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size

int grid[N][N];
int parent[N*N];
int size[N*N];

// function to initialize the grid with random 0's and 1's
void initialize_grid() {
    srand(time(NULL));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            grid[i][j] = (rand() % 2);
        }
    }
}

// function to print the grid
void print_grid() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to find the root of a given site in the grid
int find(int i, int j) {
    int index = i*N + j;
    while(index != parent[index]) {
        parent[index] = parent[parent[index]];
        index = parent[index];
    }
    return index;
}

// function to merge two sites in the grid
void merge(int i1, int j1, int i2, int j2) {
    int root1 = find(i1, j1);
    int root2 = find(i2, j2);
    if(size[root1] < size[root2]) {
        parent[root1] = root2;
        size[root2] += size[root1];
    } else {
        parent[root2] = root1;
        size[root1] += size[root2];
    }
}

// function to check if the grid percolates
int percolates() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 1) {
                int index = find(i,j);
                if(index < N) { // check if site is in top row
                    for(int k=0; k<N; k++) {
                        int top_index = find(0,k);
                        if(index == top_index) {
                            return 1;
                        }
                    }
                }
                if(index >= (N-1)*N) { // check if site is in bottom row
                    for(int k=0; k<N; k++) {
                        int bottom_index = find(N-1,k);
                        if(index == bottom_index) {
                            return 1;
                        }
                    }
                }
                if((i > 0) && (grid[i-1][j] == 1)) { // check left neighbour
                    int left_index = find(i-1,j);
                    if(find(i,j) != left_index) {
                        merge(i,j,i-1,j);
                    }
                }
                if((j > 0) && (grid[i][j-1] == 1)) { // check top neighbour
                    int top_index = find(i,j-1);
                    if(find(i,j) != top_index) {
                        merge(i,j,i,j-1);
                    }
                }
                if((i < N-1) && (grid[i+1][j] == 1)) { // check right neighbour
                    int right_index = find(i+1,j);
                    if(find(i,j) != right_index) {
                        merge(i,j,i+1,j);
                    }
                }
                if((j < N-1) && (grid[i][j+1] == 1)) { // check bottom neighbour
                    int bottom_index = find(i,j+1);
                    if(find(i,j) != bottom_index) {
                        merge(i,j,i,j+1);
                    }
                }
            }
        }
    }
    return 0;
}

// main function
int main(void) {
    initialize_grid();
    printf("Initial grid:\n");
    print_grid();
    for(int i=0; i<N*N; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    int result = percolates();
    printf("Final grid:\n");
    print_grid();
    if(result) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    } 
    return 0;
}