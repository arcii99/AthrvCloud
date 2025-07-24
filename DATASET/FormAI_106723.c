//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define K 2
#define MAX_ITER 100

double dist(double*, double*, int);
double* centroid(double**, int, int, int*);
void kmeans(double**, int, int, int);

int main() {
    double data[N][K] = {{1, 1}, {1, 2}, {2, 1}, {2, 2}, {4, 4}, {4, 5}, {5, 4}, {5, 5}, {8, 9}, {9, 8}};
    double* dataset[N];
    for (int i = 0; i < N; i++) {
        dataset[i] = data[i];
    }
    kmeans(dataset, N, K, 2);
    return 0;
}

double dist(double* p1, double* p2, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(p1[i] - p2[i], 2);
    }
    return sqrt(sum);
}

double* centroid(double** cluster, int size, int k, int* indices) {
    double* center = malloc(sizeof(double) * k);
    for (int i = 0; i < k; i++) {
        double sum = 0;
        for (int j = 0; j < size; j++) {
            if (indices[j] == i) {
                sum += cluster[j][i];
            }
        }
        center[i] = sum / size;
    }
    return center;
}

void kmeans(double** data, int n, int k, int max_iter) {
    int* indices = malloc(sizeof(int) * n);
    double** centroids = malloc(sizeof(double*) * k);
    for (int i = 0; i < k; i++) {
        centroids[i] = data[i];
    }
    for (int iter = 0; iter < max_iter; iter++) {
        // Assign each point to nearest centroid
        for (int i = 0; i < n; i++) {
            double min_dist = INFINITY;
            int min_idx = -1;
            for (int j = 0; j < k; j++) {
                double d = dist(data[i], centroids[j], K);
                if (d < min_dist) {
                    min_dist = d;
                    min_idx = j;
                }
            }
            indices[i] = min_idx;
        }

        // Compute new centroids
        for (int i = 0; i < k; i++) {
            double* center = centroid(data, n, K, indices);
            centroids[i] = center;
        }
    }
    // Print out the results
    for (int i = 0; i < k; i++) {
        printf("Centroid %d: (%f, %f)\n", i, centroids[i][0], centroids[i][1]);
    }
}