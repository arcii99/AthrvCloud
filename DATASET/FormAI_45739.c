//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000    // number of data points
#define K 5       // number of clusters
#define D 2       // number of dimensions

// Compute distance between two data points.
double distance(double *a, double *b) {
    double d = 0.0;
    for (int i = 0; i < D; i++) {
        d += pow(a[i] - b[i], 2);
    }
    return sqrt(d);
}

int main() {
    // Generate random data points.
    double data[N][D];
    srand(42);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Initialize cluster centers randomly.
    double centers[K][D];
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            centers[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Initialize cluster assignments.
    int assignments[N];
    for (int i = 0; i < N; i++) {
        assignments[i] = -1;
    }

    // Run k-means algorithm.
    int max_iterations = 100;
    int iterations = 0;
    while (iterations < max_iterations) {
        // Assign data points to nearest cluster center.
        for (int i = 0; i < N; i++) {
            double min_distance = INFINITY;
            int best_cluster = -1;
            for (int j = 0; j < K; j++) {
                double d = distance(data[i], centers[j]);
                if (d < min_distance) {
                    min_distance = d;
                    best_cluster = j;
                }
            }
            assignments[i] = best_cluster;
        }

        // Update cluster centers as mean of assigned points.
        double new_centers[K][D];
        int counts[K];
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < D; j++) {
                new_centers[i][j] = 0.0;
            }
            counts[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            int cluster = assignments[i];
            for (int j = 0; j < D; j++) {
                new_centers[cluster][j] += data[i][j];
            }
            counts[cluster]++;
        }
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < D; j++) {
                if (counts[i] > 0) {
                    centers[i][j] = new_centers[i][j] / counts[i];
                }
            }
        }

        iterations++;
    }

    // Print cluster assignments.
    for (int i = 0; i < K; i++) {
        printf("Cluster %d: ", i);
        for (int j = 0; j < N; j++) {
            if (assignments[j] == i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}