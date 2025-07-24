//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

typedef struct {
    int row, col;
} site;

void initialize_grid(int grid[][GRID_SIZE]);
void print_grid(int grid[][GRID_SIZE]);
int root_of_site(int site, int roots[]);
int is_connected(int p, int q, int roots[]);
void merge_sites(int p, int q, int roots[], int sizes[]);

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    initialize_grid(grid);
    printf("Initial grid:\n");
    print_grid(grid);

    int roots[GRID_SIZE * GRID_SIZE];
    int sizes[GRID_SIZE * GRID_SIZE];
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        roots[i] = i;
        sizes[i] = 1;
    }

    // randomly open sites until top and bottom are connected
    srand(time(NULL));
    while (!is_connected(0, GRID_SIZE * GRID_SIZE - 1, roots)) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        if (grid[row][col] == 0) {
            grid[row][col] = 1;
            site current_site = {row, col};
            int current_site_index = row * GRID_SIZE + col;
            // check top neighbor
            if (row > 0 && grid[row - 1][col] == 1) {
                int top_neighbor_index = (row - 1) * GRID_SIZE + col;
                merge_sites(current_site_index, top_neighbor_index, roots, sizes);
            }
            // check bottom neighbor
            if (row < GRID_SIZE - 1 && grid[row + 1][col] == 1) {
                int bottom_neighbor_index = (row + 1) * GRID_SIZE + col;
                merge_sites(current_site_index, bottom_neighbor_index, roots, sizes);
            }
            // check left neighbor
            if (col > 0 && grid[row][col - 1] == 1) {
                int left_neighbor_index = row * GRID_SIZE + col - 1;
                merge_sites(current_site_index, left_neighbor_index, roots, sizes);
            }
            // check right neighbor
            if (col < GRID_SIZE - 1 && grid[row][col + 1] == 1) {
                int right_neighbor_index = row * GRID_SIZE + col + 1;
                merge_sites(current_site_index, right_neighbor_index, roots, sizes);
            }
        }
    }
    printf("Final grid:\n");
    print_grid(grid);
}

// initialize grid with all sites closed
void initialize_grid(int grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// print the current state of the grid
void print_grid(int grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j] == 1 ? '*' : '-');
        }
        printf("\n");
    }
}

// find the root of a site in the union-find data structure
int root_of_site(int site, int roots[]) {
    while (site != roots[site]) {
        site = roots[site];
    }
    return site;
}

// check if two sites are connected in the union-find data structure
int is_connected(int p, int q, int roots[]) {
    return root_of_site(p, roots) == root_of_site(q, roots);
}

// merge two sites in the union-find data structure
void merge_sites(int p, int q, int roots[], int sizes[]) {
    int root_p = root_of_site(p, roots);
    int root_q = root_of_site(q, roots);
    if (root_p != root_q) {
        if (sizes[root_p] >= sizes[root_q]) {
            roots[root_q] = root_p;
            sizes[root_p] += sizes[root_q];
        } else {
            roots[root_p] = root_q;
            sizes[root_q] += sizes[root_p];
        }
    }
}