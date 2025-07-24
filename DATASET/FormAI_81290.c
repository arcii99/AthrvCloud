//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define NR_POINTS 100
#define NR_CLUSTERS 3

typedef struct point {
    int x;
    int y;
} point_t;

typedef struct cluster {
    point_t centroid;
    point_t *points;
    int nr_points;
} cluster_t;

cluster_t clusters[NR_CLUSTERS];

point_t generate_point() {
    point_t p;
    p.x = rand() % 100;
    p.y = rand() % 100;
    return p;
}

void init_clusters() {
    for(int i = 0; i < NR_CLUSTERS; i++) {
        clusters[i].centroid = generate_point();
        clusters[i].points = malloc(NR_POINTS * sizeof(point_t));
        clusters[i].nr_points = 0;
    }
}

void *assign_points_to_clusters(void *arg) {
    point_t *points = (point_t *) arg;

    for(int i = 0; i < NR_POINTS; i++) {
        int closest_cluster_index = 0;
        int min_distance = __INT_MAX__;

        for(int j = 0; j < NR_CLUSTERS; j++) {
            int dx = clusters[j].centroid.x - points[i].x;
            int dy = clusters[j].centroid.y - points[i].y;
            int distance = dx * dx + dy * dy;

            if(distance < min_distance) {
                closest_cluster_index = j;
                min_distance = distance;
            }
        }

        clusters[closest_cluster_index].points[clusters[closest_cluster_index].nr_points++] = points[i];
    }

    pthread_exit(NULL);
}

point_t compute_centroid(point_t *points, int nr_points) {
    point_t centroid;
    int x_sum = 0;
    int y_sum = 0;

    for(int i = 0; i < nr_points; i++) {
        x_sum += points[i].x;
        y_sum += points[i].y;
    }

    centroid.x = x_sum / nr_points;
    centroid.y = y_sum / nr_points;

    return centroid;
}

void *recalculate_centroids(void *arg) {
    for(int i = 0; i < NR_CLUSTERS; i++) {
        clusters[i].centroid = compute_centroid(clusters[i].points, clusters[i].nr_points);
    }

    pthread_exit(NULL);
}

int main() {
    point_t points[NR_POINTS];

    for(int i = 0; i < NR_POINTS; i++) {
        points[i] = generate_point();
    }

    init_clusters();

    pthread_t assign_points_thread, recalculate_centroids_thread;

    pthread_create(&assign_points_thread, NULL, assign_points_to_clusters, (void *) points);
    pthread_join(assign_points_thread, NULL);

    pthread_create(&recalculate_centroids_thread, NULL, recalculate_centroids, NULL);
    pthread_join(recalculate_centroids_thread, NULL);

    for(int i = 0; i < NR_CLUSTERS; i++) {
        printf("Cluster %d centroid: (%d, %d)\n", i + 1, clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points in cluster %d:\n", i + 1);

        for(int j = 0; j < clusters[i].nr_points; j++) {
            printf("(%d, %d)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }

        printf("\n");
    }

    for(int i = 0; i < NR_CLUSTERS; i++) {
        free(clusters[i].points);
    }

    return 0;
}