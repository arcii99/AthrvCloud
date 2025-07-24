//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define MAX_ITERATIONS 100

typedef struct {
    float x, y;
} point_t;

typedef struct {
    int num_points;
    point_t centroid;
    point_t points[MAX_POINTS];
} cluster_t;

int main() {
    int i, j, k; //loop variables
    int num_points, num_clusters, max_iterations; //input parameters
    point_t points[MAX_POINTS];
    cluster_t clusters[MAX_CLUSTERS];

    //get input parameters
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);
    printf("Enter the maximum iterations: ");
    scanf("%d", &max_iterations);

    //get input
    printf("Enter the points in format x y: ");
    for(i = 0; i < num_points; i++) {
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    //initialize clusters with random centroids
    for(i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = (float) rand() / RAND_MAX * 10;
        clusters[i].centroid.y = (float) rand() / RAND_MAX * 10;
    }

    //do k-means clustering
    for(i = 0; i < max_iterations; i++) {
        //assign points to closest cluster
        for(j = 0; j < num_points; j++) {
            float min_distance = INFINITY;
            int closest_cluster = 0;
            for(k = 0; k < num_clusters; k++) {
                float distance = sqrt(pow(points[j].x - clusters[k].centroid.x, 2) + pow(points[j].y - clusters[k].centroid.y, 2));
                if(distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = k;
                }
            }
            clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = points[j];
        }

        //update centroids of clusters
        for(j = 0; j < num_clusters; j++) {
            float sum_x = 0, sum_y = 0;
            for(k = 0; k < clusters[j].num_points; k++) {
                sum_x += clusters[j].points[k].x;
                sum_y += clusters[j].points[k].y;
            }
            clusters[j].centroid.x = sum_x / clusters[j].num_points;
            clusters[j].centroid.y = sum_y / clusters[j].num_points;
        }

        //check if clusters have converged
        int converged = 1;
        for(j = 0; j < num_clusters; j++) {
            if(clusters[j].num_points == 0) {
                converged = 0;
            }
        }
        if(converged) {
            break;
        }

        //reset points in clusters
        for(j = 0; j < num_clusters; j++) {
            clusters[j].num_points = 0;
        }
    }

    //print final clusters
    for(i = 0; i < num_clusters; i++) {
        printf("Cluster #%d\n", i+1);
        for(j = 0; j < clusters[i].num_points; j++) {
            printf("Point #%d: (%.2f, %.2f)\n", j+1, clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    return 0;
}