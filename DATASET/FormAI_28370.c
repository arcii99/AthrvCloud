//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define W 3       // Number of dimensions
#define N 100     // Number of data points
#define K 4       // Number of clusters

struct Point {
    double coords[W];  // Coordinates of the point
    int cluster;       // Cluster assignment
};

// Helper function to generate random double
double rand_double(double min, double max) {
    return (double)(rand()) / RAND_MAX * (max - min) + min;
}

// Main function
int main() {
    // Initialize data points
    struct Point points[N];
    for (int i=0; i<N; i++) {
        for (int j=0; j<W; j++) {
            points[i].coords[j] = rand_double(-10, 10);  // Randomize coordinates
        }
        points[i].cluster = -1;  // Initialize cluster assignment
    }

    // Initialize centroids
    struct Point centroids[K];
    for (int i=0; i<K; i++) {
        for (int j=0; j<W; j++) {
            centroids[i].coords[j] = rand_double(-5, 5);
        }
    }

    // Initialize iteration variables
    int iter = 0;
    int changed = 1;

    // Begin clustering
    while (changed && iter < 100) {
        // Cluster assignment step
        changed = 0;
        for (int i=0; i<N; i++) {
            double min_dist = INFINITY;
            for (int j=0; j<K; j++) {
                double dist = 0;
                for (int d=0; d<W; d++) {
                    dist += pow(points[i].coords[d] - centroids[j].coords[d], 2);
                }
                dist = sqrt(dist);
                if (dist < min_dist) {
                    min_dist = dist;
                    points[i].cluster = j;
                }
            }
            if (points[i].cluster != -1) {
                changed = 1;
            }
        }

        // Centroid update step
        for (int j=0; j<K; j++) {
            int cnt = 0;
            for (int d=0; d<W; d++) {
                double sum = 0;
                for (int i=0; i<N; i++) {
                    if (points[i].cluster == j) {
                        sum += points[i].coords[d];
                        cnt++;
                    }
                }
                centroids[j].coords[d] = sum / cnt;
            }
        }

        // Increment iteration counter
        iter++;
    }

    // Output results
    printf("Iterations: %d\n", iter);
    printf("Centroids:\n");
    for (int j=0; j<K; j++) {
        printf("Cluster %d: ", j);
        for (int d=0; d<W; d++) {
            printf("%.2lf ", centroids[j].coords[d]);
        }
        printf("\n");
    }

    return 0;
}