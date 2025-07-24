//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define K 3
#define MAX_ITER 100

void kmeans(double data[N], int clusters[K]) {
    double centroids[K] = {0};
    int counts[K] = {0};
    int i, j, k, iter = 0;
    double d, min_d, sum_d;

    // Select initial centroids randomly
    for (i = 0; i < K; i++) {
        centroids[i] = data[rand() % N];
    }

    while (iter < MAX_ITER) {
        // Assign each data point to the closest centroid
        for (i = 0; i < N; i++) {
            min_d = INFINITY;
            for (j = 0; j < K; j++) {
                d = fabs(data[i] - centroids[j]);
                if (d < min_d) {
                    min_d = d;
                    clusters[i] = j;
                }
            }
        }

        // Update centroids
        for (k = 0; k < K; k++) {
            for (i = 0; i < N; i++) {
                if (clusters[i] == k) {
                    centroids[k] += data[i];
                    counts[k]++;
                }
            }
            centroids[k] /= counts[k];
        }

        // Check for convergence
        sum_d = 0;
        for (i = 0; i < N; i++) {
            d = fabs(data[i] - centroids[clusters[i]]);
            sum_d += d*d;
        }
        if (sum_d < 1e-6) {
            break;
        }

        iter++;
    }
}

int main() {
    double data[N] = {1, 2, 5, 10, 12, 14, 17, 18, 20, 25};
    int clusters[N] = {0};
    int i;

    kmeans(data, clusters);

    for (i = 0; i < N; i++) {
        printf("%.1f belongs to cluster %d\n", data[i], clusters[i]);
    }

    return 0;
}