//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define N 20

// Define the probability of a site being occupied
#define P 0.6

// Define the directions in which we will be checking sites
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Define the grid and an array to keep track of connections
int grid[N][N];
int connections[N*N];

// Define a function to initialize the grid
void initialize_grid() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize each site with probability p of being occupied
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double) rand() / RAND_MAX < P) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// Define a function to print the grid
void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

// Define a function to find the root of a site
int find_root(int site) {
    while (site != connections[site]) {
        connections[site] = connections[connections[site]];
        site = connections[site];
    }
    return site;
}

// Define a function to connect two sites
void connect(int site1, int site2) {
    int root1 = find_root(site1);
    int root2 = find_root(site2);
    if (root1 != root2) {
        connections[root1] = root2;
    }
}

// Define a function to check if a site is connected to the top
int is_connected_to_top(int site) {
    int root = find_root(site);
    for (int i = 0; i < N; i++) {
        int top_site = i;
        if (grid[0][top_site] && find_root(top_site) == root) {
            return 1;
        }
    }
    return 0;
}

// Define the main function
int main() {
    // Initialize the grid
    initialize_grid();

    // Initialize connections
    for (int i = 0; i < N*N; i++) {
        connections[i] = i;
    }

    // Connect sites in the first row to a virtual top site
    int virtual_top_site = N*N;
    for (int i = 0; i < N; i++) {
        if (grid[0][i]) {
            connect(i, virtual_top_site);
        }
    }

    // Percolate through the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                int site = N*i + j;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < N && y >= 0 && y < N && grid[x][y]) {
                        int neighbor_site = N*x + y;
                        connect(site, neighbor_site);
                    }
                }
            }
        }
    }

    // Check if the virtual top site is connected to the bottom
    int is_percolating = 0;
    for (int i = 0; i < N; i++) {
        int bottom_site = N*(N-1) + i;
        if (grid[N-1][i] && is_connected_to_top(bottom_site)) {
            is_percolating = 1;
        }
    }

    // Print the grid
    print_grid();

    // Print whether or not the grid is percolating
    if (is_percolating) {
        printf("The grid is percolating\n");
    } else {
        printf("The grid is not percolating\n");
    }

    return 0;
}