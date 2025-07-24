//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define K 2
#define MAX_ITERATIONS 1000
#define THRESHOLD 0.01

typedef struct Point {
    double x, y;
} Point;

void assign_to_clusters(Point data[], Point centroids[]);
void update_centroids(Point data[], Point centroids[]);
double point_distance(Point a, Point b);

int main() {
    Point data[N] = {{1.3, 2.5}, {3.7, 4.1}, {2.6, 3.4}, {4.2, 2.8}, {1.9, 4.5},
                     {3.1, 3.2}, {2.2, 2.9}, {3.9, 3.8}, {4.9, 2.5}, {2.7, 3.6}};

    Point centroids[K] = {{1.9, 4.5}, {4.2, 2.8}};

    int i, j, iteration;
    double error = 0, prev_error = 0;

    for (iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        assign_to_clusters(data, centroids);
        update_centroids(data, centroids);

        // calculate error
        for (i = 0; i < N; i++) {
            for (j = 0; j < K; j++) {
                if (data[i].x == centroids[j].x && data[i].y == centroids[j].y) {
                    error += 0; // ignore exact matches
                } else {
                    error += point_distance(data[i], centroids[j]);
                }
            }
        }

        if (iteration > 0 && fabs(error - prev_error) < THRESHOLD) {
            break; // convergence detected
        }

        prev_error = error;
        error = 0;
    }

    printf("Cluster assignments:\n");
    for (i = 0; i < N; i++) {
        printf("(%lf, %lf) -> ", data[i].x, data[i].y);
        for (j = 0; j < K; j++) {
            if (data[i].x == centroids[j].x && data[i].y == centroids[j].y) {
                printf("%d\n", j);
                break;
            }
        }
    }

    return 0;
}

void assign_to_clusters(Point data[], Point centroids[]) {
    int i, j;
    double min_distance, distance;
    for (i = 0; i < N; i++) {
        min_distance = point_distance(data[i], centroids[0]);
        for (j = 1; j < K; j++) {
            distance = point_distance(data[i], centroids[j]);
            if (distance < min_distance) {
                min_distance = distance;
                data[i].x = j; // assign to closest cluster
            }
        }
    }
}

void update_centroids(Point data[], Point centroids[]) {
    int i, j, n;
    double x_sum[K] = {0}, y_sum[K] = {0};
    for (i = 0; i < N; i++) {
        n = (int) data[i].x; // get cluster assignment
        x_sum[n] += data[i].x;
        y_sum[n] += data[i].y;
    }
    for (i = 0; i < K; i++) {
        if (x_sum[i] != 0) {
            centroids[i].x = x_sum[i] / N;
        }
        if (y_sum[i] != 0) {
            centroids[i].y = y_sum[i] / N;
        }
    }
}

double point_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}