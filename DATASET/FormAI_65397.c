//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define K 3
#define MAX_ITER 100

typedef struct {
    double x, y;
} point;

point points[N];
int clusters[N], centroids[K];
int iter = 0;

void initialize() {
    int i, j;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;

        clusters[i] = -1;
    }

    for (i = 0; i < K; i++)
        centroids[i] = rand() % N;
}

double distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void assign_points_to_clusters() {
    int i, j;
    double d, min_d;

    for (i = 0; i < N; i++) {
        min_d = distance(points[i], points[centroids[0]]);
        clusters[i] = 0;

        for (j = 1; j < K; j++) {
            d = distance(points[i], points[centroids[j]]);

            if (d < min_d) {
                min_d = d;
                clusters[i] = j;
            }
        }
    }
}

void compute_centroids() {
    int i, j, count;
    double sum_x, sum_y;

    for (i = 0; i < K; i++) {
        count = 0;
        sum_x = sum_y = 0;

        for (j = 0; j < N; j++) {
            if (clusters[j] == i) {
                count++;
                sum_x += points[j].x;
                sum_y += points[j].y;
            }
        }

        if (count > 0) {
            centroids[i] = -1;
            points[K + i].x = centroids[i] = sum_x / count;
            points[K + i].y = sum_y / count;
        }
    }
}

void print_clusters() {
    int i, j;

    printf("\nClusters:\n");

    for (i = 0; i < K; i++) {
        printf("Cluster %d:\n", i);

        for (j = 0; j < N; j++) {
            if (clusters[j] == i)
                printf("(%lf,%lf) ", points[j].x, points[j].y);
        }

        printf("\n");
    }
}

int main(int argc, char** argv) {
    initialize();

    do {
        iter++;
        assign_points_to_clusters();
        compute_centroids();
    } while (iter < MAX_ITER);

    print_clusters();

    return (EXIT_SUCCESS);
}