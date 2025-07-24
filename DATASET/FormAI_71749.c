//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_ITERATIONS 1000
#define EPSILON 0.001

struct point {
    double x, y;
    int cluster;
};

double euclidean_distance(struct point p1, struct point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void assign_clusters(struct point points[], struct point centroids[], int k, int n) {
    for (int i = 0; i < n; i++) {
        double min_distance = INFINITY;
        int cluster_number = 0;

        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(points[i], centroids[j]);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_number = j;
            }
        }

        points[i].cluster = cluster_number;
    }
}

void update_centroids(struct point points[], struct point centroids[], int k, int n) {
    for (int i = 0; i < k; i++) {
        double x_sum = 0;
        double y_sum = 0;
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (points[j].cluster == i) {
                x_sum += points[j].x;
                y_sum += points[j].y;
                count++;
            }
        }

        if (count > 0) {
            centroids[i].x = x_sum / count;
            centroids[i].y = y_sum / count;
        }
    }
}

int main() {
    int n, k;
    struct point points[MAX_POINTS];
    struct point centroids[MAX_POINTS];

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the coordinates of the points (x, y): \n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
        points[i].cluster = 0;
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    printf("Enter the initial coordinates of the centroids (x, y): \n");
    for (int i = 0; i < k; i++) {
        scanf("%lf %lf", &centroids[i].x, &centroids[i].y);
    }

    for (int i = 1; i <= MAX_ITERATIONS; i++) {
        assign_clusters(points, centroids, k, n);
        update_centroids(points, centroids, k, n);

        double sum_distance = 0;

        for (int j = 0; j < n; j++) {
            sum_distance += euclidean_distance(points[j], centroids[points[j].cluster]);
        }

        if (sum_distance < EPSILON) {
            printf("Clustering completed after %d iterations!\n", i);
            break;
        }
    }

    printf("Final cluster assignments:\n");
    for (int i = 0; i < n; i++) {
        printf("(%lf, %lf) -> %d\n", points[i].x, points[i].y, points[i].cluster);
    }

    return 0;
}