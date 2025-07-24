//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
#include <stdio.h>

// define a point structure to represent coordinates
struct Point {
    int x;
    int y;
};

// function to calculate the distance between two points using the Pythagorean theorem
double distance(struct Point p1, struct Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// function to calculate the area of a triangle using the Shoelace formula
double area(struct Point vertices[3]) {
    double x1 = vertices[0].x;
    double y1 = vertices[0].y;
    double x2 = vertices[1].x;
    double y2 = vertices[1].y;
    double x3 = vertices[2].x;
    double y3 = vertices[2].y;
    return 0.5 * fabs(x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2);
}

int main() {
    struct Point p1 = {0,0};
    struct Point p2 = {3,4};
    
    printf("Distance between (%d,%d) and (%d,%d): %f\n", p1.x, p1.y, p2.x, p2.y, distance(p1, p2));
    
    struct Point triangle[3] = {{1,2},{3,5},{7,3}};
    
    printf("Area of triangle {(1,2),(3,5),(7,3)}: %f\n", area(triangle));
    
    return 0;
}