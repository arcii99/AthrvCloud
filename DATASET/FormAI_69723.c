//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_DISTANCE 0.001 // minimum distance between two points
#define MAX_ITERATIONS 100 // maximum number of iterations

// Count the number of points
int countPoints(double dataset[][2]) {
    int count = 0;
    while(dataset[count][0] && dataset[count][1]) {
        count++;
    }
    return count;
}

// Calculate the Euclidean distance between two points
double euclideanDistance(double x1, double y1, double x2, double y2) {
    double x_diff = x2 - x1;
    double y_diff = y2 - y1;
    return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

int main() {
    // Define the dataset
    double dataset[][2] = {{1,4}, {1.5,5}, {3,1}, {4,2}, {3.5,2.5}, {3.5,4}, {3.5,6}, {5,7}, {5,5}, {6,6}, {6,3}, {6.5,3.5}, {7,4.5}, {7,7}};

    // Cluster the dataset
    int num_points = countPoints(dataset);
    int num_clusters = 3;
    double centroids[num_clusters][2];
    double old_centroids[num_clusters][2];
    int clusters[num_points];

    // Initialize the centroids
    centroids[0][0] = 1; centroids[0][1] = 4;
    centroids[1][0] = 3.5; centroids[1][1] = 6;
    centroids[2][0] = 7; centroids[2][1] = 5;

    // Loop until convergence or maximum iterations are reached
    int i, j, k;
    for(i = 0; i < MAX_ITERATIONS; i++) {
        // Save the old centroids
        for(j = 0; j < num_clusters; j++) {
            old_centroids[j][0] = centroids[j][0];
            old_centroids[j][1] = centroids[j][1];
        }

        // Assign each point to the nearest centroid
        for(j = 0; j < num_points; j++) {
            double min_distance = INFINITY;
            for(k = 0; k < num_clusters; k++) {
                double dist = euclideanDistance(dataset[j][0], dataset[j][1], centroids[k][0], centroids[k][1]);
                if(dist < min_distance) {
                    min_distance = dist;
                    clusters[j] = k;
                }
            }
        }

        // Update the centroids
        for(j = 0; j < num_clusters; j++) {
            int num_assigned_points = 0;
            double sum_x = 0;
            double sum_y = 0;

            for(k = 0; k < num_points; k++) {
                if(clusters[k] == j) {
                    sum_x += dataset[k][0];
                    sum_y += dataset[k][1];
                    num_assigned_points++;
                }
            }

            if(num_assigned_points == 0) {
                centroids[j][0] = old_centroids[j][0];
                centroids[j][1] = old_centroids[j][1];
            } else {
                centroids[j][0] = sum_x / num_assigned_points;
                centroids[j][1] = sum_y / num_assigned_points;
            }
        }

        // Check if the centroids have moved more than the minimum distance
        int centroids_moved = 0;
        for(j = 0; j < num_clusters; j++) {
            double dist = euclideanDistance(old_centroids[j][0], old_centroids[j][1], centroids[j][0], centroids[j][1]);
            if(dist > MIN_DISTANCE) {
                centroids_moved = 1;
                break;
            }
        }

        // If the centroids have not moved, break out of the loop
        if(!centroids_moved) {
            break;
        }
    }

    // Print the final clusters
    printf("Final Clusters:\n");
    for(i = 0; i < num_clusters; i++) {
        printf("Cluster %d: ", i+1);
        for(j = 0; j < num_points; j++) {
            if(clusters[j] == i)
                printf("%d, ", j+1);
        }
        printf("\n");
    }

    return 0;
}