//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Define the number of clusters and the data points
#define K 3
#define N 15

// Define the maximum number of iterations and tolerance level
#define MAX_ITER 100
#define TOL 0.001

// Define a struct to represent a data point
typedef struct {
    double x;
    double y;
} Point2D;

// Define a struct to represent a cluster
typedef struct {
    Point2D centroid;
    Point2D points[N];
    int num_points;
} Cluster;

// Function to calculate the Euclidean distance between two points
double distance(Point2D p1, Point2D p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Function to assign points to initial clusters
void assign_clusters(Point2D data[N], Cluster clusters[K]) {
    int i, j, index;
    double min_dist, dist;
    
    // Assign each point to the closest cluster
    for (i = 0; i < N; i++) {
        min_dist = INFINITY;
        for (j = 0; j < K; j++) {
            dist = distance(data[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                index = j;
            }
        }
        clusters[index].points[clusters[index].num_points++] = data[i];
    }
}

// Function to recalculate the centroids of the clusters
void update_centroids(Cluster clusters[K]) {
    int i, j;
    double sum_x, sum_y;
    
    // Calculate the mean coordinates of the points in each cluster
    for (i = 0; i < K; i++) {
        sum_x = 0.0;
        sum_y = 0.0;
        for (j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].num_points;
        clusters[i].centroid.y = sum_y / clusters[i].num_points;
    }
}

// Function to check if the clusters have converged
bool has_converged(Cluster clusters[K], Cluster prev_clusters[K]) {
    int i, j;
    double dist;
    
    // Compare the centroids of each cluster in the current and previous iterations
    for (i = 0; i < K; i++) {
        dist = distance(clusters[i].centroid, prev_clusters[i].centroid);
        if (dist >= TOL)
            return false;
    }
    return true;
}

// Main function to run the algorithm
int main() {
    int i, j, iter;
    Point2D data[N] = {{0.5, 1.5}, {1.5, 2.5}, {3.5, 4.5}, {5.5, 6.5}, {8.5, 7.5}, 
                      {1.0, 3.0}, {3.0, 3.5}, {4.0, 4.0}, {6.0, 5.0}, {7.0, 5.5},
                      {2.5, 1.0}, {3.0, 2.0}, {4.5, 3.5}, {6.5, 6.0}, {8.0, 6.5}};
    Cluster clusters[K];
    Cluster prev_clusters[K];
    
    // Initialize the clusters with random centroids
    for (i = 0; i < K; i++) {
        clusters[i].centroid.x = data[i].x;
        clusters[i].centroid.y = data[i].y;
        clusters[i].num_points = 0;
    }
    
    // Run the K-means algorithm
    for (iter = 0; iter < MAX_ITER; iter++) {
        // Save the previous clusters for convergence checking
        for (i = 0; i < K; i++)
            prev_clusters[i] = clusters[i];
        
        // Assign points to clusters based on the current centroids
        assign_clusters(data, clusters);
        
        // Recalculate the centroids of each cluster
        update_centroids(clusters);
        
        // Check if the algorithm has converged
        if (has_converged(clusters, prev_clusters))
            break;
    }
    
    // Print the final cluster assignments and centroids
    printf("Final cluster assignments:\n");
    for (i = 0; i < K; i++) {
        printf("Cluster %d (centroid = (%0.2f, %0.2f)):\n", i+1, clusters[i].centroid.x, clusters[i].centroid.y);
        for (j = 0; j < clusters[i].num_points; j++)
            printf("(%0.2f, %0.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        printf("\n");
    }
    
    return 0;
}