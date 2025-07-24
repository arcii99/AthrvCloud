//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of data points
#define MAX_DATA_POINTS 100

// Define the number of clusters to be formed
#define NUM_CLUSTERS 3

// Define the maximum number of iterations
#define MAX_ITERATIONS 50

// Define the maximum distance to cluster center
#define MAX_DISTANCE 1000000

// Define the data structure for each data point
typedef struct {
    float x;
    float y;
} data_point;

int main() {
    // Create an array of data points
    data_point data[MAX_DATA_POINTS];

    // Initialize the data points with random values
    for (int i = 0; i < MAX_DATA_POINTS; i++) {
        data[i].x = (float)rand();
        data[i].y = (float)rand();
    }

    // Create an array for the cluster centers
    data_point centers[NUM_CLUSTERS];

    // Initialize the cluster centers with the first NUM_CLUSTERS data points
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        centers[i] = data[i];
    }

    // Create an array to store the cluster assignments for each data point
    int assignments[MAX_DATA_POINTS];

    // Initialize the cluster assignments to -1 (unassigned)
    for (int i = 0; i < MAX_DATA_POINTS; i++) {
        assignments[i] = -1;
    }

    // Run the clustering algorithm for a maximum of MAX_ITERATIONS
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // Assign each point to the nearest cluster center
        for (int j = 0; j < MAX_DATA_POINTS; j++) {
            float min_dist = MAX_DISTANCE;
            int min_index = -1;
            for (int k = 0; k < NUM_CLUSTERS; k++) {
                float dist = sqrt(pow(data[j].x - centers[k].x, 2) + pow(data[j].y - centers[k].y, 2));
                if (dist < min_dist) {
                    min_dist = dist;
                    min_index = k;
                }
            }
            assignments[j] = min_index;
        }

        // Compute the new cluster centers
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            float x_sum = 0;
            float y_sum = 0;
            int count = 0;
            for (int k = 0; k < MAX_DATA_POINTS; k++) {
                if (assignments[k] == j) {
                    x_sum += data[k].x;
                    y_sum += data[k].y;
                    count++;
                }
            }
            if (count > 0) {
                centers[j].x = x_sum / count;
                centers[j].y = y_sum / count;
            }
        }
    }

    // Print the final cluster assignments
    printf("Final cluster assignments:\n");
    for (int i = 0; i < MAX_DATA_POINTS; i++) {
        printf("%d ", assignments[i]);
    }
    printf("\n");

    return 0;
}