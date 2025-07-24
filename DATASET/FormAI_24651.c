//FormAI DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define NUM_CLUSTERS 3
#define DATA_SIZE 15

typedef struct {
    double x;
    double y;
} data_point;

typedef struct {
    data_point centroid;
    data_point *points;
    int num_points;
} cluster;

double euclidean_distance(data_point p1, data_point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void assign_points_to_clusters(data_point *data, cluster *clusters, int num_clusters) {
    int i, j;
    double min_distance, distance;
    int closest_cluster;
    
    for (i = 0; i < DATA_SIZE; i++) {
        min_distance = 999999;
        closest_cluster = -1;
        for (j = 0; j < num_clusters; j++) {
            distance = euclidean_distance(data[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = data[i];
    }
}

void update_centroids(cluster *clusters, int num_clusters) {
    int i, j, k;
    double x_sum, y_sum;
    
    for (i = 0; i < num_clusters; i++) {
        x_sum = 0;
        y_sum = 0;
        for (j = 0; j < clusters[i].num_points; j++) {
            x_sum += clusters[i].points[j].x;
            y_sum += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = x_sum / clusters[i].num_points;
        clusters[i].centroid.y = y_sum / clusters[i].num_points;
    }
}

void print_clusters(cluster *clusters, int num_clusters) {
    int i, j;
    printf("Clustering results:\n");
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        for (j = 0; j < clusters[i].num_points; j++) {
            printf("(%g, %g)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

int main() {
    data_point data[DATA_SIZE] = { {1, 2}, {2, 1}, {3, 3}, {6, 5}, {7, 7},
                                   {8, 6}, {9, 8}, {12, 12}, {13, 11}, {14, 12},
                                   {15, 10}, {17, 13}, {18, 14}, {19, 15}, {20, 20} };
    cluster clusters[NUM_CLUSTERS] = { { {2, 3}, NULL, 0 },
                                        { {8, 7}, NULL, 0 },
                                        { {15, 12}, NULL, 0 } };
    int i, j, k;
    int iterations = 0;
    
    for (i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].points = malloc(sizeof(data_point) * DATA_SIZE);
    }
    
    while (iterations < MAX_ITERATIONS) {
        for (i = 0; i < NUM_CLUSTERS; i++) {
            clusters[i].num_points = 0;
        }
        
        assign_points_to_clusters(data, clusters, NUM_CLUSTERS);
        update_centroids(clusters, NUM_CLUSTERS);
        
        iterations++;
    }
    
    print_clusters(clusters, NUM_CLUSTERS);
    
    for (i = 0; i < NUM_CLUSTERS; i++) {
        free(clusters[i].points);
    }
    
    return 0;
}