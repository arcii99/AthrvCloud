//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to this amazing geometric algorithms program!\n");
    printf("In this program, you will learn how to calculate the area of a circle and the volume of a sphere.\n");
    printf("Let's get started!\n");

    double pi = 3.14159;
    double radius;

    printf("Please enter the radius of the circle: ");
    scanf("%lf", &radius);

    // Calculate the area of the circle
    double area = pi * pow(radius, 2);
    printf("The area of the circle is: %.2f\n", area);

    printf("Now, let's move on to calculating the volume of a sphere.\n");
    printf("Please enter the radius of the sphere: ");
    scanf("%lf", &radius);

    // Calculate the volume of the sphere
    double volume = (4.0 / 3.0) * pi * pow(radius, 3);
    printf("The volume of the sphere is: %.2f\n", volume);

    printf("Wow, this was amazing! You just learned how to calculate the area of a circle and the volume of a sphere using C programming language!\n");
    printf("Thank you for using this program!\n");

    return 0;
}