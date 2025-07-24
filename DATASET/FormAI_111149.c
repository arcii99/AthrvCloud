//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_CLUSTERS 10
#define MIN_DISTANCE 0.00001

typedef struct {
    double x, y;
    int cluster;
} point_t;

point_t points[MAX_POINTS];
int num_points = 0;
int num_clusters = 0;
point_t clusters[MAX_CLUSTERS];

double randf()
{
    return (double)rand() / RAND_MAX;
}

double distance(point_t a, point_t b)
{
    double x_diff = a.x - b.x;
    double y_diff = a.y - b.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

void kmeans()
{
    int i, j, k;
    double d;
    double min_distance;
    int cluster;
    int changed;
    
    // initialize clusters
    for (i = 0; i < num_clusters; i++) {
        clusters[i].x = randf() * 10;
        clusters[i].y = randf() * 10;
    }
    
    // perform iterations
    do {
        // reset clusters
        for (i = 0; i < num_clusters; i++) {
            clusters[i].x = 0;
            clusters[i].y = 0;
            clusters[i].cluster = -1;
        }
        
        changed = 0;
        
        // assign points to nearest cluster
        for (i = 0; i < num_points; i++) {
            min_distance = INFINITY;
            for (j = 0; j < num_clusters; j++) {
                d = distance(points[i], clusters[j]);
                if (d < min_distance) {
                    min_distance = d;
                    cluster = j;
                }
            }
            if (points[i].cluster != cluster) {
                changed = 1;
                points[i].cluster = cluster;
            }
            clusters[cluster].x += points[i].x;
            clusters[cluster].y += points[i].y;
            clusters[cluster].cluster = cluster;
        }
        
        // calculate new centroids
        for (i = 0; i < num_clusters; i++) {
            if (clusters[i].cluster != -1) {
                clusters[i].x /= num_points;
                clusters[i].y /= num_points;
            }
        }
        
    } while (changed);
}

int main()
{
    int i;
    
    // generate random points
    for (i = 0; i < MAX_POINTS; i++) {
        points[i].x = randf() * 10;
        points[i].y = randf() * 10;
        points[i].cluster = -1;
        num_points++;
    }
    
    // set number of clusters
    num_clusters = rand() % MAX_CLUSTERS + 1;
    
    // perform clustering
    kmeans();
    
    // print results
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d: (%.2f, %.2f)\n", i+1, clusters[i].x, clusters[i].y);
    }
    
    return 0;
}