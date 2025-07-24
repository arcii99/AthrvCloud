//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 100
#define K 5

int main() {

    srand(time(NULL));

    int i, j, l, t, iterations = 50, cluster[N];
    float x[N][2], centroids[K][2], distance, min_distance;
    float centroid_sum[K][2], centroid_count[K];

    // Initialize data points with random values
    for (i = 0; i < N; i++) {
        x[i][0] = (float) rand() / RAND_MAX;
        x[i][1] = (float) rand() / RAND_MAX;
        cluster[i] = -1;
    }

    // Initialize centroids with random data points
    for (i = 0; i < K; i++) {
        j = rand() % N;
        centroids[i][0] = x[j][0];
        centroids[i][1] = x[j][1];
    }

    // Perform K-means clustering
    for (t = 0; t < iterations; t++) {

        // Reset centroid sum and count
        for (i = 0; i < K; i++) {
            centroid_sum[i][0] = 0.0;
            centroid_sum[i][1] = 0.0;
            centroid_count[i] = 0.0;
        }

        // Assign data points to the nearest centroid
        for (i = 0; i < N; i++) {
            min_distance = INFINITY;
            for (j = 0; j < K; j++) {
                distance = sqrt(pow(x[i][0] - centroids[j][0], 2) + pow(x[i][1] - centroids[j][1], 2));
                if (distance < min_distance) {
                    min_distance = distance;
                    cluster[i] = j;
                }
            }
            centroid_sum[cluster[i]][0] += x[i][0];
            centroid_sum[cluster[i]][1] += x[i][1];
            centroid_count[cluster[i]]++;
        }

        // Update centroids
        for (i = 0; i < K; i++) {
            if (centroid_count[i] > 0) {
                centroids[i][0] = centroid_sum[i][0] / centroid_count[i];
                centroids[i][1] = centroid_sum[i][1] / centroid_count[i];
            }
        }
    }

    // Print cluster assignments
    printf("Cluster assignments:\n");
    for (i = 0; i < N; i++) {
        printf("x[%d] = (%.2f, %.2f) -> cluster %d\n", i, x[i][0], x[i][1], cluster[i]);
    }

    return 0;
}