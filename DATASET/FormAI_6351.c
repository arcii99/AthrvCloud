//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Hello! Let's learn about Geometric Algorithms with some code.\n\n");

    printf("First, let's find the area of a triangle! Please enter the length of the base: ");
    double base;
    scanf("%lf", &base);

    printf("Great! Now please enter the height: ");
    double height;
    scanf("%lf", &height);

    double area = 0.5 * base * height;
    printf("\nThe area of the triangle is %.2lf!\n\n", area);

    printf("Next, let's find the distance between two points in 2D space.\n");
    printf("Please enter the coordinates for the first point (x1 y1): ");
    double x1, y1;
    scanf("%lf %lf", &x1, &y1);

    printf("Excellent! Now please enter the coordinates for the second point (x2 y2): ");
    double x2, y2;
    scanf("%lf %lf", &x2, &y2);

    double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    printf("\nThe distance between the two points is %.2lf!\n\n", distance);

    printf("Lastly, let's find the circumference and area of a circle.\n");
    printf("Please enter the radius of the circle: ");
    double radius;
    scanf("%lf", &radius);

    double circumference = 2 * M_PI * radius;
    double circle_area = M_PI * pow(radius, 2);
    printf("\nThe circumference of the circle is %.2lf and the area is %.2lf!\n\n", circumference, circle_area);

    printf("Thanks for learning about Geometric Algorithms with me!\n");

    return 0;
}