//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data structure to hold a point in 2D space
typedef struct Point {
    double x;
    double y;
} Point;

// Data structure to hold a cluster of points
typedef struct Cluster {
    Point *points;
    int num_points;
    Point centroid;
} Cluster;

// Calculate the distance between two points in 2D space
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Initialize a cluster with the given centroid
Cluster *init_cluster(Point centroid) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->points = NULL;
    cluster->num_points = 0;
    cluster->centroid = centroid;
    return cluster;
}

// Add a point to a cluster
void add_point(Cluster *cluster, Point point) {
    cluster->points = realloc(cluster->points, sizeof(Point) * (cluster->num_points + 1));
    cluster->points[cluster->num_points] = point;
    cluster->num_points++;
}

// Update the centroid of a cluster
void update_centroid(Cluster *cluster) {
    double x_sum = 0, y_sum = 0;
    for (int i = 0; i < cluster->num_points; i++) {
        x_sum += cluster->points[i].x;
        y_sum += cluster->points[i].y;
    }
    cluster->centroid.x = x_sum / cluster->num_points;
    cluster->centroid.y = y_sum / cluster->num_points;
}

// Cluster the given array of points into k clusters using the k-means algorithm
Cluster **k_means(Point *points, int num_points, int k) {
    Cluster **clusters = malloc(sizeof(Cluster*) * k);

    // Select k random points as the initial centroids
    for (int i = 0; i < k; i++) {
        Point centroid = points[rand() % num_points];
        clusters[i] = init_cluster(centroid);
    }

    int iterations = 0;
    while (1) {
        iterations++;

        // Assign each point to the nearest cluster
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int min_cluster_index = 0;
            for (int j = 0; j < k; j++) {
                double d = distance(points[i], clusters[j]->centroid);
                if (d < min_distance) {
                    min_distance = d;
                    min_cluster_index = j;
                }
            }
            add_point(clusters[min_cluster_index], points[i]);
        }

        // Update the centroids of each cluster to be the mean of the points assigned to it
        int num_changed = 0;
        for (int i = 0; i < k; i++) {
            Point old_centroid = clusters[i]->centroid;
            update_centroid(clusters[i]);
            if (old_centroid.x != clusters[i]->centroid.x || old_centroid.y != clusters[i]->centroid.y) {
                num_changed++;
            }
        }

        // If no points have changed cluster or the maximum number of iterations has been reached, break
        if (num_changed == 0 || iterations >= 100) {
            break;
        }

        // Clear the points from each cluster
        for (int i = 0; i < k; i++) {
            clusters[i]->num_points = 0;
            free(clusters[i]->points);
            clusters[i]->points = NULL;
        }
    }

    return clusters;
}

// Test the algorithm with some sample points
int main() {
    Point points[] = {{1, 1}, {1, 2}, {2, 1}, {2, 2}, {10, 10}, {10, 11}, {11, 10}, {11, 11}};
    int num_points = sizeof(points) / sizeof(Point);
    int k = 2;

    printf("Input points:\n");
    for (int i = 0; i < num_points; i++) {
        printf("(%g, %g)\n", points[i].x, points[i].y);
    }

    printf("\nClustering with k = %d...\n", k);
    Cluster **clusters = k_means(points, num_points, k);

    for (int i = 0; i < k; i++) {
        printf("\nCluster %d:\n", i+1);
        printf("Centroid: (%g, %g)\n", clusters[i]->centroid.x, clusters[i]->centroid.y);
        printf("Points:\n");
        for (int j = 0; j < clusters[i]->num_points; j++) {
            printf("(%g, %g)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
        }
    }

    // Free memory allocated for clusters
    for (int i = 0; i < k; i++) {
        free(clusters[i]->points);
        free(clusters[i]);
    }
    free(clusters);

    return 0;
}