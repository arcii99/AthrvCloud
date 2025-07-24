//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the area of a circle
double circle_area(double radius)
{
    return M_PI * pow(radius, 2);
}

// Function to calculate the area of a triangle given three sides
double triangle_area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    double d1, d2, d3; // The distances between the points
    double a, b, c; // The sides of the triangle
    double radius; // The radius of the circle
    double area; // The area of the triangle or circle
    
    // Take input of the three points
    printf("Enter the coordinates of the first point (x1,y1): ");
    scanf("%lf,%lf", &x1, &y1);
    printf("Enter the coordinates of the second point (x2,y2): ");
    scanf("%lf,%lf", &x2, &y2);
    printf("Enter the coordinates of the third point (x3,y3): ");
    scanf("%lf,%lf", &x3, &y3);
    
    // Calculate the distances between the points
    d1 = distance(x1, y1, x2, y2);
    d2 = distance(x1, y1, x3, y3);
    d3 = distance(x2, y2, x3, y3);
    
    // Calculate the sides of the triangle
    a = d1;
    b = d2;
    c = d3;
    
    // Calculate the area of the triangle
    area = triangle_area(a, b, c);
    
    // Calculate the radius of the circle
    radius = (a * b * c) / (4 * area);
    
    // Calculate the area of the circle
    area = circle_area(radius);
    
    // Print out the results
    printf("The distance between points 1 and 2 is %lf\n", d1);
    printf("The distance between points 1 and 3 is %lf\n", d2);
    printf("The distance between points 2 and 3 is %lf\n", d3);
    printf("The area of the triangle is %lf\n", area);
    printf("The radius of the circle is %lf\n", radius);
    printf("The area of the circle is %lf\n", area);
    
    return 0;
}