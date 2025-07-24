//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define K 2 // number of clusters
#define N 10 // number of datapoints
#define MAX_ITERATIONS 1000 // maximum number of iterations
#define THRESHOLD 0.001 // threshold for convergence
#define DIMENSIONS 2 // number of dimensions of the data points

float euclidean_distance(float *point1, float *point2);

int main()
{
    // Step 1: Initialize the data points
    float datapoints[N][DIMENSIONS] = { {2, 6}, {3, 4}, {3, 8}, {4, 7}, {6, 2}, {6, 4}, {7, 3}, {7, 4}, {8, 5}, {7, 6} };

    // Step 2: Initialize the centroids randomly
    float centroids[K][DIMENSIONS];
    int i, j;
    for (i = 0; i < K; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            centroids[i][j] = (float)(rand() % 10);
        }
    }

    // Step 3: Initialize the assignments
    int assignments[N];
    float distances[N];
    int k, closest_centroid;
    float distance;

    // Step 4: Cluster the data
    int iteration = 0;
    float diff = 1.0;
    while (iteration < MAX_ITERATIONS && diff > THRESHOLD) {
        // Step 4a: Assign each datapoint to the closest centroid
        for (i = 0; i < N; i++) {
            distance = euclidean_distance(datapoints[i], centroids[0]);
            closest_centroid = 0;
            for (k = 1; k < K; k++) {
                if ((distance = euclidean_distance(datapoints[i], centroids[k])) < distance) {
                    closest_centroid = k;
                }
            }
            assignments[i] = closest_centroid;
            distances[i] = distance;
        }

        // Step 4b: Update the centroids
        float new_centroids[K][DIMENSIONS] = {0};
        int cluster_sizes[K] = {0};
        for (i = 0; i < N; i++) {
            closest_centroid = assignments[i];
            for (j = 0; j < DIMENSIONS; j++) {
                new_centroids[closest_centroid][j] += datapoints[i][j];
            }
            cluster_sizes[closest_centroid]++;
        }
        for (k = 0; k < K; k++) {
            for (j = 0; j < DIMENSIONS; j++) {
                if (cluster_sizes[k] > 0) {
                    centroids[k][j] = new_centroids[k][j] / cluster_sizes[k];
                }
            }
        }

        // Step 4c: Calculate the difference between the old and new centroids
        diff = 0.0;
        for (k = 0; k < K; k++) {
            for (j = 0; j < DIMENSIONS; j++) {
                diff += fabs(centroids[k][j] - new_centroids[k][j]);
            }
        }

        iteration++;
    }

    // Step 5: Print the results
    printf("Final cluster assignments:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", assignments[i]);
    }
    printf("\n");

    return 0;
}

// function to calculate the euclidean distance between two points
float euclidean_distance(float *point1, float *point2) {
    int j;
    float distance = 0.0;
    for (j = 0; j < DIMENSIONS; j++) {
        distance += pow(point1[j] - point2[j], 2);
    }
    return sqrt(distance);
}