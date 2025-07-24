//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of clusters
#define K 3

// Define the maximum number of iterations
#define MAX_ITER 100

// Define the tolerance for convergence
#define TOL 0.00001

// Define the distance function
float distance(int n, float x[], float y[]) {
    float dist = 0;
    for (int i = 0; i < n; i++) {
        dist += pow(x[i]-y[i], 2);
    }
    return sqrt(dist);
}

// Define the main function
int main() {

    // Define the data set
    float data[10][2] = {{1, 1}, {1, 2}, {2, 2}, {9, 10}, {10, 10}, {10, 9}, {12, 10}, {12, 9}, {13, 9}, {13, 8}};

    // Define the centroids
    float centroids[K][2];

    // Initialize the centroids to random positions
    for (int i = 0; i < K; i++) {
        centroids[i][0] = (float)rand()/(float)(RAND_MAX/13);
        centroids[i][1] = (float)rand()/(float)(RAND_MAX/10);
    }

    // Initialize the cluster assignments to zero
    int assignment[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Define the iteration counter and convergence flag
    int iter = 0;
    int converged = 0;

    // Loop until convergence or maximum number of iterations is reached
    while (!converged && iter < MAX_ITER) {

        // Assign each point to the nearest cluster
        for (int i = 0; i < 10; i++) {
            float min_dist = distance(2, data[i], centroids[0]);
            int min_index = 0;
            for (int j = 1; j < K; j++) {
                float dist = distance(2, data[i], centroids[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_index = j;
                }
            }
            assignment[i] = min_index;
        }

        // Update the centroids
        float new_centroids[K][2] = {0};
        int counter[K] = {0};
        for (int i = 0; i < 10; i++) {
            int index = assignment[i];
            new_centroids[index][0] += data[i][0];
            new_centroids[index][1] += data[i][1];
            counter[index]++;
        }
        for (int i = 0; i < K; i++) {
            if (counter[i] > 0) {
                new_centroids[i][0] /= counter[i];
                new_centroids[i][1] /= counter[i];
            }
        }

        // Check for convergence
        float diff = 0;
        for (int i = 0; i < K; i++) {
            diff += distance(2, centroids[i], new_centroids[i]);
        }
        if (diff < TOL) {
            converged = 1;
        }

        // Update the centroids for the next iteration
        for (int i = 0; i < K; i++) {
            centroids[i][0] = new_centroids[i][0];
            centroids[i][1] = new_centroids[i][1];
        }

        iter++;
    }

    // Print the final cluster assignments
    printf("Final cluster assignments:\n");
    for (int i = 0; i < 10; i++) {
        printf("Data point %d belongs to cluster %d\n", i, assignment[i]);
    }

    return 0;
}