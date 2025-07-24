//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define K 3
#define MAX_ITERATIONS 100

double data[N][2];
int labels[N];

double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

double centroid_distance(double x1, double y1, double x2, double y2) {
    return distance(x1, y1, x2, y2);
}

void k_means_clustering() {
    double centroids[K][2];
    int i, j, k;
    int iteration = 0;
    int converged = 0;

    // initialize random centroids
    for (k = 0; k < K; k++) {
        centroids[k][0] = data[rand() % N][0];
        centroids[k][1] = data[rand() % N][1];
    }

    while (!converged && iteration < MAX_ITERATIONS) {
        // assign labels based on distance to centroids
        for (i = 0; i < N; i++) {
            double min_distance = centroid_distance(data[i][0], data[i][1], centroids[0][0], centroids[0][1]);
            int min_label = 0;
            for (k = 1; k < K; k++) {
                double d = centroid_distance(data[i][0], data[i][1], centroids[k][0], centroids[k][1]);
                if (d < min_distance) {
                    min_distance = d;
                    min_label = k;
                }
            }
            labels[i] = min_label;
        }

        // recompute centroids
        double new_centroids[K][2] = {0};
        int cluster_size[K] = {0};
        for (i = 0; i < N; i++) {
            new_centroids[labels[i]][0] += data[i][0];
            new_centroids[labels[i]][1] += data[i][1];
            cluster_size[labels[i]]++;
        }
        for (k = 0; k < K; k++) {
            if (cluster_size[k] > 0) {
                centroids[k][0] = new_centroids[k][0] / cluster_size[k];
                centroids[k][1] = new_centroids[k][1] / cluster_size[k];
            }
        }

        // check for convergence
        converged = 1;
        for (k = 0; k < K; k++) {
            if (centroid_distance(centroids[k][0], centroids[k][1], new_centroids[k][0], new_centroids[k][1]) > 1e-6) {
                converged = 0;
                break;
            }
        }

        iteration++;
    }
}

int main() {
    int i;
    srand(42);
    // generate random data
    for (i = 0; i < N; i++) {
        double x = (double)rand() / RAND_MAX * 10.0;
        double y = (double)rand() / RAND_MAX * 10.0;
        data[i][0] = x;
        data[i][1] = y;
    }
    k_means_clustering();
    // print cluster labels
    for (i = 0; i < N; i++) {
        printf("%d\n", labels[i]);
    }
    return 0;
}