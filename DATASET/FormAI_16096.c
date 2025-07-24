//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // change the value of N for a bigger or smaller matrix
#define BLOCKED 0
#define OPEN 1

int grid[N][N];
int virtual_grid[(N+2)*(N+2)];
int status[(N+2)*(N+2)];

int top_site, bottom_site;

// function to initialize values for the virtual grid
void initialize_virtual_grid() {
    for (int i = 0; i < (N+2)*(N+2); i++) {
        if (i <= N+1 || i >= ((N+2)*(N+2)) - N - 2) {
            virtual_grid[i] = -1;
            status[i] = BLOCKED;
            continue;
        }
        if (i % (N+2) == 0 || i % (N+2) == N+1) {
            virtual_grid[i] = -1;
            status[i] = BLOCKED;
            continue;
        }
        virtual_grid[i] = (i - (i / (N+2))) - (N+3);
        status[i] = BLOCKED;
    }
}

// function to connect two sites in the virtual grid
void connect(int site1, int site2) {
    virtual_grid[site1] = site2;
}

// function to check if two sites are connected in the virtual grid
int is_connected(int site1, int site2) {
    return virtual_grid[site1] == site2;
}

// function to check if a site can be opened
int is_openable(int row, int col) {
    if (row < 1 || row > N || col < 1 || col > N) {
        return 0;
    }
    int site_index = ((row+1)*(N+2)) + (col+1);
    return status[site_index] == BLOCKED;
}

// function to open a site
void open_site(int row, int col) {
    int site_index = ((row+1)*(N+2)) + (col+1);
    status[site_index] = OPEN;
    int neighbor_indexes[] = {site_index - 1, site_index + 1, site_index - (N+2), site_index + (N+2)};
    for (int i = 0; i < 4; i++) {
        if (status[neighbor_indexes[i]] == OPEN) {
            connect(site_index, neighbor_indexes[i]);
        }
    }
    if (row == 1) {
        connect(site_index, top_site);
    }
    if (row == N) {
        connect(site_index, bottom_site);
    }
}

// function to check if the top and bottom sites are connected in the virtual grid
int is_percolated() {
    return is_connected(top_site, bottom_site);
}

// function to print the grid
void print_grid() {
    printf("\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int site_index = ((i+1)*(N+2)) + (j+1);
            if (status[site_index] == OPEN) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    // initialize the virtual grid
    initialize_virtual_grid();

    // initialize the top and bottom sites
    top_site = 0;
    bottom_site = (N+2)*(N+2) - 1;

    // open sites randomly until it percolates
    srand(time(NULL));
    while (!is_percolated()) {
        int row = rand() % N + 1;
        int col = rand() % N + 1;
        if (is_openable(row, col)) {
            open_site(row, col);
        }
    }
    
    // print the final percolated grid
    print_grid();
    
    return 0;
}