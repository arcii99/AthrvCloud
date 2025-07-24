//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100      // Maximum iterations for convergence
#define NUM_POINTS 7            // Number of points in dataset
#define NUM_CLUSTERS 2          // Number of clusters for grouping

void calculate_distance(float data[][2], float centroids[][2], int grouping[]) {
    // Calculate Euclidean distance between points and centroids
    int i,j;
    float distance[NUM_POINTS][NUM_CLUSTERS];
    for(i=0; i<NUM_POINTS; i++) {
        for(j=0; j<NUM_CLUSTERS; j++) {
            distance[i][j] = sqrt(pow((data[i][0]-centroids[j][0]),2) + pow((data[i][1]-centroids[j][1]),2));
        }
    }
    // Assign points to nearest centroid
    for(i=0; i<NUM_POINTS; i++) {
        float min_distance = distance[i][0];
        int min_index = 0;
        for(j=1; j<NUM_CLUSTERS; j++) {
            if(distance[i][j] < min_distance) {
                min_distance = distance[i][j];
                min_index = j;
            }
        }
        grouping[i] = min_index;
    }
}

void calculate_centroid(float data[][2], float centroids[][2], int grouping[]) {
    // Calculate new centroids based on assigned points
    int i,j,k;
    float new_centroids[NUM_CLUSTERS][2];
    int count[NUM_CLUSTERS];
    for(i=0; i<NUM_CLUSTERS; i++) {
        new_centroids[i][0] = 0;
        new_centroids[i][1] = 0;
        count[i] = 0;
    }
    for(i=0; i<NUM_POINTS; i++) {
        int index = grouping[i];
        new_centroids[index][0] += data[i][0];
        new_centroids[index][1] += data[i][1];
        count[index]++;
    }
    for(i=0; i<NUM_CLUSTERS; i++) {
        if(count[i] != 0) {
            centroids[i][0] = new_centroids[i][0] / count[i];
            centroids[i][1] = new_centroids[i][1] / count[i];
        }
    }
}

int main() {
    // Initialize data and centroids
    float data[NUM_POINTS][2] = {{0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6}};
    float centroids[NUM_CLUSTERS][2] = {{1,1},{5,5}};
    int grouping[NUM_POINTS] = {0,0,0,0,0,0,0};
    
    // Cluster data using k-means algorithm
    int i;
    for(i=0; i<MAX_ITERATIONS; i++) {
        calculate_distance(data, centroids, grouping);
        calculate_centroid(data, centroids, grouping);
    }
    
    // Print results
    printf("Data:\n");
    for(i=0; i<NUM_POINTS; i++) {
        printf("(%f,%f) ", data[i][0], data[i][1]);
    }
    printf("\n\nCentroids:\n");
    for(i=0; i<NUM_CLUSTERS; i++) {
        printf("(%f,%f) ", centroids[i][0], centroids[i][1]);
    }
    printf("\n\nGrouping:\n");
    for(i=0; i<NUM_POINTS; i++) {
        printf("%d ", grouping[i]);
    }
    printf("\n");
    return 0;
}