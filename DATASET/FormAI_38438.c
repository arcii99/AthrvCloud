//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

// Define a point in 2D space
typedef struct {
    double x;
    double y;
} point;

// Define a line in 2D space
typedef struct {
    point p1;
    point p2;
} line;

// Calculate the distance between two points
double distance(point p1, point p2) {
    double x_diff = p2.x - p1.x;
    double y_diff = p2.y - p1.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// Calculate the slope of a line
double slope(line l) {
    double y_diff = l.p2.y - l.p1.y;
    double x_diff = l.p2.x - l.p1.x;
    return y_diff / x_diff;
}

// Calculate the y-intercept of a line
double y_intercept(line l) {
    double m = slope(l);
    return l.p1.y - m * l.p1.x;
}

// Check if two lines intersect
int intersect(line l1, line l2) {
    double m1 = slope(l1);
    double m2 = slope(l2);
    double b1 = y_intercept(l1);
    double b2 = y_intercept(l2);
    
    // Check if lines are parallel
    if (m1 == m2) {
        return 0;
    }
    
    // Calculate intersection point
    double x = (b2 - b1) / (m1 - m2);
    double y = m1 * x + b1;
    point p = {x, y};
    
    // Check if intersection point is on both lines
    double d1 = distance(l1.p1, p) + distance(l1.p2, p);
    double d2 = distance(l2.p1, p) + distance(l2.p2, p);
    if (d1 == distance(l1.p1, l1.p2) && d2 == distance(l2.p1, l2.p2)) {
        return 1;
    }
    
    return 0;
}

int main() {
    // Define two lines
    line l1 = {{1, 2}, {3, 4}};
    line l2 = {{2, 1}, {4, 3}};
    
    // Check if the lines intersect
    if (intersect(l1, l2)) {
        printf("The lines intersect at (%.2lf, %.2lf)\n", 
            (l1.p1.x + l1.p2.x + l2.p1.x + l2.p2.x) / 4,
            (l1.p1.y + l1.p2.y + l2.p1.y + l2.p2.y) / 4);
    } else {
        printf("The lines do not intersect\n");
    }
    
    return 0;
}