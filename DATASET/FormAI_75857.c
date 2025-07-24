//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>

// Function to calculate the area of a circle
double circleArea(double radius)
{
    double area = 3.14159 * radius * radius;
    return area;
}

// Function to calculate the area of a rectangle
double rectangleArea(double length, double width)
{
    double area = length * width;
    return area;
}

int main()
{
    printf("Welcome to the geometry program!\n");

    double radius;
    printf("Please enter the radius of a circle: ");
    scanf("%lf", &radius);

    double circle = circleArea(radius);
    printf("The area of the circle with radius %lf is %lf.\n", radius, circle);

    double length, width;
    printf("Please enter the length and width of a rectangle: ");
    scanf("%lf %lf", &length, &width);

    double rectangle = rectangleArea(length, width);
    printf("The area of the rectangle with length %lf and width %lf is %lf.\n", length, width, rectangle);

    printf("Thank you for using the geometry program!\n");

    return 0;
}