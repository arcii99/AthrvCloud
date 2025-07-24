//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define K 3
#define THRESHOLD 0.001

double data[N][2];
int cluster[N];
double centroid[K][2];

double euclidean_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

void initialize_centroids() {
    int i, j, rand_idx;
    double x, y;
    for (i = 0; i < K; i++) {
        rand_idx = rand() % N;
        x = data[rand_idx][0];
        y = data[rand_idx][1];
        centroid[i][0] = x;
        centroid[i][1] = y;
    }
}

void assign_clusters() {
    int i, j, min_idx;
    double min_distance, distance;
    for (i = 0; i < N; i++) {
        min_distance = INFINITY;
        for (j = 0; j < K; j++) {
            distance = euclidean_distance(data[i][0], data[i][1], centroid[j][0], centroid[j][1]);
            if (distance < min_distance) {
                min_distance = distance;
                min_idx = j;
            }
        }
        cluster[i] = min_idx;
    }
}

void update_centroids() {
    int i, j, count;
    double sum_x, sum_y;
    for (i = 0; i < K; i++) {
        count = 0;
        sum_x = 0;
        sum_y = 0;
        for (j = 0; j < N; j++) {
            if (cluster[j] == i) {
                sum_x += data[j][0];
                sum_y += data[j][1];
                count++;
            }
        }
        centroid[i][0] = sum_x / count;
        centroid[i][1] = sum_y / count;
    }
}

int main() {
    int i, j;
    double delta, sum_delta;
    for (i = 0; i < N; i++) {
        data[i][0] = rand() % 100;
        data[i][1] = rand() % 100;
    }
    initialize_centroids();
    do {
        assign_clusters();
        sum_delta = 0;
        for (i = 0; i < K; i++) {
            for (j = 0; j < 2; j++) {
                delta = fabs(centroid[i][j] - centroid[i][j]);
                sum_delta += delta;
            }
        }
        update_centroids();
    } while (sum_delta > THRESHOLD);
    for (i = 0; i < K; i++) {
        printf("Centroid %d: (%.2f, %.2f)\n", i+1, centroid[i][0], centroid[i][1]);
    }
    return 0;
}