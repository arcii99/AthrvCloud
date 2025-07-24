//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POINTS_NUM 5
#define CLUSTERS_NUM 2

typedef struct {
    float x;
    float y;
} point_t;

typedef struct {
    point_t centroid;
    point_t* points;
    int num_points;
} cluster_t;

float euclidean_distance(point_t point1, point_t point2) {
    return sqrt(pow((point1.x - point2.x), 2.0) + pow((point1.y - point2.y), 2.0));
}

int assign_points_to_clusters(point_t* points, cluster_t* clusters, int points_num, int clusters_num) {
    int assigned = 0;
    float min_distance, distance;
    cluster_t* closest_cluster;
    
    for (int i = 0; i < points_num; i++) {
        min_distance = 100000.0;
        for (int j = 0; j < clusters_num; j++) {
            distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = &clusters[j];
            }
        }
        
        if (closest_cluster->num_points == 0) {
            closest_cluster->points = (point_t*) malloc(sizeof(point_t) * points_num);
        }
        closest_cluster->points[closest_cluster->num_points] = points[i];
        closest_cluster->num_points++;
        assigned++;
    }
    
    return assigned;
}

void calculate_centroids(cluster_t* clusters, int clusters_num) {
    float avg_x, avg_y;
    
    for (int i = 0; i < clusters_num; i++) {
        avg_x = 0.0;
        avg_y = 0.0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            avg_x += clusters[i].points[j].x;
            avg_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = avg_x / clusters[i].num_points;
        clusters[i].centroid.y = avg_y / clusters[i].num_points;
    }
}

int main() {
    point_t points[POINTS_NUM] = {{1.0, 1.0}, {2.0, 3.0}, {5.0, 4.0}, {10.0, 10.0}, {11.0, 12.0}};
    cluster_t clusters[CLUSTERS_NUM] = {{{2.0, 2.0}, NULL, 0}, {{8.0, 6.0}, NULL, 0}};
    int iterations = 0;
    int clusters_changed = 1;
    
    while (clusters_changed && iterations < 100) {
        clusters_changed = 0;
        assign_points_to_clusters(points, clusters, POINTS_NUM, CLUSTERS_NUM);
        for (int i = 0; i < CLUSTERS_NUM; i++) {
            calculate_centroids(&clusters[i], 1);
            if (clusters[i].num_points == 0) {
                clusters[i].centroid.x = rand() % 10;
                clusters[i].centroid.y = rand() % 10;
                clusters_changed = 1;
            }
            clusters[i].num_points = 0;
            free(clusters[i].points);
            clusters[i].points = NULL;
        }
        iterations++;
    }
    
    printf("Iterations: %d\n", iterations);
    for (int i = 0; i < CLUSTERS_NUM; i++) {
        printf("Cluster %d:\n", i+1);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("\tPoint %d, x: %f, y: %f\n", j+1, clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
    
    return 0;
}