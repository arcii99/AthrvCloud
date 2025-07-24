//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 10000
#define MIN_DISTANCE 0.001

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point centroid;
    int count;
} cluster;

double distance(point p1, point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

void kMeans(point dataset[], int num_points, int num_clusters) {
    cluster* clusters = (cluster*)malloc(num_clusters * sizeof(cluster));
    // Initialize the clusters with randomly selected points from the dataset
    for (int i = 0; i < num_clusters; i++) {
        int random_index = rand() % num_points;
        clusters[i].centroid = dataset[random_index];
        clusters[i].count = 0;
    }
    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        // Assign each point to the nearest cluster
        for (int i = 0; i < num_points; i++) {
            point p = dataset[i];
            int closest_cluster_index = 0;
            double closest_distance = distance(p, clusters[0].centroid);
            for (int j = 1; j < num_clusters; j++) {
                double d = distance(p, clusters[j].centroid);
                if (d < closest_distance) {
                    closest_cluster_index = j;
                    closest_distance = d;
                }
            }
            clusters[closest_cluster_index].count++;
        }
        // Recompute the centroids of each cluster
        int changes = 0;
        for (int i = 0; i < num_clusters; i++) {
            point old_centroid = clusters[i].centroid;
            double avg_x = 0, avg_y = 0;
            if (clusters[i].count > 0) {
                for (int j = 0; j < num_points; j++) {
                    if (dataset[j].x == clusters[i].centroid.x && dataset[j].y == clusters[i].centroid.y) {
                        continue;
                    }
                    if (distance(dataset[j], clusters[i].centroid) < MIN_DISTANCE) {
                        avg_x += dataset[j].x;
                        avg_y += dataset[j].y;
                        clusters[i].count++;
                    }
                }
                if (clusters[i].count > 0) {
                    clusters[i].centroid.x = avg_x / clusters[i].count;
                    clusters[i].centroid.y = avg_y / clusters[i].count;
                }
            }
            if (distance(old_centroid, clusters[i].centroid) > 0) {
                changes++;
            }
        }
        if (changes == 0) {
            break;
        }
        iteration++;
    }
    // Print the results
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Count: %d\n", clusters[i].count);
        printf("Points: ");
        for (int j = 0; j < num_points; j++) {
            if (dataset[j].x == clusters[i].centroid.x && dataset[j].y == clusters[i].centroid.y) {
                continue;
            }
            if (distance(dataset[j], clusters[i].centroid) < MIN_DISTANCE) {
                printf("(%f, %f) ", dataset[j].x, dataset[j].y);
            }
        }
        printf("\n");
    }
    free(clusters);
}

int main() {
    // Generate a dataset of random points
    point dataset[100];
    for (int i = 0; i < 100; i++) {
        dataset[i].x = (double)rand()/RAND_MAX*10;
        dataset[i].y = (double)rand()/RAND_MAX*10;
    }
    // Cluster the dataset into 4 clusters
    kMeans(dataset, 100, 4);
    return 0;
}