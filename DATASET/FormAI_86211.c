//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // number of clusters
#define N 10 // number of data points
#define D 2 // number of features

typedef struct Point {
    double features[D];
    int cluster;
} Point;

double get_distance(Point p1, Point p2) {
    double distance = 0.0;
    for (int i = 0; i < D; i++) {
        distance += pow(p1.features[i] - p2.features[i], 2);
    }
    return sqrt(distance);
}

void assign_clusters(Point data[N], Point centroids[K]) {
    for (int i = 0; i < N; i++) {
        double min_distance = INFINITY;
        int min_cluster = -1;
        for (int j = 0; j < K; j++) {
            double distance = get_distance(data[i], centroids[j]);
            if (distance < min_distance) {
                min_distance = distance;
                min_cluster = j;
            }
        }
        data[i].cluster = min_cluster;
    }
}

void update_centroids(Point data[N], Point centroids[K]) {
    int cluster_size[K] = {0};
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            centroids[i].features[j] = 0.0;
        }
    }
    for (int i = 0; i < N; i++) {
        int c = data[i].cluster;
        for (int j = 0; j < D; j++) {
            centroids[c].features[j] += data[i].features[j];
        }
        cluster_size[c]++;
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            centroids[i].features[j] /= cluster_size[i];
        }
    }
}

void print_clusters(Point data[N], Point centroids[K]) {
    printf("Clusters:\n");
    for (int i = 0; i < K; i++) {
        printf("Cluster %d (centroid: ", i);
        for (int j = 0; j < D; j++) {
            printf("%.2f ", centroids[i].features[j]);
        }
        printf("):\n");
        for (int j = 0; j < N; j++) {
            if (data[j].cluster == i) {
                printf("\t(%.2f, %.2f)\n", data[j].features[0], data[j].features[1]);
            }
        }
    }
}

int main() {
    Point data[N] = {
        {{2, 10}, -1},
        {{2, 5}, -1},
        {{8, 4}, -1},
        {{5, 8}, -1},
        {{7, 5}, -1},
        {{6, 4}, -1},
        {{1, 2}, -1},
        {{4, 9}, -1},
        {{3, 8}, -1},
        {{5, 2}, -1},
    };
    Point centroids[K] = {
        {{2, 10}, -1},
        {{5, 8}, -1},
        {{1, 2}, -1},
    };
    printf("Initial clusters:\n");
    print_clusters(data, centroids);
    for (int i = 0; i < 5; i++) { // run the algorithm for 5 iterations
        assign_clusters(data, centroids);
        update_centroids(data, centroids);
        printf("Iteration %d:\n", i + 1);
        print_clusters(data, centroids);
    }
    return 0;
}