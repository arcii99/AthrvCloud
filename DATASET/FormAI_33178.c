//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: decentralized
#include <stdio.h>

// Define the coordinate struct for 2D points
struct point {
    double x;
    double y;
};

// Define the line struct using two 2D points
struct line {
    struct point p1;
    struct point p2;
};

// Calculate the slope of a line given two points
double slope(struct point p1, struct point p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
}

// Determine if two lines intersect given their slopes and y-intercepts
int intersect(double m1, double b1, double m2, double b2) {
    if (m1 == m2) {
        return 0; // Lines are parallel and never intersect
    } else {
        return 1; // Lines intersect at a single point
    }
}

// Calculate the point of intersection for two lines given their slopes and y-intercepts
struct point intersection(double m1, double b1, double m2, double b2) {
    double x = (b2 - b1) / (m1 - m2);
    double y = m1 * x + b1;
    struct point p = {x, y};
    return p;
}

int main() {
    // Define two 2D points and create a line
    struct point p1 = {1.0, 2.0};
    struct point p2 = {5.0, 7.0};
    struct line l1 = {p1, p2};

    // Define two more 2D points and create another line
    struct point p3 = {3.0, 5.0};
    struct point p4 = {7.0, 1.0};
    struct line l2 = {p3, p4};

    // Calculate the slope and y-intercept for each line
    double m1 = slope(l1.p1, l1.p2);
    double b1 = l1.p1.y - m1 * l1.p1.x;

    double m2 = slope(l2.p1, l2.p2);
    double b2 = l2.p1.y - m2 * l2.p1.x;

    // Determine if the lines intersect
    if (intersect(m1, b1, m2, b2)) {
        // Calculate the point of intersection for the lines
        struct point p = intersection(m1, b1, m2, b2);

        // Print out the coordinates of the point of intersection
        printf("The lines intersect at (%f, %f)\n", p.x, p.y);
    } else {
        printf("The lines are parallel and never intersect.\n");
    }

    return 0;
}