//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000 // Maximum number of data points
#define DIM 3   // Dimension of each data point
#define K 5     // Number of clusters

// Function to compute Euclidean distance between two data points
double euclidean_distance(double* p1, double* p2, int dim)
{
    double dist = 0.0;
    for (int i = 0; i < dim; i++) {
        dist += pow(p1[i] - p2[i], 2);
    }
    return sqrt(dist);
}

// Function to return index of nearest cluster centroid
int find_nearest_centroid(double* point, double** centroids, int k, int dim)
{
    int nearest = 0;
    double min_dist = euclidean_distance(point, centroids[0], dim);
    for (int i = 1; i < k; i++) {
        double dist = euclidean_distance(point, centroids[i], dim);
        if (dist < min_dist) {
            nearest = i;
            min_dist = dist;
        }
    }
    return nearest;
}

int main()
{
    // Generate random data points
    double data[N][DIM];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < DIM; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }
    
    // Initialize cluster centroids randomly
    double* centroids[K];
    for (int i = 0; i < K; i++) {
        centroids[i] = (double*)malloc(DIM * sizeof(double));
        for (int j = 0; j < DIM; j++) {
            centroids[i][j] = (double)rand() / RAND_MAX;
        }
    }
    
    // Perform K-means clustering
    int assignments[N];
    double* new_centroids[K];
    for (int iter = 0; iter < 10; iter++) {
        // Assign each point to nearest cluster centroid
        for (int i = 0; i < N; i++) {
            assignments[i] = find_nearest_centroid(data[i], centroids, K, DIM);
        }
        
        // Compute new centroid for each cluster
        for (int i = 0; i < K; i++) {
            new_centroids[i] = (double*)calloc(DIM, sizeof(double));
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (assignments[j] == i) {
                    for (int d = 0; d < DIM; d++) {
                        new_centroids[i][d] += data[j][d];
                    }
                    count++;
                }
            }
            if (count > 0) {
                for (int d = 0; d < DIM; d++) {
                    new_centroids[i][d] /= count;
                }
            }
        }
        
        // Update cluster centroids
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < DIM; j++) {
                centroids[i][j] = new_centroids[i][j];
            }
            free(new_centroids[i]);
        }
    }
    
    // Print final centroids
    for (int i = 0; i < K; i++) {
        printf("Cluster %d centroid: [ ", i+1);
        for (int j = 0; j < DIM; j++) {
            printf("%.2f ", centroids[i][j]);
        }
        printf("]\n");
        free(centroids[i]);
    }
    
    return 0;
}