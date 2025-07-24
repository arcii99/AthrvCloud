//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structure for our points
typedef struct Point {
    int x;
    int y;
} Point;

// Define a function to calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

// Define the main function
int main() {
    // Generate some random points
    Point points[10];
    for (int i = 0; i < 10; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    // Define our clusters
    Point cluster1;
    Point cluster2;

    // Let's randomly assign the first two points as our initial clusters
    cluster1.x = points[0].x;
    cluster1.y = points[0].y;
    cluster2.x = points[1].x;
    cluster2.y = points[1].y;

    // Keep track of which points belong to which clusters
    int belongs_to_cluster1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int belongs_to_cluster2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Continue to iterate until the clusters don't change anymore
    while (1) {
        // Calculate the distance between each point and the two clusters
        for (int i = 0; i < 10; i++) {
            double distance_to_cluster1 = distance(points[i], cluster1);
            double distance_to_cluster2 = distance(points[i], cluster2);

            // Assign each point to the cluster with the smallest distance
            if (distance_to_cluster1 < distance_to_cluster2) {
                belongs_to_cluster1[i] = 1;
                belongs_to_cluster2[i] = 0;
            } else {
                belongs_to_cluster1[i] = 0;
                belongs_to_cluster2[i] = 1;
            }
        }

        // Calculate the new centroids of the clusters
        int cluster1_sum_x = 0;
        int cluster1_sum_y = 0;
        int cluster1_num_points = 0;
        int cluster2_sum_x = 0;
        int cluster2_sum_y = 0;
        int cluster2_num_points = 0;

        for (int i = 0; i < 10; i++) {
            if (belongs_to_cluster1[i] == 1) {
                cluster1_sum_x += points[i].x;
                cluster1_sum_y += points[i].y;
                cluster1_num_points++;
            } else {
                cluster2_sum_x += points[i].x;
                cluster2_sum_y += points[i].y;
                cluster2_num_points++;
            }
        }

        Point new_cluster1;
        Point new_cluster2;

        new_cluster1.x = cluster1_sum_x / cluster1_num_points;
        new_cluster1.y = cluster1_sum_y / cluster1_num_points;
        new_cluster2.x = cluster2_sum_x / cluster2_num_points;
        new_cluster2.y = cluster2_sum_y / cluster2_num_points;

        // Check if the clusters have changed, and if not, exit the loop
        if (new_cluster1.x == cluster1.x && new_cluster1.y == cluster1.y &&
            new_cluster2.x == cluster2.x && new_cluster2.y == cluster2.y) {
                break;
        } else {
            cluster1 = new_cluster1;
            cluster2 = new_cluster2;
        }
    }

    // Print out the final cluster assignments
    printf("Cluster 1:\n");
    for (int i = 0; i < 10; i++) {
        if (belongs_to_cluster1[i] == 1) {
            printf("(%d, %d)\n", points[i].x, points[i].y);
        }
    }

    printf("Cluster 2:\n");
    for (int i = 0; i < 10; i++) {
        if (belongs_to_cluster2[i] == 1) {
            printf("(%d, %d)\n", points[i].x, points[i].y);
        }
    }

    return 0;
}