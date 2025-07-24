//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_POINTS 100
#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 50

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    int num_points;
    Point *points;
    Point centroid;
} Cluster;

Cluster clusters[NUM_CLUSTERS];
Point points[NUM_POINTS];

pthread_mutex_t mutex;

void *clusterize(void *thread_id) {
    int id = *(int *)thread_id;
    
    // Initialize cluster's centroid
    clusters[id].centroid.x = points[id].x;
    clusters[id].centroid.y = points[id].y;
    clusters[id].num_points = 1;

    // Loop through all the points
    for (int i = id; i < NUM_POINTS; i += NUM_THREADS) {
        float min_dist = 999999; // Initialize minimum distance
        int closest_cluster = 0;

        // Find the closest cluster for the current point
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            float dist = sqrt(pow((points[i].x - clusters[j].centroid.x), 2) + 
                              pow((points[i].y - clusters[j].centroid.y), 2));
            if (dist < min_dist) {
                min_dist = dist;
                closest_cluster = j;
            }
        }

        // Add point to cluster
        pthread_mutex_lock(&mutex);
        clusters[closest_cluster].points[clusters[closest_cluster].num_points] = points[i];
        clusters[closest_cluster].num_points++;
        clusters[closest_cluster].centroid.x = (clusters[closest_cluster].centroid.x + points[i].x) / 2;
        clusters[closest_cluster].centroid.y = (clusters[closest_cluster].centroid.y + points[i].y) / 2;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    // Initialize random points
    srand(time(NULL));
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    // Initialize clusters
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].num_points = 0;
        clusters[i].points = malloc(NUM_POINTS * sizeof(Point));
    }

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, clusterize, (void *)&thread_ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print clusters
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Number of points: %d\n", clusters[i].num_points);
    }

    // Cleanup
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        free(clusters[i].points);
    }
    pthread_mutex_destroy(&mutex);
    
    return 0;
}