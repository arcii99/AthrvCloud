//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 10
#define CLUSTER_SIZE 3

typedef struct point {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int find_closest_centroid(Point point, Point centroids[], int num_centroids) {
    int closest_cluster = 0;
    double smallest_distance = distance(point, centroids[0]);
    for(int i = 1; i < num_centroids; i++) {
        double d = distance(point, centroids[i]);
        if(d < smallest_distance) {
            closest_cluster = i;
            smallest_distance = d;
        }
    }
    return closest_cluster;
}

void assign_clusters(Point points[], Point centroids[], int num_points, int num_centroids, int clusters[]) {
    for(int i = 0; i < num_points; i++) {
        clusters[i] = find_closest_centroid(points[i], centroids, num_centroids);
    }
}

void update_centroids(Point points[], int num_points, int clusters[], Point centroids[], int num_centroids) {
    int cluster_counts[num_centroids];
    for(int i = 0; i < num_centroids; i++) {
        centroids[i].x = 0;
        centroids[i].y = 0;
        cluster_counts[i] = 0;
    }
    for(int i = 0; i < num_points; i++) {
        int cluster = clusters[i];
        centroids[cluster].x += points[i].x;
        centroids[cluster].y += points[i].y;
        cluster_counts[cluster]++;
    }
    for(int i = 0; i < num_centroids; i++) {
        centroids[i].x /= cluster_counts[i];
        centroids[i].y /= cluster_counts[i];
    }
}

void print_clusters(Point points[], int num_points, int clusters[]) {
    printf("Clusters:\n");
    for(int i = 0; i < NUM_POINTS/CLUSTER_SIZE; i++) {
        printf("Cluster %d:\n", i);
        for(int j = 0; j < num_points; j++) {
            if(clusters[j] == i) {
                printf("(%f, %f)\n", points[j].x, points[j].y);
            }
        }
    }
}

int main() {
    Point points[NUM_POINTS];
    Point centroids[NUM_POINTS/CLUSTER_SIZE];
    int clusters[NUM_POINTS];

    // Initialize points with random values
    for(int i = 0; i < NUM_POINTS; i++) {
        points[i].x = ((double)rand()/(double)RAND_MAX)*10;
        points[i].y = ((double)rand()/(double)RAND_MAX)*10;
    }

    // Initialize centroid positions with random points
    for(int i = 0; i < NUM_POINTS/CLUSTER_SIZE; i++) {
        centroids[i] = points[i];
    }

    // Cluster points
    for(int i = 0; i < 10; i++) {
        assign_clusters(points, centroids, NUM_POINTS, NUM_POINTS/CLUSTER_SIZE, clusters);
        update_centroids(points, NUM_POINTS, clusters, centroids, NUM_POINTS/CLUSTER_SIZE);
    }

    // Print clusters
    print_clusters(points, NUM_POINTS, clusters);

    return 0;
}