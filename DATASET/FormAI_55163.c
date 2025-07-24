//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: futuristic
#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    double radius;
} Circle;

typedef struct {
    Point start;
    Point end;
} Line;

// Function to calculate distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to determine whether a point is inside a circle
int insideCircle(Point p, Circle c) {
    double dist = distance(p, c.center);
    if (dist < c.radius) {
        return 1;
    } else {
        return 0;
    }
}

// Function to determine whether two lines intersect
int linesIntersect(Line l1, Line l2) {
    double x1 = l1.start.x;
    double y1 = l1.start.y;
    double x2 = l1.end.x;
    double y2 = l1.end.y;
    double x3 = l2.start.x;
    double y3 = l2.start.y;
    double x4 = l2.end.x;
    double y4 = l2.end.y;
    
    double m1, m2, b1, b2, x, y;
    
    // Check if lines are vertical
    if (x1 == x2) {
        if (x3 == x4) {
            if (x1 == x3) {
                if ((y3 >= y1 && y3 <= y2) || (y4 >= y1 && y4 <= y2)) {
                    return 1;
                }
            }
        }
        return 0;
    } else if (x3 == x4) {
        if ((y1 >= y3 && y1 <= y4) || (y2 >= y3 && y2 <= y4)) {
            return 1;
        }
        return 0;
    }
    
    // Calculate slopes and y-intercepts
    m1 = (y2 - y1) / (x2 - x1);
    b1 = y1 - m1 * x1;
    m2 = (y4 - y3) / (x4 - x3);
    b2 = y3 - m2 * x3;
    
    // Check if lines are parallel
    if (m1 == m2) {
        if (b1 == b2) {
            return 1;
        }
        return 0;
    }
    
    // Calculate intersection point
    x = (b2 - b1) / (m1 - m2);
    y = m1 * x + b1;
    
    // Check if intersection point is within both line segments
    if ((x >= x1 && x <= x2) || (x >= x2 && x <= x1)) {
        if ((x >= x3 && x <= x4) || (x >= x4 && x <= x3)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Point p1 = {1, 1};
    Point p2 = {4, 5};
    Point p3 = {2, 2};
    Point p4 = {3, 4};
    
    Circle c = {{3, 3}, 2};
    
    Line l1 = {p1, p2};
    Line l2 = {p3, p4};
    Line l3 = {p1, p3};
    
    if (insideCircle(p1, c)) {
        printf("Point p1 is inside circle c.\n");
    } else {
        printf("Point p1 is outside circle c.\n");
    }
    
    if (linesIntersect(l1, l2)) {
        printf("Lines l1 and l2 intersect.\n");
    } else {
        printf("Lines l1 and l2 do not intersect.\n");
    }
    
    if (linesIntersect(l1, l3)) {
        printf("Lines l1 and l3 intersect.\n");
    } else {
        printf("Lines l1 and l3 do not intersect.\n");
    }
    
    return 0;
}