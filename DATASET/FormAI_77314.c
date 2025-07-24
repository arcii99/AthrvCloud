//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* Define the structure for holding a point (x, y) */
typedef struct point {
    double x;
    double y;
} Point;

/* Define the cluster structure */
typedef struct cluster {
    int id;
    Point centroid;
    int num_points;
    Point *points;
} Cluster;

/* Function to calculate the Euclidean distance between two points */
double distance(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

/* Function to initialize the clusters */
void initialize_clusters(Cluster *clusters, int num_clusters, Point *points, int num_points) {
    int i, j;
    for(i = 0; i < num_clusters; i++) {
        clusters[i].id = i + 1;
        clusters[i].centroid = points[rand() % num_points];
        clusters[i].num_points = 0;
        clusters[i].points = (Point *) malloc(num_points * sizeof(Point));
    }
}

/* Function to assign points to the nearest cluster */
void assign_points(Cluster *clusters, int num_clusters, Point *points, int num_points) {
    int i, j, k;
    double min_distance, current_distance;
    Cluster *current_cluster;
    for(i = 0; i < num_points; i++) {
        min_distance = INFINITY;
        for(j = 0; j < num_clusters; j++) {
            current_distance = distance(clusters[j].centroid, points[i]);
            if(current_distance < min_distance) {
                min_distance = current_distance;
                current_cluster = &clusters[j];
            }
        }
        current_cluster->points[current_cluster->num_points] = points[i];
        current_cluster->num_points++;
    }
}

/* Function to re-calculate the centroid of the cluster */
void recompute_centroid(Cluster *cluster) {
    int i;
    double sum_x = 0, sum_y = 0;
    for(i = 0; i < cluster->num_points; i++) {
        sum_x += cluster->points[i].x;
        sum_y += cluster->points[i].y;
    }
    cluster->centroid.x = sum_x / cluster->num_points;
    cluster->centroid.y = sum_y / cluster->num_points;
}

/* Function to check if two points are equal */
bool points_equal(Point p1, Point p2) {
    if(p1.x == p2.x && p1.y == p2.y)
        return true;
    return false;
}

/* Function to check if the two sets of clusters are equal */
bool clusters_equal(Cluster *c1, Cluster *c2, int num_clusters) {
    int i, j;
    for(i = 0; i < num_clusters; i++) {
        if(!points_equal(c1[i].centroid, c2[i].centroid) || c1[i].num_points != c2[i].num_points) {
            return false;
        }
        for(j = 0; j < c1[i].num_points; j++) {
            if(!points_equal(c1[i].points[j], c2[i].points[j])) {
                return false;
            }
        }
    }
    return true;
}

/* Main function for k-means clustering */
int main() {
    int num_clusters = 3;  // number of clusters
    int num_points = 10;  // number of points to cluster
    Point points[] = {
        {1, 1},
        {2, 2},
        {2, 3},
        {3, 3},
        {5, 5},
        {5, 6},
        {6, 5},
        {7, 7},
        {8, 8},
        {9, 9}
    };
    Cluster old_clusters[num_clusters], new_clusters[num_clusters];
    int i, j, k = 0;
    initialize_clusters(old_clusters, num_clusters, points, num_points);
    while(k < 10) {  // Repeat 10 times
        assign_points(old_clusters, num_clusters, points, num_points);
        for(i = 0; i < num_clusters; i++) {
            recompute_centroid(&old_clusters[i]);
        }
        if(clusters_equal(old_clusters, new_clusters, num_clusters)) {
            break;
        }
        for(i = 0; i < num_clusters; i++) {
            new_clusters[i] = old_clusters[i];
        }
        k++;
    }
    return 0;
}