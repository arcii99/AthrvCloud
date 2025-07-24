//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000 // number of data points
#define K 5 // number of clusters
#define D 2 // number of dimensions

int main() {

    // step 1: randomly generate data points
    float data[N][D];
    srand((unsigned) time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            data[i][j] = (float) rand() / (float) RAND_MAX;
        }
    }

    // step 2: randomly initialize centroids
    float centroids[K][D];
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            centroids[i][j] = (float) rand() / (float) RAND_MAX;
        }
    }

    // step 3: assign each data point to the closest centroid
    int assignment[N];
    float distance[N][K];
    float min_dist;
    for (int i = 0; i < N; i++) {
        min_dist = INFINITY;
        for (int j = 0; j < K; j++) {
            distance[i][j] = 0;
            for (int d = 0; d < D; d++) {
                distance[i][j] += pow(data[i][d] - centroids[j][d], 2);
            }
            distance[i][j] = sqrt(distance[i][j]);
            if (distance[i][j] < min_dist) {
                min_dist = distance[i][j];
                assignment[i] = j;
            }
        }
    }

    // step 4: recompute centroids
    float sum[K][D];
    int count[K];
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            sum[i][j] = 0;
        }
        count[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            sum[assignment[i]][j] += data[i][j];
        }
        count[assignment[i]]++;
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            centroids[i][j] = sum[i][j] / count[i];
        }
    }

    // repeat steps 3 and 4 until convergence
    int iter = 0;
    while (iter < 100) {
        // step 3
        for (int i = 0; i < N; i++) {
            min_dist = INFINITY;
            for (int j = 0; j < K; j++) {
                distance[i][j] = 0;
                for (int d = 0; d < D; d++) {
                    distance[i][j] += pow(data[i][d] - centroids[j][d], 2);
                }
                distance[i][j] = sqrt(distance[i][j]);
                if (distance[i][j] < min_dist) {
                    min_dist = distance[i][j];
                    assignment[i] = j;
                }
            }
        }
        // step 4
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < D; j++) {
                sum[i][j] = 0;
            }
            count[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < D; j++) {
                sum[assignment[i]][j] += data[i][j];
            }
            count[assignment[i]]++;
        }
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < D; j++) {
                centroids[i][j] = sum[i][j] / count[i];
            }
        }
        iter++;
    }

    // print final centroids
    printf("Final Centroids:\n");
    for (int i = 0; i < K; i++) {
        printf("\t[ ");
        for (int j = 0; j < D; j++) {
            printf("%f ", centroids[i][j]);
        }
        printf("]\n");
    }

    return 0;
}