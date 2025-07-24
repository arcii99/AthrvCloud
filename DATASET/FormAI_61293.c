//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: light-weight
#include <stdio.h>
#include <math.h>

// Define a structure Point that stores x and y coordinates of a point in 2D space
struct Point {
    double x;
    double y;
};

// Returns the distance between two points in 2D space
double distance(struct Point p1, struct Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Returns the perimeter of a rectangle given the coordinates of its diagonal points
double rectangle_perimeter(struct Point p1, struct Point p2) {
    double width = fabs(p2.x - p1.x);
    double height = fabs(p2.y - p1.y);
    return 2 * (width + height);
}

// Returns the area of a rectangle given the coordinates of its diagonal points
double rectangle_area(struct Point p1, struct Point p2) {
    double width = fabs(p2.x - p1.x);
    double height = fabs(p2.y - p1.y);
    return width * height;
}

int main() {
    struct Point p1 = {0, 0};
    struct Point p2 = {3, 4};

    double dist = distance(p1, p2);
    printf("Distance between (%f, %f) and (%f, %f): %f\n", p1.x, p1.y, p2.x, p2.y, dist);

    double perimeter = rectangle_perimeter(p1, p2);
    printf("Perimeter of rectangle with diagonal points (%f, %f) and (%f, %f): %f\n", p1.x, p1.y, p2.x, p2.y, perimeter);

    double area = rectangle_area(p1, p2);
    printf("Area of rectangle with diagonal points (%f, %f) and (%f, %f): %f\n", p1.x, p1.y, p2.x, p2.y, area);

    return 0;
}