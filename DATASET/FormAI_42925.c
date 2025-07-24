//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <math.h>

// This function accepts the coordinates of three points in the plane,
// and returns the distance between the line passing through the first two points
// and the third point
double distanceFromLine(double x1, double y1, double x2, double y2, double x3, double y3) {
    // Compute the slope of the line passing through the first two points
    double slope = (y2 - y1) / (x2 - x1);
    
    // Compute the y-intercept of the line passing through the first two points
    double yIntercept = y1 - slope * x1;
    
    // Compute the perpendicular distance from the third point to the line
    double distance = fabs(slope * x3 - y3 + yIntercept) / sqrt(1 + slope * slope);
    
    return distance;
}

int main() {
    // Define the three points in the plane
    double x1 = 1.0, y1 = 1.0;
    double x2 = 2.0, y2 = 2.0;
    double x3 = 3.0, y3 = 1.0;
    
    // Compute the distance from the line passing through points (x1, y1) and (x2, y2) to point (x3, y3)
    double distance = distanceFromLine(x1, y1, x2, y2, x3, y3);
    
    // Print the result
    printf("The distance from the line passing through points (%lf, %lf) and (%lf, %lf) to point (%lf, %lf) is %lf\n",
           x1, y1, x2, y2, x3, y3, distance);
    
    return 0;
}