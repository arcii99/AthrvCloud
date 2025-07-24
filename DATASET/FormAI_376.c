//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2)
{
    double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return d;
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    double a, b, c;  // Lengths of sides
    double s;  // Semiperimeter
    double area;  // Area of triangle

    // Ask user for input
    printf("Enter the x and y coordinates of three points:\n");

    // Read in three points
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Calculate lengths of sides
    a = distance(x1, y1, x2, y2);
    b = distance(x2, y2, x3, y3);
    c = distance(x1, y1, x3, y3);

    // Calculate semiperimeter
    s = (a + b + c) / 2;

    // Calculate area
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Output results
    printf("The lengths of the sides are: %.2f, %.2f, %.2f\n", a, b, c);
    printf("The semiperimeter is: %.2f\n", s);
    printf("The area of the triangle is: %.2f\n", area);

    return 0;
}