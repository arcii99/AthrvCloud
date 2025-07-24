//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_POINTS 1000 // Maximum number of points in the dataset
#define MAX_ITERATIONS 100 // Maximum number of iterations to run
#define THRESHOLD 0.001 // Threshold value for convergence

// Function to calculate euclidean distance between two points
double calculate_distance(double x1, double y1, double x2, double y2) {
    double distance = pow((x2 - x1), 2) + pow((y2 - y1), 2);
    return sqrt(distance);
}

int main() {
    int n, k; // n: number of points, k: number of clusters
    double x[MAX_POINTS], y[MAX_POINTS]; // Arrays to store the coordinates
    int cluster_assignment[MAX_POINTS]; // Array to store cluster assignment for each point
    double cluster_x[MAX_POINTS], cluster_y[MAX_POINTS]; // Arrays to store coordinates of each cluster
    int cluster_size[MAX_POINTS]; // Array to store number of points in each cluster
    double prev_x[MAX_POINTS], prev_y[MAX_POINTS]; // Arrays to store previous coordinates of each cluster
    bool is_converged = false; // Flag to check for convergence
    int iterations = 0; // Variable to keep track of number of iterations

    printf("Enter the number of points in the dataset: ");
    scanf("%d", &n);

    // Read the coordinates of each point from the user
    for (int i = 0; i < n; i++) {
        printf("Enter the coordinates of point %d : ", i+1);
        scanf("%lf %lf", &x[i], &y[i]);
        cluster_assignment[i] = -1; // Set initial cluster assignment to -1
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    // Randomly initialize the coordinates of each cluster
    for (int i = 0; i < k; i++) {
        cluster_x[i] = (double) rand() / RAND_MAX * (double) (x[n-1] - x[0]) + (double) x[0];
        cluster_y[i] = (double) rand() / RAND_MAX * (double) (y[n-1] - y[0]) + (double) y[0];
        cluster_size[i] = 0;
    }

    while (!is_converged && iterations < MAX_ITERATIONS) {
        // Assign each point to the nearest cluster
        for (int i = 0; i < n; i++) {
            double min_distance = INFINITY;
            int assigned_cluster = -1;
            for (int j = 0; j < k; j++) {
                double distance = calculate_distance(x[i], y[i], cluster_x[j], cluster_y[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    assigned_cluster = j;
                }
            }
            cluster_assignment[i] = assigned_cluster;
        }

        // Update the coordinates of each cluster
        for (int i = 0; i < k; i++) {
            prev_x[i] = cluster_x[i]; // Store the previous coordinates before updating
            prev_y[i] = cluster_y[i];
            cluster_x[i] = 0.0;
            cluster_y[i] = 0.0;
            cluster_size[i] = 0;
            for (int j = 0; j < n; j++) {
                if (cluster_assignment[j] == i) {
                    cluster_x[i] += x[j];
                    cluster_y[i] += y[j];
                    cluster_size[i]++;
                }
            }
            if (cluster_size[i] > 0) {
                cluster_x[i] /= (double) cluster_size[i];
                cluster_y[i] /= (double) cluster_size[i];
            }
        }

        // Check for convergence
        is_converged = true;
        for (int i = 0; i < k; i++) {
            double distance = calculate_distance(prev_x[i], prev_y[i], cluster_x[i], cluster_y[i]);
            if (distance > THRESHOLD) {
                is_converged = false;
                break;
            }
        }

        iterations++; // Increment the number of iterations
    }

    // Print the final cluster assignment and coordinates of each cluster
    printf("\nFinal cluster assignment:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d belongs to cluster %d\n", i+1, cluster_assignment[i]+1);
    }

    printf("\nFinal coordinates of each cluster:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: (%.2lf, %.2lf)\n", i+1, cluster_x[i], cluster_y[i]);
    }

    return 0;
}