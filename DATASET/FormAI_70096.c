//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is the Cluster struct, representing a cluster and its centroid
typedef struct Cluster {
    float x; // The x-coordinate of the centroid
    float y; // The y-coordinate of the centroid
    int size; // The number of points in the cluster
} Cluster;

// This function selects a random point as the starting cluster centroid
void set_random_centroid(float* x, float* y, int count) {
    srand(time(NULL)); // Seed the random number generator with the current time

    int random_index = rand() % count; // Generate a random index
    *x = rand() % 100; // Generate a random x-coordinate
    *y = rand() % 100; // Generate a random y-coordinate

    // Set the centroid to the coordinates of the randomly selected point
    for (int i = 0; i < random_index; i++) {
        x++;
        y++;
    }
}

// This function updates the centroids of each cluster
void update_centroids(float* x, float* y, Cluster* clusters, int cluster_count) {
    for (int i = 0; i < cluster_count; i++) {
        float total_x = 0.0;
        float total_y = 0.0;

        // Add up the x and y coordinates of all the points in the cluster
        for (int j = 0; j < clusters[i].size; j++) {
            total_x += *x;
            total_y += *y;
            x++;
            y++;
        }

        // Calculate the new x and y coordinates of the centroid
        clusters[i].x = total_x / clusters[i].size;
        clusters[i].y = total_y / clusters[i].size;
    }
}

// This function assigns each point to the nearest cluster
void assign_clusters(float* x, float* y, Cluster* clusters, int cluster_count, int point_count) {
    for (int i = 0; i < point_count; i++) {
        float min_distance = 100.0;
        int min_index = 0;

        // Calculate the distance between the point and each cluster's centroid
        for (int j = 0; j < cluster_count; j++) {
            float distance = sqrt(pow(*x - clusters[j].x, 2) + pow(*y - clusters[j].y, 2));

            // If the distance is less than the minimum distance, update the min_distance and min_index
            if (distance < min_distance) {
                min_distance = distance;
                min_index = j;
            }
        }

        // Add the point to the nearest cluster
        clusters[min_index].size++;
        x++;
        y++;
    }
}

int main() {
    // Generate some random points
    float points_x[100];
    float points_y[100];

    for (int i = 0; i < 100; i++) {
        points_x[i] = rand() % 100;
        points_y[i] = rand() % 100;
    }

    // Initialize the clusters
    Cluster clusters[3];

    for (int i = 0; i < 3; i++) {
        clusters[i].size = 0;
        set_random_centroid(&clusters[i].x, &clusters[i].y, 100);
    }

    // Perform the clustering algorithm
    for (int i = 0; i < 10; i++) {
        assign_clusters(points_x, points_y, clusters, 3, 100);
        update_centroids(points_x, points_y, clusters, 3);
    }

    // Print out the final clusters
    for (int i = 0; i < 3; i++) {
        printf("Cluster %d:\n", i);
        printf("Centroid: (%f, %f)\n", clusters[i].x, clusters[i].y);
        printf("Size: %d\n", clusters[i].size);
    }

    return 0;
}