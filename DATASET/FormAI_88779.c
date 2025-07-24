//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
// This program uses geometric algorithms to find the intersection point of two lines

#include <stdio.h>

// Define a structure for a point in 2D space
typedef struct Point {
    float x;
    float y;
} Point;

// Define a structure for a line in 2D space
typedef struct Line {
    Point p1;
    Point p2;
} Line;

// Function to calculate the slope of a line
float slope(Line line) {
    return (line.p2.y - line.p1.y) / (line.p2.x - line.p1.x);
}

// Function to calculate the y-intercept of a line
float y_intercept(Line line) {
    return line.p1.y - slope(line) * line.p1.x;
}

// Function to find the intersection point of two lines
Point intersection_point(Line line1, Line line2) {
    // Calculate the slopes and y-intercepts of the two lines
    float m1 = slope(line1);
    float m2 = slope(line2);
    float b1 = y_intercept(line1);
    float b2 = y_intercept(line2);
    
    // Calculate the x-coordinate of the intersection point
    float x = (b2 - b1) / (m1 - m2);
    
    // Calculate the y-coordinate of the intersection point
    float y = m1 * x + b1;
    
    // Create a Point structure to hold the intersection point and return it
    Point intersection = { x, y };
    return intersection;
}

int main() {
    // Create two lines for testing the intersection_point function
    Line line1 = { { -2, 1 }, { 3, 8 } };
    Line line2 = { { 0, 5 }, { 6, 5 } };
    
    // Calculate and print the intersection point of the two lines
    Point intersection = intersection_point(line1, line2);
    printf("The intersection point of the lines (%.1f,%.1f)-(%.1f,%.1f) and (%.1f,%.1f)-(%.1f,%.1f) is (%.1f,%.1f).\n",
           line1.p1.x, line1.p1.y, line1.p2.x, line1.p2.y, line2.p1.x, line2.p1.y, line2.p2.x, line2.p2.y, intersection.x, intersection.y);
    
    return 0;
}