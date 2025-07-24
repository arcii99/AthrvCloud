//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100   // Maximum number of data points
#define DIMENSIONS 2   // Number of dimensions of each data point
#define CLUSTERS 3   // Number of clusters to form

// Function declarations
void initialize(double data[MAX][DIMENSIONS], int size, int clusters, double centroids[CLUSTERS][DIMENSIONS], int clusterAssignments[MAX]);
double euclideanDistance(double point1[DIMENSIONS], double point2[DIMENSIONS]);
void assignClusters(double data[MAX][DIMENSIONS], int size, double centroids[CLUSTERS][DIMENSIONS], int clusterAssignments[MAX]);
void updateCentroids(double data[MAX][DIMENSIONS], int size, double centroids[CLUSTERS][DIMENSIONS], int clusterAssignments[MAX]);
double calculateSumOfSquares(double data[MAX][DIMENSIONS], int size, double centroids[CLUSTERS][DIMENSIONS], int clusterAssignments[MAX]);

int main() {
    double data[MAX][DIMENSIONS] = {{3, 8}, {2, 6}, {5, 8}, {1, 7}, {2, 4}, {5, 2}, {6, 6}, {7, 4}, {3, 5}, {4, 5}};   // Sample data points
    double centroids[CLUSTERS][DIMENSIONS];   // Array to store cluster centroids
    int clusterAssignments[MAX];   // Array to store cluster assignments for each data point
    int size = 10;   // Number of data points
    int i, j;
    double sumOfSquares = 0;   // Variable to store the sum of squares of distances to centroids

    // Initialize data points and cluster assignments
    initialize(data, size, CLUSTERS, centroids, clusterAssignments);

    // Run clustering algorithm for 10 iterations
    for (i = 0; i < 10; i++) {
        // Assign data points to clusters based on centroid distances
        assignClusters(data, size, centroids, clusterAssignments);

        // Update centroids based on assigned data points
        updateCentroids(data, size, centroids, clusterAssignments);

        // Calculate the sum of squares of distances to centroids
        sumOfSquares = calculateSumOfSquares(data, size, centroids, clusterAssignments);
        printf("Iteration %d: Sum of Squares = %f\n", i+1, sumOfSquares);
    }

    // Print final cluster assignments
    printf("\nFinal Cluster Assignments:\n");
    for (i = 0; i < size; i++) {
        printf("Data Point %d: Cluster %d\n", i+1, clusterAssignments[i]+1);
    }

    return 0;
}

/*
    Function to initialize data points and cluster assignments
    randomly and assign initial cluster centroids.
*/
void initialize(double data[MAX][DIMENSIONS], int size, int clusters, double centroids[CLUSTERS][DIMENSIONS], int clusterAssignments[MAX]) {
    int i, j, k;
    int randIndex;

    // Assign random initial cluster assignments
    for (i = 0; i < size; i++) {
        clusterAssignments[i] = rand() % clusters;
    }

    // Assign initial cluster centroids as random data points
    for (i = 0; i < clusters; i++) {
        randIndex = rand() % size;
        for (j = 0; j < DIMENSIONS; j++) {
            centroids[i][j] = data[randIndex][j];
        }
    }

}

/*
    Function to calculate Euclidean distance between two points.
*/
double euclideanDistance(double point1[DIMENSIONS], double point2[DIMENSIONS]) {
    double distance = 0;
    int i;

    for (i = 0; i < DIMENSIONS; i++) {
        distance += pow(point1[i] - point2[i], 2.0);
    }

    return sqrt(distance);
}

/*
    Function to assign data points to clusters based on centroid distances.
*/
void assignClusters(double data[MAX][DIMENSIONS], int size, double centroids[CLUSTERS][DIMENSIONS], int clusterAssignments[MAX]) {
    int i, j;
    double minDistance = 0, distance = 0;

    for (i = 0; i < size; i++) {
        minDistance = euclideanDistance(data[i], centroids[0]);
        clusterAssignments[i] = 0;
        for (j = 1; j < CLUSTERS; j++) {
            distance = euclideanDistance(data[i], centroids[j]);
            if (distance < minDistance) {
                minDistance = distance;
                clusterAssignments[i] = j;
            }
        }
    }

}

/*
    Function to update the cluster centroids based on assigned data points.
*/
void updateCentroids(double data[MAX][DIMENSIONS], int size, double centroids[CLUSTERS][DIMENSIONS], int clusterAssignments[MAX]) {
    int i, j, k;
    int numAssigned = 0;
    double sum[DIMENSIONS] = {};

    // Reset centroids to zero
    for (i = 0; i < CLUSTERS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            centroids[i][j] = 0;
        }
    }

    // Calculate sums of assigned data points
    for (i = 0; i < size; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            sum[j] += data[i][j];
        }
        numAssigned++;
        centroids[clusterAssignments[i]][j] += data[i][j];
    }

    // Calculate new centroids
    for (i = 0; i < CLUSTERS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            if (numAssigned > 0) {
                centroids[i][j] /= numAssigned;
            }
        }
    }
}

/*
    Function to calculate the sum of squares of distances to centroids.
*/
double calculateSumOfSquares(double data[MAX][DIMENSIONS], int size, double centroids[CLUSTERS][DIMENSIONS], int clusterAssignments[MAX]) {
    int i, j;
    double distance = 0;
    double sum = 0;

    for (i = 0; i < size; i++) {
        distance = euclideanDistance(data[i], centroids[clusterAssignments[i]]);
        sum += pow(distance, 2.0);
    }

    return sum;
}