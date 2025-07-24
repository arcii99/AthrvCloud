//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
/**
 * Clustering Algorithm Implementation
 * By: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100 // Number of points to cluster
#define NUM_CLUSTERS 3 // Number of clusters to generate
#define MAX_ITERATIONS 100 // Maximum number of iterations before stopping

// Struct to hold point coordinates
typedef struct {
    float x;
    float y;
} Point;

// Struct to hold cluster information
typedef struct {
    Point center;
    int num_points;
} Cluster;

// Function to generate random point coordinates
Point generate_point() {
    Point p;
    p.x = (float)rand();
    p.y = (float)rand();
    return p;
}

// Function to calculate distance between two points
float calculate_distance(Point p1, Point p2) {
    float distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    return distance;
}

// Function to initialize clusters with random centers
void initialize_clusters(Cluster clusters[]) {
    for(int i=0; i<NUM_CLUSTERS; i++) {
        clusters[i].center = generate_point();
        clusters[i].num_points = 0;
    }
}

// Function to assign points to clusters
void assign_points(Point points[], Cluster clusters[]) {
    for(int i=0; i<NUM_POINTS; i++) {
        float min_distance = INFINITY;
        int closest_cluster = 0;
        for(int j=0; j<NUM_CLUSTERS; j++) {
            float distance = calculate_distance(points[i], clusters[j].center);
            if(distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].num_points++;
    }
}

// Function to recalculate cluster centers
void calculate_centers(Point points[], Cluster clusters[]) {
    for(int i=0; i<NUM_CLUSTERS; i++) {
        float total_x = 0;
        float total_y = 0;
        for(int j=0; j<NUM_POINTS; j++) {
            if(clusters[i].num_points > 0) {
                if(i == 0) {
                    // First time through, clear previous points
                    clusters[i].center.x = 0;
                    clusters[i].center.y = 0;
                }
                if(j == 0) {
                    // First point in cluster
                    clusters[i].center.x = points[j].x;
                    clusters[i].center.y = points[j].y;
                } else {
                    // Recalculate average center based on all points
                    clusters[i].center.x = (total_x + points[j].x) / clusters[i].num_points;
                    clusters[i].center.y = (total_y + points[j].y) / clusters[i].num_points;
                }
            }
        }
    }
}

// Main function
int main() {
    Point points[NUM_POINTS];
    Cluster clusters[NUM_CLUSTERS];
    
    // Generate random points
    for(int i=0; i<NUM_POINTS; i++) {
        points[i] = generate_point();
    }
    
    // Initialize clusters
    initialize_clusters(clusters);
    
    // Run algorithm for MAX_ITERATIONS or until clusters are stable
    int iteration = 0;
    while(iteration < MAX_ITERATIONS) {
        int num_point_changes = 0;
        
        // Assign points to clusters
        assign_points(points, clusters);
        
        // Recalculate cluster centers
        calculate_centers(points, clusters);
        
        // Check for changes in point assignments to clusters
        for(int i=0; i<NUM_CLUSTERS; i++) {
            num_point_changes += clusters[i].num_points; 
            clusters[i].num_points = 0;
        }
        
        // If no changes in point assignments, exit early
        if(num_point_changes == NUM_POINTS) {
            printf("Clusters have stabilized after %d iterations\n", iteration);
            break;
        }
        
        iteration++;
    }
    
    // Print final results
    for(int i=0; i<NUM_CLUSTERS; i++) {
        printf("Cluster %d center at (%f,%f) with %d points assigned\n", i+1, clusters[i].center.x, clusters[i].center.y, clusters[i].num_points);
    }
    
    return 0;
}