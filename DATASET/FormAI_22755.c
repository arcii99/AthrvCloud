//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000 // Maximum number of data points
#define K 3 // Number of clusters

typedef struct {
    float x;
    float y;
} Point;

int main() {
    // Generate random data points
    Point data[N];
    for (int i = 0; i < N; i++) {
        data[i].x = (float)rand() / RAND_MAX;
        data[i].y = (float)rand() / RAND_MAX;
    }
    
    // Initialize cluster centroids randomly
    Point centroids[K];
    for (int i = 0; i < K; i++) {
        centroids[i].x = (float)rand() / RAND_MAX;
        centroids[i].y = (float)rand() / RAND_MAX;
    }
    
    // Initialize cluster assignments
    int assignment[N];
    for (int i = 0; i < N; i++) {
        assignment[i] = -1;
    }
    
    // Iterate until convergence (or max iterations)
    int max_iter = 100;
    int iter = 0;
    float eps = 1e-6;
    float norm = INFINITY;
    while (iter < max_iter && norm > eps) {
        // Assign points to closest centroids
        for (int i = 0; i < N; i++) {
            float min_dist = INFINITY;
            int min_idx = -1;
            for (int j = 0; j < K; j++) {
                float dist = sqrt(pow(data[i].x - centroids[j].x, 2) + pow(data[i].y - centroids[j].y, 2));
                if (dist < min_dist) {
                    min_dist = dist;
                    min_idx = j;
                }
            }
            assignment[i] = min_idx;
        }
        
        // Update centroids
        Point new_centroids[K];
        for (int i = 0; i < K; i++) {
            new_centroids[i].x = 0.0;
            new_centroids[i].y = 0.0;
        }
        int count[K];
        for (int i = 0; i < K; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            new_centroids[assignment[i]].x += data[i].x;
            new_centroids[assignment[i]].y += data[i].y;
            count[assignment[i]]++;
        }
        for (int i = 0; i < K; i++) {
            if (count[i] > 0) {
                new_centroids[i].x /= count[i];
                new_centroids[i].y /= count[i];
            }
        }
        
        // Compute norm of centroid updates
        norm = 0.0;
        for (int i = 0; i < K; i++) {
            norm += sqrt(pow(new_centroids[i].x - centroids[i].x, 2) + pow(new_centroids[i].y - centroids[i].y, 2));
        }
        
        // Update centroids
        for (int i = 0; i < K; i++) {
            centroids[i].x = new_centroids[i].x;
            centroids[i].y = new_centroids[i].y;
        }
        
        iter++;
    }
    
    // Print results
    printf("Cluster centroids:\n");
    for (int i = 0; i < K; i++) {
        printf("Cluster %d: (%.2f, %.2f)\n", i, centroids[i].x, centroids[i].y);
    }
    
    return 0;
}