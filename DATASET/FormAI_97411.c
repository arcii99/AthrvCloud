//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Change value of N to adjust size of percolation system

int grid[N][N]; // 2D array representing percolation grid
int virtual_top, virtual_bottom; // for use in virtual sites

void print_grid() {
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int root(int* arr, int i) {
    while(i != arr[i]) {
        i = arr[i];
    }
    return i;
}

void unify(int* arr, int* sz, int p, int q) {
    int i = root(arr, p);
    int j = root(arr, q);
    if(i == j) return;
    if(sz[i] < sz[j]) {
        arr[i] = j;
        sz[j] += sz[i];
    } else {
        arr[j] = i;
        sz[i] += sz[j];
    }
}

int is_percolated(int* arr, int p, int q) {
    if(root(arr, p) == root(arr, q)) {
        if(p < N && q < N*N-N) {
            unify(arr, arr+N*N, p, q+N);
        } else if(p > N*N-N-1 && q > N-1) {
            unify(arr, arr+N*N+1, p, q-N);
        } else if(p % N == 0 && q % N == N-1) {
            unify(arr, arr+N*N, p, q+1);
        } else if(p % N == N-1 && q % N == 0) {
            unify(arr, arr+N*N+1, p, q-1);
        } else if(p < N) {
            unify(arr, arr+N*N, p, q+N);
            unify(arr, arr+N*N+1, p, q-N);
            unify(arr, arr+N*N, p, q+1);
            unify(arr, arr+N*N+1, p, q-1);
        } else if(p > N*N-N-1) {
            unify(arr, arr+N*N+1, p, q-N);
            unify(arr, arr+N*N+1, p, q+1);
            unify(arr, arr+N*N, p, q-1);
            unify(arr, arr+N*N, p, q+N);
        } else if(q % N == 0) {
            unify(arr, arr+N*N+1, p, q-1);
            unify(arr, arr+N*N+1, p, q+N);
            unify(arr, arr+N*N, p, q-N);
            unify(arr, arr+N*N, p, q+1);
        } else if(q % N == N-1) {
            unify(arr, arr+N*N, p, q-N);
            unify(arr, arr+N*N, p, q+1);
            unify(arr, arr+N*N+1, p, q+1);
            unify(arr, arr+N*N+1, p, q-N);
        } else {
            unify(arr, arr+N*N, p, q-N);
            unify(arr, arr+N*N, p, q+1);
            unify(arr, arr+N*N+1, p, q-1);
            unify(arr, arr+N*N+1, p, q+N);
        }
        return 1; // return true if it percolates
    } else return 0; // return false otherwise
}

int percolates() {
    int arr[N*N];
    int sz[N*N];
    for(int i=0; i < N*N; i++) {
        arr[i] = i;
        sz[i] = 1;
    }
    virtual_top = N*N;
    virtual_bottom = N*N+1;
    for(int i=0; i < N; i++) {
        unify(arr, sz, virtual_top, i);
        unify(arr, sz, virtual_bottom, N*N-i-1);
    }
    for(int i=0; i < N*N; i++) {
        for(int j=0; j < N*N; j++) {
            if(grid[i/N][i%N] && grid[j/N][j%N] && is_percolated(arr, i, j)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL)); // for pseudo random number generation
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            grid[i][j] = (rand() % 2);
        }
    }
    printf("Initial grid:\n");
    print_grid();
    if(percolates()) {
        printf("Percolation has occurred!\n");
    } else {
        printf("Percolation has not occurred.\n");
    }
    return 0;
}