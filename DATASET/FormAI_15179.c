//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// structure for representing points in 2D space
typedef struct point {
    double x;
    double y;
} point;

// structure for representing vectors
typedef struct vector {
    double x;
    double y;
} vector;

// helper function for calculating the cross product of two vectors
double cross_product(vector v1, vector v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

// helper function for calculating the distance between two points
double distance(point p1, point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// implementation of the Graham scan algorithm
void graham_scan(point* points, int num_points) {
    // find the point with minimum y-coordinate
    point lowest_point = points[0];
    int lowest_index = 0;
    for (int i = 1; i < num_points; i++) {
        if (points[i].y < lowest_point.y) {
            lowest_point = points[i];
            lowest_index = i;
        } else if (points[i].y == lowest_point.y && points[i].x < lowest_point.x) {
            lowest_point = points[i];
            lowest_index = i;
        }
    }

    // move the lowest point to the first position
    point temp = points[0];
    points[0] = lowest_point;
    points[lowest_index] = temp;

    // sort the remaining points by angle with the x-axis
    for (int i = 1; i < num_points - 1; i++) {
        for (int j = i + 1; j < num_points; j++) {
            vector v1 = {points[i].x - points[0].x, points[i].y - points[0].y};
            vector v2 = {points[j].x - points[0].x, points[j].y - points[0].y};
            double cross = cross_product(v1, v2);
            if (cross < 0 || (cross == 0 && distance(points[0], points[i]) > distance(points[0], points[j]))) {
                // swap points i and j
                temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }

    // push the first two points onto the stack
    point* stack = (point*) malloc(num_points * sizeof(point));
    int stack_size = 0;
    stack[0] = points[0];
    stack[1] = points[1];
    stack_size = 2;

    // process the remaining points
    for (int i = 2; i < num_points; i++) {
        // pop the top point from the stack until the cross product of the top two vectors is non-negative
        while (stack_size > 1) {
            vector v1 = {stack[stack_size - 1].x - stack[stack_size - 2].x, stack[stack_size - 1].y - stack[stack_size - 2].y};
            vector v2 = {points[i].x - stack[stack_size - 2].x, points[i].y - stack[stack_size - 2].y};
            if (cross_product(v1, v2) < 0) {
                stack_size--;
            } else {
                break;
            }
        }

        // push the new point onto the stack
        stack[stack_size] = points[i];
        stack_size++;
    }

    // output the convex hull
    printf("Convex Hull:\n");
    for (int i = 0; i < stack_size; i++) {
        printf("(%f, %f)\n", stack[i].x, stack[i].y);
    }

    // free the memory used by the stack
    free(stack);
}

int main() {
    // generate some random points in 2D space
    const int num_points = 10;
    point points[num_points];
    for (int i = 0; i < num_points; i++) {
        points[i].x = (double) rand() / RAND_MAX * 10.0;
        points[i].y = (double) rand() / RAND_MAX * 10.0;
    }

    // apply the Graham scan algorithm and output the result
    graham_scan(points, num_points);

    return 0;
}