//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10 // Number of data points
#define K 3 // Number of clusters

// Define data structure for a point
typedef struct {
    double x;
    double y;
} point_t;

// Define data structure for a cluster
typedef struct {
    point_t centroid;
    int size;
    point_t *points;
} cluster_t;

// Function to calculate Euclidean distance between two points
double euclidean_distance(point_t a, point_t b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

// Function to randomly initialize cluster centroids
void initialize_clusters(point_t *data_points, cluster_t *clusters) {
    for (int i = 0; i < K; i++) {
        clusters[i].centroid = data_points[rand() % N];
        clusters[i].size = 0;
        clusters[i].points = malloc(sizeof(point_t) * N);
    }
}

// Function to assign data points to clusters
void assign_points_to_clusters(point_t *data_points, cluster_t *clusters) {
    for (int i = 0; i < N; i++) {
        double min_dist = INFINITY;
        cluster_t closest_cluster;

        for (int j = 0; j < K; j++) {
            double dist = euclidean_distance(data_points[i], clusters[j].centroid);

            if (dist < min_dist) {
                min_dist = dist;
                closest_cluster = clusters[j];
            }
        }

        closest_cluster.points[closest_cluster.size++] = data_points[i];
    }
}

// Function to recalculate cluster centroids
void recalculate_cluster_centroids(cluster_t *clusters) {
    for (int i = 0; i < K; i++) {
        double avg_x = 0.0;
        double avg_y = 0.0;

        for (int j = 0; j < clusters[i].size; j++) {
            avg_x += clusters[i].points[j].x;
            avg_y += clusters[i].points[j].y;
        }

        if (clusters[i].size > 0) {
            clusters[i].centroid.x = avg_x / clusters[i].size;
            clusters[i].centroid.y = avg_y / clusters[i].size;
        }
    }
}

// Function to print clusters
void print_clusters(cluster_t *clusters) {
    for (int i = 0; i < K; i++) {
        printf("Cluster %d:\n", i);

        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%f,%f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }

        printf("Centroid: (%f,%f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
    }
}

int main() {
    // Initialize data points
    point_t data_points[N] = {
        { 1.0, 2.0 },
        { 2.0, 1.0 },
        { 4.0, 5.0 },
        { 5.0, 4.0 },
        { 7.0, 6.0 },
        { 6.0, 7.0 },
        { 9.0, 8.0 },
        { 8.0, 9.0 },
        { 17.0, 18.0 },
        { 18.0, 17.0 }
    };

    // Initialize clusters
    cluster_t clusters[K];
    initialize_clusters(data_points, clusters);

    // Perform clustering
    for (int i = 0; i < 10; i++) {
        assign_points_to_clusters(data_points, clusters);
        recalculate_cluster_centroids(clusters);
    }

    // Print final clusters
    print_clusters(clusters);

    // Free memory
    for (int i = 0; i < K; i++) {
        free(clusters[i].points);
    }

    return 0;
}