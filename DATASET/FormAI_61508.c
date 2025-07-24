//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

bool open[ROWS][COLS];
int parent[ROWS * COLS];
int size[ROWS * COLS];

int find(int p) {
    while (p != parent[p])
        p = parent[p];
    return p;
}

void union_(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);

    if (rootP == rootQ)
        return;

    if (size[rootP] > size[rootQ]) {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
    } else {
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
    }
}

bool isFull(int row, int col) {
    int p = (row * COLS) + col;

    if (!open[row][col])
        return false;

    for (int i = 0; i < COLS; i++)
        if (find(i) == find(p))
            return true;

    return false;
}

bool percolates(void) {
    for (int i = 0; i < COLS; i++)
        if (isFull(ROWS - 1, i))
            return true;
    return false;
}

void print_grid(void) {
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (open[row][col])
                printf("O ");
            else
                printf("X ");
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));

    for (int i = 0; i < ROWS * COLS; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    while (!percolates()) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (!open[row][col]) {
            open[row][col] = true;
            if ((col > 0) && open[row][col - 1])
                union_((row * COLS) + col, (row * COLS) + col - 1);
            if ((col < COLS - 1) && open[row][col + 1])
                union_((row * COLS) + col, (row * COLS) + col + 1);
            if ((row > 0) && open[row - 1][col])
                union_((row * COLS) + col, ((row - 1) * COLS) + col);
            if ((row < ROWS - 1) && open[row + 1][col])
                union_((row * COLS) + col, ((row + 1) * COLS) + col);
        }

        print_grid();
    }

    printf("\nPercolation achieved!\n");

    return 0;
}