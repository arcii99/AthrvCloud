//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_POINTS 200
#define NUM_CLUSTERS 4
#define MAX_ITERATIONS 100

/* Struct for a point in 2D space */
typedef struct {
    float x;
    float y;
} Point;

/* Struct for a cluster of points */
typedef struct {
    Point centroid;
    Point* points;
    int num_points;
} Cluster;

/* Function to calculate the Euclidean distance between two points */
float calculate_distance(Point p1, Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

/* Function to assign each point to its closest cluster */
void assign_points_to_clusters(Point* points, int num_points, Cluster* clusters, int num_clusters) {
    int i, j;
    for (i = 0; i < num_points; i++) {
        float closest_distance = calculate_distance(points[i], clusters[0].centroid);
        int closest_cluster = 0;
        for (j = 1; j < num_clusters; j++) {
            float distance = calculate_distance(points[i], clusters[j].centroid);
            if (distance < closest_distance) {
                closest_distance = distance;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = points[i];
    }
}

/* Function to calculate the centroid of a cluster */
Point calculate_centroid(Cluster cluster) {
    float sum_x = 0.0f;
    float sum_y = 0.0f;
    int i;
    for (i = 0; i < cluster.num_points; i++) {
        sum_x += cluster.points[i].x;
        sum_y += cluster.points[i].y;
    }
    Point centroid = { sum_x / cluster.num_points, sum_y / cluster.num_points };
    return centroid;
}

/* Function to update the centroids of each cluster */
void update_cluster_centroids(Cluster* clusters, int num_clusters) {
    int i;
    for (i = 0; i < num_clusters; i++) {
        clusters[i].centroid = calculate_centroid(clusters[i]);
        clusters[i].num_points = 0;
    }
}

/* Function to print the clusters */
void print_clusters(Cluster* clusters, int num_clusters) {
    int i, j;
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    srand(time(NULL));

    /* Generate random points */
    Point points[NUM_POINTS];
    int i;
    for (i = 0; i < NUM_POINTS; i++) {
        points[i].x = (float)(rand() % 100);
        points[i].y = (float)(rand() % 100);
    }

    /* Initialize clusters randomly */
    Cluster clusters[NUM_CLUSTERS];
    for (i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].centroid.x = (float)(rand() % 100);
        clusters[i].centroid.y = (float)(rand() % 100);
        clusters[i].points = (Point*) malloc(NUM_POINTS * sizeof(Point));
        clusters[i].num_points = 0;
    }

    /* Assign points to their closest cluster */
    assign_points_to_clusters(points, NUM_POINTS, clusters, NUM_CLUSTERS);

    /* Run the algorithm for a set number of iterations */
    int iteration;
    for (iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        /* Update the centroids of each cluster */
        update_cluster_centroids(clusters, NUM_CLUSTERS);
        /* Assign points to their closest cluster */
        assign_points_to_clusters(points, NUM_POINTS, clusters, NUM_CLUSTERS);
    }

    /* Print the final clusters */
    print_clusters(clusters, NUM_CLUSTERS);

    /* Free memory */
    for (i = 0; i < NUM_CLUSTERS; i++) {
        free(clusters[i].points);
    }

    return 0;
}