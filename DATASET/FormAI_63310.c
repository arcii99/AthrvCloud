//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x, y;
} Point;

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Dynamically allocate memory for array of points
    Point* points = malloc(sizeof(Point) * n);

    printf("Enter %d points as x, y coordinates:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    int k;
    printf("Enter the number of clusters (k): ");
    scanf("%d", &k);

    // Dynamically allocate memory for array of k centroids
    Point* centroids = malloc(sizeof(Point) * k);

    // Initialize all centroids to first k points
    for (int i = 0; i < k; i++) {
        centroids[i] = points[i];
    }

    int num_iterations = 0;

    while (1) {
        num_iterations++;

        // Create an array to hold the cluster assignments for each point
        int *cluster_assignments = calloc(n, sizeof(int));

        // Iterate through each point
        for (int i = 0; i < n; i++) {
            double min_distance = INFINITY;

            // Find the nearest centroid
            for (int j = 0; j < k; j++) {
                double d = distance(points[i], centroids[j]);
                if (d < min_distance) {
                    min_distance = d;
                    cluster_assignments[i] = j;
                }
            }
        }

        // Create an array to hold the sum of x and y coordinates for each cluster
        Point* cluster_sums = calloc(k, sizeof(Point));
        int* cluster_sizes = calloc(k, sizeof(int));

        // Iterate through each point and add its coordinates to the corresponding cluster sum
        for (int i = 0; i < n; i++) {
            int cluster_assignment = cluster_assignments[i];
            cluster_sums[cluster_assignment].x += points[i].x;
            cluster_sums[cluster_assignment].y += points[i].y;
            cluster_sizes[cluster_assignment]++;
        }

        // Update centroid positions as averages of their corresponding cluster sums
        int convergence = 1;
        for (int i = 0; i < k; i++) {
            if (cluster_sizes[i] == 0) {
                // If a cluster has no points, reset its centroid to a random point
                centroids[i] = points[rand() % n];
            } else {
                double x_average = cluster_sums[i].x / cluster_sizes[i];
                double y_average = cluster_sums[i].y / cluster_sizes[i];
                if (x_average != centroids[i].x || y_average != centroids[i].y) {
                    convergence = 0;
                }
                centroids[i].x = x_average;
                centroids[i].y = y_average;
            }
        }

        // Free memory
        free(cluster_assignments);
        free(cluster_sums);
        free(cluster_sizes);

        // If all centroids have converged, we are done
        if (convergence) {
            printf("Converged after %d iterations.\n", num_iterations);
            break;
        }
    }

    // Print final cluster assignments
    printf("Final cluster assignments:\n");
    for (int i = 0; i < n; i++) {
        printf("Point (%.1f, %.1f) assigned to cluster %d\n", points[i].x, points[i].y);
    }

    // Free memory
    free(points);
    free(centroids);

    return 0;
}