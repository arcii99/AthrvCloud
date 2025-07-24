//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// define the number of clusters and the number of points
#define NUM_CLUSTERS 5
#define NUM_POINTS 100000

// define the structure for a point
typedef struct {
    double x;
    double y;
} point;

// define the structure for a cluster
typedef struct {
    point centroid;
    point* points;
    int num_points;
} cluster;

// define the variables and arrays needed for the program
point points[NUM_POINTS];
cluster clusters[NUM_CLUSTERS];
int cluster_assignments[NUM_POINTS];
pthread_mutex_t lock;

// function to generate random points
void generate_points() {
    int i;
    srand(time(NULL));
    for (i = 0; i < NUM_POINTS; i++) {
        points[i].x = (double)(rand() % 100);
        points[i].y = (double)(rand() % 100);
    }
}

// function to initialize the clusters
void initialize_clusters() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].centroid.x = (double)(rand() % 100);
        clusters[i].centroid.y = (double)(rand() % 100);
        clusters[i].points = (point*) malloc(NUM_POINTS * sizeof(point));
        clusters[i].num_points = 0;
    }
}

// function to assign points to the closest cluster
int assign_point_cluster(point p) {
    int i, min_index;
    double min_distance = __DBL_MAX__;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        double distance = sqrt(pow((p.x - clusters[i].centroid.x), 2) + pow((p.y - clusters[i].centroid.y), 2));
        if (distance < min_distance) {
            min_distance = distance;
            min_index = i;
        }
    }
    return min_index;
}

// thread function for assigning points to clusters
void* assign_points(void* index) {
    int i, start, end;
    int thread_index = *(int*)index;
    start = thread_index * (NUM_POINTS / NUM_CLUSTERS);
    end = (thread_index + 1) * (NUM_POINTS / NUM_CLUSTERS);
    for (i = start; i < end; i++) {
        int cluster_index = assign_point_cluster(points[i]);
        pthread_mutex_lock(&lock);
        cluster_assignments[i] = cluster_index;
        clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

// function to calculate the new cluster centroid
point calculate_new_centroid(cluster clstr) {
    int i;
    double x_sum = 0, y_sum = 0;
    for (i = 0; i < clstr.num_points; i++) {
        x_sum += clstr.points[i].x;
        y_sum += clstr.points[i].y;
    }
    point new_centroid;
    new_centroid.x = x_sum / clstr.num_points;
    new_centroid.y = y_sum / clstr.num_points;
    return new_centroid;
}

// thread function for calculating new cluster centroids
void* calculate_centroids(void* index) {
    int i;
    int thread_index = *(int*)index;
    for (i = thread_index; i < NUM_CLUSTERS; i += NUM_CLUSTERS) {
        point new_centroid = calculate_new_centroid(clusters[i]);
        clusters[i].centroid = new_centroid;
        clusters[i].num_points = 0;
    }
    pthread_exit(NULL);
}

int main() {
    int i;
    // initialize the threads
    pthread_t assign_thr[NUM_CLUSTERS], calc_thr[NUM_CLUSTERS];

    // generate random points and initialize the clusters
    generate_points();
    initialize_clusters();
    pthread_mutex_init(&lock, NULL);

    // thread for assigning points to clusters
    for (i = 0; i < NUM_CLUSTERS; i++) {
        int* index = (int*) malloc(sizeof(int));
        *index = i;
        pthread_create(&assign_thr[i], NULL, assign_points, (void*)index);
    }
    for (i = 0; i < NUM_CLUSTERS; i++) {
        pthread_join(assign_thr[i], NULL);
    }

    // thread for calculating new cluster centroids
    for (i = 0; i < NUM_CLUSTERS; i++) {
        int* index = (int*) malloc(sizeof(int));
        *index = i;
        pthread_create(&calc_thr[i], NULL, calculate_centroids, (void*)index);
    }
    for (i = 0; i < NUM_CLUSTERS; i++) {
        pthread_join(calc_thr[i], NULL);
    }

    // print the final clusters
    for (i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d - Centroid: (%f, %f) - Number of Points: %d\n", i, clusters[i].centroid.x, clusters[i].centroid.y, clusters[i].num_points);
    }

    return 0;
}