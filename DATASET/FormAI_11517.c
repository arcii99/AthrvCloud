//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a circle
double circle_area(double radius){
    return M_PI * pow(radius, 2);
}

int main(){
    double radius, width, height, base;

    // Get user input for radius of circle
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    // Calculate and print the circle's area
    printf("The area of the circle is %.2lf\n", circle_area(radius));

    // Get user input for width and height of rectangle
    printf("Enter the width and height of the rectangle (separated by a space): ");
    scanf("%lf %lf", &width, &height);

    // Calculate and print the rectangle's area
    printf("The area of the rectangle is %.2lf\n", width * height);

    // Get user input for base and height of triangle
    printf("Enter the base and height of the triangle (separated by a space): ");
    scanf("%lf %lf", &base, &height);

    // Calculate and print the triangle's area
    printf("The area of the triangle is %.2lf\n", 0.5 * base * height);

    return 0;
}