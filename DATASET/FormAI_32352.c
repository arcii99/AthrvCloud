//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 20
#define MAX_CLUSTERS 3
#define DIMENSIONS 2
#define MIN_RANGE 0
#define MAX_RANGE 100

typedef struct Point {
    double x[DIMENSIONS];
    int cluster_id;
} Point;

typedef struct Cluster {
    double center[DIMENSIONS];
    int count;
    Point points[MAX_POINTS];
} Cluster;

// Calculates Euclidean distance between two points
double distance(Point *a, Point *b) {
    double sum = 0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += (a->x[i] - b->x[i]) * (a->x[i] - b->x[i]);
    }
    return sqrt(sum);
}

// Assigns initial random cluster centers
void assign_init_centers(Cluster *clusters) {
    for (int i = 0; i < MAX_CLUSTERS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].center[j] = ((double)rand() / (double)RAND_MAX) * (MAX_RANGE - MIN_RANGE) + MIN_RANGE;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    Point points[MAX_POINTS];
    
    // Generate random points
    for (int i = 0; i < MAX_POINTS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            points[i].x[j] = ((double)rand() / (double)RAND_MAX) * (MAX_RANGE - MIN_RANGE) + MIN_RANGE;
        }
    }
    
    Cluster clusters[MAX_CLUSTERS];
    assign_init_centers(clusters); // Assign initial random cluster centers
    int iterations = 0;
    
    // Iterate until convergence or max iterations
    while (iterations < 100) {
        for (int i = 0; i < MAX_POINTS; i++) {
            double min_dist = distance(&points[i], &clusters[0].points[0]);
            int min_cluster = 0;
            
            // Find the nearest cluster
            for (int j = 0; j < MAX_CLUSTERS; j++) {
                double dist = distance(&points[i], &clusters[j].points[0]);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_cluster = j;
                }
            }
            
            // Assign point to nearest cluster
            points[i].cluster_id = min_cluster;
            clusters[min_cluster].points[clusters[min_cluster].count++] = points[i];
        }
        
        // Calculate new cluster centers
        for (int i = 0; i < MAX_CLUSTERS; i++) {
            double sum_x[DIMENSIONS] = {0};
            for (int j = 0; j < clusters[i].count; j++) {
                for (int k = 0; k < DIMENSIONS; k++) {
                    sum_x[k] += clusters[i].points[j].x[k];
                }
            }
            for (int k = 0; k < DIMENSIONS; k++) {
                clusters[i].center[k] = sum_x[k] / clusters[i].count;
            }
            clusters[i].count = 0; // Reset cluster count
        }
        
        iterations++;
    }
    
    // Print resulting clusters
    for (int i = 0; i < MAX_CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].count; j++) {
            printf("(%.2f, %.2f) ", clusters[i].points[j].x[0], clusters[i].points[j].x[1]);
        }
        printf("\nCenter: (%.2f, %.2f)\n\n", clusters[i].center[0], clusters[i].center[1]);
    }
    
    return 0;
}