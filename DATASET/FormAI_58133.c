//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define MAX_SIZE 1000
#define MAX_ITERATIONS 1000000

// function to check if site is open
int is_open(int site, int *open_sites, int size) {
    return open_sites[site] == 1;
}

// function to open a site
void open_site(int site, int *open_sites, int size) {
    open_sites[site] = 1;
}

// function to check if system percolates
int percolates(int *open_sites, int size) {
    // create arrays to store visited sites
    int *top_visited = (int*) malloc(size * sizeof(int));
    int *bottom_visited = (int*) malloc(size * sizeof(int));

    // initialize visited sites to 0
    for (int i = 0; i < size; i++) {
        top_visited[i] = 0;
        bottom_visited[i] = 0;
    }

    // check top row
    for (int i = 0; i < size; i++) {
        if (is_open(i, open_sites, size)) {
            top_visited[i] = 1;
            // check neighboring sites
            if (i-1 >= 0 && is_open(i-1, open_sites, size)) {
                top_visited[i-1] = 1;
            }
            if (i+1 < size && is_open(i+1, open_sites, size)) {
                top_visited[i+1] = 1;
            }
        }
    }

    // check bottom row
    for (int i = size*(size-1); i < size*size; i++) {
        if (is_open(i, open_sites, size)) {
            bottom_visited[i-size*(size-1)] = 1;
            // check neighboring sites
            if (i-1 >= size*(size-1) && is_open(i-1, open_sites, size)) {
                bottom_visited[i-size*(size-1)-1] = 1;
            }
            if (i+1 < size*size && is_open(i+1, open_sites, size)) {
                bottom_visited[i-size*(size-1)+1] = 1;
            }
        }
    }

    // find path from top to bottom
    for (int i = 0; i < size; i++) {
        if (top_visited[i] && bottom_visited[i]) {
            free(top_visited);
            free(bottom_visited);
            return 1;
        }
    }

    free(top_visited);
    free(bottom_visited);
    return 0;
}

// main function
int main() {
    // initialize random seed
    srand(time(NULL));

    // initialize variables
    int size = 0;
    int iterations = 0;
    int open_sites[MAX_SIZE*MAX_SIZE];

    // get input from user
    printf("Enter size of grid (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);
    printf("Enter number of iterations (maximum %d): ", MAX_ITERATIONS);
    scanf("%d", &iterations);

    // initialize open sites to 0
    for (int i = 0; i < size*size; i++) {
        open_sites[i] = 0;
    }

    // run simulations
    int count = 0;
    for (int i = 0; i < iterations; i++) {
        // pick a random site to open
        int site = rand() % (size*size);
        if (!is_open(site, open_sites, size)) {
            open_site(site, open_sites, size);
            count++;
        }
        // check if system percolates
        if (percolates(open_sites, size)) {
            printf("Percolates after %d iterations\n", i+1);
            break;
        }
    }
    if (!percolates(open_sites, size)) {
        printf("Does not percolate after %d iterations\n", iterations);
    }

    return 0;
}