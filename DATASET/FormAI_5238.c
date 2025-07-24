//FormAI DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to represent a point in 2D space
struct Point {
    double x;
    double y;
};

// Define a structure to represent a circle with a center point and a radius
struct Circle {
    struct Point center;
    double radius;
};

int main () {
    // Define an array of 5 circles
    struct Circle circles[5] = {
        {{0, 0}, 1},
        {{2, 1}, 2},
        {{-1, 1}, 1.5},
        {{-3, -2}, 3},
        {{1, -3}, 2.5},
    };

    // Get the user input for the center of the circle they want to query
    struct Point queryPoint;
    printf("Enter the x-coordinate of the center of the circle: ");
    scanf("%lf", &queryPoint.x);
    printf("Enter the y-coordinate of the center of the circle: ");
    scanf("%lf", &queryPoint.y);

    // Loop through each circle and determine if the query point lies inside the circle
    int i;
    for (i = 0; i < 5; i++) {
        // Use the distance formula to determine the distance between the query point and the center of the circle
        double distance = sqrt(pow(queryPoint.x - circles[i].center.x, 2) + pow(queryPoint.y - circles[i].center.y, 2));
        
        // Determine if the distance is less than the radius of the circle
        if (distance < circles[i].radius) {
            printf("The query point (%.1lf, %.1lf) lies inside the circle centered at (%.1lf, %.1lf) with radius %.1lf.\n", queryPoint.x, queryPoint.y, circles[i].center.x, circles[i].center.y, circles[i].radius);
        }
    }

    return 0;
}