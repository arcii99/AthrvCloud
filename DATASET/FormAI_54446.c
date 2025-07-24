//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include<stdio.h>
#include<math.h>

//Structure to store co-ordinate of a point
typedef struct {
    double x;
    double y;
} Point;

//Structure to store line connecting two points
typedef struct {
    Point start;
    Point end;
} Line;

//Function to calculate distance between two points
double distance(Point p1, Point p2) {
    double xDiff = p2.x - p1.x;
    double yDiff = p2.y - p1.y;
    return sqrt(xDiff*xDiff + yDiff*yDiff);
}

//Function to check if the given point lies on the given line
int pointOnLine(Point p, Line l) {
    double d1 = distance(p, l.start);
    double d2 = distance(l.end, p);
    double d = distance(l.start, l.end);
    return (fabs(d1 + d2 - d) <= 0.000001);
}

//Function to check if the given point is inside the given rectangle
int pointInRectangle(Point p, Point topLeft, Point bottomRight) {
    return (p.x >= topLeft.x && p.x <= bottomRight.x &&
            p.y >= bottomRight.y && p.y <= topLeft.y);
}

//Driver function
int main() {
    Point p1 = {1.0, 2.0};
    Point p2 = {3.0, 4.0};
    Line l1 = {p1, p2};
    Point p3 = {2.0, 3.0};
    Point topLeft = {0.0, 5.0};
    Point bottomRight = {4.0, 0.0};
    
    if(pointOnLine(p3, l1)) {
        printf("Point (%.2f, %.2f) is on the line connecting (%.2f, %.2f) and (%.2f, %.2f)\n", p3.x, p3.y, p1.x, p1.y, p2.x, p2.y);
    } else {
        printf("Point (%.2f, %.2f) is not on the line connecting (%.2f, %.2f) and (%.2f, %.2f)\n", p3.x, p3.y, p1.x, p1.y, p2.x, p2.y);
    }
    
    if(pointInRectangle(p3, topLeft, bottomRight)) {
        printf("Point (%.2f, %.2f) is inside the rectangle with top-left corner at (%.2f, %.2f) and bottom-right corner at (%.2f, %.2f)\n", p3.x, p3.y, topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
    } else {
        printf("Point (%.2f, %.2f) is not inside the rectangle with top-left corner at (%.2f, %.2f) and bottom-right corner at (%.2f, %.2f)\n", p3.x, p3.y, topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
    }
    
    return 0;
}