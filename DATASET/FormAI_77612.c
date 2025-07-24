//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Definition of data structure */
struct Point {
    double x, y;
};

/* Function to compute Euclidean distance between two points */
double get_distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

/* Function to find the index of the nearest center */
int get_nearest_center(struct Point point, struct Point *centers, int num_centers) {
    int nearest_center_index = 0;
    double nearest_distance = get_distance(point, centers[0]);
    for (int i = 1; i < num_centers; i++) {
        double distance = get_distance(point, centers[i]);
        if (distance < nearest_distance) {
            nearest_distance = distance;
            nearest_center_index = i;
        }
    }
    return nearest_center_index;
}

/* Function to update the centers once the points have been reassigned */
void update_centers(struct Point *points, int num_points, int *point_assignments, struct Point *centers, int num_centers) {
    int *sum_x = calloc(num_centers, sizeof(int));
    int *sum_y = calloc(num_centers, sizeof(int));
    int *count = calloc(num_centers, sizeof(int));

    /* Sum up the points assigned to each center */
    for (int i = 0; i < num_points; i++) {
        int center_index = point_assignments[i];
        sum_x[center_index] += points[i].x;
        sum_y[center_index] += points[i].y;
        count[center_index]++;
    }

    /* Compute the new center */
    for (int i = 0; i < num_centers; i++) {
        if (count[i] == 0) {
            continue;
        }
        centers[i].x = sum_x[i] / count[i];
        centers[i].y = sum_y[i] / count[i];
    }

    free(sum_x);
    free(sum_y);
    free(count);
}

/* Main function */
int main() {
    /* Declare and initialize variables */
    int num_points = 10;
    struct Point *points = calloc(num_points, sizeof(struct Point));
    points[0] = (struct Point) {.x = 1, .y = 1};
    points[1] = (struct Point) {.x = 1, .y = 2};
    points[2] = (struct Point) {.x = 2, .y = 1};
    points[3] = (struct Point) {.x = 2, .y = 2};
    points[4] = (struct Point) {.x = 5, .y = 4};
    points[5] = (struct Point) {.x = 5, .y = 5};
    points[6] = (struct Point) {.x = 6, .y = 4};
    points[7] = (struct Point) {.x = 6, .y = 5};
    points[8] = (struct Point) {.x = 9, .y = 8};
    points[9] = (struct Point) {.x = 9, .y = 9};
    int num_centers = 3;
    struct Point *centers = calloc(num_centers, sizeof(struct Point));
    centers[0] = (struct Point) {.x = 1, .y = 1};
    centers[1] = (struct Point) {.x = 5, .y = 4};
    centers[2] = (struct Point) {.x = 9, .y = 8};
    int *point_assignments = calloc(num_points, sizeof(int));

    /* Perform clustering */
    for (int iter = 1; iter <= 10; iter++) {
        /* Assign points to centers */
        for (int i = 0; i < num_points; i++) {
            point_assignments[i] = get_nearest_center(points[i], centers, num_centers);
        }

        /* Update centers */
        update_centers(points, num_points, point_assignments, centers, num_centers);

        /* Print out current assignments */
        printf("Iteration %d:\n", iter);
        for (int i = 0; i < num_centers; i++) {
            printf("Center %d: (%.2f, %.2f), assigned points: ", i + 1, centers[i].x, centers[i].y);
            for (int j = 0; j < num_points; j++) {
                if (point_assignments[j] == i) {
                    printf("(%d, %d) ", (int) points[j].x, (int) points[j].y);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    /* Clean up memory */
    free(points);
    free(centers);
    free(point_assignments);

    return 0;
}