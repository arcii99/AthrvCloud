//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include<stdio.h>
#include<math.h>

int main() {
    printf("Welcome to the exciting world of geometric algorithms in C!\n");
    printf("Let's calculate the area of a triangle for starters.\n");

    float a, b, c, s, area;

    printf("Enter the length of side a: ");
    scanf("%f", &a);

    printf("Enter the length of side b: ");
    scanf("%f", &b);

    printf("Enter the length of side c: ");
    scanf("%f", &c);

    s = (a + b + c) / 2;
    area = sqrt(s * (s-a) * (s-b) * (s-c));

    printf("The area of the given triangle with sides %f, %f, and %f is: %f\n", a, b, c, area);

    printf("Let's move on to calculating the distance between two points on a coordinate plane.\n");

    float x1, y1, x2, y2, distance;

    printf("Enter the x coordinate of point 1: ");
    scanf("%f", &x1);

    printf("Enter the y coordinate of point 1: ");
    scanf("%f", &y1);

    printf("Enter the x coordinate of point 2: ");
    scanf("%f", &x2);

    printf("Enter the y coordinate of point 2: ");
    scanf("%f", &y2);

    distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

    printf("The distance between point (%f,%f) and point (%f,%f) is: %f\n", x1, y1, x2, y2, distance);

    printf("That's just the tip of the iceberg! Stay curious and keep exploring the world of geometric algorithms in C!\n");

    return 0;
}