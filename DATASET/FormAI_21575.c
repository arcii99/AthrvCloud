//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000    // maximum number of iterations
#define NUM_CLUSTERS 2         // number of clusters to form

// Helper function to calculate Euclidean distance
double euclidean_distance(double *a, double *b, int n) {
    double distance = 0.0;

    for(int i = 0; i < n; i++) {
        distance += pow((a[i] - b[i]), 2);
    }

    return sqrt(distance);
}

int main() {
    int num_points, num_dimensions;
    printf("Enter the number of data points: ");
    scanf("%d", &num_points);
    printf("Enter the number of dimensions: ");
    scanf("%d", &num_dimensions);

    double** X = (double**) malloc(num_points * sizeof(double*));   // dataset
    for(int i = 0; i < num_points; i++) {
        X[i] = (double*) malloc(num_dimensions * sizeof(double));
        printf("Enter data for point %d: ", i+1);
        for(int j = 0; j < num_dimensions; j++) {
            scanf("%lf", &X[i][j]);
        }
    }

    double** centroids = (double**) malloc(NUM_CLUSTERS * sizeof(double*));  // centroids initialization
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        centroids[i] = (double*) malloc(num_dimensions * sizeof(double));
        for(int j = 0; j < num_dimensions; j++) {
            centroids[i][j] = X[i][j];
        }
    }

    // Cluster assignments for each data point
    int* assignments = (int*) malloc(num_points * sizeof(int));

    // Calculate initial distance for each point
    double* distances = (double*) malloc(num_points * sizeof(double));
    for(int i = 0; i < num_points; i++) {
        distances[i] = euclidean_distance(X[i], centroids[0], num_dimensions);
        assignments[i] = 0;
    }

    // Iteration
    int iteration = 0;
    while(iteration < MAX_ITERATIONS) {
        int has_changed = 0;

        for(int i = 0; i < num_points; i++) {
            for(int j = 0; j < NUM_CLUSTERS; j++) {
                double distance = euclidean_distance(X[i], centroids[j], num_dimensions);
                if(distance < distances[i]) {
                    distances[i] = distance;
                    assignments[i] = j;
                    has_changed = 1;
                }
            }
        }

        if(has_changed == 0) break;

        // Update centroids
        int* cluster_sizes = (int*) calloc(NUM_CLUSTERS, sizeof(int));    // keep count of points assigned to each cluster
        for(int i = 0; i < num_points; i++) {
            int cluster = assignments[i];
            cluster_sizes[cluster]++;
            for(int j = 0; j < num_dimensions; j++) {
                centroids[cluster][j] += (X[i][j] - centroids[cluster][j]) / cluster_sizes[cluster];
            }
        }
        free(cluster_sizes);

        iteration++;
    }

    // Print final clusters
    printf("\nFinal clusters:\n");
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d: ", i+1);
        for(int j = 0; j < num_points; j++) {
            if(assignments[j] == i) {
                printf("%d ", j+1);
            }
        }
        printf("\nCentroid: ");
        for(int j = 0; j < num_dimensions; j++) {
            printf("%lf ", centroids[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for(int i = 0; i < num_points; i++) {
        free(X[i]);
    }
    free(X);

    for(int i = 0; i < NUM_CLUSTERS; i++) {
        free(centroids[i]);
    }
    free(centroids);

    free(distances);
    free(assignments);

    return 0;
}