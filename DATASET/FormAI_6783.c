//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>
#include <math.h>

int main() {
    // Welcome message
    printf("Hello! Let's explore some cool geometric algorithms in C!\n");

    // User input
    int side_x, side_y, distance;
    printf("Please enter length of side x: ");
    scanf("%d", &side_x);
    printf("Please enter length of side y: ");
    scanf("%d", &side_y);
    printf("Please enter the distance between the two sides: ");
    scanf("%d", &distance);

    // Calculations
    double angle = atan(side_y/side_x);
    double diagonal = sqrt(square(side_x) + square(side_y));
    double radius = distance / (2*sin(angle));

    // Results
    printf("The angle between the two sides is %f radians.\n", angle);
    printf("The length of the diagonal is %f.\n", diagonal);
    printf("The radius of the circle inscribed between the two sides is %f.\n", radius);

    // Goodbye message
    printf("That was fun!\n");
    return 0;
}

// Function to calculate square
int square(int x) {
    return x*x;
}