//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100
#define K 3

struct point {
    double x;
    double y;
} typedef Point;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int cluster_mean(Point* cluster, size_t n, Point* mean) {
    double x_sum = 0, y_sum = 0;
    for (size_t i = 0; i < n; i++) {
        x_sum += cluster[i].x;
        y_sum += cluster[i].y;
    }
    if (n == 0) return 0;
    mean->x = x_sum / n; mean->y = y_sum / n;
    return 1;
}

void cluster_points(Point* points, size_t n, Point centroids[K], int* clustersize[K], Point* clusters[K]) {
    for (size_t i = 0; i < K; i++) {
        clustersize[i] = (int*)malloc(sizeof(int));
        clustersize[i][0] = 0;
    }
    for (size_t i = 0; i < n; i++) {
        double mindist = distance(points[i], centroids[0]);
        int clusternum = 0;
        for (size_t j = 1; j < K; j++) {
            double dist = distance(points[i], centroids[j]);
            if (dist < mindist) {
                mindist = dist;
                clusternum = j;
            }
        }
        clustersize[clusternum][0]++;
        size_t index = clustersize[clusternum][0];
        clusters[clusternum] = (Point*)realloc(clusters[clusternum], index * sizeof(Point));
        clusters[clusternum][index - 1] = points[i];
    }
    for (size_t i = 0; i < K; i++) {
        cluster_mean(clusters[i], clustersize[i][0], &centroids[i]);
    }
    // Recursion!
    for (size_t i = 0; i < K; i++) {
        if (clustersize[i][0] > 0) {
            cluster_points(clusters[i], clustersize[i][0], centroids, clustersize, clusters);
        }
    }
}

int main() {
    Point points[N];
    Point centroids[K] = {{1, 2}, {5, 8}, {-3, 7}};
    int* clustersize[K];
    Point* clusters[K];
    srand(time(NULL));
    // generate random points
    for (size_t i = 0; i < N; i++) {
        points[i].x = (double)rand() / RAND_MAX * 20 - 10;
        points[i].y = (double)rand() / RAND_MAX * 20 - 10;
    }
    cluster_points(points, N, centroids, clustersize, clusters);
    for (size_t i = 0; i < K; i++) {
        printf("Cluster %zu: (", i);
        for (size_t j = 0; j < clustersize[i][0]; j++) {
            printf("(%.2f, %.2f)", clusters[i][j].x, clusters[i][j].y);
            if (j < clustersize[i][0] - 1) printf(", ");
        }
        printf(") Centroid: (%.2f, %.2f)\n", centroids[i].x, centroids[i].y);
        free(clusters[i]);
        free(clustersize[i]);
    }
    return 0;
}