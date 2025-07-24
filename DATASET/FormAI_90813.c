//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 2 // Number of clusters
#define N 8 // Number of data points
#define D 2 // Number of dimensions

double Euclidean_distance(double x1[], double x2[], int n) {
    double distance = 0;
    for (int i = 0; i < n; i++) {
        distance += pow(x1[i] - x2[i], 2);
    }
    return sqrt(distance);
}

int main() {
    double data[N][D] = {{1, 2}, {1, 4}, {1, 0}, {4, 2}, {4, 4}, {4, 0}, {7, 2}, {7, 4}};
    int cluster[N]; // Cluster assignment for each data point
    double centroids[K][D]; // Centroids for the two clusters
    int count[K] = {0}; // Number of data points assigned to each cluster
    
    // Initialize centroids with random data points
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            centroids[i][j] = data[rand() % N][j];
        }
    }
    
    // Iterate until convergence
    int converged = 0;
    while (!converged) {
        // Assign data points to clusters based on closest centroid
        for (int i = 0; i < N; i++) {
            double min_distance = INFINITY;
            int min_cluster;
            for (int j = 0; j < K; j++) {
                double distance = Euclidean_distance(data[i], centroids[j], D);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_cluster = j;
                }
            }
            cluster[i] = min_cluster;
            count[min_cluster]++;
        }
        
        // Update centroids based on mean of assigned data points
        double new_centroids[K][D] = {{0}};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < D; j++) {
                new_centroids[cluster[i]][j] += data[i][j];
            }
        }
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < D; j++) {
                if (count[i] != 0) {
                    centroids[i][j] = new_centroids[i][j] / count[i];
                }
            }
        }
        
        // Check for convergence
        int converged_count = 0;
        for (int i = 0; i < K; i++) {
            if (Euclidean_distance(centroids[i], new_centroids[i], D) == 0) {
                converged_count++;
            }
        }
        if (converged_count == K) {
            converged = 1;
        }
    }
    
    // Print final cluster assignments
    for (int i = 0; i < N; i++) {
        printf("Data point %d assigned to cluster %d\n", i+1, cluster[i]+1);
    }
    
    return 0;
}