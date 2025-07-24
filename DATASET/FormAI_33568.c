//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CLUSTERS 2
#define FEATURES 3
#define POINTS 5

void assign_clusters(double data[][FEATURES], double centroids[][FEATURES], int clusters[]) {
    double dist, min_dist;
    int cluster;
    for (int i = 0; i < POINTS; i++) {
        min_dist = INFINITY;
        for (int j = 0; j < CLUSTERS; j++) {
            dist = 0.0;
            for (int k = 0; k < FEATURES; k++) {
                dist += pow(data[i][k] - centroids[j][k], 2);
            }
            dist = sqrt(dist);
            if (dist < min_dist) {
                cluster = j;
                min_dist = dist;
            }
        }
        clusters[i] = cluster;
    }
}

void calculate_centroids(double data[][FEATURES], double centroids[][FEATURES], int clusters[]) {
    int cluster_count[CLUSTERS] = {0};
    for (int i = 0; i < CLUSTERS; i++) {
        for (int j = 0; j < FEATURES; j++) {
            centroids[i][j] = 0.0;
        }
    }
    for (int i = 0; i < POINTS; i++) {
        for (int j = 0; j < FEATURES; j++) {
            centroids[clusters[i]][j] += data[i][j];
        }
        cluster_count[clusters[i]]++;
    }
    for (int i = 0; i < CLUSTERS; i++) {
        if (cluster_count[i] != 0) {
            for (int j = 0; j < FEATURES; j++) {
                centroids[i][j] /= cluster_count[i];
            }
        }
    }
}

void print_clusters(double data[][FEATURES], int clusters[]) {
    for (int i = 0; i < POINTS; i++) {
        printf("Point %d: [%.1f, %.1f, %.1f] - Cluster %d\n", i+1, data[i][0], data[i][1], data[i][2], clusters[i]+1);
    }
}

int main() {
    double data[POINTS][FEATURES] = {{2.0, 3.0, 4.0}, {4.0, 6.0, 8.0}, {7.0, 9.0, 11.0}, {3.0, 4.0, 5.0}, {1.0, 2.0, 3.0}};
    double centroids[CLUSTERS][FEATURES] = {{1.0, 2.0, 3.0}, {9.0, 10.0, 11.0}};
    int clusters[POINTS] = {0};

    for (int i = 0; i < 10; i++) {
        assign_clusters(data, centroids, clusters);
        calculate_centroids(data, centroids, clusters);
    }

    print_clusters(data, clusters);
    
    return 0;
}