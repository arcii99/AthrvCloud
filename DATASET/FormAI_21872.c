//FormAI DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3
#define N 20
#define D 2

double data[N][D] = {
    {2, 4},
    {4, 6},
    {3, 7},
    {5, 5},
    {7, 3},
    {8, 2},
    {9, 1},
    {2, 6},
    {4, 4},
    {5, 3},
    {1, 3},
    {3, 5},
    {5, 4},
    {6, 3},
    {7, 2},
    {8, 1},
    {3, 6},
    {4, 5},
    {2, 3},
    {6, 2}
};

double centroids[K][D] = {
    {2, 4},
    {4, 6},
    {5, 3}
};

int nearest(double data_point[]) {
    int nearest_centroid = 0;
    double min_distance = INFINITY;
    for (int i =0; i < K; i++) {
        double distance = 0;
        for (int j = 0; j < D; j++) {
            distance += pow(data_point[j] - centroids[i][j], 2.0);
        }
        distance = sqrt(distance);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_centroid = i;
        }
    }
    return nearest_centroid;
}

void update_centroids() {
    int cluster_sizes[K] = {0};
    double sum[K][D] = {0};
    for (int i = 0; i < N; i++) {
        int nearest_centroid = nearest(data[i]);
        cluster_sizes[nearest_centroid]++;
        for (int j = 0; j < D; j++) {
            sum[nearest_centroid][j] += data[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            centroids[i][j] = sum[i][j] / cluster_sizes[i];
        }
    }
}

void print_clusters() {
    for (int i = 0; i < K; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < N; j++) {
            int nearest_centroid = nearest(data[j]);
            if (nearest_centroid == i) {
                printf("(%lf, %lf)\n", data[j][0], data[j][1]);
            }
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        update_centroids();
    }
    print_clusters();
    return 0;
}