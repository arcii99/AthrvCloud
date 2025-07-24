//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, x2, y2, x3, y3;

    printf("Enter x and y coordinates of point A: ");
    scanf("%f %f", &x1, &y1);

    printf("Enter x and y coordinates of point B: ");
    scanf("%f %f", &x2, &y2);

    printf("Enter x and y coordinates of point C: ");
    scanf("%f %f", &x3, &y3);

    // Calculate length of sides AB, BC and CA
    float AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    float BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    float CA = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    // Calculate perimeter and area of triangle
    float perimeter = AB + BC + CA;
    float s = perimeter / 2; // Semi-perimeter
    float area = sqrt(s * (s - AB) * (s - BC) * (s - CA));

    printf("Perimeter of the given triangle is: %f\n", perimeter);
    printf("Area of the given triangle is: %f\n", area);

    return 0;
}