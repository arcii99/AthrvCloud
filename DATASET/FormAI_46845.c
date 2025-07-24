//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to calculate distance between two points
double calc_distance(double x1, double y1, double x2, double y2) {
    double dx = (x2 - x1);
    double dy = (y2 - y1);
    return sqrt((dx*dx) + (dy*dy));
}

// Function to compare double values
bool double_equals(double a, double b) {
    double epsilon = 0.000001;
    return fabs(a - b) < epsilon;
}

// Structure for a point
struct point {
    double x, y;
};

// Structure for a cluster
struct cluster {
    struct point* center;
    int num_points;
    struct point* points[100];
};

int main() {
    // Initialize points
    struct point points[10] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}, {13, 14}, {15, 16}, {17, 18}, {19, 20}};
    
    // Initialize clusters
    struct cluster clusters[2];
    
    // Assign first two points as centers of clusters
    clusters[0].center = &points[0];
    clusters[1].center = &points[1];
    
    // Assign initial number of points for each cluster
    clusters[0].num_points = 1;
    clusters[1].num_points = 1;
    
    // Assign points to their nearest cluster
    for(int i=2; i<10; i++) {
        double distance1 = calc_distance(points[i].x, points[i].y, clusters[0].center->x, clusters[0].center->y);
        double distance2 = calc_distance(points[i].x, points[i].y, clusters[1].center->x, clusters[1].center->y);
        if(double_equals(distance1, distance2)) { // If distances are equal, add to cluster with less points
            if(clusters[0].num_points <= clusters[1].num_points) {
                clusters[0].points[clusters[0].num_points] = &points[i];
                clusters[0].num_points++;
            } else {
                clusters[1].points[clusters[1].num_points] = &points[i];
                clusters[1].num_points++;
            }
        } else if(distance1 < distance2) {
            clusters[0].points[clusters[0].num_points] = &points[i];
            clusters[0].num_points++;
        } else {
            clusters[1].points[clusters[1].num_points] = &points[i];
            clusters[1].num_points++;
        }
    }
    
    // Recalculate centers of clusters based on assigned points
    double sum_x, sum_y;
    for(int i=0; i<2; i++) {
        sum_x = 0; sum_y = 0;
        for(int j=0; j<clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j]->x;
            sum_y += clusters[i].points[j]->y;
        }
        clusters[i].center->x = sum_x / (double)clusters[i].num_points;
        clusters[i].center->y = sum_y / (double)clusters[i].num_points;
    }
    
    // Print results
    printf("Cluster 1: Center(%f, %f) Points[", clusters[0].center->x, clusters[0].center->y);
    for(int i=0; i<clusters[0].num_points; i++) {
        printf("(%f, %f), ", clusters[0].points[i]->x, clusters[0].points[i]->y);
    }
    printf("]\n");
    printf("Cluster 2: Center(%f, %f) Points[", clusters[1].center->x, clusters[1].center->y);
    for(int i=0; i<clusters[1].num_points; i++) {
        printf("(%f, %f), ", clusters[1].points[i]->x, clusters[1].points[i]->y);
    }
    printf("]\n");
    
    return 0;
}