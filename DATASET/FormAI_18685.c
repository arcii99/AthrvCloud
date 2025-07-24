//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_ITER 1000
#define N_POINTS 100
#define N_CLUSTERS 3

// Struct to represent a point in 2-D space
typedef struct point {
    double x;
    double y;
} point;

// Struct to represent a cluster
typedef struct cluster {
    point center;
    point *points;
    int size;
} cluster;

// Function to calculate the distance between two points
double distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to randomly initialize the centers of the clusters
void initialize_centers(cluster *clusters, int n_clusters, point *points, int n_points) {
    // Choose the first center randomly
    clusters[0].center = points[rand() % n_points];
    
    int i = 1;
    while (i < n_clusters) {
        double max_distance = -1.0;
        point new_center;
        // Iterate over all points to find the one with the maximum distance to the existing centers
        for (int j = 0; j < n_points; j++) {
            bool found = false;
            for (int k = 0; k < i; k++) {
                if (points[j].x == clusters[k].center.x && points[j].y == clusters[k].center.y) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                double min_distance = INFINITY;
                for (int k = 0; k < i; k++) {
                    double dist = distance(points[j], clusters[k].center);
                    if (dist < min_distance) {
                        min_distance = dist;
                    }
                }
                if (min_distance > max_distance) {
                    max_distance = min_distance;
                    new_center = points[j];
                }
            }
        }
        // Add the new center to the array of clusters
        clusters[i].center = new_center;
        i++;
    }
}

// Function to assign each point to the nearest cluster
void assign_clusters(cluster *clusters, int n_clusters, point *points, int n_points) {
    for (int i = 0; i < n_points; i++) {
        double min_distance = INFINITY;
        int nearest_cluster = -1;
        for (int j = 0; j < n_clusters; j++) {
            double dist = distance(points[i], clusters[j].center);
            if (dist < min_distance) {
                min_distance = dist;
                nearest_cluster = j;
            }
        }
        // Add the point to the nearest cluster
        clusters[nearest_cluster].points[clusters[nearest_cluster].size] = points[i];
        clusters[nearest_cluster].size++;
    }
}

// Function to calculate the new centers of the clusters
void calculate_centers(cluster *clusters, int n_clusters) {
    for (int i = 0; i < n_clusters; i++) {
        double sum_x = 0.0;
        double sum_y = 0.0;
        for (int j = 0; j < clusters[i].size; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].center.x = sum_x / clusters[i].size;
        clusters[i].center.y = sum_y / clusters[i].size;
    }
}

// Main function
int main() {
    // Initialize the array of points with random values
    point points[N_POINTS];
    for (int i = 0; i < N_POINTS; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    
    // Initialize the array of clusters with random centers
    cluster clusters[N_CLUSTERS];
    initialize_centers(clusters, N_CLUSTERS, points, N_POINTS);
    
    // Assign each point to the nearest cluster
    assign_clusters(clusters, N_CLUSTERS, points, N_POINTS);
    
    // Iterate over the clusters to calculate their new centers
    for (int i = 0; i < N_CLUSTERS; i++) {
        calculate_centers(clusters, N_CLUSTERS);
    }
    
    // Print the results
    for (int i = 0; i < N_CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        printf("Center: (%lf, %lf)\n", clusters[i].center.x, clusters[i].center.y);
        printf("Points: ");
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%lf, %lf) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
    
    return 0;
}