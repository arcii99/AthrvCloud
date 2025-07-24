//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRIDSIZE 10
#define NUM_CLUSTERS 3

int grid[GRIDSIZE][GRIDSIZE]; // The grid we'll cluster

// Structure for a cluster
typedef struct cluster {
    int size;
    int xcoords[GRIDSIZE*GRIDSIZE]; // Max possible size
    int ycoords[GRIDSIZE*GRIDSIZE]; // Max possible size
} Cluster;

// Allocate memory for a new cluster
Cluster* new_cluster() {
    Cluster* c = (Cluster*) malloc(sizeof(Cluster));
    c->size = 0;
    return c;
}

// Create the clusters
void create_clusters(Cluster* clusters[]) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i] = new_cluster();
    }
}

// Generate random coordinates for the grid
void generate_grid() {
    srand(time(NULL));
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the grid to visualize
void print_grid() {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Helper function to add coordinates to a cluster
void add_coord(Cluster* c, int i, int j) {
    c->xcoords[c->size] = i;
    c->ycoords[c->size] = j;
    c->size++;
}

// Cluster the grid
void cluster_grid(Cluster* clusters[]) {
    int cluster_index = 0;
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (grid[i][j] == 1) {
                if (cluster_index == NUM_CLUSTERS) {
                    cluster_index = 0;
                }
                add_coord(clusters[cluster_index], i, j);
                cluster_index++;
            }
        }
    }
}

// Print the clusters
void print_clusters(Cluster* clusters[]) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:\n", i+1);
        for (int j = 0; j < clusters[i]->size; j++) {
            printf("(%d,%d) ", clusters[i]->xcoords[j], clusters[i]->ycoords[j]);
        }
        printf("\n");
    }
}

int main() {
    // Generate the grid
    generate_grid();
    printf("Grid:\n");
    print_grid();

    // Create the clusters
    Cluster* clusters[NUM_CLUSTERS];
    create_clusters(clusters);

    // Cluster the grid
    cluster_grid(clusters);

    // Print the clusters
    printf("Clusters:\n");
    print_clusters(clusters);

    return 0;
}