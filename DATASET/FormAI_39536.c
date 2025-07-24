//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

// define the grid size
#define N 10

// define probability for the site to open
#define P 0.6

// Define a structure for the site coordinates
typedef struct {
    int row;
    int col;
} site;

// The grid to store the open state of the sites
int grid[N][N];

// Function to check if the site is open
int is_open(site s) {
    
    return grid[s.row][s.col] == 1;
}

// Function to open a site
void open(site s) {
    
    grid[s.row][s.col] = 1;
}

// Function to check if a system percolates using depth-first search
int dfs(site s) {
    
    // If the site is in the last row, it is connected to the top
    if (s.row == N - 1) {
        return 1;
    }
    
    // Mark the current site as open
    open(s);
    
    // Check neighboring sites for openness
    site neighbors[] = {{s.row + 1, s.col}, {s.row, s.col + 1}, 
                        {s.row - 1, s.col}, {s.row, s.col - 1}};
    
    for (int i = 0; i < 4; i++) {
        site neighbor = neighbors[i];
        if (neighbor.row >= 0 && neighbor.row < N && neighbor.col >= 0 && neighbor.col < N) {
            if (is_open(neighbor)) {
                if (dfs(neighbor)) {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

// Function to simulate percolation
int percolate() {
    
    // Initialize the grid to be all closed sites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }
    
    // Open the sites with probability P
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double)rand() / (double)RAND_MAX < P) {
                open((site){i, j});
            }
        }
    }
    
    // Check if the system percolates
    for (int j = 0; j < N; j++) {
        if (dfs((site){0, j})) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    
    srand(time(NULL));
    
    printf("Percolation simulation...\n");
    printf("Grid size: %d x %d\n", N, N);
    printf("Site percolation probability: %f\n", P);
    
    int num_simulations = 100;
    int num_percolations = 0;
    
    // Perform multiple simulations to get an average percolation probability
    for (int i = 0; i < num_simulations; i++) {
        if (percolate()) {
            num_percolations++;
        }
    }
    
    double percolation_probability = (double)num_percolations / (double)num_simulations;
    
    printf("Percolation probability: %f\n", percolation_probability);
    
    return 0;
}