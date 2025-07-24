//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10     // change this to adjust the grid size
#define PERCOLATION_THRESHOLD 0.6   // change this to adjust the percolation threshold

typedef struct {
    int id;
    int parent;
} Site;

Site grid[GRID_SIZE * GRID_SIZE];   // the grid of sites
int top_virtual_node, bottom_virtual_node;   // the virtual nodes for the top and bottom rows
int open_site_count;   // the number of open sites
int percolates;    // flag for percolation status

// function to initialize the grid
void initialize() {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            int index = i * GRID_SIZE + j;
            grid[index].id = index;
            grid[index].parent = -1;
        }
    }
    top_virtual_node = GRID_SIZE * GRID_SIZE;
    bottom_virtual_node = GRID_SIZE * GRID_SIZE + 1;
    open_site_count = 0;
    percolates = 0;
}

// function to find the root of a site's cluster
int find(int p) {
    while (grid[p].parent != -1) {
        p = grid[p].parent;
    }
    return p;
}

// function to merge two clusters
void union_sites(int p, int q) {
    int root_p = find(p);
    int root_q = find(q);
    grid[root_p].parent = root_q;
}

// function to determine if two sites are connected
int is_connected(int p, int q) {
    return find(p) == find(q);
}

// function to open a site
void open(int i, int j) {
    int index = i * GRID_SIZE + j;
    grid[index].parent = -1;
    open_site_count++;
    if (i == 0) {
        union_sites(index, top_virtual_node);
    }
    if (i == GRID_SIZE - 1) {
        union_sites(index, bottom_virtual_node);
    }
    if (i > 0 && grid[index - GRID_SIZE].parent != -1) {
        union_sites(index, index - GRID_SIZE);
    }
    if (i < GRID_SIZE - 1 && grid[index + GRID_SIZE].parent != -1) {
        union_sites(index, index + GRID_SIZE);
    }
    if (j > 0 && grid[index - 1].parent != -1) {
        union_sites(index, index - 1);
    }
    if (j < GRID_SIZE - 1 && grid[index + 1].parent != -1) {
        union_sites(index, index + 1);
    }
}

// function to check if the system percolates
void check_percolation() {
    if (is_connected(top_virtual_node, bottom_virtual_node)) {
        percolates = 1;
    }
}

int main() {
    srand(time(NULL));   // seed the random number generator
    int i, j;
    initialize();
    while (!percolates) {   // continue until the system percolates
        for (i = 0; i < GRID_SIZE; i++) {
            for (j = 0; j < GRID_SIZE; j++) {
                if (grid[i * GRID_SIZE + j].parent == -1) {   // skip open sites
                    continue;
                }
                if ((double) rand() / RAND_MAX < PERCOLATION_THRESHOLD) {   // open a site with the probability given by the threshold
                    open(i, j);
                }
            }
        }
        check_percolation();
    }
    printf("The system percolates with a percolation threshold of %f\n", PERCOLATION_THRESHOLD);
    printf("The total number of open sites is %d\n", open_site_count);
    return 0;
}