//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>

#define PI 3.14159

// Function to calculate the hypotenuse of a right triangle
double hypotenuse(double a, double b) {
    return sqrt(a * a + b * b);
}

// Function to calculate the area of a circle
double area_circle(double radius) {
    return PI * radius * radius;
}

// Function to calculate the volume of a sphere
double volume_sphere(double radius) {
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

int main() {
    double a, b, radius;

    printf("Enter the length of side 1 of the right triangle: ");
    scanf("%lf", &a);

    printf("Enter the length of side 2 of the right triangle: ");
    scanf("%lf", &b);

    printf("The hypotenuse of the right triangle is: %.2lf\n", hypotenuse(a, b));

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    printf("The area of the circle is: %.2lf\n", area_circle(radius));

    printf("The volume of the sphere is: %.2lf\n", volume_sphere(radius));

    return 0;
}