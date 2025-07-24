//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 6 // Number of data points
#define DIMENSIONS 2 // Number of dimensions for each data point

struct point {
    int id; // Unique identifier for the data point
    double coords[DIMENSIONS]; // Coordinates in each dimension
};

int main() {
    struct point points[NUM_POINTS] = {
        {1, {1.0, 2.0}},
        {2, {2.0, 1.0}},
        {3, {5.0, 8.0}},
        {4, {8.0, 5.0}},
        {5, {10.0, 10.0}},
        {6, {12.0, 12.0}}
    };
    
    int num_clusters = 2; // Number of clusters to form
    struct point centroids[num_clusters]; // Array to hold centroid for each cluster
    int labels[NUM_POINTS]; // Array to hold labels for each data point
    
    // Initialize centroids randomly
    for (int i = 0; i < num_clusters; i++) {
        int rand_index = rand() % NUM_POINTS;
        centroids[i] = points[rand_index];
    }
    
    // Repeat until convergence
    int max_iterations = 10;
    for (int iter = 0; iter < max_iterations; iter++) {
        // Assign each point to the closest cluster
        for (int i = 0; i < NUM_POINTS; i++) {
            double min_dist = INFINITY;
            int closest_cluster = -1;
            for (int j = 0; j < num_clusters; j++) {
                double dist = 0.0;
                for (int k = 0; k < DIMENSIONS; k++) {
                    double diff = points[i].coords[k] - centroids[j].coords[k];
                    dist += diff * diff;
                }
                dist = sqrt(dist);
                if (dist < min_dist) {
                    min_dist = dist;
                    closest_cluster = j;
                }
            }
            labels[i] = closest_cluster;
        }
        
        // Update centroids for each cluster
        for (int i = 0; i < num_clusters; i++) {
            int num_points_in_cluster = 0;
            double sum_coords[DIMENSIONS] = {0};
            for (int j = 0; j < NUM_POINTS; j++) {
                if (labels[j] == i) {
                    num_points_in_cluster++;
                    for (int k = 0; k < DIMENSIONS; k++) {
                        sum_coords[k] += points[j].coords[k];
                    }
                }
            }
            for (int k = 0; k < DIMENSIONS; k++) {
                centroids[i].coords[k] = sum_coords[k] / num_points_in_cluster;
            }
        }
    }
    
    // Print results
    for (int i = 0; i < num_clusters; i++) {
        printf("Centroid for cluster %d: (%f, %f)\n", i+1, centroids[i].coords[0], centroids[i].coords[1]);
    }
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("Data point %d belongs to cluster %d\n", points[i].id, labels[i]+1);
    }
    
    return 0;
}