//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // Number of clusters
#define MAX_ITER 100 // Maximum number of iterations

// Function to calculate distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

int main() {
    double data_points[10][2] = {{2, 4}, {2, 3}, {3, 5}, {8, 7}, 
                                {9, 7}, {7, 3}, {5, 2}, {5, 3}, {6, 2}, {4, 6}};
    int data_points_size = sizeof(data_points)/sizeof(data_points[0]);
    int i, j, k, iterations;
    double x, y, min_distance, new_distance, cluster[K][2], clusters_sum[K][2];
    int counts[K];
    
    // Initialize clusters randomly
    for (i = 0; i < K; i++) {
        cluster[i][0] = data_points[rand()%data_points_size][0]; // Random x-coordinate
        cluster[i][1] = data_points[rand()%data_points_size][1]; // Random y-coordinate
    }
    
    // Start iterations
    for (iterations = 0; iterations < MAX_ITER; iterations++) {
        
        // Reset cluster sums and counts
        for (i = 0; i < K; i++) {
            clusters_sum[i][0] = 0;
            clusters_sum[i][1] = 0;
            counts[i] = 0;
        }
        
        // Assign points to clusters
        for (i = 0; i < data_points_size; i++) {
            x = data_points[i][0];
            y = data_points[i][1];
            min_distance = -1;
            for (j = 0; j < K; j++) {
                new_distance = distance(x, y, cluster[j][0], cluster[j][1]);
                if (min_distance == -1 || new_distance < min_distance) {
                    min_distance = new_distance;
                    data_points[i][2] = j; // Store assigned cluster for this point
                }
            }
            clusters_sum[(int)data_points[i][2]][0] += x;
            clusters_sum[(int)data_points[i][2]][1] += y;
            counts[(int)data_points[i][2]]++;
        }
        
        // Update cluster centroids
        for (i = 0; i < K; i++) {
            if (counts[i] == 0) continue; // No points assigned to this cluster
            cluster[i][0] = clusters_sum[i][0]/counts[i];
            cluster[i][1] = clusters_sum[i][1]/counts[i];
        }
    }
    
    // Print final cluster assignments
    printf("Final cluster assignments:\n");
    for (j = 0; j < K; j++) {
        printf("Cluster %d: ", j+1);
        for (i = 0; i < data_points_size; i++) {
            if (data_points[i][2] == j) {
                printf("(%g, %g) ", data_points[i][0], data_points[i][1]);
            }
        }
        printf("\n");
    }
    
    return 0;
}