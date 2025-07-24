//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 1000 // Maximum number of points
#define MAX_ITERATIONS 100 // Maximum number of iterations
#define MAX_DISTANCE_SQUARED 100 // Maximum distance between points for them to be considered in the same cluster

int num_points;
int points[MAX_POINTS][2]; // 2D points in the form (x,y)
int clusters[MAX_POINTS]; // Cluster index for each point
int num_clusters = 0; // Total number of clusters

int get_distance_squared(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void print_clusters() {
    printf("Clusters:\n");
    for (int i=0; i<num_points; i++) {
        printf("(%d,%d) -> Cluster %d\n", points[i][0], points[i][1], clusters[i]);
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Generate random points
    printf("Generating random points...\n");
    num_points = rand() % MAX_POINTS + 1;
    for (int i=0; i<num_points; i++) {
        points[i][0] = rand() % 100;
        points[i][1] = rand() % 100;
        clusters[i] = -1; // Set initial cluster index to -1 (i.e. not yet assigned to a cluster)
    }
    
    // Perform clustering
    printf("Performing clustering...\n");
    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        // Check if all points have been assigned to a cluster
        int all_assigned = 1;
        for (int i=0; i<num_points; i++) {
            if (clusters[i] == -1) {
                all_assigned = 0;
                break;
            }
        }
        if (all_assigned) {
            printf("All points assigned to a cluster after %d iterations.\n", iteration);
            break;
        }
        
        // Initialize new cluster
        int new_cluster = num_clusters++;
        
        // Select a random unassigned point as the seed for the new cluster
        int seed_index;
        do {
            seed_index = rand() % num_points;
        } while (clusters[seed_index] != -1);
        clusters[seed_index] = new_cluster;
        int seed_x = points[seed_index][0];
        int seed_y = points[seed_index][1];
        
        // Assign all unassigned points within the maximum distance to the new cluster
        for (int i=0; i<num_points; i++) {
            if (clusters[i] == -1 && get_distance_squared(seed_x, seed_y, points[i][0], points[i][1]) <= MAX_DISTANCE_SQUARED) {
                clusters[i] = new_cluster;
            }
        }
        
        iteration++;
    }
    
    // Print clusters
    print_clusters();
    
    return 0;
}