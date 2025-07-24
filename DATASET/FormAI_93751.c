//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>
#include <math.h>

// Define a structure to represent a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Define a structure to represent a line segment in 2D space
typedef struct {
    Point start;
    Point end;
} Line;

// Calculate the distance between two points
double calculate_distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Calculate the length of a line segment
double calculate_length(Line line) {
    return calculate_distance(line.start, line.end);
}

// Calculate the midpoint of a line segment
Point calculate_midpoint(Line line) {
    Point midpoint;
    midpoint.x = (line.start.x + line.end.x) / 2.0;
    midpoint.y = (line.start.y + line.end.y) / 2.0;
    return midpoint;
}

// Calculate the slope of a line segment
double calculate_slope(Line line) {
    double dx = line.end.x - line.start.x;
    double dy = line.end.y - line.start.y;
    if (dx == 0.0) {
        return INFINITY;
    } else {
        return dy / dx;
    }
}

// Calculate the angle between two line segments
double calculate_angle(Line line1, Line line2) {
    double m1 = calculate_slope(line1);
    double m2 = calculate_slope(line2);
    double tan_theta = fabs((m2 - m1) / (1.0 + m1*m2));
    return atan(tan_theta);
}

// Determine if two line segments intersect
int do_lines_intersect(Line line1, Line line2) {
    double x1 = line1.start.x;
    double x2 = line1.end.x;
    double x3 = line2.start.x;
    double x4 = line2.end.x;
    double y1 = line1.start.y;
    double y2 = line1.end.y;
    double y3 = line2.start.y;
    double y4 = line2.end.y;

    double denominator = ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
    if (denominator == 0.0) {
        return 0;
    }

    double ua = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / denominator;
    double ub = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / denominator;

    if (ua >= 0.0 && ua <= 1.0 && ub >= 0.0 && ub <= 1.0) {
        return 1;
    }

    return 0;
}

int main() {
    Point p1 = {1.0, 1.0};
    Point p2 = {2.0, 3.0};
    Line line1 = {p1, p2};
    Point p3 = {3.0, 2.0};
    Point p4 = {4.0, 4.0};
    Line line2 = {p3, p4};

    printf("Length of line segment 1: %.2f\n", calculate_length(line1));
    printf("Length of line segment 2: %.2f\n", calculate_length(line2));
    Point midpoint = calculate_midpoint(line1);
    printf("Midpoint of line segment 1: (%.2f, %.2f)\n", midpoint.x, midpoint.y);
    double slope = calculate_slope(line1);
    printf("Slope of line segment 1: %.2f\n", slope);
    double angle = calculate_angle(line1, line2);
    printf("Angle between line segments 1 and 2: %.2f degrees\n", angle * 180 / M_PI);
    int do_intersect = do_lines_intersect(line1, line2);
    if (do_intersect) {
        printf("Line segments 1 and 2 intersect.\n");
    } else {
        printf("Line segments 1 and 2 do not intersect.\n");
    }
    return 0;
}