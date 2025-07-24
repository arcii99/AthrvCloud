//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define K 3

struct point {
    double x;
    double y;
};

double distance(struct point p1, struct point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    struct point points[N] = {{0, 0}, {1, 1}, {-1, -1}, {2, 2}, {5, 6}, {8, 10}, {-3, -4}, {-7, -5}, {-2, -1}, {4, 3}};
    struct point centroids[K] = {{0, 0}, {1, 1}, {-1, -1}};
    int cluster_assignment[N];

    for (int i = 0; i < N; i++) {
        double min_distance = INFINITY;
        int min_cluster = -1;
        for (int j = 0; j < K; j++) {
            double d = distance(points[i], centroids[j]);
            if (d < min_distance) {
                min_distance = d;
                min_cluster = j;
            }
        }
        cluster_assignment[i] = min_cluster;
    }

    for (int i = 0; i < K; i++) {
        double sum_x = 0, sum_y = 0;
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (cluster_assignment[j] == i) {
                sum_x += points[j].x;
                sum_y += points[j].y;
                count++;
            }
        }
        centroids[i].x = sum_x / count;
        centroids[i].y = sum_y / count;
    }

    return 0;
}