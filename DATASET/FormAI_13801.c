//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Define the number of clusters and the maximum number of iterations for convergence
#define K 3
#define MAX_ITERATIONS 100

// Define the dimensions of the dataset
#define NUM_DIMENSIONS 2

// Define the size of the dataset
#define NUM_POINTS 10

// Define a structure to hold a point in the dataset
typedef struct {
    int id;
    float x[NUM_DIMENSIONS];
} Point;

// Define a structure to hold a cluster
typedef struct {
    int id;
    Point centroid;
    int num_points;
    Point points[NUM_POINTS];
} Cluster;

// Function to calculate the Euclidean distance between two points
float calculate_distance(Point p1, Point p2) {
    float distance = 0.0;
    for (int i = 0; i < NUM_DIMENSIONS; i++) {
        distance += pow((p1.x[i] - p2.x[i]), 2);
    }
    return sqrt(distance);
}

// Function to initialize the clusters with random centroids
void initialize_clusters(Point *data, Cluster *clusters) {
    // Loop through each cluster
    for (int i = 0; i < K; i++) {
        // Set the ID of the cluster
        clusters[i].id = i;
        // Set the number of points in the cluster to zero
        clusters[i].num_points = 0;
        // Select a random point from the dataset to use as the centroid of the cluster
        int random_index = rand() % NUM_POINTS;
        clusters[i].centroid = data[random_index];
    }
}

// Function to assign each point to the nearest cluster
void assign_points(Point *data, Cluster *clusters) {
    // Loop through each point
    for (int i = 0; i < NUM_POINTS; i++) {
        float min_distance = INFINITY;
        int min_cluster_id = -1;
        // Loop through each cluster
        for (int j = 0; j < K; j++) {
            // Calculate the distance between the point and the centroid of the cluster
            float distance = calculate_distance(data[i], clusters[j].centroid);
            // If the distance is smaller than the minimum distance so far,
            // update the minimum distance and the ID of the cluster with the minimum distance
            if (distance < min_distance) {
                min_distance = distance;
                min_cluster_id = j;
            }
        }
        // Add the point to the cluster with the minimum distance
        clusters[min_cluster_id].points[clusters[min_cluster_id].num_points] = data[i];
        clusters[min_cluster_id].num_points++;
    }
}

// Function to update the centroids of the clusters
void update_centroids(Cluster *clusters) {
    // Loop through each cluster
    for (int i = 0; i < K; i++) {
        // Calculate the new centroid of the cluster by averaging the positions of all points in the cluster
        Point new_centroid;
        for (int j = 0; j < NUM_DIMENSIONS; j++) {
            float sum = 0.0;
            for (int k = 0; k < clusters[i].num_points; k++) {
                sum += clusters[i].points[k].x[j];
            }
            new_centroid.x[j] = sum / clusters[i].num_points;
        }
        // Update the centroid of the cluster
        clusters[i].centroid = new_centroid;
        // Reset the list of points in the cluster
        clusters[i].num_points = 0;
    }
}

// Function to check if the clustering has converged
bool has_converged(Cluster *clusters, Cluster *old_clusters) {
    // Loop through each cluster
    for (int i = 0; i < K; i++) {
        // Check if the centroid of the cluster has changed
        if (calculate_distance(clusters[i].centroid, old_clusters[i].centroid) != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Declare the dataset
    Point data[NUM_POINTS] = {{0, {2, 10}}, {1, {2, 5}}, {2, {8, 4}}, {3, {5, 8}}, {4, {7, 5}}, {5, {6, 4}}, {6, {1, 2}}, {7, {4, 9}}, {8, {3, 9}}, {9, {5, 10}}};

    // Declare the clusters and the old clusters
    Cluster clusters[K];
    Cluster old_clusters[K];

    // Initialize the clusters with random centroids
    initialize_clusters(data, clusters);

    // Loop through a maximum number of iterations
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // Save a copy of the old clusters
        for (int j = 0; j < K; j++) {
            old_clusters[j] = clusters[j];
        }

        // Assign each point to the nearest cluster
        assign_points(data, clusters);

        // Update the centroids of the clusters
        update_centroids(clusters);

        // Check if the clustering has converged
        if (has_converged(clusters, old_clusters)) {
            break;
        }
    }

    // Print the final clusters
    for (int i = 0; i < K; i++) {
        printf("Cluster %d:\n", i);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x[0], clusters[i].centroid.x[1]);
        printf("Points:");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf(" (%f, %f)", clusters[i].points[j].x[0], clusters[i].points[j].x[1]);
        }
        printf("\n");
    }

    return 0;
}