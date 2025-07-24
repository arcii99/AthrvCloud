//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 10
#define NUM_CLUSTERS 2

// Struct for holding each point
typedef struct {
    double x;
    double y;
    int cluster_id; // Initialized to -1 for unassigned
} Point;

// Struct for holding the centroid of each cluster
typedef struct {
    double x;
    double y;
} Centroid;

int main() {

    // Generate random points
    Point points[NUM_POINTS];
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].x = (double)(rand() % 100);
        points[i].y = (double)(rand() % 100);
        points[i].cluster_id = -1; // Start with all points unassigned
    }

    // Initialize centroids randomly
    Centroid centroids[NUM_CLUSTERS];
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        centroids[i].x = (double)(rand() % 100);
        centroids[i].y = (double)(rand() % 100);
    }

    // Cluster until convergence (no point assignments change)
    int converged = 0;
    int num_iters = 0;
    while (!converged) {
        num_iters++;

        // Assign each point to the closest centroid
        for (int i = 0; i < NUM_POINTS; i++) {
            double min_dist = INFINITY;
            int closest_cluster_id;

            for (int j = 0; j < NUM_CLUSTERS; j++) {
                double dist = sqrt(pow(points[i].x - centroids[j].x, 2) + pow(points[i].y - centroids[j].y, 2));
                if (dist < min_dist) {
                    min_dist = dist;
                    closest_cluster_id = j;
                }
            }

            points[i].cluster_id = closest_cluster_id;
        }

        // Calculate new centroids based on mean of assigned points
        for (int i = 0; i < NUM_CLUSTERS; i++) {
            double sum_x = 0.0;
            double sum_y = 0.0;
            int count = 0;

            for (int j = 0; j < NUM_POINTS; j++) {
                if (points[j].cluster_id == i) {
                    sum_x += points[j].x;
                    sum_y += points[j].y;
                    count++;
                }
            }

            if (count > 0) {
                centroids[i].x = sum_x / (double)count;
                centroids[i].y = sum_y / (double)count;
            }
        }

        // Check for convergence by comparing old and new point assignments
        int all_assigned = 1;
        for (int i = 0; i < NUM_POINTS; i++) {
            if (points[i].cluster_id == -1) {
                all_assigned = 0;
                break;
            }
        }

        converged = all_assigned;
    }

    // Print final point assignments
    printf("Final point assignments:\n");
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("(%lf, %lf) assigned to cluster %d\n", points[i].x, points[i].y, points[i].cluster_id);
    }

    printf("Converged in %d iterations\n", num_iters);

    return 0;
}