//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MIN_DIFFERENCE 0.0001

double Distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n, k, i, j, iteration;
    printf("Enter the number of points : ");
    scanf("%d", &n);

    double* x = (double*)malloc(n * sizeof(double));
    double* y = (double*)malloc(n * sizeof(double));

    printf("Enter the points (x,y) : \n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    printf("Enter the number of clusters : ");
    scanf("%d", &k);

    double* cluster_x = (double*)malloc(k * sizeof(double));
    double* cluster_y = (double*)malloc(k * sizeof(double));
    int* cluster_size = (int*)calloc(k, sizeof(int));
    int* points_cluster = (int*)malloc(n * sizeof(int));

    // Initialize the clusters randomly
    for (i = 0; i < k; i++) {
        int idx = rand() % n;
        cluster_x[i] = x[idx];
        cluster_y[i] = y[idx];
    }

    double difference = MIN_DIFFERENCE + 1.0;
    iteration = 0;
    while (iteration < MAX_ITERATIONS && difference > MIN_DIFFERENCE) {
        // Assign each point to the nearest cluster
        for (i = 0; i < n; i++) {
            double min_distance = Distance(x[i], y[i], cluster_x[0], cluster_y[0]);
            int min_cluster = 0;
            for (j = 1; j < k; j++) {
                double distance = Distance(x[i], y[i], cluster_x[j], cluster_y[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_cluster = j;
                }
            }
            points_cluster[i] = min_cluster;
        }

        // Move each cluster to the center of its points
        double new_cluster_x[k];
        double new_cluster_y[k];
        int new_cluster_size[k];
        for (i = 0; i < k; i++) {
            new_cluster_x[i] = 0;
            new_cluster_y[i] = 0;
            new_cluster_size[i] = 0;
        }
        for (i = 0; i < n; i++) {
            new_cluster_x[points_cluster[i]] += x[i];
            new_cluster_y[points_cluster[i]] += y[i];
            new_cluster_size[points_cluster[i]]++;
        }
        difference = 0;
        for (i = 0; i < k; i++) {
            if (new_cluster_size[i] > 0) {
                new_cluster_x[i] /= new_cluster_size[i];
                new_cluster_y[i] /= new_cluster_size[i];
                difference += Distance(cluster_x[i], cluster_y[i], new_cluster_x[i], new_cluster_y[i]);
                cluster_x[i] = new_cluster_x[i];
                cluster_y[i] = new_cluster_y[i];
                cluster_size[i] = new_cluster_size[i];
            }
        }
        iteration++;
    }

    // Print the results
    printf("Clusters:\n");
    for (i = 0; i < k; i++) {
        printf("Cluster %d (%.2lf,%.2lf) with %d points\n", i + 1, cluster_x[i], cluster_y[i], cluster_size[i]);
    }

    free(x);
    free(y);
    free(cluster_x);
    free(cluster_y);
    free(cluster_size);
    free(points_cluster);

    return 0;
}