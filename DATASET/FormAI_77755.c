//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include <stdio.h>
#include <math.h>

/* This program calculates the area and perimeter of a circle, square, and triangle using geometric formulas */

int main() {
    float radius, side, base, height, circle_area, circle_perimeter, square_area, square_perimeter, triangle_area, triangle_perimeter;
    const float pi = 3.14159; // constant value of pi

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    circle_area = pi * pow(radius, 2); // formula for area of a circle
    circle_perimeter = 2 * pi * radius; // formula for perimeter of a circle
    printf("The area of the circle is %.2f\n", circle_area);
    printf("The perimeter of the circle is %.2f\n", circle_perimeter);

    printf("Enter the side length of the square: ");
    scanf("%f", &side);
    square_area = pow(side, 2); // formula for area of a square
    square_perimeter = 4 * side; // formula for perimeter of a square
    printf("The area of the square is %.2f\n", square_area);
    printf("The perimeter of the square is %.2f\n", square_perimeter);

    printf("Enter the base and height of the triangle: ");
    scanf("%f%f", &base, &height);
    triangle_area = 0.5 * base * height; // formula for area of a triangle
    triangle_perimeter = base + height + sqrt(pow(base, 2) + pow(height, 2)); // formula for perimeter of a triangle using Pythagorean theorem
    printf("The area of the triangle is %.2f\n", triangle_area);
    printf("The perimeter of the triangle is %.2f\n", triangle_perimeter);

    return 0;
}