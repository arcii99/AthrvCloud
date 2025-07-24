//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define CLUSTER_NUM 5
#define DIMENSION_NUM 3
#define THRESHOLD 0.001

typedef struct {
    double centroid[DIMENSION_NUM];
    int num_points;
    double points[DIMENSION_NUM][DIMENSION_NUM];
} Cluster;

void initialize_data(double data[][DIMENSION_NUM], int num_points);
double euclidean_distance(double x[], double y[]);
void initialize_clusters(double data[][DIMENSION_NUM], Cluster clusters[], int num_clusters);
void assign_points_to_clusters(double data[][DIMENSION_NUM], Cluster clusters[], int num_points);
void update_cluster_centroids(Cluster clusters[], int num_clusters);
int compare_clusters(Cluster clusters[], Cluster old_clusters[], int num_clusters);
void print_clusters(Cluster clusters[], int num_clusters);

int main() {
    double data[100][DIMENSION_NUM];
    Cluster clusters[CLUSTER_NUM];
    Cluster old_clusters[CLUSTER_NUM];
    int num_points = 100;
    int num_clusters = CLUSTER_NUM;
    int i, j, iteration = 1;
    double threshold = THRESHOLD;
    srand(time(NULL));
    initialize_data(data, num_points);
    initialize_clusters(data, clusters, num_clusters);
    while (1) {
        assign_points_to_clusters(data, clusters, num_points);
        update_cluster_centroids(clusters, num_clusters);
        if (compare_clusters(clusters, old_clusters, num_clusters) || iteration >= 100)
            break;
        for (i = 0; i < num_clusters; i++) {
            for (j = 0; j < DIMENSION_NUM; j++) {
                old_clusters[i].centroid[j] = clusters[i].centroid[j];
            }
            old_clusters[i].num_points = clusters[i].num_points;
            for (j = 0; j < clusters[i].num_points; j++) {
                old_clusters[i].points[j][0] = clusters[i].points[j][0];
                old_clusters[i].points[j][1] = clusters[i].points[j][1];
                old_clusters[i].points[j][2] = clusters[i].points[j][2];
            }
        }
        iteration++;
    }
    print_clusters(clusters, num_clusters);
}

void initialize_data(double data[][DIMENSION_NUM], int num_points) {
    int i, j;
    for (i = 0; i < num_points; i++) {
        for (j = 0; j < DIMENSION_NUM; j++) {
            data[i][j] = (double) rand() / RAND_MAX * 100;
        }
    }
}

double euclidean_distance(double x[], double y[]) {
    int i;
    double sum = 0;
    for (i = 0; i < DIMENSION_NUM; i++) {
        sum += pow(x[i] - y[i], 2);
    }
    return sqrt(sum);
}

void initialize_clusters(double data[][DIMENSION_NUM], Cluster clusters[], int num_clusters) {
    int i, j, k;
    for (i = 0; i < num_clusters; i++) {
        for (j = 0; j < DIMENSION_NUM; j++) {
            clusters[i].centroid[j] = data[rand() % 100][j];
        }
        clusters[i].num_points = 0;
        for (j = 0; j < DIMENSION_NUM; j++) {
            for (k = 0; k < DIMENSION_NUM; k++) {
                clusters[i].points[j][k] = 0;
            }
        }
    }
}

void assign_points_to_clusters(double data[][DIMENSION_NUM], Cluster clusters[], int num_points) {
    int i, j, min_cluster_index;
    double min_distance, distance;
    for (i = 0; i < num_points; i++) {
        min_distance = euclidean_distance(data[i], clusters[0].centroid);
        min_cluster_index = 0;
        for (j = 1; j < CLUSTER_NUM; j++) {
            distance = euclidean_distance(data[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                min_cluster_index = j;
            }
        }
        for (j = 0; j < DIMENSION_NUM; j++) {
            clusters[min_cluster_index].points[clusters[min_cluster_index].num_points][j] = data[i][j];
        }
        clusters[min_cluster_index].num_points++;
    }
}

void update_cluster_centroids(Cluster clusters[], int num_clusters) {
    int i, j, k;
    double sum[DIMENSION_NUM];
    for (i = 0; i < num_clusters; i++) {
        for (j = 0; j < DIMENSION_NUM; j++) {
            sum[j] = 0;
        }
        for (j = 0; j < clusters[i].num_points; j++) {
            for (k = 0; k < DIMENSION_NUM; k++) {
                sum[k] += clusters[i].points[j][k];
            }
        }
        for (j = 0; j < DIMENSION_NUM; j++) {
            clusters[i].centroid[j] = sum[j] / clusters[i].num_points;
        }
    }
}

int compare_clusters(Cluster clusters[], Cluster old_clusters[], int num_clusters) {
    int i, j;
    double distance, max_distance = 0;
    for (i = 0; i < num_clusters; i++) {
        for (j = 0; j < DIMENSION_NUM; j++) {
            distance = fabs(clusters[i].centroid[j] - old_clusters[i].centroid[j]);
            if (distance > max_distance)
                max_distance = distance;
        }
        if ((double) clusters[i].num_points / old_clusters[i].num_points < 0.9 ||
            (double) clusters[i].num_points / old_clusters[i].num_points > 1.1) {
            max_distance = THRESHOLD * 10;
            break;
        }
    }
    return max_distance < THRESHOLD;
}

void print_clusters(Cluster clusters[], int num_clusters) {
    int i, j, k;
    printf("Clusters:\n");
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d: centroid [", i);
        for (j = 0; j < DIMENSION_NUM; j++) {
            printf("%.2lf", clusters[i].centroid[j]);
            if (j < DIMENSION_NUM - 1) {
                printf(", ");
            }
        }
        printf("], number of points %d\n", clusters[i].num_points);
        printf("Points:\n");
        for (j = 0; j < clusters[i].num_points; j++) {
            printf("[");
            for (k = 0; k < DIMENSION_NUM; k++) {
                printf("%.2lf", clusters[i].points[j][k]);
                if (k < DIMENSION_NUM - 1) {
                    printf(", ");
                }
            }
            printf("]\n");
        }
    }
}