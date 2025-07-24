//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_CLUSTERS 10
#define RADIUS 0.1

struct Point {
    double x, y;
    int cluster;
};

struct Cluster {
    double cx, cy;
    int count;
};

double dist(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void assign_points(struct Point points[MAX_POINTS], int num_points, struct Cluster clusters[MAX_CLUSTERS], int num_clusters) {
    double min_dist, current_dist;
    int closest_cluster;
    
    for (int i = 0; i < num_points; i++) {
        min_dist = INFINITY;
        closest_cluster = 0;
        
        for (int j = 0; j < num_clusters; j++) {
            current_dist = dist(points[i], (struct Point){clusters[j].cx, clusters[j].cy});
            if (current_dist < min_dist) {
                min_dist = current_dist;
                closest_cluster = j;
            }
        }
        
        points[i].cluster = closest_cluster;
        clusters[closest_cluster].count++;
        clusters[closest_cluster].cx += (points[i].x - clusters[closest_cluster].cx) / clusters[closest_cluster].count;
        clusters[closest_cluster].cy += (points[i].y - clusters[closest_cluster].cy) / clusters[closest_cluster].count;
    }
}

int update_clusters(struct Point points[MAX_POINTS], int num_points, struct Cluster clusters[MAX_CLUSTERS], int num_clusters) {
    double max_move = 0, current_move;
    
    for (int i = 0; i < num_clusters; i++) {
        current_move = dist((struct Point){clusters[i].cx, clusters[i].cy}, (struct Point){clusters[i].cx + RADIUS, clusters[i].cy});
        if (current_move > max_move)
            max_move = current_move;
            
        current_move = dist((struct Point){clusters[i].cx, clusters[i].cy}, (struct Point){clusters[i].cx, clusters[i].cy + RADIUS});
        if (current_move > max_move)
            max_move = current_move;
            
        clusters[i].count = 0;
        clusters[i].cx = 0;
        clusters[i].cy = 0;
    }
    
    assign_points(points, num_points, clusters, num_clusters);
    
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].cx += RADIUS * ((double)rand() / RAND_MAX - 0.5);
        clusters[i].cy += RADIUS * ((double)rand() / RAND_MAX - 0.5);
    }
    
    return max_move < RADIUS;
}

void print_clusters(struct Point points[MAX_POINTS], int num_points, struct Cluster clusters[MAX_CLUSTERS], int num_clusters) {
    printf("[");
    
    for (int i = 0; i < num_clusters; i++) {
        printf("{cx:%.2f, cy:%.2f, count:%d, points:[", clusters[i].cx, clusters[i].cy, clusters[i].count);
        
        for (int j = 0; j < num_points; j++) {
            if (points[j].cluster == i)
                printf("{x:%.2f, y:%.2f}, ", points[j].x, points[j].y);
        }
        
        printf("]}, ");
    }
    
    printf("]\n");
}

int main() {
    struct Point points[MAX_POINTS];
    struct Cluster clusters[MAX_CLUSTERS];
    int num_points, num_clusters, i;
    
    printf("Enter number of points: ");
    scanf("%d", &num_points);
    
    printf("Enter points (x,y):\n");
    for (i = 0; i < num_points; i++)
        scanf("%lf%lf", &points[i].x, &points[i].y);
    
    printf("Enter number of clusters: ");
    scanf("%d", &num_clusters);
    
    for (i = 0; i < num_clusters; i++) {
        clusters[i].cx = ((double)rand() / RAND_MAX) * 10;
        clusters[i].cy = ((double)rand() / RAND_MAX) * 10;
        clusters[i].count = 0;
    }
    
    while (!update_clusters(points, num_points, clusters, num_clusters)) {
        print_clusters(points, num_points, clusters, num_clusters);
    }
    
    return 0;
}