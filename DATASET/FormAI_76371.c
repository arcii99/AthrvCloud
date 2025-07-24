//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTER 5
#define MAX_ITERATIONS 20
#define THRESHOLD 0.001

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point centroid;
    int size;
    Point *points;
} Cluster;

typedef struct {
    int size;
    Point *points;
} Dataset;

void initialize_clusters(Cluster *clusters, int k, Point *points, int num_points);
void update_centroids(Cluster *clusters, int k);
float euclidean_distance(Point a, Point b);
int assign_points(Cluster *clusters, int k, Point *points, int num_points);
void print_clusters(Cluster *clusters, int k);

int main() {
    Dataset dataset;
    int num_points, i;
    printf("Enter number of points: ");
    scanf("%d", &num_points);

    dataset.size = num_points;
    dataset.points = (Point*) malloc(num_points * sizeof(Point));

    printf("Enter points in the format x,y: \n");
    for (i = 0; i < num_points; i++) {
        scanf("%f,%f", &dataset.points[i].x, &dataset.points[i].y);
    }

    int k;
    printf("Enter number of clusters: ");
    scanf("%d", &k);

    Cluster clusters[MAX_CLUSTER];
    initialize_clusters(clusters, k, dataset.points, num_points);

    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        int changes = assign_points(clusters, k, dataset.points, num_points);
        update_centroids(clusters, k);
        if (changes <= THRESHOLD) {
            break;
        }
        iteration++;
    }

    print_clusters(clusters, k);

    free(dataset.points);
    dataset.points = NULL;

    return 0;
}

void initialize_clusters(Cluster *clusters, int k, Point *points, int num_points) {
    int i, j;
    for (i = 0; i < k; i++) {
        clusters[i].centroid.x = points[i].x;
        clusters[i].centroid.y = points[i].y;
        clusters[i].size = 0;
        clusters[i].points = (Point*) malloc(num_points * sizeof(Point));
    }
}

void update_centroids(Cluster *clusters, int k) {
    int i, j;
    for (i = 0; i < k; i++) {
        float sum_x = 0, sum_y = 0;
        for (j = 0; j < clusters[i].size; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].size;
        clusters[i].centroid.y = sum_y / clusters[i].size;
    }
}

float euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int assign_points(Cluster *clusters, int k, Point *points, int num_points) {
    int i, j, l;
    int changes = 0;
    for (i = 0; i < num_points; i++) {
        float min_distance = 999999999;
        int min_distance_cluster = -1;
        for (j = 0; j < k; j++) {
            float distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                min_distance_cluster = j;
            }
        }
        for (l = 0; l < k; l++) {
            if (l == min_distance_cluster) {
                if (clusters[l].points[clusters[l].size].x != points[i].x || clusters[l].points[clusters[l].size].y != points[i].y) {
                    changes++;
                }
                clusters[l].points[clusters[l].size] = points[i];
                clusters[l].size++;
            } else {
                if (clusters[l].points[clusters[l].size].x == points[i].x && clusters[l].points[clusters[l].size].y == points[i].y) {
                    changes++;
                }
                clusters[l].points[clusters[l].size] = clusters[l].points[--clusters[l].size];
            }
        }
    }
    return changes;
}

void print_clusters(Cluster *clusters, int k) {
    int i, j;
    for (i = 0; i < k; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points: ");
        for (j = 0; j < clusters[i].size; j++) {
            printf("(%.2f, %.2f) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}