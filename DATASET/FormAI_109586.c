//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100   // Number of data points
#define NUM_CLUSTERS 3   // Number of clusters
#define DIMENSIONS 2     // Number of dimensions (x, y)

float data[NUM_POINTS][DIMENSIONS];      // The data points
float centroids[NUM_CLUSTERS][DIMENSIONS];  // The centroid points
int membership[NUM_POINTS];              // Cluster membership of each point

float calculate_distance(float *point1, float *point2, int dimensions) {
    float distance = 0.0;
    for (int i = 0; i < dimensions; i++) {
        distance += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    }
    return sqrtf(distance);
}

void initialization(){
    // Initialize data points randomly
    for (int i = 0; i < NUM_POINTS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            data[i][j] = (float)rand() / (float)RAND_MAX;
        }
    }

    // Initialize centroids randomly
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            centroids[i][j] = (float)rand() / (float)RAND_MAX;
        }
    }
}

void find_nearest_centroid(){
    // Find the nearest centroid for each data point
    float min_distance, distance;
    int min_index;
    for (int i = 0; i < NUM_POINTS; i++) {
        min_distance = INFINITY;
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            distance = calculate_distance(data[i], centroids[j], DIMENSIONS);
            if (distance < min_distance) {
                min_distance = distance;
                min_index = j;
            }
        }
        membership[i] = min_index;
    }
}

void update_centroids(){
    // Update centroids to the mean of their members
    float sum[DIMENSIONS];
    int members;
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            sum[j] = 0.0;
        }
        members = 0;
        for (int k = 0; k < NUM_POINTS; k++) {
            if (membership[k] == i) {
                for (int j = 0; j < DIMENSIONS; j++) {
                    sum[j] += data[k][j];
                }
                members++;
            }
        }
        for (int j = 0; j < DIMENSIONS; j++) {
            if (members > 0) {
                centroids[i][j] = sum[j] / members;
            } else {
                centroids[i][j] = 0.0;
            }
        }
    }
}

void print_clusters(){
    printf("Clusters:\n");
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < NUM_POINTS; j++) {
            if (membership[j] == i) {
                printf("%f, %f\n", data[j][0], data[j][1]);
            }
        }
    }
}

int main() {
    // Initialization
    initialization();

    // Iterate until convergence
    int iterations = 0;
    while (iterations < 10) {
        iterations++;
        find_nearest_centroid();
        update_centroids();
    }

    // Print final clusters
    print_clusters();

    return 0;
}