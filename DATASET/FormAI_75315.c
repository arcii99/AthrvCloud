//FormAI DATASET v1.0 Category: Data mining ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_POINTS 1000
#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 1000

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double x;
    double y;
    int count;
} Cluster;

int main() {
    srand(time(NULL));

    Point points[NUM_POINTS];
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].x = (double) rand() / RAND_MAX * 10.0;
        points[i].y = (double) rand() / RAND_MAX * 10.0;
    }

    Cluster clusters[NUM_CLUSTERS];
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].x = (double) rand() / RAND_MAX * 10.0;
        clusters[i].y = (double) rand() / RAND_MAX * 10.0;
        clusters[i].count = 0;
    }

    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        // Assign each point to closest cluster
        for (int i = 0; i < NUM_POINTS; i++) {
            double min_distance = __DBL_MAX__;
            int closest_cluster = -1;
            for (int j = 0; j < NUM_CLUSTERS; j++) {
                double distance = (points[i].x - clusters[j].x) * (points[i].x - clusters[j].x) + (points[i].y - clusters[j].y) * (points[i].y - clusters[j].y);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = j;
                }
            }
            clusters[closest_cluster].x = (clusters[closest_cluster].x * clusters[closest_cluster].count + points[i].x) / (clusters[closest_cluster].count + 1);
            clusters[closest_cluster].y = (clusters[closest_cluster].y * clusters[closest_cluster].count + points[i].y) / (clusters[closest_cluster].count + 1);
            clusters[closest_cluster].count++;
        }

        // Check if clusters have moved
        int clusters_moved = 0;
        for (int i = 0; i < NUM_CLUSTERS; i++) {
            if (clusters[i].count > 0) {
                double distance = (clusters[i].x - (double) rand() / RAND_MAX * 10.0) * (clusters[i].x - (double) rand() / RAND_MAX * 10.0) + (clusters[i].y - (double) rand() / RAND_MAX * 10.0) * (clusters[i].y - (double) rand() / RAND_MAX * 10.0);
                if (distance > 1.0) {
                    clusters[i].x = (double) rand() / RAND_MAX * 10.0;
                    clusters[i].y = (double) rand() / RAND_MAX * 10.0;
                    clusters_moved = 1;
                }
            }
        }

        if (!clusters_moved) {
            printf("Clustering converged after %d iterations:\n", iteration + 1);
            for (int i = 0; i < NUM_CLUSTERS; i++) {
                printf("Cluster %d: (%f, %f)\n", i + 1, clusters[i].x, clusters[i].y);
            }
            break;
        }
    }

    return 0;
}