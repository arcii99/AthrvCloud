//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20

int grid[GRID_SIZE][GRID_SIZE];
int open_sites = 0;

void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                printf("⬜️ ");
            } else {
                printf("🟦 ");
            }
        }
        printf("\n");
    }
}

void open_site(int row, int col) {
    if (grid[row][col] == 0) {
        grid[row][col] = 1;
        open_sites++;
    }

    if (row > 0 && grid[row - 1][col] == 1) {
        union_sites(row, col, row - 1, col);
    }
    if (row < GRID_SIZE - 1 && grid[row + 1][col] == 1) {
        union_sites(row, col, row + 1, col);
    }
    if (col > 0 && grid[row][col - 1] == 1) {
        union_sites(row, col, row, col - 1);
    }
    if (col < GRID_SIZE - 1 && grid[row][col + 1] == 1) {
        union_sites(row, col, row, col + 1);
    }
}

void union_sites(int row1, int col1, int row2, int col2) {
    // TO DO: Implement union-find algorithm to connect sites
}

int main() {
    srand(time(NULL));

    // Initialize all sites as blocked
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // Open random sites until percolation is achieved
    while (open_sites < GRID_SIZE * GRID_SIZE) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        open_site(row, col);
        print_grid();
        printf("Open sites: %d\n", open_sites);
    }

    printf("Percolation achieved!\n");

    return 0;
}