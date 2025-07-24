//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shocked
#include <stdio.h>
#include <math.h>

// function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// main function
int main() {
    double x1, y1, x2, y2, x3, y3;

    // getting input from the user
    printf("Enter x and y co-ordinates of point 1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter x and y co-ordinates of point 2: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter x and y co-ordinates of point 3: ");
    scanf("%lf %lf", &x3, &y3);

    // calculating the distance between the points
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x1, y1, x3, y3);

    // calculating the perimeter of the triangle
    double perimeter = a + b + c;

    // calculating the semi-perimeter of the triangle
    double s = perimeter / 2;

    // using Heron's formula to calculate the area of the triangle
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    // printing the calculated results
    printf("The perimeter of the triangle is: %.2lf units\n", perimeter);
    printf("The area of the triangle is: %.2lf sq.units\n", area);

    return 0;
}