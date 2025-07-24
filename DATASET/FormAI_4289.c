//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int id[N * N], sz[N * N], open[N][N];

int root(int i, int j) {
    int p = i * N + j;
    while (p != id[p]) {
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

void unionRoot(int p, int q) {
    int i = root(p / N, p % N);
    int j = root(q / N, q % N);

    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int connected(int p, int q) {
    return root(p / N, p % N) == root(q / N, q % N);
}

void printGrid() {
    printf("-------------------\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (open[i][j] == 1) printf("[ ]");
            else printf("[X]");
        }
        printf("\n");
    }
    printf("-------------------\n");
}

void percolate() {
    for (int i = 0; i < N*N; i++) {
        int randRow = rand() % N;
        int randCol = rand() % N;
        int current = randRow * N + randCol;
        int top = current - N;
        int bottom = current + N;
        int left = current - 1;
        int right = current + 1;

        if (open[randRow][randCol] == 0) {
            open[randRow][randCol] = 1;
            if (top >= 0 && open[top / N][top % N] == 1) unionRoot(current, top);
            if (bottom < N*N && open[bottom / N][bottom % N] == 1) unionRoot(current, bottom);
            if (left >= 0 && open[left / N][left % N] == 1) unionRoot(current, left);
            if (right < N*N && open[right / N][right % N] == 1) unionRoot(current, right);
        }

        if (connected(0, N*N-1)) break;

        printGrid();
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < N*N; i++) {
        id[i] = i;
        sz[i] = 1;
        open[i / N][i % N] = 0;
    }

    percolate();
    if (connected(0, N*N-1)) printf("The system percolates\n");
    else printf("The system does not percolate\n");

    return 0;
}