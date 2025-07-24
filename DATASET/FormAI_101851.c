//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POINTS 100
#define DIMENSIONS 2

struct Point {
    double coords[DIMENSIONS];
    int cluster;
};

void generate_points(struct Point* points) {
    srand(time(NULL));
    for (int i = 0; i < POINTS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            points[i].coords[j] = (double) rand() / (double) RAND_MAX;
        }
        points[i].cluster = -1;
    }
}

double distance(struct Point a, struct Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += (a.coords[i] - b.coords[i]) * (a.coords[i] - b.coords[i]);
    }
    return sum;
}

int nearest_cluster(struct Point point, struct Point* centroids, int k) {
    double min_distance = distance(point, centroids[0]);
    int min_index = 0;
    double temp_distance;
    for (int i = 1; i < k; i++) {
        temp_distance = distance(point, centroids[i]);
        if (temp_distance < min_distance) {
            min_distance = temp_distance;
            min_index = i;
        }
    }
    return min_index;
}

void update_centroids(struct Point* centroids, struct Point* points, int k) {
    int counts[k];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            centroids[i].coords[j] = 0.0;
        }
        counts[i] = 0;
    }
    for (int i = 0; i < POINTS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            centroids[points[i].cluster].coords[j] += points[i].coords[j];
        }
        counts[points[i].cluster]++;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            centroids[i].coords[j] /= (double) counts[i];
        }
    }
}

void k_means_clustering(struct Point* points, int k) {
    struct Point centroids[k];
    for (int i = 0; i < k; i++) {
        int index = rand() % POINTS;
        for (int j = 0; j < DIMENSIONS; j++) {
            centroids[i].coords[j] = points[index].coords[j];
        }
    }
    int iterations = 0;
    while (1) {
        printf("\nIteration %d:\n\n", iterations);
        iterations++;
        int changes = 0;
        for (int i = 0; i < POINTS; i++) {
            int current_cluster = points[i].cluster;
            points[i].cluster = nearest_cluster(points[i], centroids, k);
            if (points[i].cluster != current_cluster) {
                changes++;
            }
        }
        if (changes == 0) {
            break;
        }
        update_centroids(centroids, points, k);
        for (int i = 0; i < k; i++) {
            printf("Cluster %d: (", i);
            for (int j = 0; j < DIMENSIONS; j++) {
                printf("%.2lf, ", centroids[i].coords[j]);
            }
            printf(")\n");
        }
        printf("\n");
    }
}

int main() {
    struct Point points[POINTS];
    generate_points(points);
    int k = 5;
    k_means_clustering(points, k);
    return 0;
}