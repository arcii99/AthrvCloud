//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // Number of clusters
#define N 10 // Number of data points

// Define a data point structure with x and y coordinates
typedef struct data_point {
    double x;
    double y;
} DataPoint;

// Define a cluster structure with a centroid and data points
typedef struct cluster {
    DataPoint centroid;
    DataPoint *points;
    int num_points;
} Cluster;

// Define a distance function between data points based on Euclidean distance
double distance(DataPoint p1, DataPoint p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    // Initialize data points randomly
    DataPoint data[N];
    for (int i = 0; i < N; i++) {
        data[i].x = (double) rand() / RAND_MAX;
        data[i].y = (double) rand() / RAND_MAX;
    }

    // Initialize clusters randomly
    Cluster clusters[K];
    for (int i = 0; i < K; i++) {
        clusters[i].centroid.x = (double) rand() / RAND_MAX;
        clusters[i].centroid.y = (double) rand() / RAND_MAX;
        clusters[i].points = NULL;
        clusters[i].num_points = 0;
    }

    // Repeat until convergence
    int num_iterations = 0;
    while (num_iterations < 100) {
        // Assign each data point to the nearest cluster
        for (int i = 0; i < N; i++) {
            double min_distance = INFINITY;
            int closest_cluster = -1;
            for (int j = 0; j < K; j++) {
                double d = distance(data[i], clusters[j].centroid);
                if (d < min_distance) {
                    min_distance = d;
                    closest_cluster = j;
                }
            }
            clusters[closest_cluster].num_points++;
            clusters[closest_cluster].points = realloc(clusters[closest_cluster].points,
                                                        clusters[closest_cluster].num_points * sizeof(DataPoint));
            clusters[closest_cluster].points[clusters[closest_cluster].num_points - 1] = data[i];
        }

        // Update the centroids of each cluster
        for (int i = 0; i < K; i++) {
            double x_sum = 0;
            double y_sum = 0;
            for (int j = 0; j < clusters[i].num_points; j++) {
                x_sum += clusters[i].points[j].x;
                y_sum += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = x_sum / clusters[i].num_points;
            clusters[i].centroid.y = y_sum / clusters[i].num_points;
            free(clusters[i].points);
            clusters[i].points = NULL;
            clusters[i].num_points = 0;
        }

        num_iterations++;
    }

    // Output the final centroids of each cluster
    for (int i = 0; i < K; i++) {
        printf("Cluster %d: (%f, %f)\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
    }

    return 0;
}