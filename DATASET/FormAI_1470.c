//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define data structure for each point in dataset
typedef struct Point {
    double x;
    double y;
    int cluster;
} Point;

// function to calculate Euclidean distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2));
}

int main() {
    // initialize values for dataset
    int num_points = 50;
    Point data[num_points];
    srand(time(NULL));
    for (int i = 0; i < num_points; i++) {
        data[i].x = (double)rand()/RAND_MAX*10;
        data[i].y = (double)rand()/RAND_MAX*10;
        data[i].cluster = -1;
    }

    // initialize values for clusters
    int num_clusters = 3;
    Point centroids[num_clusters];
    for (int i = 0; i < num_clusters; i++) {
        centroids[i].x = (double)rand()/RAND_MAX*10;
        centroids[i].y = (double)rand()/RAND_MAX*10;
        centroids[i].cluster = i;
    }

    // run k-means clustering algorithm
    double threshold = 0.0001;
    double distance_change = 1;
    while (distance_change > threshold) {
        // assign points to closest cluster
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int closest_cluster;
            for (int j = 0; j < num_clusters; j++) {
                double d = distance(data[i], centroids[j]);
                if (d < min_distance) {
                    min_distance = d;
                    closest_cluster = j;
                }
            }
            data[i].cluster = closest_cluster;
        }

        // calculate new centroid for each cluster
        distance_change = 0;
        for (int j = 0; j < num_clusters; j++) {
            Point new_centroid;
            new_centroid.x = 0;
            new_centroid.y = 0;
            int num_points_in_cluster = 0;
            for (int i = 0; i < num_points; i++) {
                if (data[i].cluster == j) {
                    new_centroid.x += data[i].x;
                    new_centroid.y += data[i].y;
                    num_points_in_cluster++;
                }
            }
            new_centroid.x /= num_points_in_cluster;
            new_centroid.y /= num_points_in_cluster;
            double d = distance(new_centroid, centroids[j]);
            centroids[j] = new_centroid;
            distance_change += d;
        }
    }

    // print results
    for (int i = 0; i < num_points; i++) {
        printf("Point(%lf,%lf) belongs to Cluster %d\n", data[i].x, data[i].y, data[i].cluster);
    }

    return 0;
}