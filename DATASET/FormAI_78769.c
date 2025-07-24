//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: lively
// Welcome to the world of Geometric Algorithms in C!

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// function to calculate the area of a circle

double circle_area(double radius)
{
    double area;
    area = PI * radius * radius; // PI*r^2 formula for area of a circle
    return area;
}

// function to calculate the circumference of a circle

double circle_circumference(double radius)
{
    double circumference;
    circumference = 2 * PI * radius; // 2*PI*r formula for circumference of a circle
    return circumference;
}

// function to calculate the area of a triangle

double triangle_area(double base, double height)
{
    double area;
    area = 0.5 * base * height; // 1/2*b*h formula for area of a triangle
    return area;
}

// function to calculate the perimeter of a triangle

double triangle_perimeter(double side1, double side2, double side3)
{
    double perimeter;
    perimeter = side1 + side2 + side3; // sum of all sides formula for perimeter of a triangle
    return perimeter;
}

int main()
{
    printf("******** Welcome to Geometric Algorithms in C! ********\n\n");

    // calculate the area and circumference of a circle with a radius of 5

    double radius = 5.0;
    double circle_area_result = circle_area(radius);
    double circle_circumference_result = circle_circumference(radius);

    printf("The area of the circle with radius %.1f is %.2f\n", radius, circle_area_result);
    printf("The circumference of the circle with radius %.1f is %.2f\n\n", radius, circle_circumference_result);

    // calculate the area and perimeter of a triangle with base 5 and height 8

    double base = 5.0;
    double height = 8.0;
    double triangle_area_result = triangle_area(base, height);
    double side1 = 3.0;
    double side2 = 4.0;
    double side3 = 5.0;
    double triangle_perimeter_result = triangle_perimeter(side1, side2, side3);

    printf("The area of a triangle with base %.1f and height %.1f is %.2f\n", base, height, triangle_area_result);
    printf("The perimeter of a triangle with sides %.1f, %.1f, %.1f is %.2f\n\n", side1, side2, side3, triangle_perimeter_result);

    return 0;
}