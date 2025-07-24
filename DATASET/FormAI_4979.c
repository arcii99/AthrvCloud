//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 1000
#define MAX_CLUSTERS 10

typedef struct {
    float x;
    float y;
} point_t;

typedef struct {
    point_t center;
    int count;
    point_t *points[MAX_POINTS];
} cluster_t;

int main() {
    srand(time(NULL));
    
    int num_points = rand() % MAX_POINTS;
    int num_clusters = (rand() % MAX_CLUSTERS) + 1;
    point_t points[MAX_POINTS];
    cluster_t clusters[MAX_CLUSTERS];
    
    printf("Initializing %d points and %d clusters...\n", num_points, num_clusters);
    
    // Generate random points
    for (int i = 0; i < num_points; i++) {
        points[i].x = (float) rand() / RAND_MAX;
        points[i].y = (float) rand() / RAND_MAX;
    }
    
    // Initialize clusters with random points
    for (int i = 0; i < num_clusters; i++) {
        int index = rand() % num_points;
        clusters[i].center = points[index];
        clusters[i].count = 0;
    }
    
    // Assign points to clusters
    for (int i = 0; i < num_points; i++) {
        float min_distance = 1000000.0;
        int cluster_index = 0;
        
        for (int j = 0; j < num_clusters; j++) {
            float distance = sqrt(pow(points[i].x - clusters[j].center.x, 2) + pow(points[i].y - clusters[j].center.y, 2));
            
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        
        clusters[cluster_index].points[clusters[cluster_index].count] = &points[i];
        clusters[cluster_index].count++;
    }
    
    printf("Done.\n");
    
    return 0;
}