//FormAI DATASET v1.0 Category: Educational ; Style: scientific
#include <stdio.h>

// Define the constant PI
#define PI 3.14159265358979323846

// Prototype the function to find the area of a circle
double area_of_circle(double radius);

int main()
{
    double r;
    printf("Please input the radius of the circle: ");
    scanf("%lf", &r);

    // Check if radius is non-negative
    if (r < 0)
    {
        printf("Invalid input! The radius must be non-negative.\n");
        return -1; // Return error code
    }

    // Compute the area of the circle
    double area = area_of_circle(r);

    // Print the area of the circle
    printf("The area of the circle with radius %.2lf is %.4lf.\n", r, area);

    return 0; // Return success code
}

double area_of_circle(double radius)
{
    // Compute the area of the circle using the formula: A = πr^2
    return PI * radius * radius;
}