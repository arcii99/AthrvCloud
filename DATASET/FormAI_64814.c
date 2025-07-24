//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the number of clusters
#define K 3

// Define the maximum number of iterations
#define MAX_ITERATIONS 100

// Define constant for convergence check
#define THRESHOLD 0.0001

int main() {
    // Initialize the data points
    float data_points[10][2] = {
        {2.0, 3.0},
        {2.0, 4.0},
        {4.0, 4.0},
        {6.0, 5.0},
        {7.0, 6.0},
        {3.0, 6.0},
        {4.0, 7.0},
        {6.0, 9.0},
        {7.0, 9.0},
        {8.0, 9.0}
    };

    // Track the centroids
    float centroids[K][2] = {{2.0, 3.0}, {3.0, 6.0}, {7.0, 9.0}};

    // Track which cluster each data point belongs to
    int clusters[10];

    // Initialize iteration and distance variables
    int i, j, k, n, iteration = 0;
    float distance[K];

    // Start the clustering algorithm
    while (iteration < MAX_ITERATIONS) {
        // Group data points into clusters
        for (i = 0; i < 10; i++) {
            for (j = 0; j < K; j++) {
                distance[j] = sqrt(pow(data_points[i][0] - centroids[j][0], 2.0) + pow(data_points[i][1] - centroids[j][1], 2.0));
            }
            n = 0;
            for (k = 0; k < K; k++) {
                if (distance[k] < distance[n]) {
                    n = k;
                }
            }
            clusters[i] = n;
        }

        // Recalculate centroids for each cluster
        float new_centroids[K][2] = {0.0};
        int count[K] = {0};
        for (i = 0; i < 10; i++) {
            new_centroids[clusters[i]][0] += data_points[i][0];
            new_centroids[clusters[i]][1] += data_points[i][1];
            count[clusters[i]]++;
        }
        for (i = 0; i < K; i++) {
            if (count[i] > 0) {
                centroids[i][0] = new_centroids[i][0] / count[i];
                centroids[i][1] = new_centroids[i][1] / count[i];
            }
        }

        // Check for convergence
        float sum = 0.0;
        for (i = 0; i < 10; i++) {
            sum += sqrt(pow(data_points[i][0] - centroids[clusters[i]][0], 2.0) + pow(data_points[i][1] - centroids[clusters[i]][1], 2.0));
        }
        if (sum < THRESHOLD) {
            break;
        }

        // Increment iteration variable
        iteration++;
    }

    // Output the final results
    printf("Data points:\n");
    for (i = 0; i < 10; i++) {
        printf("(%0.1f, %0.1f)\n", data_points[i][0], data_points[i][1]);
    }
    printf("\nCentroids:\n");
    for (i = 0; i < K; i++) {
        printf("(%0.1f, %0.1f)\n", centroids[i][0], centroids[i][1]);
    }
    printf("\nClusters:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", clusters[i]);
    }
    printf("\n");

    return 0;
}