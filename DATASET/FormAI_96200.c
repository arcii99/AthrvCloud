//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of clusters
#define K 3

// Define the maximum number of iterations
#define MAX_ITERATIONS 100

// Define the error threshold
#define ERROR_THRESHOLD 0.01

// Define the number of data points
#define N 10

// Define the data points
float data[N][2] = {
    {1.0, 1.0},
    {1.5, 2.0},
    {3.0, 4.0},
    {5.0, 7.0},
    {3.5, 5.0},
    {4.5, 5.0},
    {3.5, 4.5},
    {4.5, 4.5},
    {5.0, 4.5},
    {5.5, 4.5}
};

// Define the centroids
float centroids[K][2];

// Define the clusters
int clusters[N];

// Declare the k-means clustering function
void kmeans_clustering(float data[N][2], float centroids[][2], int clusters[], int k, int max_iterations, float error_threshold);

int main() {
    // Initialize the centroids randomly
    for (int i = 0; i < K; i++) {
        centroids[i][0] = (float) rand() / RAND_MAX * 6.0;
        centroids[i][1] = (float) rand() / RAND_MAX * 8.0;
    }

    // Perform the k-means clustering algorithm
    kmeans_clustering(data, centroids, clusters, K, MAX_ITERATIONS, ERROR_THRESHOLD);

    // Print the results
    for (int i = 0; i < N; i++) {
        printf("Data point %d: (%.1f, %.1f) - Cluster %d\n", i + 1, data[i][0], data[i][1], clusters[i]);
    }

    return 0;
}

void kmeans_clustering(float data[N][2], float centroids[][2], int clusters[], int k, int max_iterations, float error_threshold) {
    // Initialize the error to a high value
    float error = 9999.0;

    // Repeat until convergence or maximum iterations reached
    for (int iteration = 0; iteration < max_iterations && error > error_threshold; iteration++) {
        // Assign each data point to a cluster
        for (int i = 0; i < N; i++) {
            // Initialize the minimum distance to a high value
            float min_distance = 9999.0;

            // Iterate over each centroid to find the closest one
            for (int j = 0; j < k; j++) {
                // Calculate the Euclidean distance between the data point and the centroid
                float distance = sqrt(pow(data[i][0] - centroids[j][0], 2) + pow(data[i][1] - centroids[j][1], 2));

                // If the distance is smaller than the minimum distance, assign the point to the cluster
                if (distance < min_distance) {
                    clusters[i] = j;
                    min_distance = distance;
                }
            }
        }

        // Update the centroids
        error = 0.0;
        for (int i = 0; i < k; i++) {
            // Calculate the mean coordinates of the cluster
            float sum_x = 0.0, sum_y = 0.0;
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (clusters[j] == i) {
                    sum_x += data[j][0];
                    sum_y += data[j][1];
                    count++;
                }
            }
            centroids[i][0] = sum_x / count;
            centroids[i][1] = sum_y / count;

            // Calculate the error
            error += sqrt(pow(sum_x - centroids[i][0] * count, 2) + pow(sum_y - centroids[i][1] * count, 2));
        }

        // Print the error for this iteration
        printf("Iteration %d: error = %.2f\n", iteration + 1, error);
    }
}