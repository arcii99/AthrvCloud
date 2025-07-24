//FormAI DATASET v1.0 Category: Data mining ; Style: Donald Knuth
/*
* C Data Mining Program in a Donald Knuth Style.
* Displays Clustering of Data Points.
*
* Author: [Your Name]
* Date: [Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3  // Number of Clusters
#define N 20 // Number of Data Points

typedef struct Point {
    double x;   // x coordinate
    double y;   // y coordinate
    int cluster;    // cluster membership
} Point;

double euclidean_distance(Point a, Point b) {
    // Calculate the Euclidean distance between points a and b.
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    Point data[N] = {{3, 5, 0}, {4, 6, 0}, {2, 8, 0}, {3, 9, 0}, {4, 7, 0}, {6, 2, 0}, {7, 3, 0}, {5, 4, 0}, {6, 5, 0}, {8, 2, 0}, {9, 3, 0}, {7, 4, 0}, {1, 1, 0}, {2, 3, 0}, {1, 4, 0}, {3, 3, 0}, {5, 2, 0}, {4, 1, 0}, {6, 1, 0}, {8, 3, 0}};

    // Randomly initialize centroids for each cluster.
    Point centroids[K] = {{1, 1, 0}, {5, 5, 0}, {9, 9, 0}};

    // Perform the clustering algorithm until convergence.
    int flag = 1;
    while (flag == 1) {
        flag = 0;

        // Assign each point to its nearest centroid.
        for (int i = 0; i < N; i++) {
            double min_dist = INFINITY;
            int closest_cluster;

            for (int j = 0; j < K; j++) {
                double dist = euclidean_distance(data[i], centroids[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    closest_cluster = j;
                }
            }

            if (data[i].cluster != closest_cluster) {
                flag = 1;
                data[i].cluster = closest_cluster;
            }
        }

        // Calculate the new centroids for each cluster.
        for (int i = 0; i < K; i++) {
            double sum_x = 0, sum_y = 0;
            int count = 0;

            for (int j = 0; j < N; j++) {
                if (data[j].cluster == i) {
                    sum_x += data[j].x;
                    sum_y += data[j].y;
                    count++;
                }
            }

            if (count > 0) {
                centroids[i].x = sum_x / count;
                centroids[i].y = sum_y / count;
            }
        }
    }

    // Display the clustering of data points.
    printf("Clusters:\n");
    for (int i = 0; i < K; i++) {
        printf("Cluster %d:\n", i+1);
        for (int j = 0; j < N; j++) {
            if (data[j].cluster == i) {
                printf("(%f, %f)\n", data[j].x, data[j].y);
            }
        }
        printf("\n");
    }

    return 0;
}