//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_CLUSTERS 10
#define THRESHOLD 0.01

typedef struct {
    double x, y;
} point_t;

typedef struct {
    point_t centroid;
    point_t points[MAX_POINTS];
    int num_points;
} cluster_t;

int main() {
    int num_points, num_clusters, i, j, k, num_iterations;
    double threshold, distance, min_distance;
    point_t points[MAX_POINTS];
    cluster_t clusters[MAX_CLUSTERS];
    srand(time(NULL));
    
    // Input from user
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);
    printf("Enter the threshold: ");
    scanf("%lf", &threshold);
    
    // Creating the initial clusters
    for (i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = (double) rand() / RAND_MAX;
        clusters[i].centroid.y = (double) rand() / RAND_MAX;
        clusters[i].num_points = 0;
    }
    
    // Inputting the points
    for (i = 0; i < num_points; i++) {
        printf("Enter point %d: ", i+1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    
    // Clustering routine
    for (num_iterations = 0; num_iterations < 100; num_iterations++) {
        // Assign points to clusters
        for (i = 0; i < num_points; i++) {
            min_distance = INFINITY;
            for (j = 0; j < num_clusters; j++) {
                distance = sqrt(pow(points[i].x - clusters[j].centroid.x, 2) + pow(points[i].y - clusters[j].centroid.y, 2));
                if (distance < min_distance) {
                    min_distance = distance;
                    k = j;
                }
            }
            clusters[k].points[clusters[k].num_points++] = points[i];
        }
        
        // Update centroids
        for (i = 0; i < num_clusters; i++) {
            double sum_x = 0, sum_y = 0;
            for (j = 0; j < clusters[i].num_points; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = sum_x / clusters[i].num_points;
            clusters[i].centroid.y = sum_y / clusters[i].num_points;
        }
        
        // Check if threshold has been reached
        int flag = 1;
        for (i = 0; i < num_clusters; i++) {
            for (j = 0; j < clusters[i].num_points; j++) {
                distance = sqrt(pow(clusters[i].centroid.x - clusters[i].points[j].x, 2) + pow(clusters[i].centroid.y - clusters[i].points[j].y, 2));
                if (distance > threshold) {
                    flag = 0;
                    break;
                } 
            }
            if (flag == 0) {
                break;
            }
        }
        if (flag == 1) {
            break;
        }
        
        // Empty the clusters
        for (i = 0; i < num_clusters; i++) {
            clusters[i].num_points = 0;
        }
    }
    
    // Output the results
    printf("\nFinal clusters:\n\n");
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Centroid: (%lf, %lf)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points: ");
        for (j = 0; j < clusters[i].num_points; j++) {
            printf("(%lf, %lf) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n\n");
    }
    
    return 0;
}