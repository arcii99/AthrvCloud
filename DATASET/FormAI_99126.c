//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 50
#define MAX_Y 20

struct point_t {
    int x;
    int y;
    int cluster;
};

typedef struct point_t point;

void print_map(point map[MAX_Y][MAX_X]) {
    int x, y;
    for (y = 0; y < MAX_Y; y++) {
        for (x = 0; x < MAX_X; x++) {
            printf("%d ", map[y][x].cluster);
        }
        printf("\n");
    }
    printf("\n");
}

int distance(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int find_closest_cluster(point *p, point centers[], int n_centers) {
    int i, closest_distance, closest_index;

    closest_distance = MAX_X + MAX_Y + 1; // max possible distance on the map
    closest_index = -1;

    for (i = 0; i < n_centers; i++) {
        int dist = distance(*p, centers[i]);
        if (dist < closest_distance) {
            closest_distance = dist;
            closest_index = i;
        }
    }

    return closest_index;
}

void initialize_centers(point centers[], int n_centers) {
    int i, x, y;

    for (i = 0; i < n_centers; i++) {
        do {
            x = rand() % MAX_X;
            y = rand() % MAX_Y;
        } while (i > 0 && centers[i - 1].x == x && centers[i - 1].y == y);

        centers[i].x = x;
        centers[i].y = y;
    }
}

void update_centers(point map[MAX_Y][MAX_X], point centers[], int n_centers) {
    int cluster_sizes[n_centers];
    int i, j, x, y;

    for (i = 0; i < n_centers; i++) {
        cluster_sizes[i] = 0;
        centers[i].x = 0;
        centers[i].y = 0;
    }

    for (y = 0; y < MAX_Y; y++) {
        for (x = 0; x < MAX_X; x++) {
            int cluster = map[y][x].cluster;
            centers[cluster].x += x;
            centers[cluster].y += y;
            cluster_sizes[cluster]++;
        }
    }

    for (i = 0; i < n_centers; i++) {
        if (cluster_sizes[i] > 0) {
            centers[i].x /= cluster_sizes[i];
            centers[i].y /= cluster_sizes[i];
        }
    }
}

int main() {
    point map[MAX_Y][MAX_X];
    point centers[5];
    int i, x, y;

    srand(time(NULL));

    /* Initialize map */
    for (y = 0; y < MAX_Y; y++) {
        for (x = 0; x < MAX_X; x++) {
            map[y][x].x = x;
            map[y][x].y = y;
            map[y][x].cluster = -1;
        }
    }

    /* Initialize centers */
    initialize_centers(centers, 5);

    int iter = 0;
    while (iter < 20) {
        printf("iteration %d:\n", iter + 1);

        /* Assign clusters */
        for (y = 0; y < MAX_Y; y++) {
            for (x = 0; x < MAX_X; x++) {
                int closest_cluster = find_closest_cluster(&map[y][x], centers, 5);
                map[y][x].cluster = closest_cluster;
            }
        }

        print_map(map);

        /* Update centers */
        update_centers(map, centers, 5);

        iter++;
    }

    return 0;
}