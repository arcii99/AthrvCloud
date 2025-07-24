//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // Number of clusters
#define MAX_ITERATIONS 100 // Maximum number of iterations for convergence
#define THRESHOLD 0.01 // Error threshold for convergence

typedef struct {
    double x;
    double y;
} point;

void k_means(point* data, int n, point* centroids, int k, int* membership) {
    int i, j, t, min_index;
    double least_distance, distance;
    double delta[K][2];
    int cluster_size[K] = {0};
    double error = 0.0, last_error = 1.0;

    while(fabs(error-last_error) > THRESHOLD) {
        last_error = error;
        error = 0.0;
        // Reset cluster_size and delta arrays
        for(i = 0; i < k; ++i) {
            cluster_size[i] = 0;
            delta[i][0] = 0.0;
            delta[i][1] = 0.0;
        }
        // Assign each data point to the closest centroid
        for(i = 0; i < n; ++i) {
            least_distance = 1e10;
            for(j = 0; j < k; ++j) {
                distance = sqrt(pow((data[i].x - centroids[j].x),2) + pow((data[i].y - centroids[j].y),2));
                if(distance < least_distance) {
                    least_distance = distance;
                    min_index = j;
                }
            }
            cluster_size[min_index]++;
            membership[i] = min_index;
            delta[min_index][0] += data[i].x;
            delta[min_index][1] += data[i].y;
            error += least_distance;
        }
        // Update centroids
        for(j = 0; j < k; ++j) {
            if(cluster_size[j] > 0) {
                centroids[j].x = delta[j][0]/cluster_size[j];
                centroids[j].y = delta[j][1]/cluster_size[j];
            }
        }
        if(t > MAX_ITERATIONS) break; // Break if maximum iterations reached
        ++t;
    }
}

int main() {
    point data[] = {{1,1}, {2,2}, {2,3}, {3,4}, {4,3}, {5,4}, {5,5}, {6,5}};
    point centroids[K];
    int membership[sizeof(data)/sizeof(point)] = {0};
    int i, j;

    // Choose initial centroids as first K data points
    for(i = 0; i < K; ++i) {
        centroids[i].x = data[i].x;
        centroids[i].y = data[i].y;
    }

    k_means(data, sizeof(data)/sizeof(point), centroids, K, membership);

    // Print clustering results
    for(i = 0; i < K; ++i) {
        printf("Cluster %d: ", i+1);
        for(j = 0; j < sizeof(data)/sizeof(point); ++j) {
            if(membership[j] == i) {
                printf("(%g,%g) ", data[j].x, data[j].y);
            }
        }
        printf("\nCentroid: (%g,%g)\n", centroids[i].x, centroids[i].y);
    }

    return 0;
}