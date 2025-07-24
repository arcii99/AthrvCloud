//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100      // Maximum number of data points
#define K 4        // Number of clusters

// Struct for holding data points
typedef struct {
    double x;
    double y;
} point;

// Struct for holding cluster information
typedef struct {
    point centroid;
    point points[N];
    int num_points;
} cluster;

// Function for calculating Euclidean distance between two points
double dist(point p1, point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Function for initializing the clusters with random centroids
void init_clusters(cluster* clusters, point* data, int num_points) {
    // Initialize random number generator
    srand(42);

    // Loop through clusters and set initial centroids to random data points
    for (int i = 0; i < K; i++) {
        int idx = rand() % num_points;
        clusters[i].centroid = data[idx];
        clusters[i].num_points = 0;
    }
}

// Function for assigning each point to the nearest cluster
void assign_to_clusters(cluster* clusters, point* data, int num_points) {
    // Loop through data points and assign to nearest cluster
    for (int i = 0; i < num_points; i++) {
        double min_dist = INFINITY;
        int min_index = -1;

        // Find nearest cluster
        for (int j = 0; j < K; j++) {
            double d = dist(data[i], clusters[j].centroid);
            if (d < min_dist) {
                min_dist = d;
                min_index = j;
            }
        }

        // Add point to nearest cluster
        clusters[min_index].points[clusters[min_index].num_points++] = data[i];
    }
}

// Function for updating the centroids of each cluster based on the points assigned to it
void update_centroids(cluster* clusters) {
    // Loop through clusters and update centroids based on points assigned to it
    for (int i = 0; i < K; i++) {
        // Calculate average x and y values of points in cluster
        double avg_x = 0.0;
        double avg_y = 0.0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            avg_x += clusters[i].points[j].x;
            avg_y += clusters[i].points[j].y;
        }
        avg_x /= clusters[i].num_points;
        avg_y /= clusters[i].num_points;

        // Update centroid
        clusters[i].centroid.x = avg_x;
        clusters[i].centroid.y = avg_y;

        // Reset number of points in cluster
        clusters[i].num_points = 0;
    }
}

// Function for performing k-means clustering
void k_means(cluster* clusters, point* data, int num_points, int max_iterations) {
    // Initialize clusters with random centroids
    init_clusters(clusters, data, num_points);

    // Loop through iterations and update cluster assignments/centroids each time
    for (int i = 0; i < max_iterations; i++) {
        // Assign each point to its nearest cluster
        assign_to_clusters(clusters, data, num_points);

        // Update centroids of clusters based on their points
        update_centroids(clusters);
    }
}

int main() {
    // Generate data points
    point data[N];
    for (int i = 0; i < N; i++) {
        data[i].x = ((double) rand() / RAND_MAX) * 10.0 - 5.0;
        data[i].y = ((double) rand() / RAND_MAX) * 10.0 - 5.0;
    }

    // Perform k-means clustering on data points
    cluster clusters[K];
    k_means(clusters, data, N, 10);

    // Print results
    for (int i = 0; i < K; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points:\n");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    return 0;
}