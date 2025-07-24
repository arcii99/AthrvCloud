//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    double x, y;
};

// Function to calculate the Euclidean distance between two points
double distance(struct point p1, struct point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt((dx*dx) + (dy*dy));
}

// Function to assign each point to its nearest cluster
int assign_clusters(struct point *points, int num_points, struct point *centroids, int num_clusters, int *point_cluster_mapping) {
    int changes = 0;
    for(int i=0; i<num_points; i++) {
        int closest_cluster = -1;
        double min_distance = 1e9;
        for(int j=0; j<num_clusters; j++) {
            double d = distance(points[i], centroids[j]);
            if(d < min_distance) {
                min_distance = d;
                closest_cluster = j;
            }
        }
        if(point_cluster_mapping[i] != closest_cluster) {
            point_cluster_mapping[i] = closest_cluster;
            changes++;
        }
    }
    return changes;
}

// Function to update the cluster centroids based on their assigned points
void update_centroids(struct point *points, int num_points, struct point *centroids, int num_clusters, int *point_cluster_mapping, int *cluster_sizes) {
    for(int i=0; i<num_clusters; i++) {
        centroids[i].x = 0;
        centroids[i].y = 0;
        cluster_sizes[i] = 0;
    }
    for(int i=0; i<num_points; i++) {
        int c = point_cluster_mapping[i];
        centroids[c].x += points[i].x;
        centroids[c].y += points[i].y;
        cluster_sizes[c]++;
    }
    for(int i=0; i<num_clusters; i++) {
        if(cluster_sizes[i] > 0) {
            centroids[i].x /= cluster_sizes[i];
            centroids[i].y /= cluster_sizes[i];
        }
    }
}

// Function to print out the final cluster assignments and centroids
void print_clusters(struct point *points, int num_points, struct point *centroids, int num_clusters, int *point_cluster_mapping) {
    printf("Final cluster assignments:\n");
    for(int i=0; i<num_points; i++) {
        printf("(%f, %f) -> Cluster %d\n", points[i].x, points[i].y, point_cluster_mapping[i]+1);
    }
    printf("\nFinal cluster centroids:\n");
    for(int i=0; i<num_clusters; i++) {
        printf("Cluster %d: (%f, %f)\n", i+1, centroids[i].x, centroids[i].y);
    }
}

int main() {
    int num_points = 10;
    struct point points[10] = {{0,0},{0,4},{0,8},{7,7},{8,8},{9,9},{10,10},{11,11},{1,1},{2,2}};
    int num_clusters = 3;
    struct point centroids[3] = {{2,2},{8,8},{1,1}};
    int point_cluster_mapping[10] = {0,0,0,0,0,0,0,0,0,0};
    int cluster_sizes[3] = {0,0,0};
    
    int num_iterations = 0;
    int max_iterations = 20;
    int num_changes = 0;
    do {
        printf("Iteration %d:\n", num_iterations+1);
        num_changes = assign_clusters(points, num_points, centroids, num_clusters, point_cluster_mapping);
        update_centroids(points, num_points, centroids, num_clusters, point_cluster_mapping, cluster_sizes);
        print_clusters(points, num_points, centroids, num_clusters, point_cluster_mapping);
        num_iterations++;
    } while(num_changes > 0 && num_iterations < max_iterations);
    
    return 0;
}