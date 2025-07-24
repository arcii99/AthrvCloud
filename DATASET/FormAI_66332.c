//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUM_CENTERS 5    // maximum number of centers
#define MAX_ITERATIONS 2000  // maximum number of iterations
#define MIN_DISTANCE  0.001  // minimum allowable distance between centers and points

// Define the point struct
typedef struct Point {
    double x;
    double y;
} Point;

// Define the cluster struct
typedef struct Cluster {
    Point center;
    Point points[50];
    int num_points;
} Cluster;

// Define the function to compute the distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Define the function to update the center of a cluster based on its points
void update_center(Cluster* cluster) {
    double sum_x = 0, sum_y = 0;
    for(int i = 0; i < cluster->num_points; i++) {
        sum_x += cluster->points[i].x;
        sum_y += cluster->points[i].y;
    }
    cluster->center.x = sum_x / cluster->num_points;
    cluster->center.y = sum_y / cluster->num_points;
}

// Define the k-means clustering function
void k_means_clustering(Point* points, int num_points, Cluster* clusters, int num_clusters) {
    // Initialize random seeds
    srand(time(NULL));
    
    // Randomly assign each point to a cluster
    for(int i = 0; i < num_points; i++) {
        int cluster_index = rand() % num_clusters;
        clusters[cluster_index].points[clusters[cluster_index].num_points] = points[i];
        clusters[cluster_index].num_points++;
    }
    
    // Compute the initial cluster centers
    for(int i = 0; i < num_clusters; i++) {
        update_center(&clusters[i]);
    } 
    
    // Iteratively update the cluster centers until convergence or max iterations reached
    for(int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        int num_changed_centers = 0;
        for(int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int cluster_index = -1;
            for(int j = 0; j < num_clusters; j++) {
                double d = distance(points[i], clusters[j].center);
                if(d < min_distance) {
                    min_distance = d;
                    cluster_index = j;
                }
            }
            if(min_distance > MIN_DISTANCE) {
                clusters[cluster_index].points[clusters[cluster_index].num_points] = points[i];
                clusters[cluster_index].num_points++;
                num_changed_centers++;
            }
        }
        for(int i = 0; i < num_clusters; i++) {
            update_center(&clusters[i]);
        }
        if(num_changed_centers == 0) {
            break;
        }
    }
}

int main() {
    // Define some sample points
    Point points[] = {
        {1, 2},
        {2, 1},
        {3, 7},
        {5, 6},
        {6, 5},
        {7, 7}
    };
    int num_points = sizeof(points) / sizeof(Point);
    
    // Create some initial centers
    Point centers[] = {
        {1, 1},
        {2, 5},
        {7, 2}
    };
    int num_clusters = sizeof(centers) / sizeof(Point);
    
    // Create an array to hold the clusters
    Cluster clusters[MAX_NUM_CENTERS];
    for(int i = 0; i < MAX_NUM_CENTERS; i++) {
        clusters[i].num_points = 0;
    }
    
    // Perform the clustering
    k_means_clustering(points, num_points, clusters, num_clusters);
    
    // Print the results
    for(int i = 0; i < num_clusters; i++) {
        printf("Cluster %d center: (%g, %g)\n", i+1, clusters[i].center.x, clusters[i].center.y);
        printf("Points in cluster %d:\n", i+1);
        for(int j = 0; j < clusters[i].num_points; j++) {
            printf("(%g, %g)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
    
    return 0;
}