//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: excited
// Welcome to the exciting world of Percolation Simulation in C!

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int grid[100][100]; // Initialize a 100x100 grid
int open[100]; // Keep track of open sites
int size; // Size of the grid

int root(int i) {
    // Finds the root of each element in the grid
    while(i != grid[i/size][i%size]) {
        grid[i/size][i%size] = grid[grid[i/size][i%size]/size][grid[i/size][i%size]%size];
        i = grid[i/size][i%size];
    }
    return i;
}

void make_union(int p, int q) {
    // Connects two open sites
    int i = root(p);
    int j = root(q);
    grid[i/size][i%size] = j;
}

int open_site() {
    // Generates a random integer between 0 and size^2 - 1
    int site;
    do {
        site = (rand() % (size*size));
    } while(open[site]); // Tries again if site is already open
    open[site] = 1; // Marks the site as open
    return site;
}

int percolates() {
    // Checks if the top row and bottom row of the grid are connected
    for(int i = 0; i < size; i++) {
        if(grid[0][i] == grid[(size-1)][i]) {
            return 1;
        }
    }
    return 0;
}

void percolation_simulator() {
    // The exciting Percolation Simulator
    int num_of_open_sites = 0, site, row, column;
    printf("Enter the size of the grid: ");
    scanf("%d", &size);

    // Initialize all sites to blocked
    for(int i = 0; i < size*size; i++) {
        grid[i/size][i%size] = i;
    }

    // Seed the random number generator
    srand(time(NULL));

    while(!percolates()) {
        site = open_site();
        num_of_open_sites++;
        row = site / size;
        column = site % size;

        // Connect to the left
        if(column > 0 && open[((row*size) + column - 1)]) {
            make_union(site, site-1);
        }

        // Connect to the right
        if(column < (size-1) && open[((row*size) + column + 1)]) {
            make_union(site, site+1);
        }

        // Connect to the top
        if(row > 0 && open[((row-1)*size) + column]) {
            make_union(site, site-size);
        }

        // Connect to the bottom
        if(row < (size-1) && open[((row+1)*size) + column]) {
            make_union(site, site+size);
        }
    }

    // Print the results
    printf("The grid has percolated!\n");
    printf("Total number of open sites = %d\n", num_of_open_sites);
    printf("Percolation threshold = %f", ((float)num_of_open_sites/(size*size)));

}

int main() {
    percolation_simulator();
    return 0;
}