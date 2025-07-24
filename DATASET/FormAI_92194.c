//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("Welcome to the Shape-Shifting C Clustering Algorithm Implementation Example Program!\n\n");

    // Generating random data points
    srand(12345);
    int n = 50;
    float data_points[n][2];
    float x = 0.0, y = 0.0;
    for(int i = 0; i < n; i++) {
        data_points[i][0] = x + (float)rand()/RAND_MAX * 10.0 - 5.0;
        data_points[i][1] = y + (float)rand()/RAND_MAX * 10.0 - 5.0;
        x = data_points[i][0];
        y = data_points[i][1];
    }

    // Initialize clusters with random centroids
    int k = 3;
    float centroids[k][2];
    int cluster_size[k];
    for(int i = 0; i < k; i++) {
        centroids[i][0] = (float)rand()/RAND_MAX * 20.0 - 10.0;
        centroids[i][1] = (float)rand()/RAND_MAX * 20.0 - 10.0;
        cluster_size[i] = 0;
    }

    printf("Initial centroids:\n");
    for(int i = 0; i < k; i++) {
        printf("(%f, %f)\n", centroids[i][0], centroids[i][1]);
    }
    printf("\n");

    // Run clustering algorithm for 10 iterations
    int max_iterations = 10;
    for(int iteration = 0; iteration < max_iterations; iteration++) {
        // Assign each data point to a cluster
        int assigned_clusters[n];
        for(int i = 0; i < n; i++) {
            float min_distance = 1000000.0;
            int closest_cluster = -1;
            for(int j = 0; j < k; j++) {
                float distance = sqrt(pow(data_points[i][0]-centroids[j][0], 2) + pow(data_points[i][1]-centroids[j][1], 2));
                if(distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = j;
                }
            }
            assigned_clusters[i] = closest_cluster;
            cluster_size[closest_cluster]++;
        }

        // Update centroids
        for(int i = 0; i < k; i++) {
            float sum_x = 0.0, sum_y = 0.0;
            for(int j = 0; j < n; j++) {
                if(assigned_clusters[j] == i) {
                    sum_x += data_points[j][0];
                    sum_y += data_points[j][1];
                }
            }
            centroids[i][0] = sum_x / cluster_size[i];
            centroids[i][1] = sum_y / cluster_size[i];
        }

        // Print iteration results
        printf("Iteration %d:\n", iteration+1);
        for(int i = 0; i < k; i++) {
            printf("Cluster %d (centroid: (%f, %f)):\n", i+1, centroids[i][0], centroids[i][1]);
            for(int j = 0; j < n; j++) {
                if(assigned_clusters[j] == i) {
                    printf("(%f, %f)\n", data_points[j][0], data_points[j][1]);
                }
            }
            printf("\n");
        }

        // Clear cluster size for next iteration
        for(int i = 0; i < k; i++) {
            cluster_size[i] = 0;
        }
    }
    return 0;
}