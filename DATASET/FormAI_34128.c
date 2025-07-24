//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <math.h>

// Define a structure for a point in 2D space
typedef struct Point
{
    double x;
    double y;
} Point;

// Define a function to calculate the Euclidean distance between two points
double euclidean_distance(Point p1, Point p2)
{
    double x_diff = p2.x - p1.x;
    double y_diff = p2.y - p1.y;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

// Define a function to calculate the slope of a line segment between two points
double slope(Point p1, Point p2)
{
    double x_diff = p2.x - p1.x;
    double y_diff = p2.y - p1.y;
    if (x_diff == 0) // Handle the case of vertical line
    {
        printf("Vertical line detected!\n");
        return INFINITY;
    }
    else
    {
        return y_diff / x_diff;
    }
}

int main()
{
    // Define some example points
    Point p1 = {0, 0};
    Point p2 = {3, 4};
    Point p3 = {-1, 2};
    Point p4 = {5, 6};

    // Calculate and print the Euclidean distances
    printf("The Euclidean distance between points (%g, %g) and (%g, %g) is %g.\n",
           p1.x, p1.y, p2.x, p2.y, euclidean_distance(p1, p2));
    printf("The Euclidean distance between points (%g, %g) and (%g, %g) is %g.\n",
           p3.x, p3.y, p4.x, p4.y, euclidean_distance(p3, p4));

    // Calculate and print the slopes
    printf("The slope of the line segment between points (%g, %g) and (%g, %g) is %g.\n",
           p1.x, p1.y, p2.x, p2.y, slope(p1, p2));
    printf("The slope of the line segment between points (%g, %g) and (%g, %g) is %g.\n",
           p3.x, p3.y, p4.x, p4.y, slope(p3, p4));

    return 0;
}