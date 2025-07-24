//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the area of a circle given its radius
double area_of_circle(double radius) {
    return M_PI * pow(radius, 2);
}

// Function to compute the distance between two points in 2D space
double distance_between_points(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to find the nearest point on a line to a given point
void nearest_point_on_line(double x1, double y1, double x2, double y2, double x, double y, double *nearest_x, double *nearest_y) {
    double distance_to_line = fabs((y2 - y1) * x - (x2 - x1) * y + x2 * y1 - y2 * x1) / distance_between_points(x1, y1, x2, y2);
    if (distance_to_line == 0) {
        *nearest_x = x;
        *nearest_y = y;
    } else {
        double closest_point_fraction = ((x - x1) * (x2 - x1) + (y - y1) * (y2 - y1)) / pow(distance_between_points(x1, y1, x2, y2), 2);
        *nearest_x = x1 + closest_point_fraction * (x2 - x1);
        *nearest_y = y1 + closest_point_fraction * (y2 - y1);
    }
}

int main() {
    double r = 3.5; // radius of circle
    double x = 2.0; // x coordinate of point
    double y = 1.0; // y coordinate of point
    double x1 = 0.0; // x coordinate of first point on line
    double y1 = 0.0; // y coordinate of first point on line
    double x2 = 4.0; // x coordinate of second point on line
    double y2 = 4.0; // y coordinate of second point on line
    
    // Compute the area of the circle
    double area = area_of_circle(r);
    printf("Area of the circle with radius %.1f is: %.2f\n", r, area);
    
    // Compute the distance between two points
    double distance = distance_between_points(x1, y1, x2, y2);
    printf("Distance between (%.1f, %.1f) and (%.1f, %.1f) is: %.2f\n", x1, y1, x2, y2, distance);
    
    // Find the nearest point on the line to the given point
    double nearest_x, nearest_y;
    nearest_point_on_line(x1, y1, x2, y2, x, y, &nearest_x, &nearest_y);
    printf("The point (%.1f, %.1f) is closest to the line between (%.1f, %.1f) and (%.1f, %.1f) at (%.2f, %.2f)\n", x, y, x1, y1, x2, y2, nearest_x, nearest_y);
    
    return 0;
}