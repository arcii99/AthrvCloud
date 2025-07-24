//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Point {
    int x;
    int y;
    int cluster;
} Point;

int main() {
    srand(time(NULL));

    int num_points = 20;
    Point points[num_points];
    int num_clusters = 3;

    // Create random points
    for (int i = 0; i < num_points; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
        points[i].cluster = 0;
    }

    // Initialize random cluster centroids
    Point centroids[num_clusters];
    for (int i = 0; i < num_clusters; i++) {
        int random_point_index = rand() % num_points;
        centroids[i].x = points[random_point_index].x;
        centroids[i].y = points[random_point_index].y;
    }

    // Iteratively assign points to clusters and update centroids
    int num_iterations = 10;
    for (int i = 0; i < num_iterations; i++) {
        // Assign points to clusters
        for (int j = 0; j < num_points; j++) {
            int nearest_centroid_index = -1;
            int nearest_centroid_distance = 1000000;
            for (int k = 0; k < num_clusters; k++) {
                int distance = (points[j].x - centroids[k].x) * (points[j].x - centroids[k].x) 
                             + (points[j].y - centroids[k].y) * (points[j].y - centroids[k].y);
                if (distance < nearest_centroid_distance) {
                    nearest_centroid_index = k;
                    nearest_centroid_distance = distance;
                }
            }
            points[j].cluster = nearest_centroid_index;
        }

        // Update centroids
        for (int j = 0; j < num_clusters; j++) {
            int num_points_in_cluster = 0;
            int sum_x = 0;
            int sum_y = 0;
            for (int k = 0; k < num_points; k++) {
                if (points[k].cluster == j) {
                    num_points_in_cluster++;
                    sum_x += points[k].x;
                    sum_y += points[k].y;
                }
            }
            centroids[j].x = sum_x / num_points_in_cluster;
            centroids[j].y = sum_y / num_points_in_cluster;
        }
    }

    // Print out results
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: ", i);
        for (int j = 0; j < num_points; j++) {
            if (points[j].cluster == i)
                printf("(%d, %d) ", points[j].x, points[j].y);
        }
        printf("\n");
    }

    return 0;
}