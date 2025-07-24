//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 50
#define CLUSTER_SIZE 10
#define NUMBER_OF_CLUSTERS 5

typedef struct point_t {
    int x, y;
    int cluster;
} point_t;

void init_points(point_t* points, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
        points[i].cluster = -1;
    }
}

void print_points(point_t* points, int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d,%d) - Cluster %d\n", points[i].x, points[i].y, points[i].cluster);
    }
}

int main() {
    int size = CLUSTER_SIZE * NUMBER_OF_CLUSTERS;
    point_t points[size];
    init_points(points, size);

    // TODO: Implement K-means clustering here

    print_points(points, size);

    return 0;
}