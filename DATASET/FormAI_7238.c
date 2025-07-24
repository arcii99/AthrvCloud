//FormAI DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3
#define N 20

int main() {

    // Define some sample data points
    float points[N][2] = {{1, 1}, {1.5, 2}, {3, 4}, {5, 7}, {3.5, 5},
                          {4.5, 5}, {3.5, 4.5}, {4.5, 4}, {6, 4.5},
                          {5, 2}, {2, 2}, {1.5, 5}, {3, 1}, {5, 1},
                          {6.5, 1.5}, {7, 3}, {4, 7}, {6, 7.5},
                          {5, 8}, {5.5, 6}};

    // Define an array to hold the cluster labels for each data point
    int labels[N] = {0};

    // Define an array to hold the coordinates of the K centroids
    float centroids[K][2];

    // Initialize the centroids using a random sampling method
    for (int i = 0; i < K; i++) {
        int j = rand() % N;
        centroids[i][0] = points[j][0];
        centroids[i][1] = points[j][1];
    }

    // Iterate the K-means algorithm until convergence
    int iter = 0, max_iter = 100;
    float tolerance = 0.001, diff = 0;
    do {
        diff = 0;

        // Assign each data point to the closest centroid
        for (int i = 0; i < N; i++) {
            int closest_cluster = 0;
            float closest_dist = INFINITY;

            for (int j = 0; j < K; j++) {
                float dist = sqrt(pow(points[i][0] - centroids[j][0], 2) +
                                  pow(points[i][1] - centroids[j][1], 2));
                if (dist < closest_dist) {
                    closest_cluster = j;
                    closest_dist = dist;
                }
            }

            if (labels[i] != closest_cluster) {
                labels[i] = closest_cluster;
                diff += 1;
            }
        }

        // Recalculate the centroids based on the current cluster assignments
        for (int i = 0; i < K; i++) {
            float sum_x = 0, sum_y = 0, count = 0;

            for (int j = 0; j < N; j++) {
                if (labels[j] == i) {
                    sum_x += points[j][0];
                    sum_y += points[j][1];
                    count += 1;
                }
            }

            if (count > 0) {
                centroids[i][0] = sum_x / count;
                centroids[i][1] = sum_y / count;
            }
        }

        iter += 1;
    } while (diff > tolerance && iter < max_iter);

    // Print out the final cluster assignments
    for (int i = 0; i < N; i++) {
        printf("Point (%.1f, %.1f) assigned to Cluster %d\n", points[i][0], points[i][1], labels[i]);
    }

    return 0;
}