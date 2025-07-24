//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 50
#define THRESHOLD 0.001

void kMeansClustering(double **data, int n, int k, double **centroids, int *membership) {
    // Initialize variables
    int i, j, l, iter, cluster, changed;
    double min_dist, dist, diff; 

    // Initialize centroids randomly
    int *indexes = (int *) malloc(k * sizeof(int));
    for(i = 0; i < k; i++) {
        indexes[i] = rand() % n;
        for(j = 0; j < i; j++) {
            if(indexes[i] == indexes[j]) {
                i--;
                break;
            }
        }
        centroids[i][0] = data[indexes[i]][0];
        centroids[i][1] = data[indexes[i]][1];
    }

    // K-means clustering algorithm
    iter = 0;
    do {
        changed = 0;
        iter++;

        // Assign each point to its closest centroid
        for(i = 0; i < n; i++) {
            min_dist = INFINITY;
            for(j = 0; j < k; j++) {
                dist = sqrt(pow(data[i][0] - centroids[j][0], 2) + pow(data[i][1] - centroids[j][1], 2));
                if(dist < min_dist) {
                    min_dist = dist;
                    cluster = j;
                }
            }
            if(membership[i] != cluster) {
                membership[i] = cluster;
                changed = 1;
            }
        }

        // Recalculate centroids
        for(j = 0; j < k; j++) {
            centroids[j][0] = 0.0;
            centroids[j][1] = 0.0;
            l = 0;
            for(i = 0; i < n; i++) {
                if(membership[i] == j) {
                    centroids[j][0] += data[i][0];
                    centroids[j][1] += data[i][1];
                    l++;
                }
            }
            if(l > 0) {
                centroids[j][0] /= l;
                centroids[j][1] /= l;
            }
        }

        // Calculate difference between old and new centroids
        diff = 0.0;
        for(j = 0; j < k; j++) {
            diff += sqrt(pow(centroids[j][0] - data[indexes[j]][0], 2) + pow(centroids[j][1] - data[indexes[j]][1], 2));
            indexes[j] = rand() % n;
            centroids[j][0] = data[indexes[j]][0];
            centroids[j][1] = data[indexes[j]][1];
        }

    } while((diff > THRESHOLD) && (iter < MAX_ITER));

    free(indexes);
}

int main() {
    int n = 1000; // Number of data points
    int k = 3; // Number of clusters
    int i, j;

    // Generate random 2D data points
    double **data = (double **) malloc(n * sizeof(double *));
    for(i = 0; i < n; i++) {
        data[i] = (double *) malloc(2 * sizeof(double));
        data[i][0] = 2.0 * ((double) rand() / (double) RAND_MAX) - 1.0;
        data[i][1] = 2.0 * ((double) rand() / (double) RAND_MAX) - 1.0;
    }

    // Allocate memory for centroids and membership
    double **centroids = (double **) malloc(k * sizeof(double *));
    for(i = 0; i < k; i++) {
        centroids[i] = (double *) malloc(2 * sizeof(double));
    }
    int *membership = (int *) malloc(n * sizeof(int));

    // Run K-means clustering algorithm
    kMeansClustering(data, n, k, centroids, membership);

    // Print results
    for(i = 0; i < k; i++) {
        printf("Centroid %d: (%.3f, %.3f)\n", i+1, centroids[i][0], centroids[i][1]);
    }

    // Deallocate memory
    for(i = 0; i < n; i++) {
        free(data[i]);
    }
    free(data);
    for(i = 0; i < k; i++) {
        free(centroids[i]);
    }
    free(centroids);
    free(membership);

    return 0;
}