//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_clusters 10
#define NUM_POINTS 1000
#define MAX_ITER 100

double sqr(double x) { return x * x; }

struct point {
    double x, y;
};

struct point points[NUM_POINTS];
int cluster_id[NUM_POINTS], num_clusters;

struct cluster {
    int num_points;
    double x, y;
};

struct cluster clusters[max_clusters];

double distance(struct point p, struct cluster c) {
    return sqrt(sqr(p.x - c.x) + sqr(p.y - c.y));
}

void initialize_clusters() {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].num_points = 0;
        clusters[i].x = random() % 100;
        clusters[i].y = random() % 100;
    }
}

void print_clusters() {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d -- (%lf, %lf)\n", i, clusters[i].x, clusters[i].y);
        for (int j = 0; j < NUM_POINTS; j++) {
            if (cluster_id[j] == i) printf("%lf, %lf\n", points[j].x, points[j].y);
        }
    }
}

void cluster_points() {
    for (int i = 0; i < NUM_POINTS; i++) {
        double min_dist = 1e9;
        int min_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double dist = distance(points[i], clusters[j]);
            if (dist < min_dist) {
                min_dist = dist;
                min_cluster = j;
            }
        }
        cluster_id[i] = min_cluster;
        clusters[min_cluster].num_points++;
        clusters[min_cluster].x += points[i].x;
        clusters[min_cluster].y += points[i].y;
    }
}

void update_clusters() {
    for (int i = 0; i < num_clusters; i++) {
        if (clusters[i].num_points == 0) continue;
        clusters[i].x /= clusters[i].num_points;
        clusters[i].y /= clusters[i].num_points;
    }
}

int main() {
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].x = random() % 100;
        points[i].y = random() % 100;
    }
    num_clusters = 3;
    initialize_clusters();
    for (int i = 0; i < MAX_ITER; i++) {
        cluster_points();
        update_clusters();
        if (i == MAX_ITER - 1) {
            printf("Failed to converge after %d iterations!\n", MAX_ITER);
            return 0;
        }
    }
    print_clusters();
    return 0;
}