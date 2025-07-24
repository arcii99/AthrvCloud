//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 100 // Number of points
#define K 5 // Number of clusters
#define DIM 2 // Number of dimensions

struct point {
    double coords[DIM];
    int cluster;
};

double dist(struct point a, struct point b) {
    double sum = 0;
    for (int i = 0; i < DIM; i++) {
        sum += pow(a.coords[i] - b.coords[i], 2);
    }
    return sqrt(sum);
}

void k_means(struct point *data, struct point *centroids, int n) {
    int converged = 0;
    while (!converged) {
        // Calculate cluster assignments
        for (int i = 0; i < n; i++) {
            double min_dist = INFINITY;
            int min_cluster = data[i].cluster;
            for (int j = 0; j < K; j++) {
                double d = dist(data[i], centroids[j]);
                if (d < min_dist) {
                    min_dist = d;
                    min_cluster = j;
                }
            }
            data[i].cluster = min_cluster;
        }
        // Calculate new centroids
        double sums[K][DIM] = {{0}};
        int counts[K] = {0};
        for (int i = 0; i < n; i++) {
            int cluster = data[i].cluster;
            for (int j = 0; j < DIM; j++) {
                sums[cluster][j] += data[i].coords[j];
            }
            counts[cluster]++;
        }
        converged = 1;
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < DIM; j++) {
                double new_coord = counts[i] ? sums[i][j] / counts[i] : centroids[i].coords[j];
                if (fabs(new_coord - centroids[i].coords[j]) > 1e-6) {
                    centroids[i].coords[j] = new_coord;
                    converged = 0;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    struct point data[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < DIM; j++) {
            data[i].coords[j] = (double)rand() / RAND_MAX;
        }
        data[i].cluster = rand() % K;
    }
    struct point centroids[K];
    for (int i = 0; i < K; i++) {
        centroids[i] = data[rand() % N];
    }
    k_means(data, centroids, N);
    return 0;
}