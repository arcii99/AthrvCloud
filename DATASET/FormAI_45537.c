//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: safe
#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} LineSegment;

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    Point a = {3, 4};
    Point b = {7, 1};
    Point c = {5, 5};
    LineSegment ab = {a, b};
    LineSegment ac = {a, c};
    LineSegment bc = {b, c};

    // Check if the three points form a right-angled triangle
    double distAB = distance(a, b);
    double distAC = distance(a, c);
    double distBC = distance(b, c);
    if(distAB*distAB + distAC*distAC == distBC*distBC ||
       distAC*distAC + distBC*distBC == distAB*distAB ||
       distBC*distBC + distAB*distAB == distAC*distAC) {
        printf("The three points form a right-angled triangle.\n");
    } else {
        printf("The three points do not form a right-angled triangle.\n");
    }

    // Check if point c lies on line segment ab
    double distAtoC = distance(a, c);
    double distBtoC = distance(b, c);
    double distAtoB = distance(a, b);
    if(distAtoC + distBtoC == distAtoB) {
        printf("Point c lies on line segment ab.\n");
    } else {
        printf("Point c does not lie on line segment ab.\n");
    }

    return 0;
}