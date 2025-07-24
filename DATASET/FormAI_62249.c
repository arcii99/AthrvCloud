//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
// A program to find the area of a triangle using its three sides

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float s, area;

    printf("Enter the three sides of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    // Calculate the semi-perimeter
    s = (a + b + c) / 2;

    // Calculate the area using Heron's formula
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("The area of the triangle is %.2f\n", area);

    return 0;
}