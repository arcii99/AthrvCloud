//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTERS 10
#define MAX_POINTS 100

typedef struct point_t {
    double x, y;
    int cluster;
} point_t;

typedef struct cluster_t {
    double x, y;
    int count;
} cluster_t;

int main()
{
    int i, j, k;
    int n_points = 0, n_clusters = 0;
    point_t *points = NULL;
    cluster_t *clusters = NULL;

    // Read in the number of points and clusters
    printf("Enter the number of points: ");
    scanf("%d", &n_points);
    printf("Enter the number of clusters (maximum %d): ", MAX_CLUSTERS);
    scanf("%d", &n_clusters);

    // Verify the input
    if (n_points <= 0 || n_clusters <= 0 || n_clusters > MAX_CLUSTERS) {
        printf("Invalid input.\n");
        return 1;
    }

    // Allocate memory for the points and clusters
    points = (point_t*) malloc(n_points * sizeof(point_t));
    clusters = (cluster_t*) malloc(n_clusters * sizeof(cluster_t));

    // Initialize the points
    for (i = 0; i < n_points; i++) {
        printf("Enter x and y for point %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
        points[i].cluster = -1; // No cluster assigned yet
    }

    // Initialize the clusters to random points
    for (i = 0; i < n_clusters; i++) {
        clusters[i].x = points[rand() % n_points].x;
        clusters[i].y = points[rand() % n_points].y;
        clusters[i].count = 0;
    }

    // Run the clustering algorithm
    for (i = 0; i < n_points; i++) {
        double min_distance = INFINITY;
        int min_cluster = -1;

        // Find the closest cluster
        for (j = 0; j < n_clusters; j++) {
            double distance = sqrt(pow(points[i].x - clusters[j].x, 2) +
                                   pow(points[i].y - clusters[j].y, 2));
            if (distance < min_distance) {
                min_distance = distance;
                min_cluster = j;
            }
        }

        // Update the cluster assignment for this point
        points[i].cluster = min_cluster;
        clusters[min_cluster].count++;
        clusters[min_cluster].x += points[i].x;
        clusters[min_cluster].y += points[i].y;
    }

    // Update the cluster positions
    for (i = 0; i < n_clusters; i++) {
        if (clusters[i].count > 0) {
            clusters[i].x /= clusters[i].count;
            clusters[i].y /= clusters[i].count;
        }
    }

    // Print the results
    for (i = 0; i < n_clusters; i++) {
        printf("Cluster %d (%d points): (%.2lf, %.2lf)\n",
               i + 1, clusters[i].count, clusters[i].x, clusters[i].y);
        printf("Points: ");
        for (j = 0; j < n_points; j++) {
            if (points[j].cluster == i) {
                printf("(%lf, %lf) ", points[j].x, points[j].y);
            }
        }
        printf("\n");
    }

    // Free the memory
    free(points);
    free(clusters);

    return 0;
}