//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>

// Define a Point structure to represent a 2D point
typedef struct Point {
    double x;
    double y;
} Point;

// Define the Line structure to represent a line segment with two endpoints
typedef struct Line {
    Point p1;
    Point p2;
} Line;

// Define a Rectangle structure to represent a rectangle with four corners
typedef struct Rectangle {
    Point tl;   // Top left corner
    Point tr;   // Top right corner
    Point bl;   // Bottom left corner
    Point br;   // Bottom right corner
} Rectangle;

// Function that calculates the area of a rectangle recursively using line segments
double recursiveArea(Rectangle rect) {
    if (rect.tl.x == rect.tr.x && rect.tr.y == rect.br.y) {
        // Base case: rectangle is actually a line segment
        Line line = {rect.tl, rect.br};
        return line.p1.y > line.p2.y ? line.p1.y - line.p2.y : line.p2.y - line.p1.y;
    } else {
        // Recursive case: divide rectangle into two smaller rectangles and sum their areas
        double x1 = rect.tl.x;
        double x2 = rect.tr.x;
        double y1 = rect.tl.y;
        double y2 = rect.br.y;
        double midX = (x1 + x2) / 2;
        double midY = (y1 + y2) / 2;
        Rectangle rect1 = {{x1, y1}, {midX, y1}, {x1, midY}, {midX, midY}};
        Rectangle rect2 = {{midX, y1}, {x2, y1}, {midX, midY}, {x2, midY}};
        Rectangle rect3 = {{x1, midY}, {midX, midY}, {x1, y2}, {midX, y2}};
        Rectangle rect4 = {{midX, midY}, {x2, midY}, {midX, y2}, {x2, y2}};
        return recursiveArea(rect1) + recursiveArea(rect2) + recursiveArea(rect3) + recursiveArea(rect4);
    }
}

int main() {
    // Create a rectangle with corners at (0,0) and (4,4)
    Rectangle rect = {{0, 0}, {4, 0}, {0, 4}, {4, 4}};
    // Calculate and print the area of the rectangle
    printf("Area of rectangle: %f\n", recursiveArea(rect));
    return 0;
}