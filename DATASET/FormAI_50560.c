//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
// Ephemeral style C Percolation Simulator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare global variables
int ROWS, COLS, PERCOLATES, TOTAL_SITES;
int virtual_TOP, virtual_BOTTOM;

// Declare global arrays
int *sites;
int *connected;

// Declare functions
int get_index(int row, int col);
void union_sites(int a, int b);
void check_percolation();

// Main function
int main()
{
    srand(time(0)); // Seed random number generator
    
    // Initialize variables
    printf("Enter number of rows: ");
    scanf("%d", &ROWS);
    printf("Enter number of columns: ");
    scanf("%d", &COLS);
    PERCOLATES = 0;
    TOTAL_SITES = ROWS * COLS;
    virtual_TOP = 0;
    virtual_BOTTOM = TOTAL_SITES + 1;

    // Memory allocation
    sites = (int *) malloc((size_t) ((TOTAL_SITES + 2) * sizeof(int)));
    connected = (int *) malloc((size_t) ((TOTAL_SITES + 2) * sizeof(int)));

    // Initialize arrays
    for (int i = 0; i <= TOTAL_SITES + 1; i++) {
        sites[i] = 1;
        connected[i] = 0;
    }
    connected[virtual_TOP] = 1;
    connected[virtual_BOTTOM] = 1;

    // Algorithm
    while (!PERCOLATES) {
        int rand_site = rand() % TOTAL_SITES + 1;
        int row = (rand_site - 1) / COLS + 1;
        int col = (rand_site - 1) % COLS + 1;
        int site_index = get_index(row, col);
        sites[site_index] = 0;

        int neighbors[4] = {get_index(row - 1, col), get_index(row, col + 1), get_index(row + 1, col),
                            get_index(row, col - 1)};

        for (int i = 0; i < 4; i++) {
            if (sites[neighbors[i]] == 0)
                union_sites(site_index, neighbors[i]);
        }

        check_percolation();
    }

    // Output result
    printf("Percolation threshold: %f\n", (float) (--PERCOLATES) / TOTAL_SITES);

    // Free memory
    free(sites);
    free(connected);

    return 0;
}

// Function to calculate array index from row and column values
int get_index(int row, int col)
{
    if (row < 1 || row > ROWS || col < 1 || col > COLS)
        return 0;
    else
        return (row - 1) * COLS + col;
}

// Function to connect two sites
void union_sites(int a, int b)
{
    int root_a = a, root_b = b;
    while (root_a != connected[root_a])
        root_a = connected[root_a];
    while (root_b != connected[root_b])
        root_b = connected[root_b];
    if (root_a == root_b)
        return;
    connected[root_b] = root_a;
}

// Function to check for percolation
void check_percolation()
{
    for (int i = 1; i <= COLS; i++) {
        if (connected[i] == 1 && connected[get_index(ROWS, i)] == 1) {
            PERCOLATES = 1;
            break;
        }
    }
}