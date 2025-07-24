//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PARANOID_FACTOR 1000

int main() {
    int num_points;
    printf("Enter the number of data points: ");
    scanf("%d", &num_points);

    double **data_points = malloc(num_points * sizeof(double*));
    for (int i = 0; i < num_points; i++) {
        data_points[i] = malloc(2 * sizeof(double));
        printf("Enter x coordinate of data point %d: ", i + 1);
        scanf("%lf", &data_points[i][0]);
        printf("Enter y coordinate of data point %d: ", i + 1);
        scanf("%lf", &data_points[i][1]);
    }

    int num_clusters;
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    double **centroids = malloc(num_clusters * sizeof(double*));
    double **old_centroids = malloc(num_clusters * sizeof(double*));
    int *cluster_sizes = calloc(num_clusters, sizeof(int));

    // Initialize centroids
    for (int i = 0; i < num_clusters; i++) {
        centroids[i] = data_points[i];
        old_centroids[i] = malloc(2 * sizeof(double));
        old_centroids[i][0] = old_centroids[i][1] = 0;
    }

    int iteration = 0;
    int paranoid_count = 0;

    while (paranoid_count < num_clusters * PARANOID_FACTOR) {
        paranoid_count++;
        iteration++;

        // Update cluster assignments
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int closest_cluster;

            for (int j = 0; j < num_clusters; j++) {
                double distance = sqrt(pow(data_points[i][0] - centroids[j][0], 2) + pow(data_points[i][1] - centroids[j][1], 2));
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = j;
                }
            }

            cluster_sizes[closest_cluster]++;
        }

        // Check for empty clusters
        for (int i = 0; i < num_clusters; i++) {
            if (cluster_sizes[i] == 0) {
                // Randomly reassign empty centroid
                int random_index = rand() % num_points;
                centroids[i] = data_points[random_index];
            }
        }

        // Update centroids
        for (int i = 0; i < num_clusters; i++) {
            double x_sum = 0, y_sum = 0;

            for (int j = 0; j < num_points; j++) {
                if (cluster_sizes[i] > 0 && centroids[i] == data_points[j]) {
                    x_sum += data_points[j][0];
                    y_sum += data_points[j][1];
                }
            }

            old_centroids[i][0] = centroids[i][0];
            old_centroids[i][1] = centroids[i][1];

            centroids[i][0] = x_sum / cluster_sizes[i];
            centroids[i][1] = y_sum / cluster_sizes[i];
        }

        // Check for convergence
        int converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            double distance = sqrt(pow(centroids[i][0] - old_centroids[i][0], 2) + pow(centroids[i][1] - old_centroids[i][1], 2));
            if (distance > 0.0001) {
                converged = 0;
                break;
            }
        }

        if (converged) {
            break;
        }

        // Reset cluster sizes
        for (int i = 0; i < num_clusters; i++) {
            cluster_sizes[i] = 0;
        }
    }

    printf("Converged after %d iterations.\n", iteration);

    for (int i = 0; i < num_points; i++) {
        free(data_points[i]);
    }
    free(data_points);

    for (int i = 0; i < num_clusters; i++) {
        free(old_centroids[i]);
    }
    free(old_centroids);

    free(cluster_sizes);

    return 0;
}