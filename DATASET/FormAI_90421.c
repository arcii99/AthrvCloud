//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10 // number of data points
#define K 2 // number of clusters
#define DIM 2 // dimension of data points

double distance(double *a, double *b, int dim) {
    double d = 0;
    for (int i = 0; i < dim; i++) {
        d += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(d);
}

int main() {
    double data[N][DIM] = {{1,2},{2,1},{1,1},{5,8},{6,9},{7,9},{10,12},{11,11},{12,11},{15,18}};
    double centroids[K][DIM];
    int membership[N] = {-1};
    double epsilon = 0.001;
    double diff[K][DIM];

    // initialize centroids to random data points
    for (int i = 0; i < K; i++) {
        int r = rand() % N;
        for (int j = 0; j < DIM; j++) {
            centroids[i][j] = data[r][j];
        }
    }

    int iter = 0;
    while (1) {
        // assign data points to clusters
        int change = 0;
        for (int i = 0; i < N; i++) {
            double min_dist = INFINITY;
            int min_index = -1;
            for (int j = 0; j < K; j++) {
                double dist = distance(data[i], centroids[j], DIM);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_index = j;
                }
            }
            if (membership[i] != min_index) {
                membership[i] = min_index;
                change = 1;
            }
        }

        if (!change) {
            // cluster membership didn't change, terminate
            break;
        }

        // compute new centroids
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < DIM; j++) {
                centroids[i][j] = 0;
            }
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (membership[j] == i) {
                    for (int k = 0; k < DIM; k++) {
                        centroids[i][k] += data[j][k];
                    }
                    count++;
                }
            }
            for (int j = 0; j < DIM; j++) {
                centroids[i][j] /= count;
                diff[i][j] = centroids[i][j];
            }
        }

        // check if centroids moved less than epsilon
        double max_diff = -INFINITY;
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < DIM; j++) {
                diff[i][j] -= centroids[i][j];
                max_diff = fmax(max_diff, fabs(diff[i][j]));
            }
        }
        if (max_diff < epsilon) {
            break;
        }

        iter++;
    }

    // print out results
    printf("Number of iterations: %d\n", iter);
    for (int i = 0; i < K; i++) {
        printf("Centroid %d: [", i);
        for (int j = 0; j < DIM; j++) {
            printf("%lf, ", centroids[i][j]);
        }
        printf("]\n");
    }
    for (int i = 0; i < N; i++) {
        printf("Data point %d assigned to cluster %d\n", i, membership[i]);
    }

    return 0;
}