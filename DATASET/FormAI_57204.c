//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <math.h>

// A structure to represent a point in 2D space
typedef struct {
    double x; // x-coordinate
    double y; // y-coordinate
} Point;

// A structure to represent a line segment joining two points
typedef struct {
    Point p1; // first endpoint
    Point p2; // second endpoint
} LineSegment;

// Function to calculate the Euclidean distance between two points
double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to check if two line segments intersect
int doLineSegmentsIntersect(LineSegment l1, LineSegment l2) {

    // First, check if the bounding boxes intersect
    double l1MinX = fmin(l1.p1.x, l1.p2.x);
    double l1MaxX = fmax(l1.p1.x, l1.p2.x);
    double l1MinY = fmin(l1.p1.y, l1.p2.y);
    double l1MaxY = fmax(l1.p1.y, l1.p2.y);

    double l2MinX = fmin(l2.p1.x, l2.p2.x);
    double l2MaxX = fmax(l2.p1.x, l2.p2.x);
    double l2MinY = fmin(l2.p1.y, l2.p2.y);
    double l2MaxY = fmax(l2.p1.y, l2.p2.y);

    if (l1MaxX < l2MinX || l1MinX > l2MaxX || l1MaxY < l2MinY || l1MinY > l2MaxY) {
        return 0; // No intersection between the bounding boxes
    }

    // Next, calculate the slopes and y-intercepts of the two lines
    double slope1 = (l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x);
    double slope2 = (l2.p2.y - l2.p1.y) / (l2.p2.x - l2.p1.x);

    double yIntercept1 = l1.p1.y - slope1 * l1.p1.x;
    double yIntercept2 = l2.p1.y - slope2 * l2.p1.x;

    // If the slopes are equal, the lines are parallel and if the y-intercepts are not equal, the lines do not intersect
    if (slope1 == slope2) {
        return yIntercept1 == yIntercept2;
    }

    // Calculate the point of intersection
    double intersectionX = (yIntercept2 - yIntercept1) / (slope1 - slope2);
    double intersectionY = slope1 * intersectionX + yIntercept1;

    // If the point of intersection lies within both line segments, the lines intersect
    if (intersectionX >= fmin(l1.p1.x, l1.p2.x) && intersectionX <= fmax(l1.p1.x, l1.p2.x) &&
        intersectionX >= fmin(l2.p1.x, l2.p2.x) && intersectionX <= fmax(l2.p1.x, l2.p2.x) &&
        intersectionY >= fmin(l1.p1.y, l1.p2.y) && intersectionY <= fmax(l1.p1.y, l1.p2.y) &&
        intersectionY >= fmin(l2.p1.y, l2.p2.y) && intersectionY <= fmax(l2.p1.y, l2.p2.y)) {
        return 1;
    }

    return 0; // No intersection
}

int main() {

    // Create two line segments
    LineSegment l1;
    LineSegment l2;

    // Initialize the first line segment
    l1.p1.x = 0;
    l1.p1.y = 0;
    l1.p2.x = 5;
    l1.p2.y = 5;

    // Initialize the second line segment
    l2.p1.x = 0;
    l2.p1.y = 5;
    l2.p2.x = 5;
    l2.p2.y = 0;

    // Check if the line segments intersect
    if (doLineSegmentsIntersect(l1, l2)) {
        printf("The line segments intersect\n");
    } else {
        printf("The line segments do not intersect\n");
    }

    return 0;
}