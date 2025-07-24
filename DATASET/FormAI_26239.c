//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 10
#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 100

struct Point {
    float x, y;
};

struct Cluster {
    float x, y;
    int num_points;
    struct Point points[NUM_POINTS];
};

float distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int get_nearest_cluster(struct Point p, struct Cluster clusters[], int num_clusters) {
    int nearest_cluster = 0;
    float min_distance = distance(p, clusters[0].points[0]);

    for (int i = 0; i < num_clusters; i++) {
        for (int j = 0; j < clusters[i].num_points; j++) {
            float d = distance(p, clusters[i].points[j]);
            if (d < min_distance) {
                min_distance = d;
                nearest_cluster = i;
            }
        }
    }

    return nearest_cluster;
}

void update_clusters(struct Point points[], int num_points, struct Cluster clusters[], int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        float sum_x = 0, sum_y = 0;
        int num_points_in_cluster = 0;

        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
            num_points_in_cluster++;
        }

        if (num_points_in_cluster > 0) {
            clusters[i].x = sum_x / num_points_in_cluster;
            clusters[i].y = sum_y / num_points_in_cluster;
        }
    }
}

void print_clusters(struct Cluster clusters[], int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d (%d points): (%.2f, %.2f)\n",
            i+1, clusters[i].num_points, clusters[i].x, clusters[i].y);

        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("\t(%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

int main() {
    struct Point points[NUM_POINTS] = {
        {1.0, 1.0},
        {2.0, 1.5},
        {1.5, 2.0},
        {2.5, 2.0},
        {3.0, 2.5},
        {4.0, 4.0},
        {4.5, 3.5},
        {4.0, 3.0},
        {3.5, 3.5},
        {3.0, 3.0}
    };

    struct Cluster clusters[NUM_CLUSTERS] = {
        {{1.0, 1.0}, 0},
        {{2.0, 2.0}, 0},
        {{4.0, 4.0}, 0} 
    };

    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        // Assign each point to the nearest cluster
        for (int i = 0; i < NUM_POINTS; i++) {
            int nearest_cluster = get_nearest_cluster(points[i], clusters, NUM_CLUSTERS);
            clusters[nearest_cluster].points[clusters[nearest_cluster].num_points] = points[i];
            clusters[nearest_cluster].num_points++;
        }

        // Update the centroids of each cluster
        update_clusters(points, NUM_POINTS, clusters, NUM_CLUSTERS);

        iterations++;
    }

    print_clusters(clusters, NUM_CLUSTERS);

    return 0;
}