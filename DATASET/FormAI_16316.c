//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: automated
/* This program implements a unique version of the clustering algorithm in C. 
   Given a set of points, the algorithm groups together all points that are within a certain radius of each other. 
   The algorithm then calculates the center of each group as its new "centroid".
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_DISTANCE 5.0

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Cluster {
    Point centroid;
    int size;
    Point points[MAX_POINTS];
} Cluster;

void add_point_to_cluster(Cluster *cluster, Point point) {
    cluster->points[cluster->size++] = point;
}

Point calculate_centroid(Cluster cluster) {
    Point centroid = {0, 0};
    for (int i = 0; i < cluster.size; i++) {
        centroid.x += cluster.points[i].x;
        centroid.y += cluster.points[i].y;
    }
    centroid.x /= cluster.size;
    centroid.y /= cluster.size;
    return centroid;
}

int main() {
    Point points[] = {{1.0, 2.5}, {2.0, 3.0}, {3.5, 4.0}, {5.0, 4.5}, {6.0, 6.0}, {6.5, 7.0}, {7.0, 8.5}, {8.0, 9.0}};
    int num_points = 8;
    Cluster clusters[num_points]; // Initialize each point as its own cluster
    for (int i = 0; i < num_points; i++) {
        clusters[i].centroid = points[i];
        clusters[i].size = 1;
        add_point_to_cluster(&clusters[i], points[i]);
    }

    // Merge clusters until no more clusters can be merged
    int num_clusters = num_points;
    while (num_clusters > 1) {
        // Find two closest centroids
        int closest_cluster_i = 0;
        int closest_cluster_j = 1;
        double closest_distance = INFINITY;
        for (int i = 0; i < num_clusters; i++) {
            for (int j = i+1; j < num_clusters; j++) {
                double distance = sqrt(pow(clusters[i].centroid.x - clusters[j].centroid.x, 2) + 
                                       pow(clusters[i].centroid.y - clusters[j].centroid.y, 2));
                if (distance < closest_distance) {
                    closest_distance = distance;
                    closest_cluster_i = i;
                    closest_cluster_j = j;
                }
            }
        }

        // Merge clusters i and j
        for (int k = 0; k < clusters[closest_cluster_j].size; k++) {
            add_point_to_cluster(&clusters[closest_cluster_i], clusters[closest_cluster_j].points[k]);
        }
        clusters[closest_cluster_i].centroid = calculate_centroid(clusters[closest_cluster_i]);
        clusters[closest_cluster_j].size = 0; // delete cluster j
        num_clusters--;
    }

    // Print final clusters
    printf("Clustered Points:\n");
    for (int i = 0; i < num_points; i++) {
        if (clusters[i].size > 0) {
            printf("Cluster %d:\n", i);
            printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
            printf("Points:\n");
            for (int j = 0; j < clusters[i].size; j++) {
                printf("\t(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
            }
        }
    }
    return 0;
}