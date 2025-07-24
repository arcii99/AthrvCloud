//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x, y;
} point_t;

typedef struct {
    int num_points;
    point_t points[MAX_POINTS];
    point_t centroid;
} cluster_t;

double rand_range(double min, double max) {
    double range = max - min;
    double rand_num = (double) rand() / RAND_MAX;
    return (rand_num * range) + min;
}

void init_clusters(cluster_t clusters[], int num_clusters, double min, double max) {
    int i, j;

    for (i = 0; i < num_clusters; i++) {
        cluster_t * cluster = &clusters[i];

        cluster->num_points = 0;

        cluster->centroid.x = rand_range(min, max);
        cluster->centroid.y = rand_range(min, max);

        for (j = 0; j < MAX_POINTS; j++) {
            cluster->points[j].x = 0;
            cluster->points[j].y = 0;
        }
    }
}

void print_point(point_t point) {
    printf("(%f, %f) ", point.x, point.y);
}

void print_cluster(cluster_t cluster) {
    printf("Centroid: ");
    print_point(cluster.centroid);
    printf("Points: ");

    int i;
    for (i = 0; i < cluster.num_points; i++) {
        print_point(cluster.points[i]);
    }
    printf("\n");
}

void print_clusters(cluster_t clusters[], int num_clusters) {
    int i;

    for (i = 0; i < num_clusters; i++) {
        print_cluster(clusters[i]);
    }
}

int main() {
    srand(time(NULL));

    int num_clusters = rand_range(2, MAX_CLUSTERS);
    int num_points = rand_range(num_clusters * 3, MAX_POINTS);

    cluster_t clusters[num_clusters];
    init_clusters(clusters, num_clusters, 0.0, 10.0);

    int i, j;
    for (i = 0; i < num_points; i++) {
        point_t point;
        point.x = rand_range(0.0, 10.0);
        point.y = rand_range(0.0, 10.0);

        int closest_cluster_index = 0;
        double closest_cluster_distance = 1000;

        for (j = 0; j < num_clusters; j++) {
            double distance = pow(point.x - clusters[j].centroid.x, 2) + pow(point.y - clusters[j].centroid.y, 2);

            if (distance < closest_cluster_distance) {
                closest_cluster_distance = distance;
                closest_cluster_index = j;
            }
        }

        clusters[closest_cluster_index].points[clusters[closest_cluster_index].num_points++] = point;
    }

    print_clusters(clusters, num_clusters);

    return 0;
}