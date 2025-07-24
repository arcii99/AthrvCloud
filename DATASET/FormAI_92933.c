//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ada Lovelace
// A program to find the intersection point of two lines in 2D space
// Written by Ada Lovelace

#include <stdio.h>

// Define a struct to represent a 2D point
typedef struct {
    double x;
    double y;
} Point;

// Define a struct to represent a 2D line
typedef struct {
    Point start;
    Point end;
} Line;

// Define a function to calculate the slope of a line
double slope(Line line) {
    return (line.end.y - line.start.y) / (line.end.x - line.start.x);
}

// Define a function to calculate the y-intercept of a line
double y_intercept(Line line) {
    return line.start.y - slope(line) * line.start.x;
}

// Define a function to calculate the intersection point of two lines
Point intersection(Line line1, Line line2) {
    double m1 = slope(line1);
    double b1 = y_intercept(line1);
    double m2 = slope(line2);
    double b2 = y_intercept(line2);
    
    double x = (b2 - b1) / (m1 - m2);
    double y = m1 * x + b1;
    
    return (Point) {x, y};
}

int main() {
    // Define two lines
    Line line1 = (Line) {{1, 2}, {3, 4}};
    Line line2 = (Line) {{0, 3}, {2, 1}};
    
    // Calculate the intersection point
    Point intersection_point = intersection(line1, line2);
    
    // Print the intersection point
    printf("The intersection point is (%f, %f)\n", intersection_point.x, intersection_point.y);
    
    return 0;
}