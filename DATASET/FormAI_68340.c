//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Point struct defining an (x, y) coordinate pair
typedef struct {
    double x;
    double y;
} point;

// Function to find the index of the point with the lowest y-coordinate
int find_lowest_y_index(point* points, int num_points) {
    int lowest_index = 0;
    for (int i = 1; i < num_points; i++) {
        if (points[i].y < points[lowest_index].y) {
            lowest_index = i;
        }
    }
    return lowest_index;
}

// Function to check if three points make a counter-clockwise turn
bool is_counterclockwise_turn(point p1, point p2, point p3) {
    double cross_product = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return cross_product > 0;
}

// Function to find the convex hull of a set of points using the Gift Wrapping Algorithm
// Returns a dynamically allocated array of point structs representing the convex hull
// Assumes that there are at least 3 non-collinear points in the input array
point* find_convex_hull(point* points, int num_points) {
    // Find the point with the lowest y-coordinate
    int curr_index = find_lowest_y_index(points, num_points);
    
    // Start with the lowest point as the first point in the hull
    point* hull = (point*) malloc(sizeof(point));
    *hull = points[curr_index];
    int hull_size = 1;
    
    // Find the rest of the points in the hull
    while (true) {
        int next_index = (curr_index + 1) % num_points;
        for (int i = 0; i < num_points; i++) {
            if (i == curr_index) {
                continue;
            }
            if (is_counterclockwise_turn(points[curr_index], points[i], points[next_index])) {
                next_index = i;
            }
        }
        if (next_index == find_lowest_y_index(points, num_points)) {
            break;
        }
        else {
            hull_size++;
            hull = (point*) realloc(hull, hull_size * sizeof(point));
            hull[hull_size - 1] = points[next_index];
            curr_index = next_index;
        }
    }
    
    return hull;
}

// Function to print out the coordinates of a set of points
void print_points(point* points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        printf("(%f, %f) ", points[i].x, points[i].y);
    }
    printf("\n");
}

// Main function demonstrating the use of the convex hull algorithm
int main() {
    point points[] = {{0, 0}, {1, 3}, {2, 9}, {4, 5}, {6, 3},
                      {7, 6}, {8, 4}, {9, 7}, {10, 2}, {12, 5}};
    int num_points = sizeof(points) / sizeof(points[0]);
    
    printf("Input points:\n");
    print_points(points, num_points);
    
    point* hull = find_convex_hull(points, num_points);
    int hull_size = sizeof(hull) / sizeof(hull[0]);
    
    printf("Convex hull points:\n");
    print_points(hull, hull_size);
    
    free(hull);
    return 0;
}