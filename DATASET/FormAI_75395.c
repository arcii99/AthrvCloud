//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 20
#define THRESHOLD 5.0

// Define a structure to hold the coordinates of a point
typedef struct Point {
    float x;
    float y;
} Point;

// Define a structure to hold the information for each cluster
typedef struct Cluster {
    Point center;
    int num_points;
    Point *points;
} Cluster;

// Define a function to calculate the Euclidean distance between two points
float distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    // Define an array of points
    Point points[NUM_POINTS] = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0},
                                {7.0, 8.0}, {9.0, 10.0}, {11.0, 12.0},
                                {13.0, 14.0}, {15.0, 16.0}, {17.0, 18.0},
                                {19.0, 20.0}, {21.0, 22.0}, {23.0, 24.0},
                                {25.0, 26.0}, {27.0, 28.0}, {29.0, 30.0},
                                {31.0, 32.0}, {33.0, 34.0}, {35.0, 36.0},
                                {37.0, 38.0}, {39.0, 40.0}};
    
    // Initialize the clusters
    Cluster clusters[3];
    clusters[0].center.x = 5.0;
    clusters[0].center.y = 6.0;
    clusters[1].center.x = 21.0;
    clusters[1].center.y = 22.0;
    clusters[2].center.x = 37.0;
    clusters[2].center.y = 38.0;
    
    // Loop until convergence
    int converged = 0;
    while (!converged) {
        // Assign each point to the nearest cluster
        for (int i = 0; i < NUM_POINTS; i++) {
            float min_distance = distance(points[i], clusters[0].center);
            int min_index = 0;
            for (int j = 1; j < 3; j++) {
                float d = distance(points[i], clusters[j].center);
                if (d < min_distance) {
                    min_distance = d;
                    min_index = j;
                }
            }
            // Add the point to the cluster
            clusters[min_index].points = realloc(clusters[min_index].points, 
                                                  (clusters[min_index].num_points + 1) * sizeof(Point));
            clusters[min_index].points[clusters[min_index].num_points] = points[i];
            clusters[min_index].num_points++;
        }
        
        // Recalculate the center of each cluster
        converged = 1;
        for (int i = 0; i < 3; i++) {
            float sum_x = 0.0;
            float sum_y = 0.0;
            for (int j = 0; j < clusters[i].num_points; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            Point new_center;
            new_center.x = sum_x / clusters[i].num_points;
            new_center.y = sum_y / clusters[i].num_points;
            // Check if the center has moved significantly
            if (distance(new_center, clusters[i].center) > THRESHOLD) {
                clusters[i].center = new_center;
                converged = 0;
            }
        }
        
        // Print the current state of the clusters
        printf("Cluster 1: (%f, %f)\n", clusters[0].center.x, clusters[0].center.y);
        for (int i = 0; i < clusters[0].num_points; i++) {
            printf("(%f, %f) ", clusters[0].points[i].x, clusters[0].points[i].y);
        }
        printf("\n");
        printf("Cluster 2: (%f, %f)\n", clusters[1].center.x, clusters[1].center.y);
        for (int i = 0; i < clusters[1].num_points; i++) {
            printf("(%f, %f) ", clusters[1].points[i].x, clusters[1].points[i].y);
        }
        printf("\n");
        printf("Cluster 3: (%f, %f)\n", clusters[2].center.x, clusters[2].center.y);
        for (int i = 0; i < clusters[2].num_points; i++) {
            printf("(%f, %f) ", clusters[2].points[i].x, clusters[2].points[i].y);
        }
        printf("\n");
    }
    
    // Free the memory of the points in each cluster
    for (int i = 0; i < 3; i++) {
        free(clusters[i].points);
    }
    
    return 0;
}