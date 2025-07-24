//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10                            // Number of rows and columns
#define threshold 0.5                   // Probability threshold for site to be open

int uf[N * N], ufSize[N * N], isOpen[N][N], siteStatus[N * N];
// uf is the union-find array, ufSize[] is the size of each component
// isOpen[][] array stores whether site[i][j] is open or not
// siteStatus[] array stores whether site[i][j] is full, open, or blocked

int root(int x) {
    while (x != uf[x]) {
        uf[x] = uf[uf[x]];
        x = uf[x];
    }
    return x;
}

void unionFind(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (i == j) return;
    if (ufSize[i] < ufSize[j]) {
        uf[i] = j;
        ufSize[j] += ufSize[i];
    } else {
        uf[j] = i;
        ufSize[i] += ufSize[j];
    }
}

void connect(int row, int col, int newRow, int newCol) {
    if (newRow < 0 || newCol < 0 || newRow >= N || newCol >= N) return;
    if (isOpen[newRow][newCol]) unionFind(row * N + col, newRow * N + newCol);
}

void initialize() {
    // Initialize union-find variables
    for (int i = 0; i < N * N; i++) {
        uf[i] = i;
        ufSize[i] = 1;
    }
    // Initialize siteStatus[] and isOpen[][]
    for (int i = 0; i < N * N; i++) {
        siteStatus[i] = 0;
        int row = i / N;
        int col = i % N;
        isOpen[row][col] = (rand() / (double) RAND_MAX) < threshold ? 1 : 0;
    }
    // Connect top row to virtual top site
    for (int col = 0; col < N; col++) {
        unionFind(N * N, col);
    }
    // Connect bottom row to virtual bottom site
    for (int col = 0; col < N; col++) {
        unionFind((N - 1) * N + col, N * N + 1);
    }
}

void percolate() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isOpen[i][j]) {
                siteStatus[root(i * N + j)] = 1;
                connect(i, j, i - 1, j);
                connect(i, j, i + 1, j);
                connect(i, j, i, j - 1);
                connect(i, j, i, j + 1);
            }
        }
    }
    // Detect whether the system percolates
    if (root(N * N) == root(N * N + 1)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (siteStatus[root(i * N + j)] == 1) {
                    siteStatus[root(i * N + j)] = 2;
                }
            }
        }
    } else {
        for (int i = 0; i < N * N; i++) {
            if (siteStatus[root(i)] == 1) {
                siteStatus[root(i)] = 3;
            }
        }
    }
}

void display() {
    printf("  ");
    for (int j = 0; j < N; j++) printf(" %d", j);
    printf("  \n");
    printf("  ");
    for (int j = 0; j < N; j++) printf("--");
    printf("  \n");
    for (int i = 0; i < N; i++) {
        printf("%d|", i);
        for (int j = 0; j < N; j++) {
            if (siteStatus[root(i * N + j)] == 2) {
                printf("* ");
            } else if (siteStatus[root(i * N + j)] == 3) {
                printf("# ");
            } else if (isOpen[i][j] == 1) {
                printf("  ");
            } else {
                printf("X ");
            }
        }
        printf("|\n");
    }
    printf("  ");
    for (int j = 0; j < N; j++) printf("--");
    printf("  \n");
}

int main() {
    srand((unsigned int) time(NULL));  // Set the random seed based on current time
    initialize();                       // Initialize union-find array and isOpen[][]
    percolate();                        // Perform the percolation algorithm
    display();                          // Display the result
    return 0;
}