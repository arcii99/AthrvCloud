//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 20 // number of nodes per side
#define seed 111 // seed for srand function
#define p 0.6 // probability of a node being occupied

// function to randomly occupy nodes
void populate_lattice(int *lattice) {
    int i, j;
    double r;
    srand(seed);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            r = ((double)rand() / (double)RAND_MAX);
            if (r <= p) {
                *(lattice + i*N + j) = 1; // occupy node
            }
        }
    }
}

// function to print lattice
void print_lattice(int *lattice) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (*(lattice + i*N + j) == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

// function to calculate number of occupied nodes in cluster
int find_cluster_size(int *lattice, int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) {
        return 0;
    } else if (*(lattice + i*N + j) == 0) {
        return 0;
    } else {
        *(lattice + i*N + j) = 0; // mark node as visited
        return 1 + find_cluster_size(lattice, i+1, j) + find_cluster_size(lattice, i-1, j)
               + find_cluster_size(lattice, i, j+1) + find_cluster_size(lattice, i, j-1);
    }
}

// function to find largest cluster in lattice
int find_largest_cluster(int *lattice) {
    int i, j, size, max_size = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (*(lattice + i*N + j) == 1) {
                size = find_cluster_size(lattice, i, j);
                if (size > max_size) {
                    max_size = size;
                }
            }
        }
    }
    return max_size;
}

int main() {
    int lattice[N][N] = {0};
    int largest_cluster_size;
    populate_lattice((int*)lattice);
    printf("Lattice:\n");
    print_lattice((int*)lattice);
    largest_cluster_size = find_largest_cluster((int*)lattice);
    printf("Largest Cluster Size: %d\n", largest_cluster_size);
    return 0;
}