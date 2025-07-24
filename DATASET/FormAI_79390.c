//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to hold data points
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate distance between two points
double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to initialize centroids
void init_centroids(Point** centroids, int num_clusters, Point* data_points, int num_points) {
    // Choose random data points as initial centroids
    for (int i = 0; i < num_clusters; i++) {
        int index = rand() % num_points;
        centroids[i] = &data_points[index];
    }
}

// Function to assign each data point to a cluster
void assign_clusters(Point** centroids, int num_clusters, Point* data_points, int num_points, int* clusters) {
    // Iterate over all data points
    for (int i = 0; i < num_points; i++) {
        // Initialize minimum distance to a very large number
        double min_distance = 1e9;
        int closest_cluster = -1;

        // Calculate distance to each centroid
        for (int j = 0; j < num_clusters; j++) {
            double d = distance(*centroids[j], data_points[i]);
            if (d < min_distance) {
                min_distance = d;
                closest_cluster = j;
            }
        }

        // Assign to closest cluster
        clusters[i] = closest_cluster;
    }
}

// Function to update centroids based on mean of assigned data points
void update_centroids(Point** centroids, int num_clusters, Point* data_points, int num_points, int* clusters) {
    // Initialize sum and count for each centroid
    Point sums[num_clusters];
    int counts[num_clusters];
    for (int i = 0; i < num_clusters; i++) {
        sums[i].x = 0;
        sums[i].y = 0;
        counts[i] = 0;
    }

    // Add up data points for each centroid
    for (int i = 0; i < num_points; i++) {
        Point p = data_points[i];
        int c = clusters[i];
        sums[c].x += p.x;
        sums[c].y += p.y;
        counts[c]++;
    }

    // Calculate mean for each centroid and update
    for (int i = 0; i < num_clusters; i++) {
        if (counts[i] == 0) {
            // If no data points assigned, choose new random centroid
            int index = rand() % num_points;
            centroids[i] = &data_points[index];
        } else {
            centroids[i]->x = sums[i].x / counts[i];
            centroids[i]->y = sums[i].y / counts[i];
        }
    }
}

int main() {
    // Generate some random data points
    int num_points = 100;
    Point data_points[num_points];
    for (int i = 0; i < num_points; i++) {
        data_points[i].x = (double) rand() / RAND_MAX;
        data_points[i].y = (double) rand() / RAND_MAX;
    }

    // Initialize variables for K-means clustering
    int num_clusters = 5;
    Point* centroids[num_clusters];
    int clusters[num_points];

    // Initialize centroids and assign initial clusters
    init_centroids(centroids, num_clusters, data_points, num_points);
    assign_clusters(centroids, num_clusters, data_points, num_points, clusters);

    // Iterate K-means algorithm until convergence (or max iterations)
    int max_iterations = 100;
    for (int i = 0; i < max_iterations; i++) {
        // Update centroids based on mean of assigned data points
        update_centroids(centroids, num_clusters, data_points, num_points, clusters);

        // Assign clusters based on new centroids
        assign_clusters(centroids, num_clusters, data_points, num_points, clusters);

        // Check for convergence (no cluster assignments change)
        int num_changes = 0;
        for (int j = 0; j < num_points; j++) {
            int c = clusters[j];
            double d = distance(*centroids[c], data_points[j]);
            if (d > 1e-6) {
                num_changes++;
            }
        }
        if (num_changes == 0) {
            printf("Converged after %d iterations.\n", i+1);
            break;
        }
    }

    return 0;
}