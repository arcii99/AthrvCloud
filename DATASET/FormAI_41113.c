//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define K 3 // Number of clusters
#define MAX_ITERATIONS 1000

// Define a point as a tuple of (x, y) coordinates
typedef struct {
    double x;
    double y;
} Point;

// Compute the Euclidean distance between two points
double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    Point data[] = { {1.0, 1.0}, {2.0, 1.0}, {4.0, 3.0}, {8.0, 6.0}, {9.0, 6.0}, {9.0, 8.0} };
    int num_points = sizeof(data) / sizeof(Point);

    // Initialize centroids with random data points
    Point centroids[K];
    for (int i = 0; i < K; i++) {
        centroids[i] = data[rand() % num_points];
    }

    // Initialize cluster memberships
    int membership[num_points];
    memset(membership, 0, sizeof(membership));

    // Run K-means algorithm
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // Assign each point to the nearest centroid
        for (int j = 0; j < num_points; j++) {
            double min_distance = INFINITY;
            for (int k = 0; k < K; k++) {
                double d = distance(data[j], centroids[k]);
                if (d < min_distance) {
                    min_distance = d;
                    membership[j] = k;
                }
            }
        }

        // Update each centroid to be the average of its points
        int cluster_sizes[K];
        memset(cluster_sizes, 0, sizeof(cluster_sizes));
        for (int j = 0; j < num_points; j++) {
            int k = membership[j];
            centroids[k].x += data[j].x;
            centroids[k].y += data[j].y;
            cluster_sizes[k]++;
        }
        for (int k = 0; k < K; k++) {
            centroids[k].x /= cluster_sizes[k];
            centroids[k].y /= cluster_sizes[k];
        }
    }

    // Print final cluster assignments
    printf("Final cluster assignments:\n");
    for (int k = 0; k < K; k++) {
        printf("Cluster %d:\n", k);
        for (int j = 0; j < num_points; j++) {
            if (membership[j] == k) {
                printf("(%lf, %lf)\n", data[j].x, data[j].y);
            }
        }
    }

    return 0;
}