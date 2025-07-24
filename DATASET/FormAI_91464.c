//FormAI DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_DIMENSIONS 2
#define NUM_POINTS 10
#define NUM_CLUSTERS 2
#define MAX_ITERATIONS 100

typedef struct {
    double x[NUM_DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point* points;
    int num_points;
} Cluster;

int main(void) {
    Point dataset[NUM_POINTS] = {{1, 2}, {2, 1}, {1, 3}, {2, 4}, {3, 5},
                                 {7, 5}, {8, 7}, {7, 6}, {10, 8}, {9, 9}};

    Cluster clusters[NUM_CLUSTERS];
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].centroid = dataset[i];
        clusters[i].points = malloc(NUM_POINTS * sizeof(Point));
        clusters[i].num_points = 0;
    }

    // k-means clustering algorithm
    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        // Assign each point to the closest cluster
        for (int i = 0; i < NUM_POINTS; i++) {
            double min_distance = INFINITY;
            int closest_cluster = 0;
            for (int j = 0; j < NUM_CLUSTERS; j++) {
                double distance = 0;
                for (int k = 0; k < NUM_DIMENSIONS; k++) {
                    distance += pow(dataset[i].x[k] - clusters[j].centroid.x[k], 2);
                }
                distance = sqrt(distance);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = j;
                }
            }
            clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = dataset[i];
        }

        // Recalculate the centroid of each cluster
        int converged = 1;
        for (int i = 0; i < NUM_CLUSTERS; i++) {
            Point old_centroid = clusters[i].centroid;
            for (int j = 0; j < NUM_DIMENSIONS; j++) {
                double sum = 0;
                for (int k = 0; k < clusters[i].num_points; k++) {
                    sum += clusters[i].points[k].x[j];
                }
                clusters[i].centroid.x[j] = sum / clusters[i].num_points;
            }
            if (old_centroid.x[0] != clusters[i].centroid.x[0] || old_centroid.x[1] != clusters[i].centroid.x[1]) {
                converged = 0;
            }
        }
        if (converged) {
            break;
        }

        // Reset the points for each cluster
        for (int i = 0; i < NUM_CLUSTERS; i++) {
            clusters[i].num_points = 0;
        }

        iteration++;
    }

    // Print the results
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x[0], clusters[i].points[j].x[1]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        free(clusters[i].points);
    }

    return EXIT_SUCCESS;
}