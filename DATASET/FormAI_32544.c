//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Euclidean Distance function
double euclidean_distance(double *a, double *b, int dimensions) {
    double distance = 0;
    for(int i=0; i<dimensions; i++) {
        distance += pow(b[i]-a[i], 2);
    }
    return sqrt(distance);
}

// K-means Clustering function
void kmeans_clustering(double **data, int num_points, int dimensions, int num_clusters, double **centroids, int max_iterations) {
    bool clusters_changed = true;
    int *cluster_ids = (int*) malloc(num_points * sizeof(int));
    int iterations = 0;
    while(clusters_changed && iterations < max_iterations) {
        clusters_changed = false;
        // Assign each point to the closest centroid
        for(int i=0; i<num_points; i++) {
            double min_distance = INFINITY;
            for(int j=0; j<num_clusters; j++) {
                double distance = euclidean_distance(data[i], centroids[j], dimensions);
                if(distance < min_distance) {
                    min_distance = distance;
                    cluster_ids[i] = j;
                }
            }
        }
        // Compute new cluster centroids
        double **new_centroids = (double**) malloc(num_clusters * sizeof(double*));
        for(int i=0; i<num_clusters; i++) {
            new_centroids[i] = (double*) malloc(dimensions * sizeof(double));
            int num_points_in_cluster = 0;
            for(int j=0; j<dimensions; j++) {
                new_centroids[i][j] = 0;
            }
            for(int j=0; j<num_points; j++) {
                if(cluster_ids[j] == i) {
                    for(int k=0; k<dimensions; k++) {
                        new_centroids[i][k] += data[j][k];
                    }
                    num_points_in_cluster++;
                }
            }
            for(int j=0; j<dimensions; j++) {
                new_centroids[i][j] /= num_points_in_cluster;
            }
        }
        // Check if the clusters have changed
        for(int i=0; i<num_clusters; i++) {
            for(int j=0; j<dimensions; j++) {
                if(new_centroids[i][j] != centroids[i][j]) {
                    clusters_changed = true;
                }
            }
        }
        // Update centroids
        for(int i=0; i<num_clusters; i++) {
            for(int j=0; j<dimensions; j++) {
                centroids[i][j] = new_centroids[i][j];
            }
        }
        iterations++;
    }
    printf("Number of iterations: %d\n", iterations);
    printf("Final cluster assignments:\n");
    for(int i=0; i<num_points; i++) {
        printf("Point %d -> Cluster %d\n", i, cluster_ids[i]);
    }
}

// Main function
int main() {
    // Data points (4-dimensional)
    double data[10][4] = {
        {5.0, 3.5, 1.3, 0.3},
        {4.9, 3.0, 1.4, 0.2},
        {4.7, 3.2, 1.3, 0.2},
        {7.0, 3.2, 4.7, 1.4},
        {6.4, 3.2, 4.5, 1.5},
        {6.9, 3.1, 4.9, 1.5},
        {6.3, 3.3, 6.0, 2.5},
        {5.8, 2.7, 5.1, 1.9},
        {7.1, 3.0, 5.9, 2.1},
        {6.3, 2.9, 5.6, 1.8}
    };
    // Parameters for K-means Clustering
    int num_points = 10;
    int dimensions = 4;
    int num_clusters = 3;
    int max_iterations = 100;
    // Select initial centroids (randomly or based on some heuristic)
    double centroids[3][4] = {
        {5.0, 3.5, 1.3, 0.3},
        {6.9, 3.1, 4.9, 1.5},
        {6.3, 2.9, 5.6, 1.8}
    };
    // Perform K-means Clustering
    kmeans_clustering(data, num_points, dimensions, num_clusters, centroids, max_iterations);
    return 0;
}