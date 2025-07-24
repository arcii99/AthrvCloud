//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>
#include <math.h>

int main()
{
    int radius;
    printf("Hi there! Let's calculate the area and circumference of a circle!\n");
    printf("Please enter the radius of the circle: ");
    scanf("%d", &radius);
    double pi = 3.14159265359;
    double area = pi * pow(radius, 2);
    double circumference = 2 * pi * radius;
    printf("Great job! Here are the results:\n");
    printf("Area: %f\n", area);
    printf("Circumference: %f\n\n", circumference);
    printf("Let's try another one! What's the length of the side of a square?\n");
    int side;
    scanf("%d", &side);
    int perimeter = 4 * side;
    printf("Awesome! Here are the results:\n");
    printf("Area: %d\n", side * side);
    printf("Perimeter: %d\n\n", perimeter);
    printf("I hope you had fun learning about geometric algorithms with me! Have a great day!\n");
    return 0;
}