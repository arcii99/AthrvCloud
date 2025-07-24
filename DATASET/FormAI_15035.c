//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define K 5
#define MAX_ITER 100

/* Generate random data points */
void gen_data(float data[][2]) {
    int i;
    for (i = 0; i < N; i++) {
        data[i][0] = (float)rand() / RAND_MAX * 10 - 5; // x
        data[i][1] = (float)rand() / RAND_MAX * 10 - 5; // y
    }
}

/* Implement the C clustering algorithm */
void c_clustering(float data[][2], int cluster[N]) {
    int i, j, k, n, iter;
    float dist, min_dist, centroid[K][2], sum[K][2];
    /* Initialize centroids */
    for (i = 0; i < K; i++) {
        centroid[i][0] = (float)rand() / RAND_MAX * 10 - 5; // x
        centroid[i][1] = (float)rand() / RAND_MAX * 10 - 5; // y
        printf("Initial centroid %d: (%f, %f)\n", i, centroid[i][0], centroid[i][1]);
    }
    /* Assign each data point to the nearest centroid */
    for (iter = 0; iter < MAX_ITER; iter++) {
        /* Initialize sums for each cluster */
        for (i = 0; i < K; i++) {
            sum[i][0] = 0;
            sum[i][1] = 0;
            n = 0;
        }
        /* Assign each data point to the nearest centroid */
        for (i = 0; i < N; i++) {
            min_dist = INFINITY;
            for (j = 0; j < K; j++) {
                dist = sqrt(pow(data[i][0] - centroid[j][0], 2) + pow(data[i][1] - centroid[j][1], 2));
                if (dist < min_dist) {
                    min_dist = dist;
                    cluster[i] = j;
                }
            }
            /* Add data point to cluster sum */
            sum[cluster[i]][0] += data[i][0];
            sum[cluster[i]][1] += data[i][1];
            n++;
        }
        /* Update centroids */
        for (i = 0; i < K; i++) {
            if (n > 0) {
                centroid[i][0] = sum[i][0] / (float)n;
                centroid[i][1] = sum[i][1] / (float)n;
            }
            printf("Updated centroid %d: (%f, %f)\n", i, centroid[i][0], centroid[i][1]);
        }
    }
}

int main() {
    float data[N][2];
    int cluster[N];
    gen_data(data);
    c_clustering(data, cluster);
    return 0;
}