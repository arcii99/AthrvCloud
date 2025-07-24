//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define a Point struct
typedef struct point {
    double x;
    double y;
} Point;

// Define a Line struct
typedef struct line {
    Point p1;
    Point p2;
} Line;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to check if three points are collinear
int collinear(Point p1, Point p2, Point p3) {
    double area = 0.5 * (p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y));
    return (area == 0);
}

// Function to check if two lines intersect
int intersect(Line l1, Line l2) {
    Point p1 = l1.p1;
    Point p2 = l1.p2;
    Point p3 = l2.p1;
    Point p4 = l2.p2;
    
    double d1 = (p4.x - p3.x)*(p1.y - p3.y) - (p4.y - p3.y)*(p1.x - p3.x);
    double d2 = (p4.x - p3.x)*(p2.y - p3.y) - (p4.y - p3.y)*(p2.x - p3.x);
    double d3 = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
    double d4 = (p2.x - p1.x)*(p4.y - p1.y) - (p2.y - p1.y)*(p4.x - p1.x);
    
    if ((d1*d2 < 0) && (d3*d4 < 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    Point p1 = {1, 1};
    Point p2 = {2, 3};
    Point p3 = {3, 5};
    
    // Check if the three points are collinear
    if (collinear(p1, p2, p3)) {
        printf("The three points are collinear.\n");
    }
    else {
        printf("The three points are not collinear.\n");
    }
    
    Line l1 = {p1, p2};
    Line l2 = {p2, p3};
    
    // Check if the two lines intersect
    if (intersect(l1, l2)) {
        printf("The two lines intersect.\n");
    }
    else {
        printf("The two lines do not intersect.\n");
    }
    
    return 0;
}