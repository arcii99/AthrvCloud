//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
#include <stdio.h>
#define PI 3.14159265358979323846 // Defining a constant value for pi

int main() {
    int radius, height, base, side, area, circumference, volume;

    // Calculate area and circumference of a circle
    printf("Enter radius of circle: ");
    scanf("%d", &radius);

    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    printf("\nArea of circle: %d", area);
    printf("\nCircumference of circle: %d\n\n", circumference);

    // Calculate area of a triangle
    printf("Enter base and height of triangle: ");
    scanf("%d %d", &base, &height);

    area = 0.5 * base * height;

    printf("\nArea of triangle: %d\n\n", area);

    // Calculate volume of a cube
    printf("Enter side of cube: ");
    scanf("%d", &side);

    volume = side * side * side;

    printf("\nVolume of cube: %d\n", volume);

    return 0;
}