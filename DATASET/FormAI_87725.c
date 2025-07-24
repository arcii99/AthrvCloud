//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define P 0.6

int grid[N][N];
int size[N*N];
int count = 0;

void initialize() {
    int i, j;
    srand(time(NULL));
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if((double)rand()/RAND_MAX < P) {
                grid[i][j] = 1;
                size[count++] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
}

int root(int p) {
    while(p != size[p]) p = size[p];
    return p;
}

void unite(int p, int q) {
    int i = root(p), j = root(q);
    if(i == j) return;
    if(size[i] < size[j]) {
        size[j] += size[i];
        size[i] = j;
    }
    else {
        size[i] += size[j];
        size[j] = i;
    }
}

int is_percolating() {
    int i, j, top = N*N+1, bottom = N*N+2;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            int p = i*N+j;
            if(grid[i][j]) {
                if(i == 0) unite(p, top);
                if(i == N-1) unite(p, bottom);
                if(j > 0 && grid[i][j-1]) unite(p, p-1);
                if(j < N-1 && grid[i][j+1]) unite(p, p+1);
                if(i > 0 && grid[i-1][j]) unite(p, p-N);
                if(i < N-1 && grid[i+1][j]) unite(p, p+N);
            }
        }
    }
    return root(top) == root(bottom);
}

void print_grid() {
    int i, j;
    printf("\n");
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(grid[i][j]) {
                printf("* ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void print_size() {
    int i;
    printf("\n");
    for(i=0; i<N*N; i++) {
        printf("%d ", size[i]);
    }
    printf("\n");
}

int main() {
    initialize();
    print_grid();
    if(is_percolating()) {
        printf("System percolates!\n");
    }
    else {
        printf("System does not percolate.\n");
    }
    return 0;
}