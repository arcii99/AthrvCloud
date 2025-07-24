//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the size of the grid and probability of sites being open
#define SIZE 30
#define P 0.5

int isOpen[SIZE+2][SIZE+2]; // Keeps track of each site's state
int clusters[SIZE+2][SIZE+2]; // ID of each cluster
int cluster_sizes[SIZE*SIZE]; // Keeps track of size of each cluster
int cluster_count; // Keeps track of number of clusters
int largest_cluster;

// Initializing all sites to be closed
void init_grid() {
    for(int i=0; i<SIZE+2; i++) {
        for(int j=0; j<SIZE+2; j++) {
            isOpen[i][j] = 0;
        }
    }
}

// Opening up sites with probability p
void open_sites() {
    for(int i=1; i<=SIZE; i++) {
        for(int j=1; j<=SIZE; j++) {
            if((double)rand() / RAND_MAX < P) isOpen[i][j] = 1;
        }
    }
}

// Prints out the current grid, marking open sites with "*"
void print_grid() {
    for(int i=1; i<=SIZE; i++) {
        for(int j=1; j<=SIZE; j++) {
            printf("%c ", isOpen[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

// Clears all clusters
void clear_clusters() {
    for(int i=0; i<SIZE+2; i++) {
        for(int j=0; j<SIZE+2; j++) {
            clusters[i][j] = 0;
        }
    }
    cluster_count = 0;
}

// Gathers all adjacent sites into one cluster
void gather_neighbors(int row, int col, int id) {
    // Check adjacent sites
    if(isOpen[row-1][col] && clusters[row-1][col] == 0) {
        clusters[row-1][col] = id;
        gather_neighbors(row-1, col, id);
    }
    if(isOpen[row+1][col] && clusters[row+1][col] == 0) {
        clusters[row+1][col] = id;
        gather_neighbors(row+1, col, id);
    }
    if(isOpen[row][col-1] && clusters[row][col-1] == 0) {
        clusters[row][col-1] = id;
        gather_neighbors(row, col-1, id);
    }
    if(isOpen[row][col+1] && clusters[row][col+1] == 0) {
        clusters[row][col+1] = id;
        gather_neighbors(row, col+1, id);
    }
}

// Labels clusters and gathers statistics
void cluster_and_stat() {
    clear_clusters();

    for(int i=1; i<=SIZE; i++) {
        for(int j=1; j<=SIZE; j++) {
            if(isOpen[i][j]) {
                if(clusters[i][j] == 0) {
                    cluster_count++;
                    clusters[i][j] = cluster_count;
                    cluster_sizes[cluster_count] = 1;
                    gather_neighbors(i, j, cluster_count);
                } else {
                    cluster_sizes[clusters[i][j]]++;
                }
            }
        }
    }

    // Find largest cluster
    largest_cluster = 0;
    for(int i=1; i<=cluster_count; i++) {
        if(cluster_sizes[i] > cluster_sizes[largest_cluster]) {
            largest_cluster = i;
        }
    }
}

int main() {
    srand(time(NULL));

    init_grid();
    open_sites();
    print_grid();
    printf("\n");

    int i=0;
    while(1) {
        i++;
        cluster_and_stat();
        printf("Iteration %d:\n", i);
        print_grid();
        printf("\n");
        printf("Number of clusters: %d\n", cluster_count);
        printf("Size of largest cluster: %d\n\n", cluster_sizes[largest_cluster]);
        if(cluster_sizes[largest_cluster] == SIZE*SIZE) break; // Percolation!
        for(int j=1; j<=cluster_sizes[largest_cluster]; j++) {
            int row, col;
            do {
                row = rand()%SIZE + 1;
                col = rand()%SIZE + 1;
            } while(clusters[row][col] != largest_cluster);
            isOpen[row][col] = 0; // Remove site from largest cluster
        }
    }

    printf("Percolation occurred after %d iterations.\n", i);
    printf("Size of largest cluster: %d\n", cluster_sizes[largest_cluster]);

    return 0;
}