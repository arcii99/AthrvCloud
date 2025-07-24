//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000           // Maximum number of data points
#define DIM 2            // Number of dimensions
#define K 3              // Number of clusters

// Structure to store a data point
struct Point {
    double x[DIM];
    int cluster;
};

// Calculate Euclidean distance between two data points
double distance(struct Point *p1, struct Point *p2) {
    double d = 0;
    for(int i = 0; i < DIM; i++) {
        d += pow((p1->x[i] - p2->x[i]), 2);
    }
    return sqrt(d);
}

// Initialize centroids randomly
void init_centroids(struct Point *points, struct Point *centroids) {
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < DIM; j++) {
            centroids[i].x[j] = points[rand() % N].x[j];
        }
    }
}

// Assign each data point to the closest centroid
void assign_clusters(struct Point *points, struct Point *centroids) {
    double min_dist, dist;
    int min_index;
    for(int i = 0; i < N; i++) {
        min_dist = distance(&points[i], &centroids[0]);
        min_index = 0;
        for(int j = 1; j < K; j++) {
            dist = distance(&points[i], &centroids[j]);
            if(dist < min_dist) {
                min_dist = dist;
                min_index = j;
            }
        }
        points[i].cluster = min_index;
    }
}

// Update centroid positions based on new cluster assignments
void update_centroids(struct Point *points, struct Point *centroids) {
    int cluster_sizes[K] = {0};
    for(int i = 0; i < N; i++) {
        cluster_sizes[points[i].cluster]++;
        for(int j = 0; j < DIM; j++) {
            centroids[points[i].cluster].x[j] += points[i].x[j];
        }
    }
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < DIM; j++) {
            centroids[i].x[j] /= cluster_sizes[i];
        }
    }
}

int main() {
    struct Point points[N];
    struct Point centroids[K];
    srand(time(NULL));          // Seed random number generator
    
    // Generate random data points
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < DIM; j++) {
            points[i].x[j] = rand() % 100;
        }
    }
    
    init_centroids(points, centroids);         // Initialize centroids randomly
    
    for(int i = 0; i < 10; i++) {              // Run K-means algorithm for 10 iterations
        assign_clusters(points, centroids);    // Assign data points to centroids
        update_centroids(points, centroids);   // Update centroid positions
    }
    
    printf("Final cluster assignments:\n");
    for(int i = 0; i < N; i++) {
        printf("Point %d: Cluster %d\n", i, points[i].cluster);
    }
    
    return 0;
}