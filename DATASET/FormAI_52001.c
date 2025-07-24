//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    // define the coordinates of three points
    int x1, y1, x2, y2, x3, y3;

    // read the coordinates of the three points from the user
    printf("Enter the coordinates of point 1 (x, y): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of point 2 (x, y): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the coordinates of point 3 (x, y): ");
    scanf("%d %d", &x3, &y3);

    // calculate the length of each side of the triangle
    double side1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    double side2 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    double side3 = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));

    // calculate the area of the triangle using Heron's formula
    double s = (side1 + side2 + side3) / 2;
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

    // calculate the radius of the inscribed circle
    double radius = area / s;

    // calculate the coordinates of the center of the inscribed circle
    double centerX = (side1 * x3 + side2 * x1 + side3 * x2) / (side1 + side2 + side3);
    double centerY = (side1 * y3 + side2 * y1 + side3 * y2) / (side1 + side2 + side3);

    // print the results
    printf("Radius of the inscribed circle: %f\n", radius);
    printf("Center of the inscribed circle: (%f, %f)\n", centerX, centerY);

    return 0;
}