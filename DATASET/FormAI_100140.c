//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include <stdio.h>
#include <math.h>

int main() {
    // Define variables for the input and calculations
    int numPoints;
    int x, y;
    double centroidX = 0.0, centroidY = 0.0;
    double area = 0.0;

    // Ask user for number of points
    printf("Enter the number of points: ");
    scanf("%d", &numPoints);

    // Loop through each point and calculate the centroid and area
    printf("Enter the x and y coordinates of each point:\n");
    for(int i=0; i<numPoints; i++){
        scanf("%d %d", &x, &y);
        centroidX += x;
        centroidY += y;
        area += x*y;
    }

    // Finish centroid and area calculations
    centroidX /= numPoints;
    centroidY /= numPoints;
    area /= 2;

    // Output results
    printf("Centroid: (%.2f, %.2f)\n", centroidX, centroidY);
    printf("Area: %.2f\n", fabs(area));

    return 0;
}