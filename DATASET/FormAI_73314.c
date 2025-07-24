//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 1000
#define CLUSTER_SIZE 5
#define DISTANCE_THRESHOLD 10

typedef struct data_point {
    int x;
    int y;
} DataPoint;

typedef struct cluster {
    DataPoint centroid;
    DataPoint *points;
    int num_points;
} Cluster;

int distance(DataPoint point1, DataPoint point2) {
    int dx = point1.x - point2.x;
    int dy = point1.y - point2.y;
    return ((dx * dx) + (dy * dy));
}

DataPoint generate_point() {
    DataPoint point;
    point.x = rand() % 100;
    point.y = rand() % 100;
    return point;
}

Cluster* create_clusters() {
    Cluster *clusters = malloc(sizeof(Cluster) * CLUSTER_SIZE);
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        clusters[i].num_points = 0;
        clusters[i].points = malloc(sizeof(DataPoint) * DATA_SIZE);
        clusters[i].centroid = generate_point();
    }
    return clusters;
}

void add_point_to_cluster(DataPoint point, Cluster *cluster) {
    cluster->points[cluster->num_points++] = point;
}

void clear_cluster_points(Cluster *cluster) {
    cluster->num_points = 0;
}

void assign_points_to_clusters(DataPoint *data, Cluster *clusters) {
    for (int i = 0; i < DATA_SIZE; i++) {
        int min_distance = -1;
        int closest_cluster = -1;
        for (int j = 0; j < CLUSTER_SIZE; j++) {
            int current_distance = distance(data[i], clusters[j].centroid);
            if (min_distance == -1 || current_distance < min_distance) {
                min_distance = current_distance;
                closest_cluster = j;
            }
        }
        add_point_to_cluster(data[i], &clusters[closest_cluster]);
    }
}

DataPoint calculate_centroid(Cluster *cluster) {
    int total_x = 0;
    int total_y = 0;
    for (int i = 0; i < cluster->num_points; i++) {
        total_x += cluster->points[i].x;
        total_y += cluster->points[i].y;
    }
    DataPoint centroid;
    centroid.x = total_x / cluster->num_points;
    centroid.y = total_y / cluster->num_points;
    return centroid;
}

void update_cluster_centroids(Cluster *clusters) {
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        clusters[i].centroid = calculate_centroid(&clusters[i]);
        clear_cluster_points(&clusters[i]);
    }
}

void print_clusters(Cluster *clusters) {
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        printf("Cluster %d centroid: (%d, %d)\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points in Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%d, %d) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

void run_clustering_algorithm(DataPoint *data) {
    Cluster *clusters = create_clusters();
    for (int i = 0; i < 10; i++) {
        assign_points_to_clusters(data, clusters);
        update_cluster_centroids(clusters);
    }
    print_clusters(clusters);
}

int main() {
    srand(time(0));
    DataPoint data[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = generate_point();
    }
    run_clustering_algorithm(data);
    return 0;
}