//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>
#include <math.h>

/* Define a Point struct */
typedef struct Point {
    double x;
    double y;
} Point;

/* Define a Line struct */
typedef struct Line {
    Point p1;
    Point p2;
} Line;

/* Function to calculate distance between two points */
double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

/* Function to calculate slope of a line */
double slope(Line l) {
    double dx = l.p2.x - l.p1.x;
    double dy = l.p2.y - l.p1.y;
    return dy/dx;
}

/* Function to calculate y-intercept of a line */
double y_intercept(Line l) {
    double m = slope(l);
    return l.p1.y - m*l.p1.x;
}

/* Function to calculate intersection point of two lines */
Point intersection(Line l1, Line l2) {
    double m1 = slope(l1);
    double m2 = slope(l2);
    double b1 = y_intercept(l1);
    double b2 = y_intercept(l2);
    double x = (b2 - b1)/(m1 - m2);
    double y = m1*x + b1;
    return (Point){x, y};
}

/* Main function */
int main() {
    /* Define two lines */
    Line l1 = (Line){{1, 2}, {3, 4}};
    Line l2 = (Line){{4, 2}, {0, 3}};

    /* Calculate and print distance between two points */
    printf("Distance between Point 1 and Point 2: %.2f\n", distance(l1.p1, l1.p2));

    /* Calculate and print slope of line */
    printf("Slope of Line 1: %.2f\n", slope(l1));

    /* Calculate and print y-intercept of line */
    printf("Y-intercept of Line 1: %.2f\n", y_intercept(l1));

    /* Calculate and print intersection point of two lines */
    Point intersect = intersection(l1, l2);
    printf("Intersection Point of Line 1 and Line 2: (%.2f, %.2f)\n", intersect.x, intersect.y);

    return 0;
}