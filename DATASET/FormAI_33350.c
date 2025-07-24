//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define K 3
#define MAX_ITER 100

double data[N][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {2, 4}, {6, 8}, {1, 3}, {5, 7}, {2, 6}};
double centroids[K][2] = {{1, 2}, {5, 6}, {9, 10}};
int assignments[N];

int main() {
    int i, j, k, iter;
    double x, y, dist, min_dist;
    double sum_x[K], sum_y[K], count[K];

    // Iterate until convergence or max iterations reached
    for (iter = 0; iter < MAX_ITER; iter++) {
        // Reset sums and counts for each centroid
        for (k = 0; k < K; k++) {
            sum_x[k] = 0;
            sum_y[k] = 0;
            count[k] = 0;
        }

        // Assign data points to the nearest centroid
        for (i = 0; i < N; i++) {
            x = data[i][0];
            y = data[i][1];
            min_dist = INFINITY;
            for (j = 0; j < K; j++) {
                dist = sqrt(pow(x - centroids[j][0], 2) + pow(y - centroids[j][1], 2));
                if (dist < min_dist) {
                    assignments[i] = j;
                    min_dist = dist;
                }
            }
            // Add data point to sum and count for assigned centroid
            sum_x[assignments[i]] += x;
            sum_y[assignments[i]] += y;
            count[assignments[i]]++;
        }

        // Update centroid positions
        for (k = 0; k < K; k++) {
            if (count[k] > 0) {
                centroids[k][0] = sum_x[k] / count[k];
                centroids[k][1] = sum_y[k] / count[k];
            }
        }
    }

    // Print final assignments and centroid positions
    printf("Final cluster assignments:\n");
    for (i = 0; i < N; i++) {
        printf("Data point (%f, %f) assigned to cluster %d\n", data[i][0], data[i][1], assignments[i]);
    }
    printf("\nFinal centroid positions:\n");
    for (k = 0; k < K; k++) {
        printf("Cluster %d centroid at (%f, %f)\n", k, centroids[k][0], centroids[k][1]);
    }

    return 0;
}