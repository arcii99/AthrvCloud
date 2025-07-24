//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265  //declaring global variable PI

int main()
{
    //declaring variables
    float radius, circumference, area, volume;
    int side, perimeter, surface_area;

    printf("Enter the value of radius: ");
    scanf("%f", &radius);

    //calculating circumference, area, and volume of sphere
    circumference = 2 * PI * radius;
    area = PI * pow(radius, 2);
    volume = (4.0 / 3.0) * PI * pow(radius, 3);

    printf("Circumference of the circle: %.2f\n", circumference);
    printf("Area of the circle: %.2f\n", area);
    printf("Volume of the sphere: %.2f\n", volume);

    printf("Enter the value of side: ");
    scanf("%d", &side);

    //calculating perimeter and surface area of cube
    perimeter = 4 * side;
    surface_area = 6 * pow(side, 2);

    printf("Perimeter of the cube: %d\n", perimeter);
    printf("Surface area of the cube: %d\n", surface_area);

    return 0;
}