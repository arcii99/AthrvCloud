//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Function for printing the grid
void print_grid(int grid[SIZE][SIZE]) {
    printf("Percolation Grid:\n\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("[]");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Union find data structure for percolation
int find(int parents[], int x) {
    if (parents[x] == x) {
        return x;
    }
    parents[x] = find(parents, parents[x]);
    return parents[x];
}

void union_sets(int parents[], int size[], int x, int y) {
    int root_x = find(parents, x);
    int root_y = find(parents, y);
    if (root_x == root_y) {
        return;
    }
    if (size[root_x] < size[root_y]) {
        int temp = root_x;
        root_x = root_y;
        root_y = temp;
    }
    parents[root_y] = root_x;
    size[root_x] += size[root_y];   
}

int main() {
    srand(time(NULL));

    int percolation_grid[SIZE][SIZE]; // 0 = closed, 1 = open
    int parent[SIZE * SIZE];
    int size[SIZE * SIZE];

    // Initialize grid, parent array, and size array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            percolation_grid[i][j] = 0;
            parent[i * SIZE + j] = i * SIZE + j;
            size[i * SIZE + j] = 1;
        }
    }

    // Open top and bottom row
    for (int i = 0; i < SIZE; i++) {
        percolation_grid[0][i] = 1;
        percolation_grid[SIZE - 1][i] = 1;
    }

    // Randomly open sites until percolation occurs
    int num_open = 0;
    while (find(parent, 0) != find(parent, (SIZE * SIZE) - 1)) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (percolation_grid[row][col] == 0) {
            percolation_grid[row][col] = 1;
            num_open++;
            if (row > 0 && percolation_grid[row - 1][col] == 1) {
                union_sets(parent, size, row * SIZE + col, (row - 1) * SIZE + col);
            }
            if (row < SIZE - 1 && percolation_grid[row + 1][col] == 1) {
                union_sets(parent, size, row * SIZE + col, (row + 1) * SIZE + col);
            }
            if (col > 0 && percolation_grid[row][col - 1] == 1) {
                union_sets(parent, size, row * SIZE + col, row * SIZE + col - 1);
            }
            if (col < SIZE - 1 && percolation_grid[row][col + 1] == 1) {
                union_sets(parent, size, row * SIZE + col, row * SIZE + col + 1);
            }
        }
    }

    printf("Percolation Threshold: %.2f%%\n", (double) num_open / (SIZE * SIZE) * 100);

    print_grid(percolation_grid);

    return 0;
}