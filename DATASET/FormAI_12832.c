//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the maximum number of data points and the maximum dimensions
#define MAX_N 10000
#define MAX_DIM 10

// Define a structure for a data point
typedef struct {
    double values[MAX_DIM];
} DataPoint;

// Define a structure for the output of clustering
typedef struct {
    int clusterIndex;
    double distance;
} ClusterOutput;

// Define a function to calculate the distance between two data points
double distance(DataPoint a, DataPoint b, int dimensions) {
    double dist = 0.0;
    for (int i = 0; i < dimensions; i++) {
        dist += pow(a.values[i] - b.values[i], 2);
    }
    return sqrt(dist);
}

// Define the main function
int main() {

    // Initialize the random seed
    srand(time(NULL));

    // Declare variables for the data set
    int numPoints, numDimensions;
    DataPoint dataSet[MAX_N];

    // Prompt the user for the number of data points and dimensions
    printf("Enter the number of data points: ");
    scanf("%d", &numPoints);
    printf("Enter the number of dimensions: ");
    scanf("%d", &numDimensions);

    // Prompt the user to enter the data points
    for (int i = 0; i < numPoints; i++) {
        printf("Enter data point %d: ", i+1);
        for (int j = 0; j < numDimensions; j++) {
            scanf("%lf", &dataSet[i].values[j]);
        }
    }

    // Declare variables for the number of clusters and the maximum iterations
    int K, maxIterations;
    printf("Enter the number of clusters: ");
    scanf("%d", &K);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    // Declare variables for the centroids and the cluster assignments
    DataPoint centroids[K];
    int assignments[numPoints];

    // Initialize the centroids randomly
    for (int i = 0; i < K; i++) {
        centroids[i] = dataSet[rand() % numPoints];
    }

    // Declare variables for the cost and the previous cost
    double cost, prevCost = INFINITY;

    // Start the iterations
    for (int iter = 0; iter < maxIterations; iter++) {

        // Assign each data point to its nearest centroid
        for (int i = 0; i < numPoints; i++) {
            double minDistance = INFINITY;
            int minIndex;
            for (int j = 0; j < K; j++) {
                double d = distance(dataSet[i], centroids[j], numDimensions);
                if (d < minDistance) {
                    minDistance = d;
                    minIndex = j;
                }
            }
            assignments[i] = minIndex;
        }

        // Calculate the cost
        cost = 0.0;
        for (int i = 0; i < numPoints; i++) {
            cost += pow(distance(dataSet[i], centroids[assignments[i]], numDimensions), 2);
        }

        // Check if the cost has converged
        if (fabs(cost - prevCost) < 1e-6) {
            printf("Converged after %d iterations.\n", iter+1);
            break;
        }
        else {
            prevCost = cost;
        }

        // Update the centroids
        for (int i = 0; i < K; i++) {
            DataPoint sum = {0};
            int count = 0;
            for (int j = 0; j < numPoints; j++) {
                if (assignments[j] == i) {
                    for (int k = 0; k < numDimensions; k++) {
                        sum.values[k] += dataSet[j].values[k];
                    }
                    count++;
                }
            }
            if (count == 0) {
                centroids[i] = dataSet[rand() % numPoints];
            }
            else {
                for (int k = 0; k < numDimensions; k++) {
                    centroids[i].values[k] = sum.values[k] / count;
                }
            }
        }

    }

    // Output the cluster assignments and distances for each data point
    for (int i = 0; i < numPoints; i++) {
        double minDistance = INFINITY;
        int minIndex;
        for (int j = 0; j < K; j++) {
            double d = distance(dataSet[i], centroids[j], numDimensions);
            if (d < minDistance) {
                minDistance = d;
                minIndex = j;
            }
        }
        printf("Data point %d assigned to cluster %d with distance %lf.\n", i+1, minIndex+1, minDistance);
    }

    // Calculate the average distance of each point from its centroid
    ClusterOutput clusterOutputs[numPoints];
    for (int i = 0; i < numPoints; i++) {
        double minDistance = INFINITY;
        int minIndex;
        for (int j = 0; j < K; j++) {
            double d = distance(dataSet[i], centroids[j], numDimensions);
            if (d < minDistance) {
                minDistance = d;
                minIndex = j;
            }
        }
        clusterOutputs[i].clusterIndex = minIndex+1;
        clusterOutputs[i].distance = minDistance;
    }
    double totalDistance = 0.0;
    for (int i = 0; i < numPoints; i++) {
        totalDistance += clusterOutputs[i].distance;
    }
    printf("Average distance of data points from their assigned centroids: %lf.\n", totalDistance / numPoints);

    return 0;
}