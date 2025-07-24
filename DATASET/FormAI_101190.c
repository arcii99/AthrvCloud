//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A surreal implementation of the K-means clustering algorithm

// Define the number of clusters
#define NUM_CLUSTERS 3

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the number of data points
#define NUM_POINTS 100

// Define the features of each data point
#define NUM_FEATURES 2

// Define the minimum and maximum values for each feature
#define MIN_VALUE 0
#define MAX_VALUE 10

// Define the data structure for each data point
typedef struct {
    float features[NUM_FEATURES];
    int cluster;
} DataPoint;

// Declare functions
float distance(float features1[], float features2[]);
void assignToClusters(DataPoint dataPoints[], float centroids[][NUM_FEATURES], int numDataPoints);
void calculateCentroids(DataPoint dataPoints[], float centroids[][NUM_FEATURES], int numDataPoints);
void printClusters(DataPoint dataPoints[], int numDataPoints);

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    // Initialize the data points and centroids
    DataPoint dataPoints[NUM_POINTS];
    float centroids[NUM_CLUSTERS][NUM_FEATURES];
    
    // Generate the data points and initialize their features and cluster assignments
    int i, j;
    for (i = 0; i < NUM_POINTS; i++) {
        for (j = 0; j < NUM_FEATURES; j++) {
            dataPoints[i].features[j] = (float) (MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1));
        }
        dataPoints[i].cluster = -1;
    }
    
    // Print the initial data points
    printf("Initial Data Points:\n");
    for (i = 0; i < NUM_POINTS; i++) {
        for (j = 0; j < NUM_FEATURES; j++) {
            printf("%.2f ", dataPoints[i].features[j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Initialize the centroids randomly
    for (i = 0; i < NUM_CLUSTERS; i++) {
        for (j = 0; j < NUM_FEATURES; j++) {
            centroids[i][j] = (float) (MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1));
        }
    }
    
    // Print the initial centroids
    printf("Initial Centroids:\n");
    for (i = 0; i < NUM_CLUSTERS; i++) {
        for (j = 0; j < NUM_FEATURES; j++) {
            printf("%.2f ", centroids[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Iterate until convergence or maximum number of iterations reached
    int iteration = 0;
    int converged = 0;
    while (!converged && iteration < MAX_ITERATIONS) {
        assignToClusters(dataPoints, centroids, NUM_POINTS);
        calculateCentroids(dataPoints, centroids, NUM_POINTS);
        converged = 1;
        for (i = 0; i < NUM_POINTS; i++) {
            if (dataPoints[i].cluster != dataPoints[(i + 1) % NUM_POINTS].cluster) {
                converged = 0;
                break;
            }
        }
        iteration++;
    }
    
    // Print the final clusters and their centroids
    printf("Final Clusters:\n");
    printClusters(dataPoints, NUM_POINTS);
    printf("\nFinal Centroids:\n");
    for (i = 0; i < NUM_CLUSTERS; i++) {
        for (j = 0; j < NUM_FEATURES; j++) {
            printf("%.2f ", centroids[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

float distance(float features1[], float features2[]) {
    int i;
    float dist = 0;
    for (i = 0; i < NUM_FEATURES; i++) {
        dist += (features1[i] - features2[i]) * (features1[i] - features2[i]);
    }
    return dist;
}

void assignToClusters(DataPoint dataPoints[], float centroids[][NUM_FEATURES], int numDataPoints) {
    int i, j, k;
    float dist, minDist;
    for (i = 0; i < numDataPoints; i++) {
        minDist = distance(dataPoints[i].features, centroids[0]);
        dataPoints[i].cluster = 0;
        for (j = 1; j < NUM_CLUSTERS; j++) {
            dist = distance(dataPoints[i].features, centroids[j]);
            if (dist < minDist) {
                minDist = dist;
                dataPoints[i].cluster = j;
            }
        }
    }
}

void calculateCentroids(DataPoint dataPoints[], float centroids[][NUM_FEATURES], int numDataPoints) {
    int i, j, k, count;
    float sum;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        count = 0;
        for (j = 0; j < NUM_FEATURES; j++) {
            sum = 0;
            for (k = 0; k < numDataPoints; k++) {
                if (dataPoints[k].cluster == i) {
                    sum += dataPoints[k].features[j];
                    count++;
                }
            }
            if (count > 0) {
                centroids[i][j] = sum / count;
            }
        }
    }
}

void printClusters(DataPoint dataPoints[], int numDataPoints) {
    int i, j;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        for (j = 0; j < numDataPoints; j++) {
            if (dataPoints[j].cluster == i) {
                printf("%.2f %.2f\n", dataPoints[j].features[0], dataPoints[j].features[1]);
            }
        }
        printf("\n");
    }
}