//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 2
#define MAX_ITERATIONS 100

double euclidean_distance(double *x, double *y, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += pow(x[i] - y[i], 2);
    }
    return sqrt(sum);
}

void k_means(double **data, int n, int m, int *assignments) {
    double centroids[K][m];
    
    // Initialize centroids with random data points
    for (int i = 0; i < K; i++) {
        int rand_index = rand() % n;
        for (int j = 0; j < m; j++) {
            centroids[i][j] = data[rand_index][j];
        }
    }
    
    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        // Assign data points to centroids
        for (int i = 0; i < n; i++) {
            double min_distance = INFINITY;
            for (int j = 0; j < K; j++) {
                double distance = euclidean_distance(data[i], centroids[j], m);
                if (distance < min_distance) {
                    min_distance = distance;
                    assignments[i] = j;
                }
            }
        }
        
        // Update centroids
        double new_centroids[K][m];
        int cluster_sizes[K] = {0};
        for (int i = 0; i < n; i++) {
            int cluster = assignments[i];
            for (int j = 0; j < m; j++) {
                new_centroids[cluster][j] += data[i][j];
            }
            cluster_sizes[cluster]++;
        }
        for (int i = 0; i < K; i++) {
            if (cluster_sizes[i] == 0) continue;
            for (int j = 0; j < m; j++) {
                centroids[i][j] = new_centroids[i][j] / cluster_sizes[i];
            }
        }
        
        iteration++;
    }
}

int main() {
    // Example data points: (0,0), (0,1), (1,0), (1,1), (5,5), (5,6), (6,5), (6,6)
    double data[8][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {5, 5}, {5, 6}, {6, 5}, {6, 6}};
    int assignments[8];
    
    k_means((double **)data, 8, 2, assignments);
    
    // Print assignments
    for (int i = 0; i < 8; i++) {
        printf("(%g, %g) belongs to cluster %d\n", data[i][0], data[i][1], assignments[i]);
    }
    
    return 0;
}