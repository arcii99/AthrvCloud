//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // Number of clusters
#define N 10 // Number of data points

// Function prototypes
float euclidean_distance(float x1, float y1, float x2, float y2);
int find_closest_cluster(float x, float y, float centroids[][2]);
void update_centroids(float data[][2], int labels[], float centroids[][2]);

int main() {
    // Data initialization
    float data[N][2] = {{2, 10}, {2, 5}, {8, 4}, {5, 8}, {7, 5}, {6, 4}, {1, 2}, {4, 9}, {7, 4}, {5, 2}};
    int labels[N] = {0}; // Cluster labels for each data point
    float centroids[K][2] = {{2, 10}, {5, 8}, {1, 2}}; // Initial centroids

    // K-means clustering
    for (int i = 0; i < 100; i++) {
        // Assign each data point to its closest centroid
        for (int j = 0; j < N; j++) {
            float x = data[j][0];
            float y = data[j][1];
            labels[j] = find_closest_cluster(x, y, centroids);
        }

        // Update centroids based on new cluster assignments
        update_centroids(data, labels, centroids);
    }

    // Print final cluster assignments
    printf("Final Cluster Assignments:\n");
    for (int i = 0; i < N; i++) {
        printf("Data Point %d --> Cluster %d\n", i+1, labels[i]+1);
    }

    return 0;
}

// Calculates the Euclidean distance between two points in a 2D plane
float euclidean_distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Finds the closest cluster centroid for a given data point
int find_closest_cluster(float x, float y, float centroids[][2]) {
    int closest_cluster = 0;
    float min_distance = euclidean_distance(x, y, centroids[0][0], centroids[0][1]);

    for (int i = 1; i < K; i++) {
        float distance = euclidean_distance(x, y, centroids[i][0], centroids[i][1]);
        if (distance < min_distance) {
            closest_cluster = i;
            min_distance = distance;
        }
    }

    return closest_cluster;
}

// Updates the centroids based on the new cluster assignments
void update_centroids(float data[][2], int labels[], float centroids[][2]) {
    // Initialize sum and count arrays for each cluster
    float sum[K][2] = {{0}};
    int count[K] = {0};

    // Calculate sums and counts for each cluster
    for (int i = 0; i < N; i++) {
        int cluster = labels[i];
        sum[cluster][0] += data[i][0];
        sum[cluster][1] += data[i][1];
        count[cluster]++;
    }

    // Update centroids based on the new sums and counts
    for (int i = 0; i < K; i++) {
        centroids[i][0] = sum[i][0] / count[i];
        centroids[i][1] = sum[i][1] / count[i];
    }
}