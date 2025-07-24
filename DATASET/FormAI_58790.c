//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_GROUP 50

struct Point {
    double x;
    double y;
};

struct Group {
    int count;
    struct Point points[MAX_POINTS];
};

double distance(struct Point p1, struct Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

void add_to_group(struct Group* group, struct Point point) {
    group->points[group->count++] = point;
}

struct Group* find_nearest_group(struct Group* groups, int n_groups, struct Point point) {
    struct Group* nearest_group = NULL;
    double nearest_distance = INFINITY;
    for (int i = 0; i < n_groups; i++) {
        double group_distance = distance(groups[i].points[0], point);
        if (group_distance < nearest_distance) {
            nearest_distance = group_distance;
            nearest_group = &groups[i];
        }
    }
    return nearest_group;
}

int main(void) {
    // Generate random data
    struct Point data[MAX_POINTS];
    int n_points = 200;
    for (int i = 0; i < n_points; i++) {
        data[i].x = (double) rand() / RAND_MAX;
        data[i].y = (double) rand() / RAND_MAX;
    }

    // Initialize groups
    struct Group groups[MAX_GROUP];
    int n_groups = 10;
    for (int i = 0; i < n_groups; i++) {
        groups[i].count = 1;
        groups[i].points[0] = data[i];
    }

    // Iterate over remaining points
    for (int i = n_groups; i < n_points; i++) {
        struct Point point = data[i];
        struct Group* nearest_group = find_nearest_group(groups, n_groups, point);
        add_to_group(nearest_group, point);
    }

    // Print results
    for (int i = 0; i < n_groups; i++) {
        printf("Group %d:\n", i+1);
        for (int j = 0; j < groups[i].count; j++) {
            struct Point point = groups[i].points[j];
            printf("\t(%lf, %lf)\n", point.x, point.y);
        }
    }

    return 0;
}