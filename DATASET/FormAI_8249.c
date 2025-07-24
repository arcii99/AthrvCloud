//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100
#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 100

// Struct to store coordinates of a point
struct Point {
    double x;
    double y;
};

// Function to generate random points within a range
struct Point generate_random_point(double min, double max) {
    struct Point point;

    point.x = ((double) rand() / RAND_MAX) * (max - min) + min;
    point.y = ((double) rand() / RAND_MAX) * (max - min) + min;

    return point;
}

// Function to calculate distance between two points
double distance(struct Point point1, struct Point point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

int main() {
    // Generate some random points
    struct Point points[NUM_POINTS];
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i] = generate_random_point(0, 10);
    }

    // Initialize cluster centers randomly
    struct Point cluster_centers[NUM_CLUSTERS];
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        cluster_centers[i] = generate_random_point(0, 10);
    }

    // Run clustering algorithm for a maximum number of iterations
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        // Assign each point to its closest cluster center
        int point_cluster_assignment[NUM_POINTS];
        for (int i = 0; i < NUM_POINTS; i++) {
            double min_distance = INFINITY;
            for (int j = 0; j < NUM_CLUSTERS; j++) {
                double d = distance(points[i], cluster_centers[j]);
                if (d < min_distance) {
                    min_distance = d;
                    point_cluster_assignment[i] = j;
                }
            }
        }

        // Update cluster center positions to the average position of its assigned points
        struct Point new_cluster_centers[NUM_CLUSTERS];
        int num_points_assigned[NUM_CLUSTERS] = {0};
        for (int i = 0; i < NUM_POINTS; i++) {
            int j = point_cluster_assignment[i];
            new_cluster_centers[j].x += points[i].x;
            new_cluster_centers[j].y += points[i].y;
            num_points_assigned[j]++;
        }
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            if (num_points_assigned[j] > 0) {
                new_cluster_centers[j].x /= num_points_assigned[j];
                new_cluster_centers[j].y /= num_points_assigned[j];
            } else {
                new_cluster_centers[j] = generate_random_point(0, 10);
            }
        }

        // Check if cluster centers have moved significantly
        int centers_changed = 1;
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            if (distance(cluster_centers[j], new_cluster_centers[j]) > 0.01) {
                centers_changed = 0;
                break;
            }
        }
        if (centers_changed) {
            break;
        }

        // Update cluster centers
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            cluster_centers[j] = new_cluster_centers[j];
        }
    }

    // Print final cluster center positions
    printf("Final cluster center positions:\n");
    for (int j = 0; j < NUM_CLUSTERS; j++) {
        printf("Cluster %d: (%f, %f)\n", j, cluster_centers[j].x, cluster_centers[j].y);
    }

    return 0;
}