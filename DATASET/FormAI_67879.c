//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define THRESHOLD 0.001

typedef struct {
    double x;
    double y;
} point;

double euclidean_distance(point p1, point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

void print_clusters(int n, point* data, int* cluster_id) {
    for (int i = 0; i < n; i++) {
        printf("Point %d: (x=%f, y = %f)\n", i, data[i].x, data[i].y);
        printf("Cluster ID: %d\n", cluster_id[i]);
    }
}

void k_means_clustering(int k, int n, point* data, int* cluster_id, point* centroids) {
    int i, j, iter;
    double min_distance, distance;
    int closest_cluster;

    // Initialization: choose k random centroids from data points
    for (i = 0; i < k; i++) {
        centroids[i].x = data[i].x;
        centroids[i].y = data[i].y;
    }

    for (iter = 0; iter < MAX_ITERATIONS; iter++) {
        // Assign each data point to the closest centroid
        for (i = 0; i < n; i++) {
            min_distance = euclidean_distance(data[i], centroids[0]);
            closest_cluster = 0;

            for (j = 1; j < k; j++) {
                distance = euclidean_distance(data[i], centroids[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = j;
                }
            }

            cluster_id[i] = closest_cluster;
        }

        // Recalculate the centroid for each cluster
        for (i = 0; i < k; i++) {
            centroids[i].x = 0;
            centroids[i].y = 0;
            int count = 0;

            for (j = 0; j < n; j++) {
                if (cluster_id[j] == i) {
                    centroids[i].x += data[j].x;
                    centroids[i].y += data[j].y;
                    count++;
                }
            }

            if (count > 0) {
                centroids[i].x /= count;
                centroids[i].y /= count;
            }
        }

        // Calculate the sum of squared errors (SSE) to check for convergence
        double sse = 0;
        for (i = 0; i < n; i++) {
            sse += pow(euclidean_distance(data[i], centroids[cluster_id[i]]), 2);
        }

        // Check for convergence
        if (sse < THRESHOLD) {
            printf("Converged after %d iterations\n", iter+1);
            return;
        }
    }

    printf("Did not converge after %d iterations\n", MAX_ITERATIONS);
}

int main() {
    int k = 3; // number of clusters
    int n = 10; // number of data points
    point data[] = {{1,2}, {2,1}, {2,3}, {6,2}, {7,3}, {7,1}, {11,5}, {12,4}, {13,5}, {14,6}};
    int cluster_id[n];
    point centroids[k];

    k_means_clustering(k, n, data, cluster_id, centroids);

    printf("\nFinal clustering:\n");
    print_clusters(n, data, cluster_id);

    return 0;
}