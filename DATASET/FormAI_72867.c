//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <math.h>

int main() {

    // Let's calculate the area of a triangle with geometric algorithms
    printf("Hey there! Let's calculate the area of a triangle!\n");

    // Get user input for the length of the base and the height
    float base, height;
    printf("Enter the length of the base: ");
    scanf("%f", &base);
    printf("Enter the height: ");
    scanf("%f", &height);

    // Calculate the area with the formula: (base * height) / 2
    float area = (base * height) / 2;

    // Round the area to two decimal places
    area = roundf(area * 100) / 100;

    // Display the result to the user
    printf("The area of the triangle is: %.2f\n", area);

    // Let's also calculate the perimeter of a circle with geometric algorithms
    printf("Now let's calculate the perimeter of a circle!\n");

    // Get user input for the radius
    float radius;
    printf("Enter the radius: ");
    scanf("%f", &radius);

    // Calculate the perimeter with the formula: 2 * PI * radius
    float perimeter = 2 * M_PI * radius;

    // Round the perimeter to two decimal places
    perimeter = roundf(perimeter * 100) / 100;

    // Display the result to the user
    printf("The perimeter of the circle is: %.2f\n", perimeter);

    return 0;
}